#ifndef _BARCODEARRAYSCANNER
#define _BARCODEARRAYSCANNER
#include "UPC.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


void loadData(UPC codes[], string inputFile){
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
        UPC *input = new UPC(stoll(result[0]), result[1]);
//Inserts UPC object into BST
        codes[count] = *input;
        count++;
    }
    cout<<count<<endl;
}

#endif