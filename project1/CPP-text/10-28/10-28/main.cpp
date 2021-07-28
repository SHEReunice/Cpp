//
//  main.cpp
//  10-28
//
//  Created by Eunice on 2020/10/28.
//  Copyright © 2020 Eunice. All rights reserved.
//
#include <iostream>
#include <iomanip>
using namespace std;
class Array
{
public:
    Array();
    friend Array operator+(Array a1, Array a2);
    void input();
    void display();
private:
    int arr[2][3];
};
Array::Array()
{
    int i, j;
    for (i=0; i<2; i++)
        for (j=0; j<3;j++)
            arr[i][j]=0;
}
Array operator+(Array a1, Array a2)
{
    Array a3;
    int i, j;
    for (i=0; i<2; i++)
        for (j=0; j<3; j++)
            a3.arr[i][j]=a1.arr[i][j]+a2.arr[i][j];
    return a3;
}
void Array::input()
{
    cout<<"Please enter array:";
    for (int i=0; i<2; i++)
        for (int j=0; j<3; j++)
            cin>>arr[i][j];
}
void Array::display()
{
    int i, j;
    for (i=0; i<2; cout<<endl, i++)
        for (j=0; j<3; cout<<setw(4)<<arr[i][j]<<' ', j++);
}
int main()
{
    Array a, b, c;
    a.input();
    b.input();
    c=a+b;
    c.display();
    system("pause");
    return 0;
}
