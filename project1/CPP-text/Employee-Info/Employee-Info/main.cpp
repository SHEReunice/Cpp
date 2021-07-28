//
//  main.cpp
//  Employee-Info
//
//  Created by Eunice on 2020/11/18.
//  Copyright © 2020 Eunice. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
    void setInfo();
    void edit();
    void display();
private:
    string name;
    string street;
    string city;
    string province;
    string zip;
};

void Employee::setInfo(){
    cin >> name;
    cin >> street;
    cin >> city;
    cin >> province;
    cin >> zip;
}

void Employee::edit(){
    char c[5];
    unsigned long len, i;
    cout << "Edit name,press 1;" << endl;
    cout << "Edit street,press 2;" << endl;
    cout << "Edit city,press 3;" << endl;
    cout << "Edit province,press 4;" << endl;
    cout << "Edit zip, press 5;" << endl;
    scanf("%s",c);
    len  = strlen(c);
    for(i=0; i<len; i++){
        switch(c[i]){
            case '1':
                cin >> name;
                break;
            case '2':
                cin >> street;
                break;
            case '3':
                cin >> city;
                break;
            case '4':
                cin >> province;
                break;
            case '5':
                cin >> zip;
                break;
            default:
                break;
        }
    }
}

void Employee::display(){
        cout << "Name: " << name << endl;
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Province: " << province << endl;
        cout << "Zip: " << zip << endl;
}
int main(int argc, const char * argv[]) {
    Employee employee;
    employee.setInfo();
    employee.edit();
    employee.display();
    return 0;
}
