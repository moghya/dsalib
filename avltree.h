/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   avltree.h
 * Author: moghya_s
 *
 * Created on June 17, 2016, 9:02 PM
 */

#ifndef AVLTREE_H
#define AVLTREE_H

namespace dsa
{
    template<class type>
    class avltree
    {
        private:
            static const long long int IF=1;
            struct avltnode
            {

                avltnode   *left,*right;
                type        data;
                long long int ht;
                

                avltnode()
                {
                    ht=-1;
                    left = NULL;
                    right= NULL;
                }

                avltnode(type param)
                {
                    ht=-1;
                    left = NULL;
                    right= NULL;
                    data = param;
                }
            };
            
            avltnode *root;
            long long int count;
            
            avltnode* create_avltnode(type param)
            {
               avltnode *temp = new avltnode(param);
               return temp;       
            }    
            
            long long int _height(avltnode *troot)
            {
                if(troot==NULL) 
                    return -1; 
                else 
                    return troot->ht;
            }
            
            void _srotateR(avltnode *troot)
            {
                avltnode *temp;                
               
                temp = troot->left;                
                troot->left = temp->right;                
                temp->right = troot;                
                troot->ht = maxof( _height( troot->left ), _height( troot->right ) ) + 1;                
                temp->ht = maxof( _height( temp->left ), troot->ht ) + 1;                
                troot = temp;
            }
            
            void  _srotateL(avltnode *troot)
            {
                avltnode *temp;
                avltnode *temp2;
                
                temp = troot->right;                
                troot->right = temp->left;                
                
                temp2->data=troot->data;
                temp2->ht=troot->ht;
                temp2->left=troot->left;
                temp2->right=troot->right;
                
                temp->left = temp2;                
               
                troot->ht = maxof( _height( troot->left ),_height( troot->right ) ) + 1;                
                temp->ht = maxof(troot->ht,_height( temp->right )) + 1;                
                troot = temp;
            }
           
            void  _drotateRL(avltnode *troot)
            {           
                _srotateL(troot->left);
                _srotateR(troot);
                
            }
            
            void  _drotateLR(avltnode *troot)
            {
                _srotateR(troot->right);
                _srotateL(troot);               
            }
            
            void  _balance(avltnode *troot)
            {
                if(troot==NULL)
                return ;
                
                long long int tl = _height(troot->left),tr = _height(troot->right);
                
                if( tl - tr > IF)
                {                   
                    if( _height(troot->left->left) >= _height(troot->left->right))
                        _srotateR(troot);
                    else
                        _drotateRL(troot);
                }
                else
                {
                    if( tr - tl > IF)
                    {
                        if( _height(troot->right->right) >= _height(troot->right->left) )
                            _srotateL(troot);
                        else
                            _drotateLR(troot);
                    }
                }
                
                troot->ht = maxof(_height(troot->left),_height(troot->right)) + 1;           
                
            }
            
            avltnode* _insert(avltnode *troot,avltnode *temp)
            {

                if(troot==NULL)
                    troot=temp;
                else
                    if(temp->data < troot->data)
                            troot->left = _insert(troot->left,temp);
                    else
                            troot->right = _insert(troot->right,temp);  
               
               _balance(troot);
               return troot;
            }
            
            void _preorder(avltnode *temp,void (fun)(type obj))
            {   
                if(temp==NULL) return;                

                fun(temp->data);
                _preorder(temp->left,fun);
                _preorder(temp->right,fun);

            }

            void _bfs(void (fun) (type obj))
            {
                queue<avltnode*> q;
                avltnode *temp;
                if(root!=NULL)
                {
                    q.enqueue(root);
                    while(!q.isempty())
                    {
                        temp=q.front_element();
                        fun(temp->data);
                        if(temp->left!=NULL)    q.enqueue(temp->left);
                        if(temp->right!=NULL)     q.enqueue(temp->right); 
                        q.dequeue();
                    }
                }                
            }

        public:
           
            avltree()
            {
                root=NULL;
                count=0;
            }
                       
            bool insert(type param)
            {                
                avltnode *temp = create_avltnode(param); 
                root = _insert(root,temp);
                count++;                
                return true;
            }            
            
            void preorder(void (fun)(type obj))
            {
               _preorder(root,fun);
            }
            
            void bfs(void (fun) (type obj))
            {
                _bfs(fun);
            }
                                  
    
    };


}


#endif /* AVLTREE_H */

