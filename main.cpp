/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: moghya_s
 *
 * Created on May 31, 2016, 11:12 AM
 */

#include <cstdlib>
#include <iostream>
#include "dsa.h"

using namespace std;
using namespace dsa;
 
class stud
{
    public:
    int id;
    string name;
    display()
    {
        cout<<"id="<<id<<" name="<<name<<"\n";
    }
    
    static void just(stud obj)
    {
        cout<<obj.id<<" ";
    }
    bool operator <(const stud& d)
    {
        if(id < d.id)
            return true;
        else
            return false;
    }
    
};

bool haha(int val)
{
    if(val>=3) return true;
    else return false;
}

void fun (int obj)
{
    cout<<obj<<" ";
}

int main(int argc, char** argv)
{
    array<int> a(6);
    a[0]=6;
    a[1]=3;
    a[2]=1;    a[3]=0;    a[4]=5;    a[5]=4;
    heapsort(a);
    a.traverse(fun);
    cout<<binarysearch(a,0,5,3);
    return 0;
}

