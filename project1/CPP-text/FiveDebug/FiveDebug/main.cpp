//
//  main.cpp
//  FiveDebug
//
//  Created by Eunice on 2020/11/18.
//  Copyright © 2020 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;
class A
{public:
    A(int i=0){m=i;};
    void show(){cout<<m;};
    void ~A(){};
private:
        int m;
};
int main()
{   A a(5);
a.m+=10;
a.show();
return 0;
}
