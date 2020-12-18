//
// Created by Zver on 16.12.2020.
//

#ifndef LAB8__FUNCTIONS_H_
#define LAB8__FUNCTIONS_H_

#include <string>
#include <cctype>
#include "stack.h"
// Checking

bool Operators(char &op) {
  if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
    return true;
  }
  return  false;
}

bool Digits(std::string &ex, int &n) {
  return isdigit(ex[n - 1]) && isdigit(ex[n + 1]);
}

bool DigitsAndBrackets1(std::string &ex, int &n) {
  return isdigit(ex[n - 1]) && ex[n + 1] == '(';
}

bool DigitsAndBrackets2(std::string &ex, int &n) {
  return isdigit(ex[n + 1]) && ex[n - 1] == ')';
}

bool Brackets(std::string &ex, int &n) {
  return ex[n - 1] == ')' && ex[n + 1] == '(';
}

bool CheckingExpressionForMistakes(std::string &exp) {
  bool ok = true;
  int brackets = 0;
  int operators = 0;
  int k = exp.length();
  if (Operators(exp[k - 1]) || exp[k - 1] == '(' || exp[k - 1] == '.') {
    ok = false;
    return ok;
  }
  if (Operators(exp[0]) || exp[0] == '.') {
    ok = false;
    return ok;
  }
  for (int i = 0; i < k; ++i) {
      if(Operators(exp[i])) {
        if (!Digits(exp, i) && !DigitsAndBrackets1(exp, i) && DigitsAndBrackets2(exp, i) && Brackets(exp, i)) {
          ok = false;
        }
      }
      if (exp[i] == '.') {
        if (!isdigit(exp[i - 1]) || !isdigit(exp[i + 1])) {
          ok = false;
        }
      }
      if (exp[i] == '(') {
        ++brackets;
        if (exp[i + 1] == ')') {
          ok = false;
        }
      }
      if (exp[i] == ')') {
        if (brackets == 1) {
          for (int f = i; exp[f] != '('; --f) {
            if (Operators(exp[f])) {
              ++operators;
            }
          }
          if (operators == 0) {
            ok = false;
          }
          operators = 0;
          brackets = 0;
        } else {
          ok = false;
        }
      }
  }
  if (brackets != 0) {
    ok = false;
  }
  return ok;
}


//Converting

int OpPriority(std::string &op) {
  std::string op_type[5] = { "(", ")", "-+", "*/", "^"};
  int num = -1;
  for (int i = 0; i < 5; ++i) {
    std::string Elem = op_type[i];
    for (int l = 0; l < Elem.length(); ++l) {
      char el = Elem[l];
      std::string elem(1, el);
      if (op != elem) {
        continue;
      } else {
        num = i;
        break;
      }
    }
  }
  return num;
}

std::string ConversionWithDA(std::string &ar_exp) {
  Stack_A<std::string> operators;
  std::string RevPol;
  std::string number;
  for (int i = 0; i < ar_exp.length(); ++i) {
    std::string K(1, ar_exp[i]);
    if (isdigit(ar_exp[i])) {
      number += K;
    }
    if (ar_exp[i] == '.') {
      number += K;
      continue;
    }
    if (!isdigit(ar_exp[i])) {
      if (!number.empty()) {
        RevPol = RevPol + number + '|';
        number = "";
      }
      std::string K1 = "f";
      if (!operators.IsEmpty()) {
        K1 = operators.Top();
      }
      if (OpPriority(K) == 0) {
        operators << K;
        continue;
      }
      if ((operators.IsEmpty() == true || OpPriority(K) > OpPriority(K1)) && OpPriority(K) != 1){
        operators << K;
        continue;
      }
      if ((OpPriority(K) == OpPriority(K1) || OpPriority(K) < OpPriority(K1)) && OpPriority(K) != 1) {
        Stack_A<std::string> leftovers;
        for (int l = operators.Size(); l > 0; --l) {
          std::string K2 = operators.Top();
          if (OpPriority(K) == OpPriority(K2) || OpPriority(K) < OpPriority(K2)) {
            std::string op = operators >> operators;
            RevPol = RevPol + op;
          } else {
            std::string op = operators >> operators;
            leftovers << op;
          }
        }
        int n1 = leftovers.Size();
        for (int n2 = 0; n2 < n1; ++n2) {
         std::string K3 = leftovers >> leftovers;
         operators << K3;
        }
        operators << K;
        continue;
      }
      if (OpPriority(K) == 1) {
        int k1 = operators.Size();
        for (int k2 = k1; operators[k2] != "("; --k2) {
          std::string K4 = operators >> operators;
          RevPol = RevPol + K4;
        }
        operators >> operators;
      }
    }
  }
  if (!operators.IsEmpty()) {
    int f1 = operators.Size();
    for (int f2 = f1; f2 > 0; --f2) {
      std::string K5 = operators >> operators;
      RevPol = RevPol + K5;
    }
  }
  return RevPol;
}

#endif //LAB8__FUNCTIONS_H_
