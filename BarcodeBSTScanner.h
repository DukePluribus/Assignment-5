#ifndef _BINARYSEARCHTREE
#define _BINARYSEARCHTREE
#include "BinarySearchTree.h"
#include "UPC.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

void loadData(BinarySearchTree<UPC> &tree, string inputFile){
    ifstream inFile;
    inFile.open (inputFile);
    string token;
    getline(inFile, token);
//Parses the file
    while(getline(inFile, token)) {
        stringstream ss(token);
        vector<string> result;
        while(ss.good()){
            string substr;
            getline(ss, substr, ',');       //Splits the line into the UPC and the item description
            result.push_back(substr);
        }
//Creates a UPC object to be inserted
        if(result[0].length()>12)continue;
        UPC input(stoll(result[0]), result[1]);
//Inserts UPC object into BST
        tree.insert(input);
        //cout<<input<<endl;
    }
}

#endif