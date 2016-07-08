/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.h
 * Author: moghya_s
 *
 * Created on June 21, 2016, 12:39 PM
 */

#ifndef HEAP_H
#define HEAP_H
namespace dsa
{
    template<class type>
    class maxheap
    {
        private:
            long long int count,capacity;
            type *objs;       
            void _reheapup(long long int index)
            {
                if(index>0)
                {
                    long long int parent=(index-1)/2;
                    if(objs[parent]<objs[index])
                    {
                        swapit(objs[parent],objs[index]);
                        _reheapup(parent);
                    }
                }
                return ;
            }
            
            void _reheapdown(long long index)
            {
                if(index>=0&&index<count)
                {
                    long long int lc=2*index+1,rc=2*index+2,large;
                    if(lc<count)
                    {
                        large=lc;
                        if(rc<count)
                        {
                            if(objs[lc]<objs[rc])
                                large=rc;                                            
                        }
                        if(objs[index]<objs[large])
                        {
                            swapit(objs[index],objs[large]);
                            _reheapdown(large);
                        }
                    }
                }
                return ;
            }
            
        public:
            
            maxheap(long long int size)
            {    
                count = 0;
                capacity=size;
                objs = new type[capacity];           
            }
            
            maxheap(array<type> arr)
            {    
                count = 0;
                capacity=arr.size();
                objs = new type[capacity];
                long long int i;
                for(i=0;i<arr.size();i++)
                    insert(arr[i]);
            }
            
            bool insert(type param)
            {
                if(count+1>capacity) return false;
                objs[count]=param;
                _reheapup(count);
                count++;
                return true;
            }
            
            bool popmax()
            {
                if(count>0)
                {
                    objs[0]=objs[count-1];
                    count--;
                    _reheapdown(0);
                    return true;
                }    
                return false;
            }
            
            type getmax()
            {
                
                return objs[0];
            }
           
            long long int size()
            {
                return count;
            }

            void traverse(void (fun)(type obj))
            {
                long long int i;
                for(i=0;i<count;i++)
                    fun(objs[i]);
                   
            }
            


    };
    
    template<class type>
    class minheap
    {
        private:
            long long int count,capacity;
            type *objs;       
                        
            void _reheapup(long long int index)
            {
                if(index>0)
                {
                    long long int parent=(index-1)/2;
                    if(objs[index]<objs[parent])
                    {
                        swapit(objs[parent],objs[index]);
                        _reheapup(parent);
                    }
                }
                return ;
            }
            
            void _reheapdown(long long index)
            {
                if(index>=0&&index<count)
                {
                    long long int lc=2*index+1,rc=2*index+2,less;
                    if(lc<count)
                    {
                        less=lc;
                        if(rc<count)
                        {
                            if(objs[rc]<objs[lc])
                                less=rc;                                            
                        }
                        if(objs[less]<objs[index])
                        {
                            swapit(objs[index],objs[less]);
                            _reheapdown(less);
                        }
                    }
                }
                return ;
            }
            
        public:
            
            minheap(long long int size)
            {    
                count = 0;
                capacity=size;
                objs = new type[capacity];           
            }
            minheap(array<type> arr)
            {    
                count = 0;
                capacity=arr.size();
                objs = new type[capacity];
                long long int i;
                for(i=0;i<arr.size();i++)
                    insert(arr[i]);
            }
            
            bool insert(type param)
            {
                if(count+1>capacity) return false;
                objs[count]=param;
                _reheapup(count);
                count++;
                return true;
            }
            
            bool popmin()
            {
                if(count>0)
                {
                    objs[0]=objs[count-1];
                    count--;
                    _reheapdown(0);
                    return true;
                }    
                return false;
            }
            
            type getmin()
            {
                
                return objs[0];
            }
           
            long long int size()
            {
                return count;
            }

            void traverse(void (fun)(type obj))
            {
                long long int i;
                for(i=0;i<count;i++)
                    fun(objs[i]);
                   
            }          


    };
}
#endif /* HEAP_H */
