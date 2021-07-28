//
//  main.cpp
//  CPP-text
//
//  Created by Eunice on 2020/10/21.
//  Copyright © 2020 Eunice. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
/*（1）
 int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}*/

/*
 （2）
int main(){
    int i;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4-i; j++)
            cout << " ";
        for(int j = 1; j <= 2*i-1; j++)
            cout << "*";
        for(int j = 1; j <= 4-i; j++)
            cout << " ";
        cout << endl;
    }
    for(int i = 3; i >= 1; i--){
        for(int j = 1; j <= 4-i; j++)
            cout << " ";
        for(int j = 1; j <= 2*i-1; j++)
            cout << "*";
        for(int j = 1; j <= 4-i; j++)
            cout << " ";
        cout << endl;
    }
    return 0;
}*/
/*（3）
struct Student{
    string student_number;
    string name;
    string major;
    int score;
};
    
int main(){
    Student student;
    cin >> student.student_number;
    cin >> student.name;
    cin >> student.major;
    
    cin >> student.score;
    cout << student.student_number << endl;
    cout << student.name << endl;
    cout << student.major << endl;
    cout << student.score << endl;
    return 0;
}
*/
/*2-1
int main(){
    int multiple;
    for(int i = 1; i <= 100; i++){
        if(i % 13 == 0)
            multiple = i;
    }
    cout <<  multiple << endl;
    return 0;
}
*/
/*2-2
int fib(int n){
    if(n == 0)
        return 0;
    int f0 = 0, f1 = 1, f2;
    for(int i = 0; i < n-1; i++){//只能加到n-2
        f2 = f0 + f1;
        f0 = f1 % 1000000007;
        f1 = f2 % 1000000007;
    }
    return f1;
}
    
int main(){
    int num;
    cin >> num;
    cout << fib(num) << endl;
    return 0;
    
}
*/
/*2-3
int main(){
    string s[5];
    for(int i = 0; i < 5; i++)
        cin >> s[i];
    sort(s,s+5);
    for(int i = 0; i < 5; i++)
        cout << s[i] << endl;
    return 0;

}
 */
/*3-1.1
 int main(){
     int max(int a, int b, int c);
     int a, b, c;
     cin >> a >> b >> c;
     cout << "max(a,b,c) = " << max(a,b,c) << endl;
     return 0;
 }
 int max(int a, int b, int c){
     if(b > a) a = b;
     if(c > a) a = c;
     return a;
 }
*/
/*3-1.2
int main(){
    int max(int a, int b, int c = 0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << "max(a,b,c) = " << max(a,b,c) << endl;
    return 0;
}
int max(int a, int b, int c){
    if(b > a) a = b;
    if(c > a) a = c;
    return a;
}
*/
/*3-2
int mystrchr(char string[], char c){
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == c){
            return i;
    }
}
        return 0;
}
int main(){
    char string[100];
    char c;
    cin >> string;
    cin >> c;
    
    cout << mystrchr(string,c) << endl;
}
*/
/*3-3
int gap(int x1, int x2, int y1, int y2){
    int z = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    return z;
}
double gap(double x1, double x2, double y1, double y2){
    double z = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    return z;
}
int main(){
    int x1, x2, y1, y2;
    double x3, x4, y3, y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    cout << "两个整数点之间距离为：" << gap(x1,x2,y1,y2) << endl;
    cout << "两个小数点之间距离为：" << gap(x3,x4,y3,y4) << endl;
    return 0;
}
*/
/*3-4
class Array{
public:
    int row,col;
    int m;
    int a[][5];
    void max(int a[][5],int m, int &rows,int &cols){
        int max_num = a[0][0];
        rows = cols = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < 5; j++){
                if(max_num < a[i][j]){
                    max_num = a[i][j];
                    rows = i;
                    cols = j;
                }
            }
        }
        row = rows;
        col = cols;
    }
    void Input(void){
        cin >> m;
        for(int i=0; i < m; i++){
            for(int j=0; j < 5; j++){
                cin >> a[i][j];
            }
        }
    }
    void Print(void){
        cout << "数组中的最大数行数为：" << row << endl;
        cout << "数组中的最大数列数为：" << col << endl;
    }
};
int main(){
    Array a1;
    a1.Input();
    a1.max(a1.a, a1.m, a1.row, a1.col);
    a1.Print();
    return 0;
}
*/
/*4-1
class Clock
{
public:
    void set_clock(void);
    void show_clock(void);
    int hour;
    int minute;
    int second;
};
void set_clock(void)
{
    Clock t;
    cin>>t.hour;
    cin>>t.minute;
    cin>>t.second;
};
    void show_clock(void)
{
    Clock t;
    cout<<t.hour<<":"<<t.minute<<":"<<t.second<<endl;
};

    int main()
{
    Clock clock;
    set_clock();
   show_clock ();
}
*/

    

