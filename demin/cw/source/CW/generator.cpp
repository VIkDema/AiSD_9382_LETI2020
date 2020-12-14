#include "generator.h"

int generator::randnum(int a, int b) {
    return (rand()) % (b - a + 1)+a;
}

string generator::generatorStr(int complexity) {
    string str;
    for (int i = 0; i < complexity; ++i) {
        str+=(char)randnum(32,126);
    }
    return str;
}
