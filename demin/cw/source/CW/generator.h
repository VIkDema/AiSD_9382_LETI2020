#ifndef GENERATOR_H
#define GENERATOR_H
#include <ctime>
#include <string>
#include <algorithm>
#include<iostream>
using namespace std;


class generator {
     public:
        int randnum(int a, int b);
        string generatorStr(int complexity);
};

#endif // GENERATOR_H
