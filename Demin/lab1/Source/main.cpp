#include <iostream>
#include <fstream>

//indents
static int k = 0;
//for file "result.txt"
static std::ofstream fout;

//recursive function
long f(long n) {
    fout << "f(" << n << ")::\\";
    fout << "\n";
    long sum = 0;
    if (n == 1) {
        fout << "\n";
        for (int i = 0; i < k; i++) {
            fout << "\t";
        }
        fout << "/f(" << n << ")::" << 1;
        fout << "\n";

        return 1;
    }
    if (n >= 2) {
        for (long i = 2; i <= n; i++) {

            k++;
            for (int i = 0; i < k; i++) {
                fout << "\t";
            }

            sum += f(n / i);

            k--;
            fout << "\n";
        }

        for (int i = 1; i <= k; i++) {
            fout << "\t";
        }
        fout << "/f(" << n << ")::" << sum;
        fout << "\n";
        return sum;
    }
    return 0;
}

//result output
void print_result(int a, int b) {
    long n = 0;
    for (int i = a; i < b; ++i) {
        fout << "f(" << i << ") : " << "\n";
        fout << "-------------------------------------------------------------------" << "\n";
        n = f(i);
        std::cout << "f(" << i << ") : " << n << "\n";
    }
}

//type_selection
void type_selection() {
    int type = 0;
    int value = 0;
    std::cout << "select type:\n 1-one value,2 - from 15 to 31\n";
    std::cin >> type;
    switch (type) {
        case 1:
            std::cout << "enter value\n";
            std::cin >> value;
            if(value<1){
                std::cout<<"Incorrect data";
                break;
            }
            print_result(value, value + 1);
            break;
        case 2:
            print_result(15, 31);
            break;
        default:
            std::cout << "error: wrong type";
    }
    std::cout << "intermediate values are written to the result file";
}

int main() {
    fout.open("result.txt");
    type_selection();
    fout.close();
    return 0;
}
