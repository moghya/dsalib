/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binarysearch.h
 * Author: moghya_s
 *
 * Created on June 22, 2016, 11:04 AM
 */

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

namespace dsa
{
    template<typename type>
    long long int binarysearch(array<type> arr,long long int start,long long int end,type param)
    {
        if(start<=end)
        {
            long long int mid=(start+end)/2;        
            if(arr[mid]<param)
                return binarysearch(arr,mid+1,end,param);               
            else
                if(param<arr[mid])
                return binarysearch(arr,start,mid-1,param);
                else
                return mid;
        }
        else
        {
            return -1;
        }
    }
}

#endif /* BINARYSEARCH_H */

