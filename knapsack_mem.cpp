#include <iostream>
using namespace std;

int weight[] = {0, 10, 20, 30};
int value[] = {0, 100, 50, 1};

class Knapsack {
public:
  int **mem_map;
  int capacity = 0;
  int items = 0;
  Knapsack(int capacity, int items) {
    this->mem_map = new int *[items + 1];
    this->capacity = capacity;
    this->items = items;

    // fill table w/ zeros
    for (int i = 0; i < items + 1; i++) {
      this->mem_map[i] = new int[capacity + 1]{0};
    }
  }

  int determine() {
    for (int i = 1; i < items + 1; i++) {
      for (int j = 1; j < capacity + 1; j++) {
        int excluded_item = mem_map[i - 1][j];
        int included_item = 0;

        if (weight[i] <= capacity) {
          if (j - weight[i] < 0) {
            included_item = mem_map[i - 1][j];
          } else {
            // include the item, add to previous item total
            included_item = value[i] + mem_map[i - 1][j - weight[i]];
          }
        }
        // pick the more valuable option to fill table with
        // ie if we had weight 4 w/ value 10 and weight 4 w/ value 100, choose
        // 100
        mem_map[i][j] = max(included_item, excluded_item);
      }
    }
    // return the value of item # of items, and capacity # of weight
    return mem_map[items][capacity];
  }
};

int main() {
  Knapsack knapsack(100, 3);
  cout << knapsack.determine();
  return 0;
}
