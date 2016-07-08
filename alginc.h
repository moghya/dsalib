/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alginc.h
 * Author: moghya_s
 *
 * Created on June 15, 2016, 7:44 AM
 */

#ifndef ALGINC_H
#define ALGINC_H

namespace dsa
{
    template<typename T>
    inline void swapit(T &x, T &y)
    {
        T t = x;
        x = y;
        y = t;
    }

    template<typename T>
    inline T maxof(T &x, T &y)
    {
        T max;
        max = (x > y) ? x : y;
        return max;
    }

    template<typename T>
    inline T minof(T x, T y)
    {
        T min;
        min = (x < y) ? x : y;
        return min;
    }

}

#endif /* ALGINC_H */

