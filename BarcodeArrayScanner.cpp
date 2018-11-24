#include "BarcodeArrayScanner.h"
#include <iostream>
#include "UPC.h"

using namespace std;

int BarcodeArrayScannerMain(){
    UPC* codes = new UPC[10000000];
    //cout<<"Enter name of file to be assessed: ";
    string inputFile = "test.txt";
    //cin>>inputFile; cout<<endl;
    loadData(codes, inputFile);
    cout<<endl;
    delete[] codes;
}

UPC arraySearch(){

}