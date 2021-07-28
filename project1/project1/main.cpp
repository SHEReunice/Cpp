//
//  main.cpp
//  project1
//
//  Created by Eunice on 2020/9/22.
//  Copyright © 2020 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    // insert code here...
    void sort(int x,int y,int z);
    int x,y,z;
    cin>>x>>y>>z;
    sort(x,y,z);
    return 0;
    
    return 0;
}
void sort(int x,int y,int z){
    int temp;
    if(x>y) {temp = x; x = y; y = temp;}
    if(z<x){
        cout <<z<<','<<x<<','<<y<<endl;
    }
    else if(z<y)cout<<x<<','<<z<<','<<y<<endl;
    else cout<<x<<','<<y<<','<<z<<endl;
}
