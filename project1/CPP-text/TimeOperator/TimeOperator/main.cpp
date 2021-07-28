//
//  main.cpp
//  TimeOperator
//
//  Created by Eunice on 2020/11/18.
//  Copyright © 2020 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;
class Time{
public:
    void PrintMilitary();
    void PrintStardard();
    void SetClock();
private:
    int hour;
    int minute;
    int second;
};

void Time::SetClock(){
    cin >> hour;
    cin >> minute;
    cin >> second;
}

void Time::PrintMilitary(){
    cout << hour << ":" << minute << ":" << second << endl;
}

void Time::PrintStardard(){
    if(hour < 12){
        cout << hour << ":" << minute << ":" << second << "AM" << endl;
    }else if(hour == 12){
        cout << hour << ":" << minute << ":" << second << "PM" << endl;
    }else{
        cout << hour-12 << ":" << minute << ":" << second << "PM" << endl;
    }
}

int main() {
    int hour,minute,second;
    Time time;
    time.SetClock();
    time.PrintMilitary();
    time.PrintStardard();
    return 0;
}
