#ifndef _UPCHashObject_
#define _UPCHashObject_
#include <iostream>

using namespace std;


class UPCHashObject{
public:
    UPCHashObject();
    UPCHashObject(long long _key, string _data);
    int getKey();
    friend bool operator== (const UPCHashObject& lhs, const UPCHashObject& rhs);


private:
    int key;
    string data;
    int hash(long long _key);
};

UPCHashObject::UPCHashObject(){
}

UPCHashObject::UPCHashObject(long long _key, string _data){
        key = hash(_key);
        data = _data;
    }

int UPCHashObject::hash(long long _key){
    return _key%1000;
}

int UPCHashObject::getKey(){
    return key;
}

bool operator== (const UPCHashObject& lhs, const UPCHashObject& rhs){
        return lhs.key == rhs.key;
    }


#endif