//
//  main.cpp
//  vector
//
//  Created by Eunice on 2021/4/29.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <vector>
#include<set>
#include <map>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    /*
    vector<int> a ;  //定义的时候不指定vector的大小
    cout << a.size() << endl;
    for(int i = 0; i < 10; i++){
        a.push_back(i); //在vector a的末尾添加一个元素i
    }
    cout << a.size() << endl;
    vector<int> b(15); //定义的时候指定vector的c大小，默认b里面元素都是0
    cout << b.size() << endl;
    for(int i = 0; i < b.size(); i++){
        b[i] = 15;
    }
    for(int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
    vector<int> c(20,2);//定义的时候指定vector的大小，并把所有的元素赋一个指定的值
    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
    cout << endl;
    for(auto it = c.begin(); it != c.end(); it++){
        cout << *it << " ";
    }
     */
    /*
    set<int> s; //定义一个空集合s
    s.insert(1); //向集合s里插入一个1
    cout << *(s.begin()) << endl; //输出集合s的第一个元素（前面的星号表示对指针取值）
    for(int i = 0; i < 6; i++){
        s.insert(i); //向集合s中插入i
    }
    for(auto it = s.begin();it != s.end(); it++){ //用迭代器遍历集合s中的每一个元素
        cout << *it << " ";
    }
    cout << endl << (s.find(2) != s.end()) << endl; //查找集合s中的值，如果结果等于s.end(）表示未找到，因为s.end()表示的是集合中最后一个元素的下一个元素所在的位置
    cout << (s.find(10) != s.end()) << endl; //s.find(10)!=s.end()表示能找到10这个元素
    s.erase(1);//删除集合s中1这个元素
    cout << (s.find(1)!=s.end()) << endl; //这个时候应该就找不到元素1了
    */
    map<string, int> m;//定义一个空的map m，键是string类型的，值是int类型的
    m["hello"] = 2; //将key为“hello”，value为2的键值对（key-vlaue)存入map中
    cout << m["hello"] << endl; //访问map中key为“hello”的value，如果key不存在，则返回0
    cout << m["world"] << endl;
    m["world"] = 3; //将"world"键对应的值修改为3
    m[","] = 1;//设立一组键值对，键为“，”，值为1
    //用迭代器遍历，输出map中所有的元素，键用it->first获取，值用it->second获取
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    //访问map的第一个元素，输出它的键和值
    cout << m.begin()->first << " " << m.begin()->second << endl;
    //访问map的最后一个元素，输出它的键和值
    cout << m.rbegin()->first << " " << m.rbegin()->second << endl;
    //输出map的元素个数
    cout << m.size() << endl;
    return 0;
}
