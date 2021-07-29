#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"
#define Max_size 10
#define NUM_PRODUCER 6
#define NUM_CONSUMER 10
#define PRODUCER_SLEEP_TIME_MS 500
#define CONSUMER_SLEEP_TIME_MS 500
using namespace std;

long int buffer[Max_size];
int k;
int t;
long TotalItemsProduced; //生产的商品总数
long TotalItemsConsumed; //消费的商品总数
BOOL StopRequested;  //停止请求
CRITICAL_SECTION CS; //临界区
CONDITION_VARIABLE _empty; //线程休眠和唤醒的条件变量，下同（在vs里面is_empty会报错，所以这里命名就改成了_empty
CONDITION_VARIABLE is_full;
DWORD WINAPI Producer(LPVOID); //生产者线程
DWORD WINAPI Consumer(LPVOID); //消费者线程

int main() {
    int i;
    HANDLE h1[NUM_PRODUCER], h2[NUM_CONSUMER]; //10个生产者10个消费者

    InitializeCriticalSection(&CS); //初始化临界区
    InitializeConditionVariable(&_empty); //初始化条件变量，下同
    InitializeConditionVariable(&is_full); 
    for (int i = 0; i < NUM_PRODUCER; i++) { //创建生产者线程
        h1[i] = CreateThread(NULL, 0, &Producer, &i, 0, NULL);
    }
    for (int i = 0; i < NUM_CONSUMER; i++) { //创建消费者线程，中间没有设置路障，这些线程运行顺序是随机的
        h2[i] = CreateThread(NULL, 0, &Consumer, &i, 0, NULL);
    }

    puts("Press enter to stop...");
    getchar(); //同时按住ctrl+Z停止运行

    EnterCriticalSection(&CS);
    StopRequested = TRUE;
    LeaveCriticalSection(&CS);

    WakeAllConditionVariable(&_empty); //唤醒在这个条件变量上休眠的所有线程，下同
    WakeAllConditionVariable(&is_full);
    WaitForMultipleObjects(NUM_PRODUCER, h1, true, INFINITE);//主线程等待这一组线程完成，第一个是让函数查看的内核对象的数量，第二个是指向内核对象句柄的指针
    //第三个传true，在所有对象变为已通知之前，该函数不允许调用线程运行，第四个是一个超时值，等待时间到了，函数无论如何都会返回
    WaitForMultipleObjects(NUM_CONSUMER, h2, true, INFINITE);
    for (int i = 0; i < NUM_PRODUCER; i++) {
        CloseHandle(h1[i]);  //线程终止运行后，线程对象仍在系统中，必须通过CloseHandle()函数来关闭该线程对象
    }
    for (int i = 0; i < NUM_CONSUMER; i++) {
        CloseHandle(h2[i]);
    }
    DeleteCriticalSection(&CS); //对临界区使用完之后调用该函数删除临界区结构的对象
    return 0;
}

DWORD WINAPI Producer(LPVOID p) {
    int ThreadNum = *(int*)p;
    while (true) {
        // Produce a new item.
        int item;
        EnterCriticalSection(&CS); //进入临界区，其他要访问临界区的线程将被挂起要一直等到临界区被释放
        item = (rand() % 80) + 1; //随机生成商品的值
        while (k == Max_size && StopRequested == FALSE) { //物品队列满了，生产者线程阻塞
            // Buffer is full - sleep, so consumers can get items.
            SleepConditionVariableCS(&_empty, &CS, INFINITE);  //线程休眠，第一个线程等待被唤醒的条件变量
        }
        if (StopRequested == TRUE) //请求停止
        {
            LeaveCriticalSection(&CS); //释放临界区
            break;
        }
        // Insert the item at the end of the queue and increment size.
        buffer[(k + t)%Max_size] = item; //商品进入物品队列中
        k++; //当前队列的长度加一
        TotalItemsProduced++;  //总生产量加一
        printf("Producer %u: item %2d, queue_size %2u\r\n", ThreadNum, item, k);

        LeaveCriticalSection(&CS);  //释放临界区
        WakeConditionVariable(&is_full);  // If a consumer is waiting, wake it.

        Sleep(rand() % PRODUCER_SLEEP_TIME_MS); 
    }
       
    printf("Producer %u exiting\r\n", ThreadNum);
    return 0;
}

DWORD WINAPI Consumer(LPVOID p) {
    int ThreadNum = *(int*)p;
    while (true) {

        int item;
        EnterCriticalSection(&CS);
        while (k == 0 && StopRequested == FALSE) {
            // Buffer is empty - sleep so producers can create items.
          
            SleepConditionVariableCS(&is_full, &CS, INFINITE);
        }
        if (StopRequested == TRUE && k == 0)
        {

            LeaveCriticalSection(&CS);
            break;
        }
        // Consume the first available item.
        item = buffer[t];
        k--; //队列长度减一
        t++;
        TotalItemsConsumed++;
        if (t == Max_size)
        {
            t = 0;
        }
        printf("Consumer %u: item %2d, queue_size %2u\r\n", ThreadNum, item, k);

        LeaveCriticalSection(&CS);//释放临界区
        WakeConditionVariable(&_empty);// If a producer is waiting, wake it.
        Sleep(rand() % CONSUMER_SLEEP_TIME_MS);
    }
    printf("Consumer %u exiting\r\n", ThreadNum);
    return 0;
}
