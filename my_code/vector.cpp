#include <iostream>
#include "vector.h"

using namespace std;

int data[0];
int sz;
int capacity;

void print_vector(const MyVec& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

MyVec::MyVec() {
    sz = 0;
    capacity = 0;

}

MyVec::MyVec(const MyVec& v2) {
    data = v2.data;
    sz = v2.size();
    capacity = v2.capacity;
}

MyVec::~MyVec() {

}

// MyVec& MyVec::operator=(const MyVec& v2) {
//     data = v2.data;
//     sz = v2.size();
//     capacity = v2.capacity;
// }

/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    if(v1.size() != v2.size()) {
        return false;
    }
    else {
        for(int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
    int temp[sz*2];
    for(int i = 0; i < sz; i++) {
        data[i] = temp[i];
    }
    temp[sz] = val;
    ++sz;
    
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    int& j = data[i];
    return j;
}
