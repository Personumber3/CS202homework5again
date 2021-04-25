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

#endif //CS202HOMEWORK5_MYREADWRITE_H
