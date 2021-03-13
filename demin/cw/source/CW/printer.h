#ifndef PRINTER_H
#define PRINTER_H
#include<iostream>
#include <vector>
#include <QString>
using namespace std;
class Printer
{
    static QString binary_char(int a);
public:
    Printer();
    static string write(vector<pair<char,string>> al);
    static QString write_binary(QString str);

};

#endif // PRINTER_H
