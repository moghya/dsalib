/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mergesort.h
 * Author: moghya_s
 *
 * Created on June 18, 2016, 7:32 AM
 */

#ifndef MERGESORT_H
#define MERGESORT_H

namespace dsa
{
    template<typename type>
    void merge(array<type> arr,long long int size,long long int start,long long int middle,long long int end)
    {
        array<type> temp(size); long long int i,j,k;
        for(i=start;i<=end;i++)
            temp[i]=arr[i];
            
        i=start;
        j=middle+1;
        k=start;
        
        while(i<=middle&&j<=end)
        {
            if(temp[i]<=temp[j])
            {
                arr[k]=temp[i];
                i++;              
            }
            else
            {
                arr[k]=temp[j];
                j++;
            }
            k++;
        }
        while(i<=middle)
        {
            arr[k]=temp[i];
            k++;
            i++;
        }        
        
    }
    
    template<typename type>
    void mergesort(array<type> arr,long long int size,long long int start,long long int end)
    {
        if(start<end){
            long long int middle = (start+end)/2;
            mergesort(arr,size,start,middle);
            mergesort(arr,size,middle+1,end);
            merge(arr,size,start,middle,end);
        }  
    }
}
#endif /* MERGESORT_H */

