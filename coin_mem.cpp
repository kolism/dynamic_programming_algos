#include <bits/stdc++.h>
#include <map> // Include map
#include <string>

using namespace std;
#define UPPER 10000000

std::map<std::string, int> mem;

int coinChange(vector<int> &coins, int total) {
  std::string f = "";
  std::string keySrch = f.append(to_string(total));

  auto item = mem.find(keySrch);
  if (item != mem.end()) {
    return item->second;
  }

  if (total == 0 || coins.size() == 0) {
    return 0;
  } else if (total < 0) {
    return UPPER;
  }

  vector<int> results{};
  for (int i = 0; i < coins.size(); ++i) {
    results.push_back(coinChange(coins, total - coins[i]));
  }
  auto it = std::min_element(results.begin(), results.end());
  int resultIt = *it;
  int result = 1 + resultIt;

  mem.insert({keySrch, result});
  return result;
}

int main() {
  vector<int> coins = {1, 5, 10, 25};
  int numCoins = coinChange(coins, 24);
  cout << numCoins;
  return 0;
}
