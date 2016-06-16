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
#include "linklist.h"
#include "queue.h"
#include "stack.h"
#include "alginc.h"
#include "tree.h"
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
       {
          return true;
       }
       
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


int main(int argc, char** argv) {

    stud obj;    
    bstree<int> bt,abt;
    
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    
    bt.preorder(fun);
    abt=bt;
    abt.preorder(fun);
    
    
     return 0;
}
