/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   insertionsort.h
 * Author: moghya_s
 *
 * Created on June 21, 2016, 8:55 AM
 */

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <iostream>

#include "array.h"

namespace dsa
{
    template<typename type>
    void insertionsort(array<type> arr,long long int size)
    {
        long long int i,j,var;
        for(i=1;i<size;i++)
        {
            var = arr[i];
            for(j=i-1;j>=0&&var<arr[j];j--)
                arr[j+1]=arr[j];                 
            
            arr[j+1]=var;

        }
    }
}
#endif /* INSERTIONSORT_H */

