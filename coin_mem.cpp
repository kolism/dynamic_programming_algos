#include<bits/stdc++.h>
using namespace std;



int calcCoin (vector<int>& coins, int total ) 
{   
  if(total <= 0 || coins.size() <= 0)
  {
      return 0;
  }
  int coin = coins[coins.size() - 1];
  vector<int> mem_map(total+1,0);
  mem_map[0] = 1; 
  
  for(int i=0; i<coins.size();i++){
    for(int j=coins[i]; j<=total; j++){
      mem_map[j] += mem_map[j-coins[i]];
    }
  }
  return mem_map[total];


}


int main() {
  vector<int> coins={1,5,10,25};
  int numCoins = calcCoin(coins,50);
  cout << numCoins;
  return 0;
}

