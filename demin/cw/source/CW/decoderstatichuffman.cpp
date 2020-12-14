#include "decoderstatichuffman.h"

DecoderStaticHuffman::DecoderStaticHuffman()
{
}

vector<pair<char, string>> DecoderStaticHuffman::decoding(string &str,vector<pair<char, string>> al) {
    QElapsedTimer clock;
    clock.start();
    full_code.clear();
    size_t n=0;
       for(auto it = str.begin();it<str.end();it++){
           for (auto i = al.begin(); i <al.end() ; ++i) {
                   while(n<i->second.size()&& *it==i->second[n]){
                       it++;
                       if(it==str.end()){
                           break;
                       }
                       n++;
                   }
                   if(n==i->second.size()){
                       it--;
                       n=0;
                       full_code+=i->first;
                       break;
                   }
           }
    }
    string result;
    result+= std::to_string(str.size())+" "+std::to_string(full_code.size()*8)+" "+std::to_string(al.size())+" "+std::to_string(clock.elapsed())+'\n';
    notify(result);
    return al;
}

string DecoderStaticHuffman::get_code() {
    return full_code;
}

bool DecoderStaticHuffman::need_alphabet(){
    return true;
}
void DecoderStaticHuffman::notify(string message){
    file=new FileLog("decodersh.txt");
    file->write(message.c_str());
    delete file;
}

