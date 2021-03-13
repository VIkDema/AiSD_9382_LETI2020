#ifndef CODERSTATICHAFFMAN_H
#define CODERSTATICHAFFMAN_H
#include "ICoder.h"
#include "BinaryTree.h"


class CoderStaticHaffman:public ICoder
{
    string full_code;
    void formAlpabet(string const &str, vector<pair<char, int>> &alphabet);
    static bool compair_alphabet(pair<char, int> a1, pair<char, int> a2);
    node * makeBinaryTree(vector<pair<char, int>> alphabet);
    void makeCode(node *tree, char ch, string &code, bool &flag);
    FileLog* file;

public:
    CoderStaticHaffman();
    vector<pair<char, string>> coding(string &str) override;
    string get_code() override;
    void notify(string message) override;

};

#endif // CODERSTATICHAFFMAN_H
