
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xuxin17
 *
 * Created on November 23, 2018, 2:31 PM
 */

#include <cstdlib>
#include <iostream>
#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"

#include <string>
#include <sstream>


using namespace std;

/*
 * 
 */

int main() {

    string line;
    string command;
    string name, status;
    unsigned int IPaddress;
    bool active, insert, remove;
    TreeDB database;
    DBentry* newEntry;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input

    while (!cin.eof()) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so the flags are cleared
        stringstream lineStream (line);

        // Read from string stream into the command
        lineStream >> command;

        
        
        if (command.compare("insert") == 0) {
          
            lineStream >> name;
            lineStream >> IPaddress;
            lineStream >> status;
            
            if(status.compare("active") == 0)
                active=true;
            else active=false;
            
            newEntry= new DBentry(name, IPaddress, active);
            
            insert=database.insert(newEntry);
            if(insert) {
                 cout<<"Success"<<endl;
            }else            {
                 cout<<"Error: entry already exists"<<endl;
            }
            
            
        }else if(command.compare("find") == 0){
            
            lineStream >> name;
            
            newEntry=database.find(name);
            
            if(newEntry!=NULL){
                if(newEntry->getActive())
                 cout<<newEntry->getName()<<" : "<<newEntry->getIPaddress()<<" : active"<<endl;
                else 
                 cout<<newEntry->getName()<<" : "<<newEntry->getIPaddress()<<" : inactive"<<endl;
            }else {
                 cout<<"Error: entry does not exist"<<endl;
            }
                
            
        }else if(command.compare("remove") == 0){
            
            lineStream >> name;
            
            remove=database.remove(name);
            
            if(remove){
                cout<<"Success"<<endl;
            }else{
              cout<<"Error: entry does not exist"<<endl;
            }
            
            
        }else if(command.compare("printall") == 0){
            
            database.printall();
            
        }else if(command.compare("printprobes") == 0){
            
            lineStream >> name;
            
        }else if(command.compare("removeall") == 0){
            
            database.clear();
             cout<<"Success"<<endl;
            
        }else if(command.compare("countactive") == 0){
            
            database.countActive();
            
        }else if(command.compare("updatestatus") == 0){
            
            lineStream >> name;            
            lineStream >> status;
            
            if(status.compare("active") == 0)
                active=true;
            else active=false;
            
            newEntry=database.find(name);
            
            if(newEntry!=NULL){
                newEntry->setActive(active);
                cout<<"Success"<<endl;
            }else{
                cout<<"Error: entry does not exist"<<endl;
            }
            
        }else {
            
            cout<<"Error: command not found"<<endl;
            
        }
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
        
    }  // End input loop until EOF.
    
    
                
               
                

    return 0;
}



//         int main(){
//             //test DBentry class
//                string tests= "hello";
//                unsigned int testing=3;
//                bool tester=true;
//
//                DBentry* test= new DBentry(tests, testing, tester);
//
//
//               bool state= test->getActive();
//               unsigned int longer = test->getIPaddress();
//               string name=test->getName();
//               unsigned int small=4;
//
//               test->setActive(false);
//               test->setIPaddress(small);
//               test->setName("hi");
//
//                delete test;
//                test=NULL;
//         }
