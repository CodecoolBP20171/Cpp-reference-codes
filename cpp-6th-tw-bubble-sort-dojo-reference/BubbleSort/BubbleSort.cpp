#include "stdafx.h"
#include <vector>
#include <iostream>

void bubblesort(std::vector<int>& v)
{
  unsigned sortedElements = 0;
  bool swapHappened = false;

  do{
    swapHappened = false;
    for(unsigned i = 0; i < v.size() - 1 - sortedElements; ++i){
      if(v[i] > v[i + 1]) {
        std::swap(v[i], v[i + 1]);
        swapHappened = true;
      }
    }
    ++sortedElements;
  }while(swapHappened);
}

void print(const std::vector<int>& v)
{
  for (const int& item : v) {
      std::cout << item << " ";
  }
}

int _tmain(int argc, _TCHAR* argv[])
{
  std::vector<int> v = {2, 4, 1, 32, 0, 7, 3, 9, 1, 100};
  std::cout << "Before: " << std::endl;
  print(v);

  bubblesort(v);

  std::cout << std::endl << "After: " << std::endl;
  print(v);
  
  char c;
  std::cin >> c;

  return 0;
}

