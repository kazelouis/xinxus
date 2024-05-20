//TreeDB.cpp
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


using namespace std;

   // the default constructor, creates an empty database.
   TreeDB::TreeDB(){
       
       root=NULL;
       int probesCount=0;
       
   }

   // the destructor, deletes all the entries in the database.
   TreeDB::~TreeDB(){
       
     
           destroy(root);
      
   }

   
   //helper function for destructor
   void TreeDB::destroy(TreeNode* root){
       
       if(root==NULL) return;
       
       //else at least one node
       //delete left then right then root
       destroy(root->getLeft());
       destroy(root->getRight());
       
       delete root->getEntry();
      // delete root;
       
       
   }
   
   
   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB::insert(DBentry* newEntry){
       
       
       //if empty binary search tree
       if(root==NULL) {
           root = new TreeNode(newEntry);
           root->setLeft(NULL);
           root->setRight(NULL);
           return true;
       }
       
           
            
      if((root->getEntry()->getName()).compare(newEntry->getName())==0)
            return false;    
      else { 
            insertRecursive(newEntry, root);
            return true;
      }
      
     
}

void TreeDB:: insertRecursive(DBentry* newEntry, TreeNode* root){

    TreeNode* toinsert=new TreeNode(newEntry);
    
    // if found same name already
    if((root->getEntry()->getName()).compare(newEntry->getName()) ==0){
        return;
    }
    
    
    // Insert helper function.
    if((root->getEntry()->getName()).compare(newEntry->getName()) >0){
        if(root->getLeft()==NULL){
            root->setLeft(toinsert);
            //delete toinsert;
            return;
        }
        else insertRecursive(newEntry, root->getLeft());
    }
    if((root->getEntry()->getName()).compare(newEntry->getName()) <0){
        if(root->getRight()==NULL){
            root->setRight(toinsert);
            //delete toinsert;
            return;
        }
        else insertRecursive(newEntry, root->getRight());
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
       
       delete current;
 
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
       
       else {
           deleteTreeDB(root, name);     
           return true;
       }
       
       
   }
	
   
   
    void TreeDB:: deleteTreeDB(TreeNode * root, string name){

    // base case 
    if (root == NULL) return; 
  
    
    //Locate the element
    bool found = false;
    TreeNode * temp;
    TreeNode * curr;
    TreeNode * parent;
    curr = root;
    
    while(curr)
    {
         if((curr->getEntry()->getName()).compare(name)==0)
         {
	    found = true;
            break;
         }
         else
         {
             parent = curr;
             if((curr->getEntry()->getName()).compare(name)<0)
				 curr = curr->getLeft();
             else 
				 curr = curr->getRight();
         }
    }
    if(!found){
        return;
    }

    
    // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children


	
    
	/* this code is for deleting node having both children */
    if( curr->getLeft() != NULL && curr->getRight() != NULL)
    {

	/* this code is for deleting root node with both children*/
        if( curr == root)
        {
            temp = curr->getLeft();
            parent = curr->getRight();
            root = temp;

                    while(temp->getRight() != NULL)
                            temp = temp->getRight();
                    temp->setRight(parent);
                    delete curr;
                    root=NULL;
                    return;
        }


       if(parent->getLeft() == curr)
       {
			temp = curr->getLeft();
			parent->setLeft(curr->getLeft());
			
			while(temp->getRight()!= NULL)
				temp = temp->getRight();
			
			temp->setRight(curr->getRight());
			curr->setLeft(NULL);
			curr->setRight(NULL);
       }
       else
       {
			temp = curr->getRight();
			parent->setRight(curr->getRight());
			
			while(temp->getLeft() != NULL)
				temp = temp->getLeft();
			
			temp->setLeft(curr->getLeft());
			curr->setLeft(NULL);
			curr->setRight(NULL);
       }

	   delete curr;
	   return;
  }


	/* this code is for deleting a node with one child*/
    if(curr->getLeft() == NULL && curr->getRight() != NULL)
    {
		if( curr == root)/* this code is for deleting root node with right child*/
		{
			temp = curr->getLeft();
			parent = curr->getRight();
			root = temp;
			
			while(temp->getRight() != NULL)
				temp = temp->getRight();
			
			temp->setRight(parent);
			root=NULL;
			delete curr;
			return;
		}

		if(parent->getLeft() == curr)
			parent->setLeft(curr->getRight());
        else
            parent->setRight(curr->getRight());
            curr->setRight(NULL);
            delete curr;
			return;
    }

	if(curr->getLeft() != NULL && curr->getRight() == NULL)
        {
                    if( curr == root)/* this code is for deleting root node with left child*/
                    {
                            temp = curr->getLeft();
                            parent = curr->getRight();
                            root = temp;

                            while(temp->getRight() != NULL)
                                    temp = temp->getRight();

                            temp->setRight(parent);
                            delete curr;
                            root=NULL;
                            return;
                    }

            if(parent->getLeft() == curr)
                            parent->setLeft(curr->getLeft());
            else
                parent->setRight(curr->getLeft()); 
                curr->setLeft(NULL);
                return;
        }

    
	//We're looking at a leaf node
	if( curr->getLeft() == NULL && curr->getRight() == NULL)
        {
                    if(curr == root)/* this code is for deleting root node with no children*/
                    {
                            delete curr;
                            root = NULL;
                            return;
                    }

            if(parent->getLeft() == curr)
                            parent->setLeft(NULL);
            else 
                            parent->setRight(NULL);
                    delete curr;
                    return;
        }

 
       
   }

   

// deletes all the entries in the database.
   void TreeDB::clear(){
       
               destroy(root);
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

  
 
 
 
 void TreeDB::printall(){
     
     if(root==NULL) 
         return;
     else 
         print(root);
     
     return;
 }
 
 //helper of printall
 void TreeDB::print(TreeNode* root){
     
     //inorder traversal
     
    // Check terminating condition
    if (root != NULL)
    {
       // Print left subtree
       print(root->getLeft());

        //print   
         if(root->getEntry()->getActive())
            cout<<root->getEntry()->getName()<<" : "<<root->getEntry()->getIPaddress()<<" : active"<<endl;
         else 
            cout<<root->getEntry()->getName()<<" : "<<root->getEntry()->getIPaddress()<<" : inactive"<<endl;

       // Print right subtree
       print(root->getRight());
    }
                
  
 }

 