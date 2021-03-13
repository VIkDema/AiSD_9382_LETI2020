#ifndef DECODERSTATICHUFFMAN_H
#define DECODERSTATICHUFFMAN_H
#include "IDecoder.h"
#include <QDebug>

class DecoderStaticHuffman: public IDecoder
{
    string full_code;
    FileLog* file;
public:
    DecoderStaticHuffman();
     vector<pair<char, string>> decoding(string &str,vector<pair<char, string>> al) override;
     string get_code() override;
     bool need_alphabet() override;
     void notify(string message) override;
};

#endif // DECODERSTATICHUFFMAN_H
