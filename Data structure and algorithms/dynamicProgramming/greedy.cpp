#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void printVector(vector<int> &vec){
  cout<<endl;
  int size = vec.size();
  for(int i = 0; i < size; i++){
    cout<<vec[i]<<" ";
  }
  cout<<endl;
}

pair<int, int> candyStore(vector<int> &candies, int k){
  sort(candies.begin(), candies.end());
  int size = candies.size();
  int mini = 0;
  int buy = 0, free = size - 1;

  while(buy <= free){
    mini = mini + candies[buy];
    buy++;
    free = free - k;
  }

  int maxi = 0;
  buy = size - 1, free = 0;

  while(free <= buy){
    maxi = maxi + candies[buy];
    buy--;
    free = free + k;
  }

  return {mini, maxi};
}

int minimumDaysToBuy(int S, int N, int M){
  int sunday = S/7;
  int buyingDays = S - sunday;
  int ans = 0, totalFood = S * M;

  if(totalFood % N == 0)
    ans = totalFood/N;
  else
    ans = totalFood/N + 1;

  return ans <= buyingDays ? ans : -1;
}

string reverseWord(string str){
  int size = str.length();
  string ans = "";
  string temp = "";

  for(int i = size - 1; i >= 0; i--){
    if(str[i] == '.'){
      reverse(temp.begin(), temp.end());
      ans = ans + temp;
      ans.push_back('.');
      temp = "";
    }else{
      temp.push_back(str[i]);
    }
  }

  reverse(temp.begin(), temp.end());
  ans = ans + temp;

  return ans;
}

int chocolateDistribution(vector<int> choco, int students){
  int size = choco.size();
  sort(choco.begin(), choco.end());
  int i = 0, j = students - 1;
  int mini = INT32_MAX;
  while(j < size){
    int diff = choco[j++] - choco[i++];
    mini = min(mini, diff);
  }

  return mini;
}

long long minCostToJoinRopes(vector<long long> &arr){
  long long n = arr.size();
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for(int i = 0; i < n; i++){
    pq.push(arr[i]);
  }

  long long mini = 0;
  while(pq.size() > 1){
    long long first = pq.top();
    pq.pop();

    long long second = pq.top();
    pq.pop();

    long long added = first + second;
    mini += added;
    pq.push(added);
  }

  return mini;
}

//hufman encoding


int main() {
  // vector<int> candy = {4, 3, 1, 2};
  // pair<int, int> ans = candyStore(candy, 2);
  // cout<<"Min : "<<ans.first<<" Max : "<<ans.second<<endl;

  // string str;
  // cout<<"Enter a string : ";
  // cin>>str;
  // cout<<reverseWord(str)<<endl;

  vector<long long> ropes = {2, 5, 1, 5};
  minCostToJoinRopes(ropes);
  return 0;
}
