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
class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};

class cmp{
  public:
  bool operator()(Node* a, Node* b){
    return a->data > b->data;
  }
};

void solveHuffManEncodes(Node* root, vector<string> &ans, string temp){
  if(root->left == NULL && root->right == NULL){
    ans.push_back(temp);
    return;
  }

  solveHuffManEncodes(root->left, ans, temp+'0');
  solveHuffManEncodes(root->right, ans, temp+'1');
}
vector<string> huffmanCodes(string S,vector<int> f,int N){
  priority_queue<Node*, vector<Node*>, cmp> pq;
  for(int i = 0; i < N; i++){
    Node* node = new Node(f[i]);
    pq.push(node);
  }

  while(pq.size() > 1){
    Node* left = pq.top();
    pq.pop();
    Node* right = pq.top();
    pq.pop();

    Node* addedNode = new Node(left->data + right->data);
    addedNode->left = left;
    addedNode->right = right;

    pq.push(addedNode);
  }
  vector<string> ans;
  string temp = "";
  solveHuffManEncodes(pq.top(), ans, temp);
  return ans;
}

struct Item{
  int value;
  int weight;
};
bool comparator(pair<double, Item>a, pair<double, Item> b){
  return a.first > b.first;
}
double fractionalKnapsack(int w, Item arr[], int n) {
  vector<pair<double, Item>> perUnitVal(n);
    for(int i = 0; i < n; i++){
      double perUnit = (1.0*arr[i].value)/arr[i].weight;
      pair<double, Item> p = make_pair(perUnit, arr[i]);
      perUnitVal.push_back(p);
    }
    sort(perUnitVal.begin(), perUnitVal.end(), comparator);
  
    double maxi = 0;
    for(int i = 0; i < n; i++){
      int perUnit = perUnitVal[i].first;
      Item item = perUnitVal[i].second;
      if(w < item.weight){
        maxi = maxi + (perUnit * w);
        w = 0;
      }else{
        maxi = maxi + item.value;
        w -= item.weight;
      }
    }
  return maxi;
}


struct Job { 
  int id;
  int dead;
  int profit;
};
bool myCmp(Job a, Job b){
  return a.profit > b.profit;
}    
vector<int> JobScheduling(Job arr[], int n){ 
  sort(arr, arr+n, myCmp);
  int maxDeadLine = INT32_MIN;
  for(int i = 0; i < n; i++){
    maxDeadLine = max(maxDeadLine, arr[i].dead);
  }
  
  vector<int> schedule(maxDeadLine+1, -1);
  int count = 0;
  int maxProfit = 0;
  
  for(int i = 0; i < n; i++){
    int currProfit = arr[i].profit;
    int currDead = arr[i].dead;
    int currId = arr[i].id;
    
    for(int k = currDead; k > 0; k--){
      if(schedule[k] == -1){
        count++;
        maxProfit += currProfit;
        schedule[k] = currId;
        break;
      }
    }
  }
  
  vector<int> ans;
  ans.push_back(count);
  ans.push_back(maxProfit);
  
  return ans;
} 


int main() {
  // vector<int> candy = {4, 3, 1, 2};
  // pair<int, int> ans = candyStore(candy, 2);
  // cout<<"Min : "<<ans.first<<" Max : "<<ans.second<<endl;

  // string str;
  // cout<<"Enter a string : ";
  // cin>>str;
  // cout<<reverseWord(str)<<endl;

  // vector<long long> ropes = {2, 5, 1, 5};
  // minCostToJoinRopes(ropes);
  vector<int> f = {5, 9, 12, 13, 16, 45};
  vector<string>ans = huffmanCodes("abcdef", f, 6);
  for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
