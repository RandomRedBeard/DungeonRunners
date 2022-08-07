#include <iostream>

namespace Test {
    typedef int myint;
}

int main() {
    Test::myint i = 0;
    assert(i);
}