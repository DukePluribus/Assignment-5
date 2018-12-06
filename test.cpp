#include "HashTable.h"

using namespace std;

int main(){
    HashTable test;
    UPC testUPC = UPC(701197194311, "butts");
    test.insert(testUPC);
    if(test.search(testUPC)==true){
        cout<<"success"<<endl;
    }
    return 0;
}