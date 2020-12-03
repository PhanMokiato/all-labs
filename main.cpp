#include <iostream>
#include "stack.h"


int main() {
    Stack_A Calc;
    Calc << 3.4;
    Calc << 5.6;
    Calc << -1.27;
    Stack_A Calc1;
    Calc1 = Calc;
    Calc.PrintStack_A();
    int s = Calc.Size();
    double k = Calc>>Calc;
    Calc.PrintStack_A();
    std::cout << k << std::endl;
    Calc1.PrintStack_A();
    if (Calc1 > Calc) {
        std::cout << "The second one is bigger." << std::endl;
    } else {
        std::cout << "The second one is smaller." << std::endl;
    }
    if (Calc1 < Calc) {
        std::cout << "The first one is bigger." << std::endl;
    } else {
        std::cout << "The first one is smaller." << std::endl;
    }
    if (Calc == Calc1) {
        std::cout << "They are equal." << std::endl;
    } else {
        std::cout << "They aren't equal." << std::endl;
    }
    // adding new element
    Calc << 8.71;
    // done
    if (Calc == Calc1) {
        std::cout << "They are equal." << std::endl;
    } else {
        std::cout << "They aren't equal." << std::endl;
    }
    std::cout << Calc[1];
    return 0;
}
