#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

void printVector(vector<int> &v){
  int size = v.size();
  cout<<endl;
  for(int i = 0; i < size; i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

template <typename T>
class Graph{
  public:
  unordered_map<T, vector<T>> adjList;

  void addEdge(T u, T v, bool isDirected){
    adjList[u].push_back(v);
    if(!isDirected){
      adjList[v].push_back(u);
    }
  }

  void printGraph(){
    for(auto i:adjList){
      cout<<i.first<<" -> ";
      for(auto j : i.second){
        cout<<j<<", ";
      }cout<<endl;
    }
  }
};

vector<int> bfsTraversal(int n, unordered_map<int, vector<int>> &adjList){
  vector<int> ans;
  queue<int> q;
  unordered_map<int, bool> visited;

  for(int i = 0; i < n; i++){
    if(!visited[i]){
      q.push(i);
      visited[i] = true;
      while(!q.empty()){
        int front = q.front(); q.pop();
        ans.push_back(front);
        for(int j = 0; j < adjList[front].size(); j++){
          if(!visited[adjList[front][j]]){
            q.push(adjList[front][j]);
            visited[adjList[front][j]] = true;
          }
        }
      }
    }
  }
  return ans;
}

void dfsSolve(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int i){
  if(!visited[i]){
    ans.push_back(i);
    visited[i] = true;
  }
  for(int j = 0; j < adj[i].size(); j++){
    if(!visited[j]) dfsSolve(adj, visited, ans, j);
  }
}

vector<int> dfsTravsersal(int n, unordered_map<int, vector<int>> &adj){
  vector<int> ans;
  unordered_map<int, bool> visited;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      dfsSolve(adj, visited, ans, i);
    }
  }
  return ans;
}

int main() {
  int n, m;
  bool isDirected;
  cout<<"Enter number of vertices(Node) : ";
  cin>>n;
  cout<<"Enter number of edges : ";
  cin>>m;
  cout<<"Directed or not (1/0) : ";
  cin>>isDirected;
  cout<<"Now enter all edges information"<<endl;

  Graph<int>gp;
  for(int i = 0; i < m; i++){
    int u, v;
    cin>>u>>v;
    gp.addEdge(u, v, isDirected);
  }

  gp.printGraph();
  // vector<int>ans = bfsTraversal(n, gp.adjList);
  vector<int>ans = dfsTravsersal(n, gp.adjList);
  printVector(ans);
  return 0;
}