#include "BarcodeBSTScanner.h"


int main(){
    BinarySearchTree<UPC> codes;
    cout<<"Enter name of file to be assessed: ";
    string inputFile;
    cin>>inputFile; cout<<endl;
    loadData(codes, inputFile);
    codes.printInOrder();
    cout<<endl;
}