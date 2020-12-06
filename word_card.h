//
// Created by Zver on 05.12.2020.
//

#ifndef KR2_GR4_MOKIEVEC_DASHA_WORD_CARD_H
#define KR2_GR4_MOKIEVEC_DASHA_WORD_CARD_H

#include <string>
#include <iostream>

using std::string;
class WordCard {
 public:
  WordCard() {
    word_ = "";
    counter_ = 0;
  }
  WordCard(string word) {
    word_ = word;
    counter_ = 1;
  }

  WordCard(WordCard &word) : word_(word.word_), counter_(word.counter_) {};
  WordCard &operator=(WordCard other) {
    word_ = other.word_;
    counter_ = other.counter_;
    return *this;
  };

  WordCard(WordCard &&other) noexcept {
    word_ = other.word_;
    counter_ = other.counter_;
    other.word_ = "";
    other.counter_ = 0;
  }
  WordCard &operator=(WordCard &&other) noexcept {
    word_ = other.word_;
    counter_ = other.counter_;
    other.word_ = "";
    other.counter_ = 0;
    return *this;
  }

  ~WordCard() {
  };

  string GetWord() {
    return word_;
  };
  size_t GetCounter() {
    return counter_;
  };

  void IncCounter() {
    ++counter_;
  };

  bool operator==(WordCard &other) {
    return word_ == other.word_ && counter_ == other.counter_;
  }
  bool operator!=(WordCard &other) {
    return word_ != other.word_ || counter_ != other.counter_;
  }

  bool operator<(WordCard &second) {
    return counter_ < second.counter_;
  }

 private:
  string word_;
  size_t counter_;
};

#endif //KR2_GR4_MOKIEVEC_DASHA_WORD_CARD_H
