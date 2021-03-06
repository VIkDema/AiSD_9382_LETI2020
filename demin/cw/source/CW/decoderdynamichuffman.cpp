#include "decoderdynamichuffman.h"

DecoderDynamicHuffman::DecoderDynamicHuffman()
{

}

string DecoderDynamicHuffman::get_code() {
    return full_code;
}

bool DecoderDynamicHuffman::need_alphabet() {
    return false;
}
vector<pair<char, string>> DecoderDynamicHuffman::decoding(string &str,vector<pair<char, string>> al){
    //алфавит
      QElapsedTimer clock;
      clock.start();
        char a = 0;
        full_code = "";
        new_node();
        for (int i = 0; i < 8; i++) {
            if (str[i] == '1') {
                a += pow(2, (7 - i));
            }
        }
        full_code += a;
        al.emplace_back(make_pair(a,"код ascii"));
        update(a);//добавили первый символ
        Node *temp = root;

        for (int j = 8; j < str.size(); j++) {
            char a = 0;

            if (str[j] == '0') {
                temp = temp->left;
                if (temp == getNode['\0']) {
                    a = 0;
                    j++;
                    for (int i = 0; i < 8; i++) {
                        if (str[j] == '1') {
                            a += pow(2, (7 - i));
                        }
                        j++;
                    }
                    j--;
                    full_code += a;
                    al.emplace_back(make_pair(a,"код ascii"));
                    update(a);
                    temp = root;
                }else {
                    char ch=temp->c;
                    if(ch!='\0'&&getNode.find(ch)!=getNode.end()){
                        full_code+=ch;
                        update(ch);
                        temp = root;
                    }
                }
            } else {
                temp = temp->right;
                if (temp == getNode['\0']) {
                    a = 0;
                    j++;
                    for (int i = 0; i < 8; i++) {
                        if (str[j] == '1') {
                            a += pow(2, (7 - i));
                        }
                        j++;
                    }
                    j--;
                    full_code += a;
                    al.emplace_back(make_pair(a,"код ascii"));
                    update(a);
                    temp = root;
                }else{
                    char ch=temp->c;
                    if(ch!='\0'&&getNode.find(ch)!=getNode.end()){
                        full_code+=ch;
                        update(ch);
                        temp = root;
                    }
                }
            }
        }
        string result;
        result+= std::to_string(str.size())+" "+std::to_string(full_code.size()*8)+" "+std::to_string(al.size())+" "+std::to_string(clock.elapsed())+'\n';
        notify(result);
        return al;
}

void DecoderDynamicHuffman::update(char a) {
    if (getNode.find(a) == getNode.end()) {
        Node *p = new Node();
        p->c = a;
        p->weight = 0;
        p->parent = getNode['\0'];
        getNode[a] = p;
        getNode['\0']->right = p;

        //Creating new NYT node
        Node *n = new Node();
        n->c = '\0';
        n->weight = 0;
        n->parent = getNode['\0'];
        n->left = nullptr;
        n->right = nullptr;

        getNode['\0']->left = n;
        getNode['\0'] = n;
    }

    Node *temp = getNode[a];
    while (temp != nullptr) {
        temp->weight++;
        temp = temp->parent;
    }


    while (true) {
        vector<Node *> levelorder = levelOrder();
        int i;
        for (i = 1; i < levelorder.size() - 1; i++)
            if (levelorder[i]->weight > levelorder[i + 1]->weight)
                break;
        if (i == levelorder.size() - 1)
            return;
        int j;
        for (j = levelorder.size() - 1; j >= 0; j--)
            if (levelorder[j]->weight == levelorder[i]->weight - 1)
                break;
        if (j < i)
            return;
        //Swap nodes at position i and j
        Node *parentofi = levelorder[i]->parent;
        Node *parentofj = levelorder[j]->parent;

        levelorder[i]->parent = parentofj;
        levelorder[j]->parent = parentofi;

        if (parentofi->left == levelorder[i] && parentofj->left == levelorder[j]) {
            parentofi->left = levelorder[j];
            parentofj->left = levelorder[i];
        } else if (parentofi->left == levelorder[i] && parentofj->right == levelorder[j]) {
            parentofi->left = levelorder[j];
            parentofj->right = levelorder[i];
        } else if (parentofi->right == levelorder[i] && parentofj->left == levelorder[j]) {
            parentofi->right = levelorder[j];
            parentofj->left = levelorder[i];
        } else if (parentofi->right == levelorder[i] && parentofj->right == levelorder[j]) {
            parentofi->right = levelorder[j];
            parentofj->right = levelorder[i];
        }


        levelorder = levelOrder();
        for (int i = 0; i < levelorder.size() - 1; i += 2)
            if (levelorder[i]->parent->weight != levelorder[i]->weight + levelorder[i + 1]->weight)
                levelorder[i]->parent->weight = levelorder[i]->weight + levelorder[i + 1]->weight;
    }
}


vector<Node *> DecoderDynamicHuffman::levelOrder() {
    vector<Node *> ans;
    if (!root) return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++) {
            if (q.front()->right)
                q.push(q.front()->right);
            if (q.front()->left)
                q.push(q.front()->left);
            ans.push_back(q.front());
            q.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void DecoderDynamicHuffman::new_node() {

    getNode.clear();
    root = new Node();
    root->c = '\0';
    root->weight = 0;
    root->parent = nullptr;
    root->left = nullptr;
    root->right = nullptr;

    getNode['\0'] = root;
}
void DecoderDynamicHuffman::notify(string message){
    file=new FileLog("decoderdh.txt");
    file->write(message.c_str());
    delete file;
}

