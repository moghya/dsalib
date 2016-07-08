/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graph.h
 * Author: moghya_s
 *
 * Created on June 22, 2016, 3:43 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

namespace dsa
{
    template<class type>
    class graph
    {
        private:
            linklist<gnode> nodes;
            long long int count;
            struct gnode
            {
                long long int key;
                type data;
                gnode(type param)
                {
                    data=param;
                    key=count+1;
                }
            };
            gnode create_gnode()
            {
            
            }
        public:
            


    };
}
#endif /* GRAPH_H */

