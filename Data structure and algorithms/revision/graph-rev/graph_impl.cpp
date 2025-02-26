#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
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

bool detectCycleDFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int node, int currNodeParent){
  visited[node] = true;

  for(int i = 0; i < adj[node].size(); i++){
    if(adj[node][i] == currNodeParent) continue;
    if(visited[adj[node][i]]) return true;
    if(detectCycleDFS(adj, visited, adj[node][i], node))
    return true;
  }
  return false;
}
bool detectCycleInUndirected(int n, unordered_map<int, vector<int>> &adj){
  vector<bool> visited(n, false);
  bool ans = false;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      ans = ans || detectCycleDFS(adj, visited, i, -1);
    }
  }
  return ans;
}

bool detectCycleUndirectedBFS(int n, unordered_map<int, vector<int>> &adj){
  queue<int> q;
  vector<int>parent(n, -1);
  vector<bool> visited(n, 0);
  
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      q.push(i);
      visited[i] = true;
      while(!q.empty()){
        int node = q.front(); q.pop();
        for(int j = 0; j < adj[node].size(); j++){
          if(parent[node] == adj[node][j]) continue;
          if(visited[adj[node][j]]) return true;
          q.push(adj[node][j]);
          visited[adj[node][j]] = true;
          parent[adj[node][j]] = node;
        }
      }
    }
  }
  return false;
}

void topoDFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, stack<int> &st, int node){
  visited[node] = true;
  for(int i = 0; i < adj[node].size(); i++){
    if(!visited[adj[node][i]]){
      topoDFS(adj, visited, st, adj[node][i]);
    }
  }
  st.push(node);
}
vector<int> topologicalSort1(int n, unordered_map<int, vector<int>> &adj){
  stack<int> st;
  vector<bool> visited(n, false);
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      topoDFS(adj, visited, st, i);
    }
  }
  vector<int> ans;
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}

//Kahn's algorithm
vector<int> topologicalSortBFS(int n, unordered_map<int, vector<int>> &adj){
  vector<int> indeg(n, 0);
  queue<int> q;
  vector<int> ans;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < adj[i].size(); j++){
      indeg[adj[i][j]]++;
    }
  }

  for(int i = 0; i < n; i++){
    if(indeg[i] == 0) q.push(i);
  }

  while(!q.empty()){
    int node = q.front(); q.pop();
    ans.push_back(node);
    for(int i = 0; i < adj[node].size(); i++){
      indeg[adj[node][i]]--;
      if(indeg[adj[node][i]] == 0) q.push(adj[node][i]);
    }
  }

  return ans;
}

bool detectCycleDirectedSolve(unordered_map<int, vector<int>> &adj, vector<bool> &path, vector<bool> &visited, int node){
  path[node] = true;
  visited[node] = true;
  for(int i = 0; i < adj[node].size(); i++){
    if(path[adj[node][i]]){
      return true;
    }
    //always check this after checking path, this is for not visiting any node twice
    if(visited[adj[node][i]]) continue;
    if(detectCycleDirectedSolve(adj, path, visited, adj[node][i])){
      return true;
    }
  }
  path[node] = false;
  return false;
}
bool detectCycleDirectedGraph(int n, unordered_map<int, vector<int>> &adj){
  vector<bool> path(n, false);
  vector<bool> visited(n, false);
  bool ans = false;
  for(int i = 0; i < n; i++){
    ans = ans || detectCycleDirectedSolve(adj, path, visited, i);
  }

  return ans;
}

bool detectCycleDirectedGraphKahnAlgo(int n, unordered_map<int, vector<int>> &adj){
  int count = 0;
  queue<int> q;
  vector<int> indeg(n, 0);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < adj[i].size(); j++){
      indeg[adj[i][j]]++;
    }
  }

  for(int i = 0; i < n; i++){
    if(indeg[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int node = q.front();
    q.pop();
    count++;
    for(int i = 0; i < adj[node].size(); i++){
      indeg[adj[node][i]]--;
      if(indeg[adj[node][i]] == 0){
        q.push(adj[node][i]);
      }
    }
  }

  return count != n;
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
  // vector<int>ans = dfsTravsersal(n, gp.adjList);
  // printVector(ans);

  // cout<<detectCycleInUndirected(n, gp.adjList)<<endl;

  // vector<int> topoAns = topologicalSort1(n, gp.adjList);
  vector<int> topoAns = topologicalSortBFS(n, gp.adjList);
  printVector(topoAns);
  return 0;
}