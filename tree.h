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


namespace dsa
{
    template<class type>
    class tnode
    {
        public:
            tnode<type>   *left,*right;
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
    
    template<class type>
    class bstree
    {
        private:
                        
            /*
            Function: creates tnode<type> of type type
            Pre: param of type type to create tnode<type> 
            Post: tnode<type> created
            */
            tnode<type>* create_tnode(type param)
            {
               tnode<type> *temp = new tnode<type>(param);
               return temp;       
            } 
            
            tnode<type> *root;
            long long int count;                    
            
            tnode<type>* _find_min(tnode<type>* temp)
            {
                if(temp==NULL)          return NULL;                
                if(temp->left==NULL)    return temp;
                return _find_min(temp->left);
            }
            
            tnode<type>* _find_max(tnode<type>* temp)
            {
                if(temp==NULL)          return NULL;
                if(temp->right==NULL)   return temp;
                return _find_max(temp->right);
            }
           
            bool _insert(tnode<type> *troot,tnode<type> *temp)
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
            
            tnode<type>* _remove(tnode<type> *troot,type param)
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
                            tnode<type> *temp = troot;
                            troot=troot->right;
                            delete temp;  count--;                          
                        }
                        else
                        {   
                            if(troot->right==NULL)
                            {
                                tnode<type> *temp = troot;
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
            
            void _clear(tnode<type> *temp)
            {
                if(temp==NULL) return;                
                _clear(temp->left);
                _clear(temp->right);
                remove(temp->data);
            }
            void _inorder(tnode<type> *temp,void (fun)(type obj))
            {               
                if(temp==NULL) return;
                
                _inorder(temp->left,fun);
                fun(temp->data);
                _inorder(temp->right,fun);
            }
        
            void _preorder(tnode<type> *temp,void (fun)(type obj))
            {   
                if(temp==NULL) return;                
               
                fun(temp->data);
                _preorder(temp->left,fun);
                _preorder(temp->right,fun);
                
            }
            
            void _postorder(tnode<type> *temp,void (fun)(type obj))
            {               
                if(temp==NULL) return;                
                
                _postorder(temp->left,fun);
                _postorder(temp->right,fun);
                fun(temp->data);
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
                tnode<type> *temp=create_tnode(param);
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
            
            void copy(type param)
            {
                insert(param);
            }
            
            void operator=(bstree<type> from)
            {
                clear();
                from.preorder(copy);
                
            }
    };


}

#endif /* TREE_H */

