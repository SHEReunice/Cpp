#include <iostream>
#define N 100
using namespace std;
int n;//��Ʒ���� 
double W;//�������� 
double w[N];//��Ʒ���� 
double v[N];//��Ʒ��ֵ 
bool x[N];  //�洢����� 
bool best[N]; 
double now_v;   //��ǰ��ֵ
double remain_v;    //ʣ���ֵ
double now_w;   //��ǰ����
double best_v;  //���ż�ֵ
 
 double Bound(int k)//���ص�ǰ��ֵ��ʣ���ֵ֮�� 
 {
     remain_v = 0;
     while(k <= n){
         remain_v += v[k];
         k++;
     }
     return remain_v + now_v;
 }
 
 void Backtrack(int t)
 {
     if(t > n){  //�Ƿ񵽴�Ҷ�ڵ�
         for(int i = 1; i <= n; i++){
             best[i] = x[i];  
         }
         best_v = now_v;
         return;
     }
     //û�е�Ҷ�ڵ㣬�ж���Ʒ�Ƿ���Է��뱳�� 
     if(now_w + w[t] <= W){  //�����ǰ������ĳ��Ʒ����С�ڱ�����������װ�� 
         x[t] = 1;
         now_w += w[t];
         now_v += v[t];
         Backtrack(t+1); //������һ���ڵ�ķ���
         now_w -= w[t];  //�ڵ���Ҷ�ڵ����л���
         now_v -= v[t];
     }
     //��װ������������ǰ��ֵ��ʣ���ֵ���Ѿ����������ֵ���󣬲����½��� 
	  if(Bound(t+1) > best_v){   
         x[t] = 0;
         Backtrack(t+1);
     }
 
 }
 
 void fun(double W, int n)
 {
     double sum_w = 0;
     double sum_v = 0;
     best_v = 0;
     for(int i = 0; i < n; i++){
         sum_w += w[i];
         sum_v += v[i];
     }
     
     Backtrack(1);
     cout << "����ֵΪ:" << best_v << endl;
     cout << "��Ʒװ�����Ϊ:" ;
     for(int i = 1; i <= n; i ++){
     	if(best[i]==1)cout<<"��Ʒ"<<i<<"     "; 
     }
     cout << endl;
 }
 
 int main()
 {
     cout << "��������Ʒ����:";
     cin >> n;
     cout << "�����뱳������:";
     cin >> W;
     cout << "�����������Ʒ������:";
     for(int i = 1; i <= n; i++){
         cin >> w[i];
     }
     cout << "�����������Ʒ�ļ�ֵ:";
     for(int i = 1; i <= n; i++){
         cin >> v[i];
     }
     fun(W,n);
     return 0;
}

