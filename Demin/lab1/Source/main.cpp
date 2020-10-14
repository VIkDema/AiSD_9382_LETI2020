#include <iostream>
#include <fstream>

static int k = 0;
static std::ofstream fout;


long f(long n) {
    fout << "f(" << n << ")::\\";
    fout << "\n";
    long sum = 0;
    if (n == 1) {
        fout << "\n";
        for (int i = 0; i < k; i++) {
            fout << "\t";
        }
        fout <<"/f(" << n << ")::"<<1;
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
        fout <<"/f(" << n << ")::"<<sum;
        fout << "\n";
        return sum;
    }
    return 0;
}

void print_result() {
    fout.open("result.txt");
    long n = 0;
    for (int i = 15; i < 31; ++i) {
        fout << "f(" << i << ") : " << "\n";
        fout << "-------------------------------------------------------------------" << "\n";
        n = f(i);
        std::cout << "f(" << i << ") : " << n << "\n";
    }
}

int main() {
    print_result();
    fout.close();
    return 0;
}
