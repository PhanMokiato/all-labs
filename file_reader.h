//
// Created by Zver on 05.12.2020.
//

#ifndef KR2_GR4_MOKIEVEC_DASHA_FILE_READER_H
#define KR2_GR4_MOKIEVEC_DASHA_FILE_READER_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cctype>
class FileReader {
 public:
  std::vector<std::string> ReadLines(const std::string &file_path) {
    std::ifstream read(file_path);
    if (!read.is_open()) {
      std::cout << "This file isn't open." << std::endl;
    }
    std::vector<std::string> lines;
    while (!read.eof()) {
      std::string line;
      getline(read, line, '\n');
      lines.push_back(line);
    }
    read.close();
    return lines;
  }
  std::vector<std::string> ReadWords(const std::string &file_path) {
    std::ifstream read(file_path);
    if (!read.is_open()) {
      std::cout << "This file isn't open." << std::endl;
    }
    std::vector<std::string> words;
    while (!read.eof()) {
      std::string line;
      getline(read, line, '\n');
      std::string word;
      for (int i = 0; i < line.length(); ++i){
        if(isalnum(line[i])) {
          word = word + line[i];
        }
        if (!isalnum(line[i]) && !word.empty()) {
          words.push_back(word);
          word = "";
        }
        if (!isalnum(line[i]) && word.empty()) {
          continue;
        }
      }
    }
    read.close();
    return words;
  }
};

#endif //KR2_GR4_MOKIEVEC_DASHA_FILE_READER_H
