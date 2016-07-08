/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   array.h
 * Author: moghya_s
 *
 * Created on June 15, 2016, 10:23 AM
 */

#ifndef ARRAY_H
#define ARRAY_H

namespace dsa
{
    template<class type>
    class array
    {
        private:
            long long int count,capacity;
            type *objs;        
        public:
            
            array(long long int size)
            {    
                count = size;
                capacity=size;
                objs = new type[capacity];                
            }
                                    
            type &operator[](long long int index)
            {
                if(index>=0&&index<count)
                {
                    return objs[index];
                }            
            }            
            
            void reverse(long long int start,long long int end)
            {
                if(start>=0&&start<count&&end>=0&&end<count)
                {   
                    while(start<end/2)
                    {
                        swapit(objs[start],objs[end-start]);
                        start++;
                    }
                }
            }
            
            long long int size()
            {
                return count;
            }

            void traverse(void (fun)(type obj))
            {
                long long int i;
                for(i=0;i<count;i++)
                    fun(objs[i]);
                   
            }
    };
}
#endif /* ARRAY_H */

