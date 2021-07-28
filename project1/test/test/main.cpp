//
//  main.cpp
//  test
//
//  Created by Eunice on 2020/9/28.
//  Copyright © 2020 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;
void f1(int *px){*px += 10;}
void f2(int &xx){xx += 10;}

/*int a = 4;
int &f(int x){
    a = a + x;
    return a;
} //函数返回a的引用，即a的别名
*/
int &f(int  &x){
    static int t = 2;
    t = x++;
    return t;
}
    
int main(void){
    /*int x = 0;
    cout<<"x="<<x<<endl;
    f1(&x);
    cout<<"x="<<x<<endl;
    f2(x);
    cout<<"x="<<x<<endl;
  
    int t = 5;
    cout<<f(t)<<endl;   //输出9，（a = 5,t = 5)
    f(t)=20;//先调用，再赋值，a=20，t=5
    cout<<f(t)<<endl;//输出25（a=25,t=5)
    t = f(t);//先调用，再赋值。a=30,t=30
    cout<<f(t)<<endl; //输出60
    return 0;*/
    
    int a = 3;
    cout<<f(a)<<endl;
    cout<<"a="<<a<<endl;
    f(a) = 20;
    cout<<"a="<<a<<endl;
    a = a + 5;
    cout<<"a="<<a<<endl;
    cout<<f(a)<<endl;
    cout<<"a="<<a<<endl;
    a = f(a);
    cout<<"a="<<a<<endl;
    cout<<f(a)<<endl;
    cout<<"a="<<a<<endl;

    
}
