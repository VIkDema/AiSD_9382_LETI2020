//
// Created by vikto on 04.11.2020.
//
#include <iostream>
#include <fstream>

using namespace std;

//класс узла дерева
template<typename T>
class treeNode {
    ~treeNode() {
        delete left;
        delete right;
    }

public:
    T root;//корень
    treeNode *left;//левая ветвь
    treeNode *right;//правая ветвь
};

//класс для вывода промежуточных значений в файл
class logger {
    string str;
    std::FILE *file;
public:
    //конструктор класса длв вывода промежуточных значений
    logger() : file(std::fopen("intermeiate.txt", "w+")) {
        if (!file)
            throw std::runtime_error("file open failure");
    }

    //закрытие файла
    ~logger() {
        cout<< "\nIntermeiate values write to file \"intermeiate.txt\"";
        if (std::fclose(file) != 0) {
        }
    };

    //рекурсивная функция для вывода промежуточных деревьев
    void logTree(treeNode<char> *tree, int level) {
        if (tree) {
            logTree(tree->left, level + 1);
            for (int i = 0; i < level; i++) fputs("   ", file);
            if (!tree->left && !tree->right) {
                str = "(" + std::string(1, tree->root) + ")\n";
                fputs(str.c_str(), file);
            } else {
                str = string(1, tree->root) + "\n";
                fputs(str.c_str(), file);
            }
            logTree(tree->right, level + 1);

        }
    }

    //вызов рекурсивной функции
    void logWriteTree(treeNode<char> *tree, int level) {
        if (tree) {
            fputs("---------------------------------------------\n", file);
            logTree(tree, level);
        }
    }

    //начало для файла промежуточных значений
    void logStartEnter() {
        fputs("StartEnter\n", file);
        fputs("Leaves in brackets\n", file);
    }
};

static logger *log = new logger();

template<typename T>
class binaryTree {

    ~binaryTree() {
        delete BT;
    }

    //проверка пустое ли дерево
    bool isNull(treeNode<T> *bt) {
        return bt == nullptr;
    }

    //получение корня узла дерева
    T root(treeNode<T> *bt) {
        return bt->root;
    }

    //создание узла дерева
    treeNode<T> *cons(T elem, treeNode<T> *left, treeNode<T> *right) {
        treeNode<T> *a = new treeNode<T>;
        a->root = elem;
        a->left = left;
        a->right = right;
        return a;
    }

    //рекурсивная функции вывода элементов дерева
    void writeNode(treeNode<T> *bt, ofstream &file) {
        if (file.is_open()) {
            if (!isNull(bt)) {
                file << root(bt) << " ";
                writeNode(bt->left, file);
                writeNode(bt->right, file);
            }
        } else {
            if (!isNull(bt)) {
                cout << root(bt) << " ";
                writeNode(bt->left, file);
                writeNode(bt->right, file);
            }
        }
    }

    //рекурсивная функция вывод листьев дерева
    void writeLeaflet(treeNode<T> *bt, ofstream &file) {
        if (file.is_open()) {
            if (!isNull(bt)) {
                if (!bt->left && !bt->right) {
                    file << root(bt) << " ";
                }
                writeLeaflet(bt->left, file);
                writeLeaflet(bt->right, file);
            }
        } else {
            if (!isNull(bt)) {
                if (!bt->left && !bt->right) {
                    cout << root(bt) << " ";
                }
                writeLeaflet(bt->left, file);
                writeLeaflet(bt->right, file);
            }
        }

    }

    //рекурсивная функция вывода узлов с уровнем
    void writeLevel(treeNode<T> *bt, int level, int n, int *count) {
        if (!isNull(bt)) {
            if (n == level) {
                (*count)++;
                return;
            }
            writeLevel(bt->left, level + 1, n, count);
            writeLevel(bt->right, level + 1, n, count);
        }
    }

public:
    treeNode<T> *BT;

    //создание пустого дерева
    binaryTree() {
        this->BT = nullptr;
    }

    //создание дерева с первым корнем
    explicit binaryTree(T a) {
        this->BT = new treeNode<T>;
        this->BT->root = a;
        this->BT->left = nullptr;
        this->BT->right = nullptr;
    };

    //вызов рекурсивной функции для вывода элементов дерева
    void writeTree(ofstream &file) {
        writeNode(this->BT, file);
    }

    //вызов рекурсивной функции для вывода листьев дерева
    void writeLeaves(ofstream &file) {
        writeLeaflet(this->BT, file);
    }


//рекурсивная функция ввода дерева из консоли
    treeNode<T> *enterTree() {
        log->logWriteTree(BT, 1);
        char ch;
        treeNode<T> *l;
        treeNode<T> *r;
        cin >> ch;

        if (ch == '/') return NULL;
        else {
            l = enterTree();
            log->logWriteTree(l, 0);
            r = enterTree();
            log->logWriteTree(r, 0);
            return cons(ch, l, r);
        }
    }

//рекурсивная функция ввода дерева из файла
    treeNode<T> *enterTreeFromFile(ifstream *file) {
        char ch;
        treeNode<T> *l;
        treeNode<T> *r;
        *file >> ch;
        if (ch == '/') return NULL;
        else {
            l = enterTreeFromFile(file);
            log->logWriteTree(l, 0);
            r = enterTreeFromFile(file);
            log->logWriteTree(r, 0);
            return cons(ch, l, r);;
        }
    }

//вывод количества узлов одного уровня
    void writeWithLevel(ofstream &file, int n) {
        if (file.is_open()) {
            int count = 0;
            writeLevel(BT, 1, n, &count);
            file << count;

        } else {
            int count = 0;
            writeLevel(BT, 1, n, &count);
            cout << count;
        }

    }

};

//интерфейс
void enter(binaryTree<char> *a) {
    int type = 0;
    cout << "Enter from console -1\n";
    cout << "Enter from file -2\n";
    cin >> type;
    ifstream file;
    string name;
    log->logStartEnter();
    switch (type) {
        case 2:
            cout << "Enter file name\n";
            cin >> name;
            file.open(name);
            if (file.is_open()) {
                a->BT = a->enterTreeFromFile(&file);
                log->logWriteTree(a->BT, 0);
                file.close();
            } else cout << "Unable to open file";
            break;
        case 1:
            a->BT = a->enterTree();
            log->logWriteTree(a->BT, 0);
            break;
        default:
            cout << "incorrect type\n";
    }
}

void writeResult(binaryTree<char> *a) {
    int type = 0;
    int n = 0;
    cout << "Print to console -1\n";
    cout << "Print to file -2\n";
    cin >> type;
    cout << "At what level to count the number of tree nodes?\n";
    cin >> n;
    ofstream file;
    string name_f;
    switch (type) {
        case 1: {
            cout << "Tree elements: ";
            a->writeTree(file);
            cout << "\n";
            cout << "Tree leaves:";
            a->writeLeaves(file);
            cout << "\n";
            cout << "Count tree elements with level " << n << " :";

            a->writeWithLevel(file, n);
        }
            break;
        case 2:
            cout << "Enter file name\n";
            cin >> name_f;
            file.open(name_f);
            if (file.is_open()) {
                file << "Tree elements: ";
                a->writeTree(file);
                file << "\n";
                file << "Tree leaves:";
                a->writeLeaves(file);
                file << "\n";
                file << "Tree elements with levels: " << n << " :";
                a->writeWithLevel(file, n);
                cout << "the final result is written to the file \"" + name_f << "\"" << endl;
            } else cout << "Unable to open file";
            break;
        default:
            cout << "error: selection of output type";
            break;
    }

}

int main() {
    binaryTree<char> *a = new binaryTree<char>();
    enter(a);
    writeResult(a);
    delete log;
    return 0;
}