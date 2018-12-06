#ifndef UPC_h
#define UPC_h

#include <iostream>

using namespace std;

class UPC{
    
    long long UPCnum;
    string info;

    public:


        UPC();
        UPC(long long _UPCnum, string _info);
        long long getNum();
        friend bool operator== (const UPC& lhs, const UPC& rhs);
        friend bool operator!= (const UPC& lhs, const UPC& rhs);
        friend bool operator< (const UPC& lhs, const UPC& rhs);
        friend bool operator> (const UPC& lhs, const UPC& rhs);
        friend ostream& operator<<(ostream& os, const UPC& upc);
        bool isInitialized();
};

UPC::UPC(){
    UPCnum = -123456789;
    info = "";
}
bool UPC::isInitialized(){
    return UPCnum==-123456789;
}

long long UPC::getNum(){
    return UPCnum;
}

UPC::UPC(long long _UPCnum, string _info){
    UPCnum = _UPCnum;
    info = _info;
}

bool operator== (const UPC& lhs, const UPC& rhs){
        return lhs.UPCnum == rhs.UPCnum;
    }
bool operator!= (const UPC& lhs, const UPC& rhs){
    return !(lhs==rhs);
}
bool operator< (const UPC& lhs, const UPC& rhs){
    return lhs.UPCnum < rhs.UPCnum;
}
bool operator> (const UPC& lhs, const UPC& rhs){ 
    return rhs.UPCnum < lhs.UPCnum; 
}
ostream& operator<<(ostream& os, const UPC& upc){
    os << '[' << upc.UPCnum << "]   " << upc.info;
    return os;
}

#endif