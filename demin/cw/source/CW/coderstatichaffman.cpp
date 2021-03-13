#include "coderstatichaffman.h"

CoderStaticHaffman::CoderStaticHaffman()
{
}

vector<pair<char, string>> CoderStaticHaffman::coding(string &str)
{
    QElapsedTimer clock;
    clock.start();
        vector<pair<char, int>> alphabet;
        vector<pair<char, string>> alphabetWithCode;
        formAlpabet(str, alphabet);

        sort(alphabet.begin(), alphabet.end(), compair_alphabet);
        node *binaryTree = makeBinaryTree(alphabet);

        string code;
        bool flag = true;

        if(alphabet.size()>1){
            for (auto it = begin(alphabet); it != end(alphabet); ++it) {
            makeCode(binaryTree, it->first, code, flag);
            alphabetWithCode.emplace_back(make_pair(it->first, code));
            code = "";
            flag = true;
        }}else if(alphabet.size()==1){
            code="0";
            alphabetWithCode.emplace_back(make_pair(alphabet[0].first, code));
         }
        full_code ="";
        for (auto ch = str.begin(); ch != str.end(); ++ch) {
            for (auto it = alphabetWithCode.begin(); it != alphabetWithCode.end(); ++it) {
                if (it->first == *ch.base()) {
                    full_code=full_code+it->second;
                }
            }
        }
        string result;
        result+= std::to_string(str.size()*8)+" "+std::to_string(full_code.size())+" "+std::to_string(alphabetWithCode.size())+" "+std::to_string(clock.elapsed())+'\n';
        notify(result);
        return alphabetWithCode;
}

void CoderStaticHaffman::formAlpabet(string const &str, vector<pair<char, int>> &alphabet) {

    bool flag = false;
    for (size_t i = 0; i < str.size(); ++i) {
        flag = false;
        for (auto it = begin(alphabet); it != end(alphabet); ++it) {
            if (str[i] == it->first) {
                flag = true;
                it->second++;
                break;
            }
        }
        if (flag) {
            continue;
        }
        alphabet.emplace_back(make_pair(str[i], 1));
    }
};

bool CoderStaticHaffman::compair_alphabet(pair<char, int> a1, pair<char, int> a2) {
    return a1.second > a2.second;
}

node * CoderStaticHaffman::makeBinaryTree(vector<pair<char, int>> alphabet) {
    vector<node *> tree;
    for (auto it = alphabet.begin(); it != alphabet.end(); ++it) {
        tree.push_back(new node(it->second, it->first));
    }
    sort(tree.begin(), tree.end(), node::compairNode);
    while (tree.size() != 1) {
        tree.push_back(node::cons(tree[tree.size() - 2], tree[tree.size() - 1]));
        sort(tree.begin(), tree.end(), node::compairNode);
        tree.pop_back();
        tree.pop_back();
    }

    return tree[0];
}

void CoderStaticHaffman::makeCode(node *tree, char ch, string &code, bool &flag) {
    if (flag) {
        if (tree != nullptr) {
            if (tree->ch == ch) {
                flag = false;
                return;
            }
            code += "0";
            makeCode(tree->left, ch, code, flag);
            if (flag) {
                code.pop_back();
            } else { return; }
            code += "1";
            makeCode(tree->right, ch, code, flag);
            if (flag) {
                code.pop_back();
            }
        }
    }
}
string CoderStaticHaffman::get_code(){
    return full_code;
}

void CoderStaticHaffman::notify(string message){

    file=new FileLog("codersh.txt");
    file->write(message.c_str());
    delete file;
}
