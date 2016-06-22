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
            long long int count,elsize;
            type *start,*end,*objs;          
        public:
            
            array(long long int size)
            {    
                count = size;
                elsize = sizeof(type);
                objs = new type[size];
                start = objs;
                end =  objs+size*elsize;
            }

            array()
            {    
                count = 0;
                elsize = sizeof(type);
                objs = new type[size];
                start = objs;
                end =  objs+size*elsize;
            }
            
            type &operator[](long long int index)
            {
                if(index>=0&&index<count)
                {
                    return objs[index];
                }            
            }
            
            long long int size()
            {
                return count;
            }
                      
    };
}
#endif /* ARRAY_H */

