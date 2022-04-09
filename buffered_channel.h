//
// Created by Zver on 08.04.2022.
//

#ifndef CHANNEL__BUFFERED_CHANNEL_H_
#define CHANNEL__BUFFERED_CHANNEL_H_


#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <queue>
#include <utility>


template<class T>
class BufferedChannel {
 public:
  explicit BufferedChannel(const int &size) {
    if (size > 0) {
      _buffer_size = size;
    } else {
      std::cout << "I can't create buffer with this size. Sorry, but 10 will have to do" << std::endl;
      _buffer_size = 10;
    }
  }

  BufferedChannel& operator=(BufferedChannel<T>&& bc)  noexcept {
    this->_values = bc._values;
    this->_buffer_size = bc._buffer_size;
    this->_closed = bc._closed;
    this->mutex = bc._mutex;
    this->_our_cv = bc._our_cv;
    delete bc;
    return *this;
  }

  BufferedChannel() : _buffer_size(10) {}

  void Send(T value) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::unique_lock<std::mutex> locker(_mutex);
    try {
      if (_closed) {
        throwException();
      }
        if (!_closed) {
          _our_cv.wait(locker, [&]() { return _values.size() < _buffer_size; });
          std::cout << "We are adding " << value << std::endl;
          _values.push(value);
        }
    } catch (std::runtime_error &error) {
      std::cout << error.what() << std::endl;
    }
  }

  void throwException() {
    throw std::runtime_error("You can't send elements anymore, because the channel is closed now.");
  }

  std::pair<T, bool> Recv() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::unique_lock<std::mutex> locker(_mutex);
    if (_closed && _values.empty()) {
      T default_value;
      return std::make_pair(default_value, _closed);
    }
    _our_cv.wait(locker, [&]() { return !_values.empty(); });
    T value = _values.front();
    _values.pop();
    std::cout << "We are deleting " << value << std::endl;
    return std::make_pair(value, _closed);
  }

  void Close() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "We are closing the channel" << std::endl;
    _closed = true;
    _our_cv.notify_all();
  }

 private:
  std::queue<T> _values;
  int _buffer_size = 0;
  bool _closed = false;
  std::mutex _mutex;
  std::condition_variable _our_cv;
};


#endif //CHANNEL__BUFFERED_CHANNEL_H_
