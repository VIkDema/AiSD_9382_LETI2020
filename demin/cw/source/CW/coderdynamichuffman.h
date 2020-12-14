#ifndef CODERDYNAMICHUFFMAN_H
#define CODERDYNAMICHUFFMAN_H
#include "ICoder.h"
#include <BinaryTree.h>


class CoderDynamicHuffman:public ICoder {
    Node *root;
    string full_code;
    unordered_map<char, Node *> getNode;
    vector<Node *> levelOrder();
    void update(char a);
    void new_node();
    FileLog* file;
public:

    string get_code() override;

    CoderDynamicHuffman();

    vector<pair<char,string>> coding(string& str) override;
    void notify(string message) override;
};

#endif // CODERDYNAMICHUFFMAN_H
