

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//TreeDB.cpp
#include <cstdlib>
#include <string>
#include <iostream>
#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"


//private:
//   TreeNode* root;
//   int probesCount;


   // the default constructor, creates an empty database.
   TreeDB::TreeDB(){
       
       root=NULL;
       int probesCount=0;
       
   }

   // the destructor, deletes all the entries in the database.
   TreeDB::~TreeDB(){
       
       if(root==NULL){
           return;
       }
//       root->getLeft()->clear(root->getLeft());
//       root->getRight()->clear(root->getRight());
//       root->clear(root);
   }

   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB::insert(DBentry* newEntry){
       
       if(root==NULL) {
           root = new TreeNode(newEntry);
           return true;
       }
       
        if((newEntry->getName()).compare(root->getEntry()->getName())<0){
            //if key<root.key, go left
            
            return insert(root->getLeft()->getEntry());
            
        }else if((newEntry->getName()).compare(root->getEntry()->getName())>0){
            //if key>root.key, go right
            
            return insert(root->getRight()->getEntry());
            
        }else if(root->getEntry()->getName().compare(newEntry->getName())==0){
            return false;
        }
      
     
}

   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* TreeDB::find(string name){
       
       TreeNode* current=root;
       probesCount=0;
       
       if(root==NULL) {
           return NULL;
       }
       
       if((current->getEntry()->getName()).compare(name)<0){
           //search right
           current=current->getRight();
           probesCount++;
           return find(name);
          
       }else if((current->getEntry()->getName()).compare(name)>0){
           //search left
           current=current->getLeft();
           probesCount++;
           return find(name);
           
       }else if((current->getEntry()->getName()).compare(name)==0){
           probesCount++;          
           return current->getEntry();           
       }
       
 
   }

   // deletes the entry with the specified name (key)  from the database.
   // If the entry was indeed in the database, it returns true.
   // Returns false otherwise.
   // See section 6 of the lab handout for the *required* removal method.
   // If you do not use that removal method (replace deleted node by
   // maximum node in the left subtree when the deleted node has two children)
   // you will not match exercise's output.
   bool TreeDB::remove(string name){
       
       //base case
       
       if(root==NULL){
           return false;
       }
       
       else if(deleteTreeDB(root, name)!=NULL){          
           return true;
       }
       else {
           return false;
       }
       
   }
	
   
   TreeNode* TreeDB:: deleteTreeDB(TreeNode * root, string name){

    // base case 
    if (root == NULL) return NULL; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if ((root->getEntry()->getName()).compare(name)<0){
        root->setLeft(deleteTreeDB(root->getLeft(), name));
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    } else if ((root->getEntry()->getName()).compare(name)>0) {
        root->setRight(deleteTreeDB(root->getRight(), name));
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    } else
    { 
        // node with only one child or no child 
        if (root->getLeft() == NULL) 
        { 
            TreeNode *temp = root->getRight();
            delete root;
            return temp; 
        } 
        else if (root->getRight() == NULL) 
        { 
            TreeNode *temp = root->getLeft();
            delete root; 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (largest in left subtree) 
        TreeNode* temp = LeftMost(root->getLeft()); 
  
        // Copy the inorder successor's content to this node 
        root->getEntry()->setName(temp->getEntry()->getName());
         root->getEntry()->setIPaddress(temp->getEntry()->getIPaddress());
          root->getEntry()->setActive(temp->getEntry()->getActive());
  
        // Delete the inorder successor 
        root->setRight(deleteTreeDB(root->getRight(), temp->getEntry()->getName())); 
    } 
    return root; 
 
       
   }
   

// deletes all the entries in the database.
   void TreeDB::clear(){
   
       clearAll(root);
   }
   
   
   // deletes all the entries in the database.
   void TreeDB::clearAll(TreeNode * root){
       if(root==NULL)
           return;
             
       if(root != NULL) {
	    clearAll(root->getLeft());
	    clearAll(root->getRight());
	    delete root->getEntry();
	}
       
   
       
   }
    
   // prints the number of probes stored in probesCount
   void TreeDB::printProbes() const{
       
       cout<<this->probesCount<<endl;
       
   }
   
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   void TreeDB::countActive () const{
       
 
    TreeNode *current, *previous; 
    int count=0;
    
    if (root == NULL) 
        return; 
  
    current = root; 
    while (current != NULL) { 
  
        if (current->getLeft() == NULL) { 
            
         if(current->getEntry()->getActive())
             count++;
         
            current = current->getRight();
        } 
        else { 
  
            //find predecessor of current 
            previous = current->getLeft();
            while (previous->getRight() != NULL && previous->getRight() != current) 
                previous = previous->getRight(); 
  
            //Make current the right child of predecessor 
            if (previous->getRight() == NULL) { 
                previous->setRight(current);
                current = current->getLeft();
            } 
  
            //fix the right child of predecessor
            else { 
                previous->setRight(NULL);
                
                if(current->getEntry()->getActive())
                    count++;
                
                current = current->getRight();
            } // End of previous right == NULL 
        } //end of current left == NULL
    } //end o f while loop

    cout<<count<<endl;
       
   }

  
 
 
 TreeNode* TreeDB::LeftMost(TreeNode * root)
{
	if(root == NULL) return NULL;
	while(root->getLeft()!= NULL){
            root=root->getLeft();
        }
	return root;
}
 

 
 
 void TreeDB::printall(){
     
     //inorder traversal
     
     
    TreeNode *current, *previous; 
    
    if (root == NULL) 
        return; 
  
    current = root; 
    while (current != NULL) { 
  
        if (current->getLeft() == NULL) { 
         //print   
         if(current->getEntry()->getActive())
            cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : active"<<endl;
         else 
            cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : inactive"<<endl;

         //   cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<current->getEntry()->getActive()<<endl;
            
            current = current->getRight();
        } 
        else { 
  
            //find predecessor of current 
            previous = current->getLeft();
            while (previous->getRight() != NULL && previous->getRight() != current) 
                previous = previous->getRight(); 
  
            //Make current the right child of predecessor 
            if (previous->getRight() == NULL) { 
                previous->setRight(current);
                current = current->getLeft();
            } 
  
            //fix the right child of predecessor
            else { 
                previous->setRight(NULL);
                
           //print   
         if(current->getEntry()->getActive())
            cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : active"<<endl;
         else 
            cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : inactive"<<endl;

          //  cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<current->getEntry()->getActive()<<endl;

                
                current = current->getRight();
            } // End of previous right == NULL 
        } //end of current left == NULL
    } //end o f while loop


     
 }