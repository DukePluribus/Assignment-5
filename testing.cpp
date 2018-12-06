#include "BarcodeArrayScanner.h"
#include "HashTable.h"
#include "BarcodeBSTScanner.h"
#include "time.h"

int main(){
    clock_t t;
    size_t size = 100000;
    //cout<<"Enter name of file to be assessed: ";
    string inputFile = "upc_corpus.txt";
    //cin>>inputFile; cout<<endl;


//*******************************************//
//          Creates the array                //
//*******************************************//
    UPC* codesArray = new UPC[10000000];
    loadData(codesArray, inputFile);
    cout<<endl;
    cout<<"Loaded array"<<endl;

//*******************************************//
//          Creates the BST                  //
//*******************************************//
    BinarySearchTree<UPC> codesBST;
    loadData(codesBST, inputFile);
    cout<<endl;
    cout<<"Loaded BST"<<endl;

//*******************************************//
//          Creates the HashTable            //
//*******************************************//

    HashTable codesHash;
    codesHash.loadData(inputFile);
    cout<<endl<<"Loaded HashTable"<<endl;


long long input=10000;

while (input < 100000){
    clock_t BSTtime;
    clock_t ArrayTime;
    clock_t HashTime;
    cout<<"Searching for the "<<input<<"th item that is in the array.\n";
    //cin>>input;
    UPC item = codesArray[input];


    t = clock();
    codesBST.search(item);
    BSTtime = clock() - t;
    cout<<"BST time is "<<BSTtime<<endl;

    t = clock();
    for(int i=0; !codesArray[i].isInitialized(); i++){
        if (codesArray[i] == item){
            break;
        }
    }
    ArrayTime = clock() - t;
    cout<<"Array time is "<<ArrayTime<<endl;

    t = clock();
    codesHash.search(item);
    HashTime = clock() - t;
    cout<<"HashTable time is "<<HashTime<<endl;

    input = input + 10000;
}
    delete[] codesArray;
}