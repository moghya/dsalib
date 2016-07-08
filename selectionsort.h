/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   selectionsort.h
 * Author: moghya_s
 *
 * Created on June 21, 2016, 8:23 AM
 */

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
namespace dsa
{

    template<typename type>
    void selectionsort(array<type> arr,long long int size)
    {
        long long int i,j,k,min;
        for(i=0;i<size;i++)
        {
            min = i;
            for(j=i+1;j<size;j++)
            {
                if(arr[j]<arr[min])
                    min = j;
            }
            
            swapit(arr[i],arr[min]);
       }
    }

}
#endif /* SELECTIONSORT_H */

