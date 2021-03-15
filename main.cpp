#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <regex>
#include <string>
#include <unordered_set>


//first task
class Input {
 public:
  std::list<std::string> operator>>(std::ifstream &attend) {
    std::list<std::string> list;
    std::copy(std::istream_iterator<std::string> (attend), std::istream_iterator<std::string> (), std::back_inserter(list));
    return list;
  }
};

//fifth task
class Second_Sorting {
 public:
  std::string name;
  std::string name1;
  std::string ID;
  Second_Sorting(std::string &_name, std::string &_name1, const std::string &_name2 = "") : name(_name), name1(_name1), ID(_name2) {
  };
  friend bool operator>(Second_Sorting &str1, Second_Sorting &str2);
  friend bool operator==(const Second_Sorting &str1, const Second_Sorting &str2);
  friend std::ostream& operator<<(std::ostream& out, Second_Sorting &str);
};

std::ostream& operator<<(std::ostream& out, Second_Sorting &str) {
  out << str.name;
  return out;
}

bool operator==(const Second_Sorting &str1, const Second_Sorting &str2) {
  return str1.name1 == str2.name1;
}

bool operator>(Second_Sorting &str1, Second_Sorting &str2) {
  int compare = 0;
  for(int i = 0, j = 0; (i < str1.name.length() && j < str2.name.length()); ++i, ++j) {
    if (str1.name[i] == str2.name[j]){
      compare = 0;
      continue;
    }
    if (str1.name[i] > str2.name[j]){
      compare = 1;
      break;
    }
    if (str1.name[i] < str2.name[j]){
      compare = -1;
      break;
    }
  }
  if ((str1.name.length() > str2.name.length()) && (compare == 0)) {
    compare = 1;
  }
  if ((str1.name.length() < str2.name.length()) && (compare == 0)) {
    compare = -1;
  }
  switch (compare) {
    case 0: return false;
    case 1: return true;
    case -1: return false;
  }
}

//seventh task
struct StringHash {
  size_t operator()(const Second_Sorting &st) const {
//    std::regex reg("(\\D+)(\\s)(\\D+)(\\s)(\\D+)(\\s)(\\D+)(\\s)(\\d+)(\\s)(kursa)(\\s)(\\d+)");
//    std::string hashing = std::regex_replace(st.name1, reg, "$13");
//    const char* hash = hashing.c_str();
//    int h = atoi(hash);
//    return h ^ (h << 4);
  std::string hash;
  for (int i = 0; i < st.name1.size(); ++i) {
    int symbol1 = st.name1[i];
    char symbol2 = symbol1;
    hash += symbol2;
  }
  const char* hashing = hash.c_str();
  return atoi(hashing);
  }
};

struct Compare{
  bool operator()(const Second_Sorting &ptr1,
                  const Second_Sorting &ptr2) const {
    return ptr1 == ptr2;
  }
};


int main() {
  //first task
  std::ifstream attendant("G:\\labs\\lab 1 - 2 sem\\L1_ANSI.txt");
  std::list<std::string> the_list;
  if (!attendant.is_open()) {
    std::cout << "The file is not found.";
    return 0;
  }
  Input in;
  the_list = in >> attendant;
  //second task
  std::vector<std::string> new_list;
  for (auto elem : the_list) {
    std::regex reg_one("(\\D+)(\\d+)(\\D+)(\\d+)(\\D+)(\\d+)(\\D+)(\\d+)(\\D+)(kursa)(\\d+)");
    std::string elem1 = std::regex_replace(elem, reg_one, "$1 $3 $5 $7 $8 $10 $11");
    for (int i = 0; i < elem1.size(); ++i) {
      if (isdigit(elem1[i])) {
        if(isdigit(elem1[i + 3])) {
          elem1.erase(i, 3);
          break;
        }  else {
          elem1.erase(i, 2);
          break;
        }
      }
    }
    int k = elem1.size();
    if(isdigit(elem1[k - 10]) && !isdigit(elem1[k - 11])){
      elem1.erase(k - 10, 2);
    } else {
      elem1.erase(k - 11, 3);
    }
    new_list.push_back(elem1);
  }
  for (auto el : new_list) {
    std::cout << el << std::endl;
  }
  //third task
  std::vector<std::shared_ptr<std::string>> attend_ptrs;
  for (auto element : new_list) {
    auto ptr = std::make_shared<std::string>(element);
    attend_ptrs.push_back(ptr);
  }
  //fourth task
  int number;
  for (int i = 0; ; ++i) {
    std::cout << "Please, chose a number for minimal accepted course(from 1 to 3):" << std::endl;
    std::cin >> number;
    if (number != 1 && number != 2 && number != 3) {
      std::cout << "This number is not accepted." << std::endl;
      continue;
    } else {
      break;
    }
  }
  for (int i = 1; i < 7; ++i) {
    for (int l = 0; l < new_list.size(); ++l) {
      std::string str = new_list[l];
      switch(i) {
        case 1:
          if (str.find("student 1 kursa") != std::string::npos) {
            new_list.erase(new_list.begin() + l);
            new_list.push_back(str);
          }
          break;
        case 2:
          if (str.find("student 2 kursa") != std::string::npos) {
            new_list.erase(new_list.begin() + l);
            new_list.push_back(str);
          }
          break;
        case 3:
          if (str.find("student 3 kursa") != std::string::npos) {
            new_list.erase(new_list.begin() + l);
            new_list.push_back(str);
          }
          break;
        case 4:
          if (str.find("student 4 kursa") != std::string::npos) {
            new_list.erase(new_list.begin() + l);
            new_list.push_back(str);
          }
          break;
        case 5:
          if (str.find("magistrant 1 kursa") != std::string::npos) {
            new_list.erase(new_list.begin() + l);
            new_list.push_back(str);
          }
          break;
        case 6:
          if (str.find("magistrant 2 kursa") != std::string::npos) {
            new_list.erase(new_list.begin() + l);
            new_list.push_back(str);
          }
          break;
      }
    }
  }
  std::vector<std::string> first_sort;
  std::for_each(new_list.begin(), new_list.end(), [&number, &first_sort](std::string &st){ switch(number) {
    case 1 :
      if (st.find("student 1 kursa") == std::string::npos) {
        first_sort.push_back(st);
      }
      break;
    case 2:if (st.find("student 1 kursa") == std::string::npos &&
    st.find("student 2 kursa") == std::string::npos) {
        first_sort.push_back(st);
      }
      break;
    case 3: if (st.find("student 1 kursa") == std::string::npos &&
          st.find("student 2 kursa") == std::string::npos &&
          st.find("student 3 kursa") == std::string::npos) {
        first_sort.push_back(st);
      }
      break;
  } });
  //fifth task
  std::vector<Second_Sorting> second_sort;
  for (auto stroka : first_sort) {
    std::regex reg("(\\D+)(\\s)(\\D+)(\\s)(\\D+)(\\s)(\\D+)(\\s)(\\d+)(\\s)(kursa)(\\s)(\\d+)");
    std::string name1 = std::regex_replace(stroka, reg, "$1 $3 $5");
    std::string name2 = std::regex_replace(stroka, reg, "$13");
    Second_Sorting new_string (stroka, name1, name2);
    second_sort.push_back(new_string);
  }
  std::sort(second_sort.begin(),second_sort.end(),[](Second_Sorting &ss1, Second_Sorting &ss2) {return ss1 > ss2; });
  std::list<std::string> final_list;
  for (auto str : second_sort) {
    final_list.push_front(str.name);
  }
  //sixth task
  std::copy(final_list.begin(), final_list.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  std::cout << std::endl;
  //seventh task
  std::unordered_set<Second_Sorting, StringHash, Compare> Final;
  for (auto str : second_sort) {
    Final.insert(str);
  }
  for ( ; ; ) {
    std::cout << "Please, enter your full name(Surname, First Name, Second Name):" << std::endl;
    std::string Name1, Name2, Name3;
    std::cin >> Name1;
    if (Name1 == "exit") {
      return 0;
    }
    std::cin >> Name2 >> Name3;
    std::cout << std::endl;
    std::string Name = Name1 + " " + Name2 + " " + Name3;
    Second_Sorting YourName(Name, Name);
    if (Final.find(YourName) != Final.end()) {
      std::cout << Final.find(YourName)->ID << std::endl;
    } else {
      std::cout << "There is no such person." << std::endl;
    }
  }
}
