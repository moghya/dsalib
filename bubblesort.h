/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bubblesort.h
 * Author: moghya_s
 *
 * Created on June 21, 2016, 12:13 PM
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H
namespace dsa
{

    template<typename type>
    void bubblesort(array<type> arr,long long int size)
    {
        long long int i,j;
        for(i=0;i<size;i++)
        {          
            for(j=1;j<size;j++)
            {
                if(arr[j]<arr[j-1])
                    swapit(arr[j],arr[j-1]);
            }       
        }
    }

}


#endif /* BUBBLESORT_H */

