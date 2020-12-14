#ifndef ICODER_H
#define ICODER_H
#include <vector>
#include <algorithm>
#include <iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include <File.h>
#include <QElapsedTimer>
using namespace std;

class ICoder{
public:
    virtual vector<pair<char, string>> coding(string &str)=0;
    virtual string get_code()=0;
    virtual void notify(string message) = 0;
};

#endif // ICODER_H
