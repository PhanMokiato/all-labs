//
// Created by Zver on 05.12.2020.
//

#ifndef KR2_GR4_MOKIEVEC_DASHA_VOCABULARY_H
#define KR2_GR4_MOKIEVEC_DASHA_VOCABULARY_H

#include <string>
#include <map>

#include "bidirectional_list_on_array.h"
#include "word_card.h"

class Vocabulary {
 public:
  void ReadFileToCards(std::string file_path) {}
  WordCard *ConvertStringToWordCard(string str) {
    WordCard Str(str);
    return &Str;
  };
  void MakeFrequencyVocab();
  void SortWords();
  std::map<string, size_t> CopyToMap(){
    std::map<std::string, size_t> empty;
    return empty;
  }

 private:
  BiDirectionalListOnArray<WordCard *> list_word_cards;

};

#endif //KR2_GR4_MOKIEVEC_DASHA_VOCABULARY_H
