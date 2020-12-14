#include "tester.h"


Tester::Tester()
{

}
void Tester::startTest(int count_of_tests){
    generator gen;
    string str;
    CoderDynamicHuffman cdh;
    CoderStaticHaffman csh;
    DecoderDynamicHuffman ddh;
    DecoderStaticHuffman dsh;
    vector<pair<char,string>> al;
    for(int i = 2; i<count_of_tests;i++){
        str=gen.generatorStr(i);
        cdh.coding(str);
        al=csh.coding(str);
        str=csh.get_code();
        dsh.decoding(str,al);
        str=cdh.get_code();
        ddh.decoding(str,al);
    }
}


