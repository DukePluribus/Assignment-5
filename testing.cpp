#include "BarcodeArrayScanner.h"
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

long long input=100;

while (input != 0){
    clock_t BSTtime;
    clock_t ArrayTime;
    cout<<"What UPC to search for: ";
    cin>>input;
    UPC item(input, "");
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
}



    // t = clock();
    // UPC test(797776092321, "butts");
    // codesBST.search(test);
    // t=clock() -t;
    // cout<<"time is "<<t<<endl;
    // cout<<CLOCKS_PER_SEC<<" clocks per second"<<endl;
    // cout<<"time: "<< t*1.0/CLOCKS_PER_SEC<<" seconds"<<endl;

    delete[] codesArray;
}