/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree.h
 * Author: moghya_s
 *
 * Created on June 15, 2016, 8:17 AM
 */

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "queue.h"


namespace dsa
{
    

    template<class type>
    class bstree
    {
        private:            
            struct tnode
            {

                tnode   *left,*right;
                type    data;            

                tnode()
                {
                    left = NULL;
                    right= NULL;
                }

                tnode(type param)
                {
                    left = NULL;
                    right= NULL;
                    data = param;
                }
            };
                        
            /*
            Function: creates tnode of type type
            Pre: param of type type to create tnode 
            Post: tnode created
            */
            tnode* create_tnode(type param)
            {
               tnode *temp = new tnode(param);
               return temp;       
            } 
            
            tnode *root;
            long long int count;                    
            
            tnode* _find_min(tnode* temp)
            {
                if(temp==NULL)          return NULL;                
                if(temp->left==NULL)    return temp;
                return _find_min(temp->left);
            }
            
            tnode* _find_max(tnode* temp)
            {
                if(temp==NULL)          return NULL;
                if(temp->right==NULL)   return temp;
                return _find_max(temp->right);
            }
           
            bool _insert(tnode *troot,tnode *temp)
            {
                if(temp->data < troot->data)
                {
                    if(troot->left==NULL)
                    {
                        troot->left=temp;
                        count++;
                        return true;
                    }
                    else
                    return  _insert(troot->left,temp);
                }
                else
                {                      
                    if(troot->right==NULL)
                    {
                        troot->right=temp;
                        count++;
                        return true;
                    }
                    else
                    return  _insert(troot->right,temp);
                }
                
            }
            
            tnode* _remove(tnode *troot,type param)
            {    
                
                if( troot == NULL )             return troot;                
                else if( param < troot->data )  troot->left = _remove(troot->left,param);
                else if( troot->data < param )  troot->right =_remove(troot->right,param);
                else 
                {   
                    if(troot->left==NULL&&troot->right==NULL){
                        delete troot;
                        troot = NULL;
                        count--;
                    }
                    else
                    {
                        
                        if(troot->left==NULL)
                        {
                            tnode *temp = troot;
                            troot=troot->right;
                            delete temp;  count--;                          
                        }
                        else
                        {   
                            if(troot->right==NULL)
                            {
                                tnode *temp = troot;
                                troot=troot->left;
                                delete temp; count--;
                            }
                            else
                            {
                                troot->data = _find_min(troot->right)->data;
                                troot->right = _remove(troot->right,troot->data);
                            }
                        }
                    }    
                }
                return troot;
            }   
            
            void _clear(tnode *temp)
            {
                if(temp==NULL) return;                
                _clear(temp->left);
                _clear(temp->right);
                remove(temp->data);
            }
            
            void _inorder(tnode *temp,void (fun)(type obj))
            {               
                if(temp==NULL) return;
                
                _inorder(temp->left,fun);
                fun(temp->data);
                _inorder(temp->right,fun);
            }

            void _preorder(tnode *temp,void (fun)(type obj))
            {   
                if(temp==NULL) return;                
               
                fun(temp->data);
                _preorder(temp->left,fun);
                _preorder(temp->right,fun);
                
            }
            
            void _postorder(tnode *temp,void (fun)(type obj))
            {               
                if(temp==NULL) return;                
                
                _postorder(temp->left,fun);
                _postorder(temp->right,fun);
                fun(temp->data);
            }
            
            void _bfs(void (fun) (type obj))
            {
                queue<tnode*> q;
                if(root!=NULL)
                {
                    q.enqueue(root);
                    while(!q.isempty())
                    {
                        fun(q.front_element()->data);
                        q.enqueue(q.front_element()->left);
                        q.enqueue(q.front_element()->right);
                        q.dequeue();
                    }
                }                
            }
        public:
            
            bstree()
            {
                root = NULL;
                count=0;
            }
                       
            
            type find_min()
            {
                return _find_min(root)->data;
            }
            
            type find_max()
            {
                return _find_max(root)->data;
            }
            
            bool insert(type param)
            {                
                tnode *temp=create_tnode(param);
                if(root==NULL)
                {
                   root=temp;
                   count++;
                   return true; 
                }           
                return _insert(root,temp);
            }
            
            bool remove(type param)
            {         
                long long int temp=count;
                root=_remove(root,param);
                if(count<temp)
                     return true;
                else
                     return false;
            }
            
            type tree_root()
            {
                return root->data;
            }
            
            long long int size()
            {
                return count;
            }
            
            void clear()
            {
                _clear(root);
            }
            
            bool isempty()
            {
                if(count==0)
                    return true;
                else
                    return false;
            }                        

            void inorder(void (fun)(type obj))
            {
                _inorder(root,fun);
            }

            void preorder(void (fun)(type obj))
            {
               _preorder(root,fun);
            }
            
            void postorder(void (fun)(type obj))
            {
                _postorder(root,fun);
            }
            
            void bfs(void (fun) (type obj))
            {
                _bfs(fun);
            }
            

    };
    
    
    template<class type>
    class avltree
    {
    
    };


}

#endif /* TREE_H */

