#ifndef BINARYTREE_H
#define BINARYTREE_H
typedef struct nodeTree node;

struct nodeTree {//узел бинарного дерева
        nodeTree(int w, char c) {
            count = 1;
            this->weight = w;
            this->ch = c;
            this->left = nullptr;
            this->right = nullptr;

        }

        nodeTree() {
            count = 0;
            weight = 0;
            ch = -1;
            left = nullptr;
            right = nullptr;
        }



    static node *cons(node *a, node *b) {
        node *c = new node();
            c->weight = a->weight + b->weight;
            c->ch = -1;
            if (a->weight > b->weight) {//узел у которого вес больше станет правым поддеревом
                c->right = a;
                c->left = b;
            } else {
                c->right = b;
                c->left = a;
            }
            c->count = a->count + b->count;
            return c;
    }

    // для сортировки узлов дерева
    static bool compairNode(node *a1, node *a2) {
        if (a1->weight == a2->weight) {
                if (a1->count == 1 && a2->count == 1) {
                    return a1->ch > a2->ch;
                } else if (a1->count == a2->count && a1->count > 1) {
                    node* a=a1;
                    while(a->left!= nullptr){
                        a=a->left;
                    }
                    node* b=a2;
                    while(b->left!= nullptr){
                        b=b->left;
                    }
                    return a->ch>b->ch;
                }else{
                    return a1->count < a2->count;
                }
            }
            return a1->weight > a2->weight;
    }


    int weight;//вес узла
    char ch;//символ в узле
    node *left;//левое поддерево
    node *right;//правое поддерево
    int count;
};
struct Node {

    char c;
    int weight;
    Node *parent;
    Node *left;
    Node *right;
};


#endif // BINARYTREE_H
