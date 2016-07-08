/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heapsort.h
 * Author: moghya_s
 *
 * Created on June 22, 2016, 12:27 PM
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H



namespace dsa
{
    template<typename type>
    void heapsort(array<type> arr)
    {
        minheap<type> h(arr);
        long long int i=0;
        while(i<arr.size())
        {
            arr[i]=h.getmin();
            h.popmin();
            i++;
        }
        return ;
    }
}

#endif /* HEAPSORT_H */

