
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//TreeNode.cpp

#include <iostream>
#include "TreeNode.h"
#include "DBentry.h"
#include <string>
#include <cstdlib>

using namespace std;

/*private:
    DBentry* entryPtr;
    TreeNode* left;
    TreeNode* right;
*/


   TreeNode::TreeNode(DBentry* _entryPtr){
   
              
      entryPtr=_entryPtr;
       left=NULL;
       right=NULL;
       
    }

    // the destructor
    TreeNode::~TreeNode(){
        
        delete entryPtr;
//        entryPtr=NULL;
       
    }

 
   

    // sets the left child of the TreeNode.
    void TreeNode::setLeft(TreeNode* newLeft){
    
            //set this->left to newLeft
             this->left=newLeft;
        
        
    }    
        
        

    // sets the right child of the TreeNode
    void TreeNode::setRight(TreeNode* newRight){
        
        
            //set this->left to newLeft
             this->right=newRight;
    
        
    }

    // gets the left child of the TreeNode.
    TreeNode* TreeNode::getLeft() const{
        
        return this->left;
    }

    // gets the right child of the TreeNode
    TreeNode* TreeNode::getRight() const{
        return this->right;
    }

    // returns a pointer to the DBentry the TreeNode contains. 
    DBentry* TreeNode::getEntry() const{
        return this->entryPtr;
    }

    
//    int main(){
    
//        string asd= "asd";
//        string zxc= "zxc";
//        
//        DBentry test, t1, t2, t3;
//        DBentry right(asd, 3, true);
//        DBentry left(zxc, 2, false);
//        
//        DBentry* testit=&test;
//        DBentry* t11=&t1;
//        DBentry* t12=&t2;
//        DBentry* t13=&t3;
//        
//        DBentry* r=&right;
//        DBentry* l=&left;
//        
//        TreeNode first(testit);
//        TreeNode a(t11);
//        TreeNode s(t12);
//        TreeNode d(t13);
//        TreeNode ri(r);
//        TreeNode le(l);
//    
//        TreeNode* m=first.getLeft();
//        TreeNode* n=first.getRight();
//        
//        TreeNode* rig=&ri;
//        TreeNode* lef=&le;
//        
//        a.setLeft(lef);
//        s.setRight(rig);
//        
//        
//        DBentry* entr=first.getEntry();
//    
//    
    
                   //test tree node
//    
//
//                DBentry* test1= new DBentry("hi",3, true);
//                DBentry* test2= new DBentry("hi",3, true);
//                DBentry* test3= new DBentry("hi",3, true);
//                
//                TreeNode* tree1= new TreeNode(test1);
//                TreeNode* tree2= new TreeNode(test1);
//                TreeNode* tree3= new TreeNode(test1);
//                
//                tree1->setLeft(tree2);
//                tree1->setRight(tree3);
//                
//                TreeNode* one=tree1->getLeft();
//                TreeNode* two=tree1->getRight();
//                
//                delete one;
//                delete two; 
//                delete tree1;
//                delete tree2;
//                delete tree3;
//                delete test1;
//                delete test2; 
//                delete test3;
//    
    
    
//    }