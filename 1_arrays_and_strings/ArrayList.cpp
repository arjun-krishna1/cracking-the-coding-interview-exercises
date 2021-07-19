#include <iostream>
#include <memory>
#include <stdio.h>

template <typename T> class ArrayList {
public:
  ArrayList(int size1) {
    size = size1;
    data.reset(new T[size]);
  }

  void print() {

    for (int i = 0; i < length; i++) {
      std::cout << data[i] << ", "; 
    }
    printf("\n%d used out of %d\n\n", length, size);
  }

  void push(int newVal) {
    if (length >= size) {
      doubleSize();
    }
    data[length] = newVal;
    length++;
  }

private:
  int size;
  int length;
  std::unique_ptr<T[]> data;

  void doubleSize() {
    int newSize = size * 2;
    std::unique_ptr<T[]> newData(new T[newSize]);

    for (int i = 0; i < length; i++) {
      newData[i] = data[i];
    }

    printf("ArrayList memory limit reached\nDoubling size from %d to %d\n",
           size, newSize);
    data = std::move(newData);
    size = newSize;
  }
};

int main() {
  ArrayList <int> arr(10);
  arr.print();

  // fill up to limit
  for (int i = 0; i < 10; i++) {
    arr.push(i);
    arr.print();
  }

   
  // fill past limit, so it doubles it's size
  for (int i = 0; i < 10; i++) {
    arr.push(i);
    arr.print();
  }

   
  // fill past limit again, so it soubles size multiple times
  for (int i = 0; i < 100; i++) {
    arr.push(i);
    arr.print();
  }
  
  return 0;
}
