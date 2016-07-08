/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   quicksort.h
 * Author: moghya_s
 *
 * Created on June 18, 2016, 9:58 PM
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

namespace dsa
{
    template<typename type>
    long long int partition(array<type> arr,long long int start,long long int end)
    {
        type var = arr[end];
        long long int i,j;
        i=start-1;
        for(j=start;j<end;j++)
        {
            if(arr[j]<=var)
            {   i++;
                swapit(arr[i],arr[j]);
            }
        }
        i++;
        swapit(arr[i],arr[end]);
        return i;
    }
    
    template<typename type>
    void quicksort(array<type> arr,long long int start,long long int end)
    {
        if(start<end)
        {
            long long int pivot;
            pivot = partition(arr,start,end);
            quicksort(arr,start,pivot-1);
            quicksort(arr,pivot+1,end);
        }  
    }

}
#endif /* QUICKSORT_H */
