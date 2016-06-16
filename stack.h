/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: moghya_s
 *
 * Created on June 14, 2016, 5:51 PM
 */

#ifndef STACK_H
#define STACK_H



namespace dsa
{
    
    template<class type>
    class snode
    {
        public :
        snode *prev;
        type data;
        snode *next;

        snode()
        {
            prev = NULL;
            next = NULL;
        }

        snode(type param)
        {
            prev = NULL;
            data = param;
            next = NULL;
        }
    };

    template<class type>
    class stack
    {
        private:
            snode<type> *top  ;      
            long long int count;
            
            /*
            Function: creates qnode of type type
            Pre: param of type type to create qnode 
            Post: qnode created
            */
            snode<type>* create_snode(type param)
            {
               snode<type> *temp = new snode<type>(param);
               return temp;       
            }

        public:
               
            stack()
            {
                top = NULL;
                count = 0;
            }    
            
            /*
             * Function: Pushes element on stack
             * Pre: param element of type type
             * Post: element added 
             */
            type push(type param)
            {
                snode<type> *temp = create_snode(param);
                if(count==0)
                {
                   top = temp;
                }
                else
                {
                    top->next = temp;
                    temp->prev = top;
                    top = temp;
                    
                }
                count++;
                return top->data;
            }

            /*
             * Function: Pop element from stack
             * Pre: none
             * Post: element removed 
             */
            type pop()
            {
                type param;
                
                if(count>0)
                {   
                    snode<type> *temp=top->prev;
                    if(count==1)
                    {
                        param = top->data;
                        delete top;
                        top = NULL;
                    }
                    else
                    {
                        param = top->data;
                        temp->next= NULL;
                        delete top;
                        top = temp;
                    }
                    count--;
                }
                return param;
            }
            
            
            /*
             * Function: gives top element
             * Pre: none
             * Post: top element returned
             */
            type top_element()
            {
                type param;
                if(count>0)
                    param = top->data;
                
                return param;
            }            

            
            /*
             * Function: no of elements in stack
             * Pre: none
             * Post: size returned 
             */
            long long int size()
            {
                return count;
            }
                        
            /*
             * Function: checks if empty
             * Pre: none
             * Post: true if isempty else false
             */
            bool isempty()
            {
                if(count==0)
                    return true;
                else
                    return false;
            }
            
            /*
             * Function: Removes all elements from stack
             * Pre: none
             * Post: stack empty
             */
            void clear()
            {
                while(count!=0)
                {
                    pop();
                }            
            }
    };
}
#endif /* STACK_H */

