
#include <iostream>

using namespace std;

struct Thing {
    int* iarr;
    Thing(int n) {
        iarr = new int[n];
    }
    ~Thing() { // destructor cannot have any parameters
        delete iarr; // you just delete iarr - you don't need to add any parameters
    }
};

const int OUTER = 1000000;
const int INNER = 1000;

//int main() {
//    for(int i = 0; i < OUTER; i++) {
//        Thing** things = new Thing*[INNER];
//        for(int j=0; j < INNER; j++){
//            things[j] = new Thing(INNER);
//        }
//        for(int j=0; j < INNER; j++) {
//            delete things[j];
//        }
//        delete[] things; //delete array of things
//    }
//}
