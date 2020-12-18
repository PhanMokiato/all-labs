#include <iostream>
#include "functions.h"
#include <string>

int main() {
    std::cout << "Please, enter your expression:" << std::endl;
    std::string expr;
    std::cin >> expr;
    if (CheckingExpressionForMistakes(expr)) {
      std::cout << ConversionWithDA(expr) << std::endl;
    } else {
      std::cout << "Aaaahh. Nope. Not happening." << std::endl;
    }
    return 0;
}
