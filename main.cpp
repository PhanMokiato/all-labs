#include <iostream>
#include "bidirectional_list_on_array.h"
#include <vector>
#include "file_reader.h"
#include "word_card.h"
int main() {
  BiDirectionalListOnArray<int> nums;
  nums.PushBack(3);
  nums.PushBack(5);
  nums.PushBack(3);
  nums.PushBack(-7);
  std::cout << "New list:" << std::endl;
  nums.Print();
  std::cout << "New lists:" << std::endl;
  nums.PushFront(4);
  nums.Print();
  nums.PushBack(-128);
  nums.Print();
  std::cout << "New lists:" << std::endl;
  nums.PopBack();
  nums.Print();
  nums.PopFront();
  nums.Print();
  std::cout << "First 3 stands with this index:" << std::endl;
  std::cout << nums.Find(3) << std::endl;
  std::cout << "This number stands with index [3]:" << std::endl;
  std::cout << nums[3] << std::endl;
  nums.InsertAfter(1, 6);
  nums.InsertBefore(1, 4);
  std::cout << "New list:" << std::endl;
  nums.Print();
  std::vector<int> three = nums.FindAll(5);
  std::cout << "All 3 stand with this index:" << std::endl;
  for (auto elem : three) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  nums.Print();
  std::vector<int> vec = nums.ToVector();
  std::cout << "This one is vector:" << std::endl;
  for (auto elem : vec) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  std::cout << "The list's size is: " << nums.Size() << std::endl;
  std::cout << "The front is " << *nums.Front() << std::endl;
  std::cout << "The back is " << *nums.Back() << std::endl;
  BiDirectionalListOnArray<int> nums2(nums);
  std::cout << "New list:" << std::endl;
  nums2.Print();
  if (nums2 == nums) {
    std::cout << "These lists are equal." << std::endl;
  }
  nums2.PopBack();
  nums2.PushBack(123);
  std::cout << "New list:" << std::endl;
  nums2.Print();
  if (nums2 != nums) {
    std::cout << "These lists aren't equal." << std::endl;
  }
  BiDirectionalListOnArray<int> nums3;
  if (nums3.IsEmpty()) {
    std::cout << "There is a new list and it is empty." << std::endl;
  }
  nums3 = nums;
  nums3.PopBack();
  nums3.PopFront();
  std::cout << "New list:" << std::endl;
  nums3.Print();
  if (nums3 < nums) {
    std::cout << "The new list is smaller." << std::endl;
  }
  if (nums > nums3) {
    std::cout << "The old list is bigger." << std::endl;
  }
  BiDirectionalListOnArray<int> nums4 {1, 2, 3, 4, 5, 6, 7, 8, 9};
//  FileReader reading;
//  std::vector<std::string> lines = reading.ReadLines("new_text");
//  for (auto elem : lines) {
//    std::cout << elem << std::endl;
//  }
//  std::vector<std::string> words = reading.ReadWords("new_text");
//  for (auto elem : words) {
//    std::cout << elem << std::endl;
//  }
  WordCard word1;
  WordCard word2("Happy");
  WordCard word3(word2);
  std::cout << word2.GetWord() << word3.GetCounter() << std::endl;
  if (word2 == word3) {
    std::cout << "These word cards are alike." << std::endl;
  }
  word3.IncCounter();
  std::cout << word3.GetCounter() << std::endl;
  if (word2 != word3) {
    std::cout << "These word cards are different." << std::endl;
  }
  if (word2 < word3) {
    std::cout << "Second word card has smaller counter now." << std::endl;
  }
  return 0;
}
