#include "printer.h"

Printer::Printer()
{

}



string Printer::write(vector<pair<char,string>> al){
    string str;
    str=str+"Symbol\t\tCode\n";
        for (auto it = al.begin(); it != al.end(); ++it) {
            if(it->second=="код ascii"){
                str=str+it->first+"\t\t"+binary_char(it->first).toStdString()+"\n";
                continue;
            }
            str=str+it->first+"\t\t"+it->second+"\n";
        }
    return str;
};

QString Printer::write_binary(QString str){
    QString binary_code;
    QByteArray arr = str.toLocal8Bit();
    for(auto it =arr.begin();it!=arr.end();it++){
        int a =(unsigned char)*it;
         binary_code += binary_char(a);

    }
    return binary_code;
};
QString Printer::binary_char(int a){
    QString binary_code;
    for (int i = 0; i < 8; ++i) {
            if (a % 2 == 1) {
                binary_code.append("1");
            } else {
                binary_code.append("0");
            }
            a=a/2;
    }
    reverse(binary_code.begin(), binary_code.end());
    return binary_code;
}

