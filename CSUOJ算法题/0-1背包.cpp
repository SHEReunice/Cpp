#include <iostream>
#define N 100
using namespace std;
int n;//物品个数 
double W;//背包容量 
double w[N];//物品重量 
double v[N];//物品价值 
bool x[N];  //存储顶点号 
bool best[N]; 
double now_v;   //当前价值
double remain_v;    //剩余价值
double now_w;   //当前容量
double best_v;  //最优价值
 
 double Bound(int k)//返回当前价值和剩余价值之和 
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
     if(t > n){  //是否到达叶节点
         for(int i = 1; i <= n; i++){
             best[i] = x[i];  
         }
         best_v = now_v;
         return;
     }
     //没有到叶节点，判断物品是否可以放入背包 
     if(now_w + w[t] <= W){  //如果当前重量加某物品重量小于背包容量，则装入 
         x[t] = 1;
         now_w += w[t];
         now_v += v[t];
         Backtrack(t+1); //进行下一个节点的分析
         now_w -= w[t];  //在到达叶节点后进行回溯
         now_v -= v[t];
     }
     //不装入情况，如果当前价值加剩余价值比已经算出的最优值还大，才往下进行 
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
     cout << "最大价值为:" << best_v << endl;
     cout << "物品装入情况为:" ;
     for(int i = 1; i <= n; i ++){
     	if(best[i]==1)cout<<"物品"<<i<<"     "; 
     }
     cout << endl;
 }
 
 int main()
 {
     cout << "请输入物品个数:";
     cin >> n;
     cout << "请输入背包容量:";
     cin >> W;
     cout << "请输入各个物品的重量:";
     for(int i = 1; i <= n; i++){
         cin >> w[i];
     }
     cout << "请输入各个物品的价值:";
     for(int i = 1; i <= n; i++){
         cin >> v[i];
     }
     fun(W,n);
     return 0;
}

