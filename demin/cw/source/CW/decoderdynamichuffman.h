#ifndef DECODERDYNAMICHUFFMAN_H
#define DECODERDYNAMICHUFFMAN_H
#include "IDecoder.h"
#include <cmath>
#include <BinaryTree.h>



class DecoderDynamicHuffman: public IDecoder
{
    string full_code;
    Node *root;
    unordered_map<char, Node *> getNode;
    FileLog* file;
    vector<Node *> levelOrder();

    void update(char a);
    void new_node();


public:
    DecoderDynamicHuffman();
    vector<pair<char, string>> decoding(string &str,vector<pair<char, string>> al) override;
    string get_code() override;
    bool need_alphabet() override;
    void notify(string message) override;
};

#endif // DECODERDYNAMICHUFFMAN_H
