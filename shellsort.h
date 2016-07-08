/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shellsort.h
 * Author: moghya_s
 *
 * Created on June 22, 2016, 7:33 AM
 */

#ifndef SHELLSORT_H
#define SHELLSORT_H

namespace dsa
{
    template<typename type>
    void shellsort(array<type> arr,long long int size)
    {
        long long int incr,cur,temp;
        type var;
        for(incr=(size-1)/2;incr>0;incr/=2)
        {
            for (cur = incr; cur <size; cur++)
            {
                var=arr[cur];                
                for(temp=cur-incr;temp>=0&&var<arr[temp];temp-=incr)
                {
                    arr[temp+incr]=arr[temp];
                }
                arr[temp+incr]=var;
            }
        }
        return ;
    }
}


#endif /* SHELLSORT_H */

