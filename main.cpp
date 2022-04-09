#include <iostream>

#include "buffered_channel.h"

int main() {
  BufferedChannel<int> bc(10);
  std::thread thr1([&]() {
    bc.Send(32);
    bc.Send(-44);
    bc.Recv();
  });
  std::thread thr2([&]() {
    bc.Send(129);
    bc.Send(70);
    bc.Recv();
    bc.Send(88);
    bc.Send(47);
    bc.Send(64);
  });
  thr1.join();
  thr2.join();
  return 0;
}
