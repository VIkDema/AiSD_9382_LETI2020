#ifndef IDECODER_H
#define IDECODER_H
#include <vector>
#include <algorithm>
#include <iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include <File.h>
#include <QElapsedTimer>

using namespace std;

class IDecoder{
public:
    virtual vector<pair<char, string>> decoding(string &str,vector<pair<char, string>> al)=0;
    virtual string get_code()=0;
    virtual bool need_alphabet()=0;
    virtual void notify(string message) = 0;
};


#endif // IDECODER_H
