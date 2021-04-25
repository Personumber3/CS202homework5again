//
// Created by Alden Ahern on 4/24/21.
//

#ifndef CS202HOMEWORK5_MYREADWRITE_H
#define CS202HOMEWORK5_MYREADWRITE_H


// Includes for this testing program
#include <fstream>      // for std::ifstream and std::ofstream
using std::ifstream;
using std::ofstream;

template<typename Type>
void myWrite(ofstream &ofs,Type &val){ofs.write(reinterpret_cast<const char *>(&val),sizeof(Type));};

template<typename Type>
void myRead(ifstream &ifs,Type &val){ifs.read(reinterpret_cast<char *>(&val),sizeof(Type));};

int fib(int n);
int fib_loop(int n);

int fib(int n){
    if (n == 1 or n == 0){return 1;}
    return fib(n-1)+fib(n-2);
}

int fib_loop(int n){
    if (n == 0 or n == 1){return 1;}
    int previos = 1; // starts as first term: f_0
    int f_i = 1; // starts with the second term: f_1
    int holder;
    int i = 1; // already accounted for
    while (i < n){
        ++i;
        holder = f_i;
        f_i  += previos; // fi = fi-1 + fi-2. fi is already fi-1, so we just need to add fi-2.
        previos = holder;
    }
    return f_i;
}



#endif //CS202HOMEWORK5_MYREADWRITE_H
