//
//  main.cpp
//  Student Info
//
//  Created by Eunice on 2020/11/18.
//  Copyright © 2020 Eunice. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    void PrintStu();
    void SetStu();
private:
    string name;
    string Stunums;
    string gender;
    int age;
};
/*
Student :: Student(string n,string nu,string g,int ag){
    name = n;
    Stunums = nu;
    gender = g;
    age = ag;
}*/

void Student::SetStu(){
    cin >> name;
    cin >> Stunums;
    cin >> gender;
    cin >> age;
}

void Student::PrintStu(){
    cout << "Nmae: " << name << endl;
    cout << "Num: " << Stunums << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
}



int main() {
    Student s1;
    s1.SetStu();
    s1.PrintStu();
    return 0;
    
}
