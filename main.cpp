#include <iostream>
#include "myreadwrite.h"

int fib(int n);
int fib_loop(int n);

int fib(int n){
    if (n == 1 or n == 0){return 1;}
    return fib(n-1)+fib(n-2);
}
int fib_loop(int n){
    if (n == 0 or n == 1){return 1;}
    int f_i = 1; // starts with the second term: f_1
    int holder;
    int f_i_1 = 1; // starts as first term: f_0
    int i = 1; // already accounted for
    while (i < n){
        ++i;
        holder = f_i;
        f_i  += f_i_1; // fi = fi-1 + fi-2. fi is already fi-1, so we just need to add fi-2.
        f_i_1 = holder;
    }
}

int whatever() {
    ofstream ofile("numbers.dat");
    double d=13.3;
    myWrite(ofile,d);
    int x=5;
    myWrite(ofile,x);

    ifstream ifile("numbers.dat");
    double readd;
    int readx;

    myRead(ifile,readd);
    myRead(ifile,readx);

    return 0;
}
