#include <iostream>
using namespace std;
#define UPPER 10000000

long int mem_map[UPPER] = {};

int calcFib(int i){
  if(mem_map[i] == 0){
    if(i<=1)
      mem_map[i] = i;
    else
      mem_map[i] = calcFib(i - 1) + calcFib(i - 2);
  }
  return mem_map[i];

}

int main() {
  int fib = calcFib(20);
  cout << fib;
  return 0;
}

