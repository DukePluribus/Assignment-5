#ifndef _HashTable
#define _HashTable
#include "UPC.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class HashTable{

public:
    HashTable();
    void insert(UPC data);
    bool search(UPC data);
    void loadData(string inputFile);

private:
    int hash(UPC data);
    LinkedList<UPC>table[1000];
};

void HashTable::loadData(string inputFile){
    cout<<"Loading HashTable\n";
    ifstream inFile;
    inFile.open (inputFile);
    string token;
    getline(inFile,token);
//Parses the file
    int count = 0;
    while(getline(inFile, token)) {
        stringstream ss(token);
        vector<string> result;
        while(ss.good()){
            string substr;
            getline(ss, substr, ',');       //Splits the line into the UPC and the item description
            result.push_back(substr);
        }
    //Creates a UPC object to be inserted
    //cout<<(int)result[0][0]<<(int)result[0][1]<<(int)result[0][2]<<endl;
    if(result[0].length()>12)continue;
    //cout<<":"<<result[0]<<":"<<result[0].length()<<endl;
    UPC input = UPC(stoll(result[0]), result[1]);
    //cout<<input<<endl;
    //Inserts UPC object into BST
    //cout<<"attempting to input UPC into Hash table \n";
        table[hash(input)].inserLast(input);
    //cout<<"UPC input into HashTable\n";
        count++;
    }
    cout<<count<<endl;
}

HashTable::HashTable(){
}

void HashTable::insert(UPC data){
    table[hash(data)].inserLast(data);
}

bool HashTable::search(UPC data){
    if(table[hash(data)].search(data)==data){
        return true;
    } else {
        return false;
    }
}

int HashTable::hash(UPC data){
    int hashNum = data.getNum()%1000;
    if (hashNum < 0){
        hashNum = -hashNum;
    }
    return hashNum;
}

#endif