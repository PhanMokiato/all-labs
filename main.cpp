#include <iostream>
#include "functions.h"
#include <string>

int main() {
    for (int i = 0; ; ++i) {
      std::cout << "Please, enter your expression(without spaces):" << std::endl;
      std::string expr;
      std::cin >> expr;
      if (CheckingExpressionForMistakes(expr)) {
        std::cout << "The answer is " << Solving(expr) <<  std::endl;
        std::cout << "Do you wish to continue? Write 'Yes' or 'No', please:" << std::endl;
        std::string Answer;
        std::cin >> Answer;
        if (Answer == "Yes") {
          continue;
        }
        if (Answer == "No") {
          std::cout << "Ok, bye).";
          break;
        }
        if (Answer != "Yes" && Answer != "No") {
          std::cout << "I'll take it for a 'No'. Ok, bye).";
          break;
        }
      } else {
        std::cout << "Aaaahh. Nope. Not happening. Try again, please:" << std::endl;
        continue;
      }
    }
  return 0;
}
