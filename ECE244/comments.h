

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
   	probesCount=0;
   	if(root==NULL) return;
  	 
   	//else at least one node
   	//delete left then right then root
   	destroy(root->getLeft());
   	destroy(root->getRight());
  	 
   	delete root->getEntry();
  	// delete root;
  	 
  	 
   }
   
//   // inserts the entry pointed to by newEntry into the database.
//   // If an entry with the same key as newEntry's exists
//   // in the database, it returns false. Otherwise, it returns true.
//   //pass 5/6 test cases
//   
//   bool TreeDB::insert(DBentry* newEntry){
//  	 
//  	 
//   	//if empty binary search tree
//   	if(root==NULL) {
//       	root = new TreeNode(newEntry);
//       	root->setLeft(NULL);
//       	root->setRight(NULL);
//       	return true;
//   	}
//  	 
//      	 
//       	 
//  	if((root->getEntry()->getName()).compare(newEntry->getName())==0)
//        	return false;    
//  	else {
//        	insertRecursive(newEntry, root);
//        	return true;
//  	}
// 	 
//	 
//}
//
//void TreeDB:: insertRecursive(DBentry* newEntry, TreeNode* root){
//
//	TreeNode* toinsert=new TreeNode(newEntry);
//    
//	// if found same name already
//	if((root->getEntry()->getName()).compare(newEntry->getName()) ==0){
//    	return;
//	}
//    
//    
//	// Insert helper function.
//	if((root->getEntry()->getName()).compare(newEntry->getName()) >0){
//    	if(root->getLeft()==NULL){
//        	root->setLeft(toinsert);
//        	//delete toinsert;
//        	return;
//    	}
//    	else insertRecursive(newEntry, root->getLeft());
//	}
//	if((root->getEntry()->getName()).compare(newEntry->getName()) <0){
//    	if(root->getRight()==NULL){
//        	root->setRight(toinsert);
//        	//delete toinsert;
//        	return;
//    	}
//    	else insertRecursive(newEntry, root->getRight());
//	}
//    
//    
//    
//
//}
 
   
   
//	memory leaks, do not work
//	bool TreeDB::insert(DBentry* newEntry){
//  	 
//   	if(root==NULL) {
//       	root = new TreeNode(newEntry);
//       	return true;
//   	}
//  	 
//    	if((newEntry->getName()).compare(root->getEntry()->getName())<0){
//        	//if key<root.key, go left
//       	 
//        	return insert(root->getLeft()->getEntry());
//       	 
//    	}else if((newEntry->getName()).compare(root->getEntry()->getName())>0){
//        	//if key>root.key, go right
//       	 
//        	return insert(root->getRight()->getEntry());
//       	 
//    	}else if(root->getEntry()->getName().compare(newEntry->getName())==0){
//        	return false;
//    	}
// 	 
//	 
//}
//  
//   
   
   
   // inserts the entry pointed to by newEntry into the database.
   // If an entry with the same key as newEntry's exists
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB::insert(DBentry* newEntry){
  	 
   	if(newEntry==NULL) return false;
  	 
   	//passing in TreeNode create memory leaks
  	// TreeNode* toinsert=new TreeNode(newEntry);
  	 
   	//if empty binary search tree
   	if(root==NULL) {
       	root = new TreeNode(newEntry);
       	root->setLeft(NULL);
       	root->setRight(NULL);
       	return true;
   	}
   	else {      	 
        	insertRecursive(newEntry, root);
        	return true;
   	}
 	 
	 
}
   
   //iterative insertion
   void TreeDB:: insertRecursive(DBentry* newEntry, TreeNode* root){
  	 
   	TreeNode* temp=new TreeNode(newEntry);
  	 
   	temp->setLeft(NULL);
   	temp->setRight(NULL);
  	 
  	 
   	if(root==NULL){
       	//insert at head if empty
       	root=temp;
   	}else{
      	 
      	 
       	bool insert=false;
       	TreeNode* location=root;
      	 
       	while(!insert){
          	 
           	//if key found
           	if((location->getEntry()->getName()).compare(newEntry->getName()) ==0){
               	//already inserted
               	delete temp;
               	insert=true;             	 
           	}else if((location->getEntry()->getName()).compare(newEntry->getName()) >0){
               	//if root is bigger than newEntry
               	if(location->getLeft()==NULL){
                  	// insert left
                   	location->setLeft(temp);
                   	insert=true;
               	}else{
                   	location=location->getLeft();
               	}
              	 
              	 
           	}else{
               	//if root is smaller than newEntry
               	if(location->getRight()==NULL){
                   	//insert right
                   	location->setRight(temp);
                   	insert=true;
               	}else{
                   	//keep on moving right
                   	location=location->getRight();
               	}
    	 
            	}
 
       	}//end of while loop
   
   	}
    
   }
   
   
   
   
// void TreeDB:: insertRecursive(DBentry* newEntry, TreeNode* root){
//
//	//cannot insert, pointer treenode lost after recursion
// 	TreeNode * toinsert=new TreeNode(newEntry);
//
//	 
//	 
//	// Insert helper function.
//	if((root->getEntry()->getName()).compare(newEntry->getName()) >0){
//    	if(root->getLeft()==NULL){
//       	 
//        	root->setLeft(toinsert);
//        	toinsert==NULL;
//        	return;
//    	}
//    	else insertRecursive(newEntry, root->getLeft());
//	}
//	if((root->getEntry()->getName()).compare(newEntry->getName()) <0){
//    	if(root->getRight()==NULL){
//        	root->setRight(toinsert);
//        	toinsert==NULL;
//        	return;
//    	}
//    	else insertRecursive(newEntry, root->getRight());
//	}
//    
//    
//    
//
//}  
   
// //version using TreeNode instead of DBentry
//void TreeDB:: insertRecursive(TreeNode* toinsert, TreeNode* root){
//
//	//memory leaks and errors
//    
//    
//	// Insert helper function.
//	if((root->getEntry()->getName()).compare(toinsert->getEntry()->getName()) >0){
//    	if(root->getLeft()==NULL){
//       	 
//        	root->setLeft(toinsert);
//        	//delete toinsert;
//        	return;
//    	}
//    	else insertRecursive(toinsert, root->getLeft());
//	}
//	if((root->getEntry()->getName()).compare(toinsert->getEntry()->getName()) <0){
//    	if(root->getRight()==NULL){
//        	root->setRight(toinsert);
//        	//delete toinsert;
//        	return;
//    	}
//    	else insertRecursive(toinsert, root->getRight());
//	}
//    
//    
//    
//
//}

   
   
   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* TreeDB::find(string name){
    
    
   	probesCount=0;
  	 
  	 
   	//if empty tree
   	if(root==NULL) {
       	return NULL;
   	}
	 
   	//iterative search of tree
   	while(root!=NULL){


        	if((root->getEntry()->getName()).compare(name)<0){
            	//search right
            	root=root->getRight();
            	probesCount++;
           	 
        	}else if((root->getEntry()->getName()).compare(name)>0){
            	//search left
            	root=root->getLeft();
            	probesCount++;

        	}else if((root->getEntry()->getName()).compare(name)==0){
            	probesCount++;    
            	//if found in tree, return DBentry*
            	return root->getEntry();      	 
        	}
  	 
   	}
  	 
   	return NULL;
  	 
  	 
  	// return search(root, name);
	 
 
   }

//   
//DBentry* TreeDB:: search(TreeNode* root, string name)
//{
//	// Base Cases: root is null or key is present at root
//	if (root == NULL || (root->getEntry()->getName()).compare(name)==0)
//   	return root->getEntry();
//	 
//	// Key is greater than root's key
//	if ((root->getEntry()->getName()).compare(name)<0)
//   	return search(root->getRight(), name);
//  
//	// Key is smaller than root's key
//	return search(root->getLeft(), name);
//}
   
   
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

// //Iterative implementation of printall   
//	void TreeDB::printall(){
//	 
// 	//inorder traversal
//	 
//	 
//	TreeNode *current, *previous;
//    
//	if (root == NULL)
//    	return;
//  
//	current = root;
//	while (current != NULL) {
//  
//    	if (current->getLeft() == NULL) {
//     	//print   
//     	if(current->getEntry()->getActive())
//        	cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : active"<<endl;
//     	else
//        	cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : inactive"<<endl;
//
//     	//   cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<current->getEntry()->getActive()<<endl;
//       	 
//        	current = current->getRight();
//    	}
//    	else {
//  
//        	//find predecessor of current
//        	previous = current->getLeft();
//        	while (previous->getRight() != NULL && previous->getRight() != current)
//            	previous = previous->getRight();
//  
//        	//Make current the right child of predecessor
//        	if (previous->getRight() == NULL) {
//            	previous->setRight(current);
//            	current = current->getLeft();
//        	}
//  
//        	//fix the right child of predecessor
//        	else {
//            	previous->setRight(NULL);
//           	 
//       	//print   
//     	if(current->getEntry()->getActive())
//        	cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : active"<<endl;
//     	else
//        	cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<" : inactive"<<endl;
//
//      	//  cout<<current->getEntry()->getName()<<" : "<<current->getEntry()->getIPaddress()<<current->getEntry()->getActive()<<endl;
//
//           	 
//            	current = current->getRight();
//        	} // End of previous right == NULL
//    	} //end of current left == NULL
//	} //end o f while loop
//
//
//	 
// }
