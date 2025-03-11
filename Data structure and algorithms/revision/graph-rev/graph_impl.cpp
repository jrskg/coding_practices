#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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

bool isBipartiteBFS(int n, unordered_map<int, vector<int>> &adj){
  vector<int> color(n, -1);
  queue<int> q;

  for(int i = 0; i < n; i++){
    if(color[i] != -1) continue;
    color[i] = 0;
    q.push(i);
    while(!q.empty()){
      int node = q.front(); q.pop();
      for(int j = 0; j < adj[node].size(); j++){
        if(color[adj[node][j]] == -1){
          color[adj[node][j]] = color[node] == 0 ? 1 : 0;
          q.push(adj[node][j]);
        }

        if(color[adj[node][j]] == color[node]){
          return false;
        }
      }
    }
  }

  return true;
}

bool isBipartiteDFSSolve(unordered_map<int, vector<int>> &adj, vector<int> &color, int node){
  bool rem = true;
  for(int i = 0; i < adj[node].size(); i++){
    if(color[adj[node][i]] == -1){
      color[adj[node][i]] = color[node] == 0 ? 1 : 0;
      rem = rem && isBipartiteDFSSolve(adj, color, adj[node][i]);
    }
    if(color[adj[node][i]] == color[node]){
      return false;
    }
  }

  return rem;
}
bool isBipartiteDFS(int n, unordered_map<int, vector<int>> &adj){
  bool ans = true;
  vector<int> color(n, -1);
  for(int i = 0; i < n; i++){
    if(color[i] != -1) continue;
    color[i] = 0;
    ans = ans && isBipartiteDFSSolve(adj, color, i);
  }

  return ans;
}

bool isIndexValid(int row, int col, int rowN, int colN){
  return 
      (row > -1 && row < rowN) &&
      (col > -1 && col < colN);
}
int covidSpread(vector<vector<int>> &hospital){
  int rowN = hospital.size();
  int colN = hospital[0].size();
  int timer = 0;
  int direction[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
  };
  queue<pair<int, int>> q;
  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if(hospital[i][j] == 2){
        q.push({i, j});
      }
    }
  };
  q.push({-1, -1});

  while(!q.empty()){
    pair<int, int> node = q.front(); q.pop();
    if(node.first == -1 && node.second == -1){
      timer++;
      if(!q.empty()) q.push({-1, -1});
    }else{
      for(int i = 0; i < 4; i++){
        int newRow = node.first + direction[i][0];
        int newCol = node.second + direction[i][1];
        if(isIndexValid(newRow, newCol, rowN, colN) && hospital[newRow][newCol] == 1){
          q.push({newRow, newCol});
          hospital[newRow][newCol] = 2;
        }
      }
    }
  }

  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if(hospital[i][j] == 1){
        return -1;
      }
    }
  }

  return timer - 1;
}

int numIslands(vector<vector<char>> &grid){
  int rowN = grid.size();
  int colN = grid[0].size();
  int count = 0;
  int direction[8][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
    //this is for diagonal
    {-1, -1},
    {1, -1},
    {-1, 1},
    {1, 1},
  };

  queue<pair<int, int>> q;
  // initially i have used a visited array to keep track of visited node but later modified the original grid and changed the visited node from '1' -> '0'
  // vector<vector<bool>> visited(rowN, vector<bool>(colN, false));
  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if(grid[i][j] == '1'){
        q.push({i, j});
        grid[i][j] = '0'; //here modifying the original array
        count++;
        while(!q.empty()){
          pair<int, int> node = q.front(); q.pop();
          for(int k = 0; k < 8; k++){
            int newRow = node.first + direction[k][0];
            int newCol = node.second + direction[k][1];
            if(isIndexValid(newRow, newCol, rowN, colN) && grid[newRow][newCol] == '1'){
              q.push({newRow, newCol});
              grid[newRow][newCol] = '0';
            }
          }
        }
      }
    }
  }

  return count;
}

vector<vector<char>> replaceOwithX(vector<vector<char>> &grid){
  int rowN = grid.size();
  int colN = grid[0].size();
  int direction[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
  };

  queue<pair<int, int>> q;
  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if((i == 0 || j == 0 || i == rowN-1 || j == colN-1) && grid[i][j] == 'O'){
        q.push({i, j});
        grid[i][j] = 'T';
        while(!q.empty()){
          pair<int, int> node = q.front(); q.pop();
          for(int k = 0; k < 4; k++){
            int newRow = node.first + direction[k][0];
            int newCol = node.second + direction[k][1];
            if(isIndexValid(newRow, newCol, rowN, colN) && grid[newRow][newCol] == 'O'){
              q.push({newRow, newCol});
              grid[newRow][newCol] = 'T';
            }
          }
        }
      }
    }
  }

  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if(grid[i][j] == 'O'){
        grid[i][j] = 'X';
      }else if(grid[i][j] == 'T'){
        grid[i][j] = 'O';
      }
    }
  }
  return grid;
}

int rottenOranges(vector<vector<int>> &grid){
  int rowN = grid.size();
  int colN = grid[0].size();
  int direction[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
  };
  queue<pair<int, int>> q;
  int timer = 0;
  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if(grid[i][j] == 2){
        q.push({i, j});
      }
    }
  }
  q.push({-1, -1});

  while(!q.empty()){
    pair<int, int> node = q.front(); q.pop();
    if(node.first == -1 && node.second == -1){
      timer++;
      if(!q.empty()) q.push({-1, -1});
    }
    else{
      for(int i = 0; i < 4; i++){
        int newRow = node.first + direction[i][0];
        int newCol = node.second + direction[i][1];
        if(isIndexValid(newRow, newCol, rowN, colN) && grid[newRow][newCol] == 1){
          grid[newRow][newCol] = 2;
          q.push({newRow, newCol});
        }
      }
    }
  }

  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if(grid[i][j] == 1){
        return -1;
      }
    }
  }
  return timer - 1;
}

int totalXShapes(vector<vector<char>> &grid){
  //same as numIslands but here diagonals are not included
  int rowN = grid.size();
  int colN = grid[0].size();
  queue<pair<int, int>> q;
  int directions[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
  };
  int count = 0;

  for(int i = 0; i < rowN; i++){
    for(int j = 0; j < colN; j++){
      if(grid[i][j] == 'X'){
        q.push({i, j});
        count++;
        grid[i][j] = 'O';
        while(!q.empty()){
          pair<int, int> node = q.front(); q.pop();
          for(int k = 0; k < 4; k++){
            int newRow = node.first + directions[k][0];
            int newCol = node.second + directions[k][1];
            if(isIndexValid(newRow, newCol, rowN, colN) && grid[newRow][newCol] == 'X'){
              q.push({newRow, newCol});
              grid[newRow][newCol] = 'O';
            }
          }
        }
      }
    }
  }
  return count;
}

int numProvinces(vector<vector<int>> &mat){
  int rowN = mat.size();
  vector<bool> visited(rowN, false);
  queue<int> q;

  int ans = 0;
  for(int i = 0; i < rowN; i++){
    if(!visited[i]){
      q.push(i);
      visited[i] = true;
      ans++;
      while(!q.empty()){
        int node = q.front(); q.pop();
        for(int j = 0; j < rowN; j++){
          if(mat[node][j] == 1 && !visited[j]){
            q.push(j);
            visited[j] = true;
          }
        }
      }
    }
  }
  return ans;
}

bool prerequisiteTask(int n, int p, vector<pair<int, int>> &pre){
  vector<vector<int>> adj(n);
  vector<int> indeg(n, 0);

  for(int i = 0; i < p; i++){
    adj[pre[i].second].push_back(pre[i].first);
    indeg[pre[i].first]++;
  }
  queue<int> q;
  for(int i = 0; i < n; i++){
    if(indeg[i] == 0){
      q.push(i);
    }
  }

  int count = 0;
  while(!q.empty()){
    int node = q.front(); q.pop();
    count++;
    for(int i = 0; i < adj[node].size(); i++){
      indeg[adj[node][i]]--;
      if(indeg[adj[node][i]] == 0){
        q.push(adj[node][i]);
      }
    }
  }

  return count == n;
}

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
  vector<vector<int>> adj(n);
  vector<int> indeg(n, 0);
  queue<int> q;
  vector<int> ans;
  for(int i = 0; i < m; i++){
    adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    indeg[prerequisites[i][0]]++;
  }

  for(int i = 0; i < n; i++){
    if(indeg[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int node = q.front(); q.pop();
    ans.push_back(node);
    for(int i = 0; i < adj[node].size(); i++){
      indeg[adj[node][i]]--;
      if(indeg[adj[node][i]] == 0){
        q.push(adj[node][i]);
      }
    }
  }
  if(ans.size() != n) return {};
  return ans;
}

bool dfsStr(unordered_map<char, vector<char>> &adj, unordered_map<char, bool> &visited, unordered_map<char, bool> &path, stack<char> &s, char node){
  visited[node] = true;
  path[node] = true;
  for(int i = 0; i < adj[node].size(); i++){
    if(path[adj[node][i]]) return true;
    if(visited[adj[node][i]]) continue;
    if(dfsStr(adj, visited, path, s, adj[node][i])){
      return true;
    }
  }
  s.push(node);
  path[node] = false;
  return false;
}
string findOrderAlien(vector<string> &words){
  //alien's dictionary
  unordered_map<char, vector<char>> adj;
  for(int i = 0; i < words.size(); i++){
    for(int j = 0; j < words[i].size(); j++){
      adj[words[i][j]];
    }
  }
  for(int i = 0; i < words.size()-1; i++){
    int j = 0, k = 0;
    string str1 = words[i], str2 = words[i+1];
    while(j < str1.size() && k < str2.size()){
      if(str1[j] != str2[k]){
        adj[str1[j]].push_back(str2[k]);
        break;
      }
      j++;k++;
    }
    if(k >= str2.size() && str1.size() > str2.size()){
      return "";
    }
  }
  bool isCycle = false;
  unordered_map<char, bool>visited;
  unordered_map<char, bool>path;
  stack<char> s;
  for(auto c: adj){
    if(!visited[c.first]){
      isCycle = isCycle || dfsStr(adj, visited, path, s, c.first);
    }
  }

  if(isCycle) return "";

  string ans = "";
  while(!s.empty()){
    ans.push_back(s.top());
    s.pop();
  }

  return ans;
}

string findOrderAlienKahn(vector<string> &words){
  unordered_map<char, vector<char>> adj;
  unordered_map<char, int> indeg;
  for(int i = 0; i < words.size(); i++){
    for(int j = 0; j < words[i].size(); j++){
      adj[words[i][j]];
      indeg[words[i][j]] = 0;
    }
  }
  
  for(int i = 0; i < words.size()-1; i++){
    string str1 = words[i], str2 = words[i+1];
    int j = 0, k = 0;
    while(j < str1.size() && k < str2.size()){
      if(str1[j] != str2[k]){
        adj[str1[j]].push_back(str2[k]);
        indeg[str2[k]]++;
        break;
      }
      j++;k++;
    }
    if(k >= str2.size() && str1.size() > str2.size()) return "";
  }

  queue<char> q;
  for(auto i:indeg){
    if(i.second == 0){
      q.push(i.first);
    }
  }

  string ans = "";
  while(!q.empty()){
    char node = q.front(); q.pop();
    ans.push_back(node);
    for(int i = 0; i < adj[node].size(); i++){
      indeg[adj[node][i]]--;
      if(indeg[adj[node][i]] == 0){
        q.push(adj[node][i]);
      }
    }
  }

  return ans.size() != indeg.size() ? "" : ans;
}

int parallelCourse(int n, vector<vector<int>>& relations, vector<int>& time){
  //minimum time
  vector<vector<int>> adj(n+1);
  vector<int> indeg(n+1, 0);
  vector<int> completionTime(n+1, 0);
  for(int i = 0; i < relations.size(); i++){
    adj[relations[i][0]].push_back(relations[i][1]);
    indeg[relations[i][1]]++;
  }

  queue<int> q;
  for(int i = 1; i < n+1; i++){
    if(indeg[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int node = q.front(); q.pop();
    for(int i = 0; i < adj[node].size(); i++){
      indeg[adj[node][i]]--;
      completionTime[adj[node][i]] = max(completionTime[adj[node][i]], completionTime[node]+time[node-1]);
      if(indeg[adj[node][i]] == 0){
        q.push(adj[node][i]);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < n+1; i++){
    ans = max(ans, completionTime[i] + time[i-1]);
  }
  return ans;
}

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
  //undirected graph
  int n = adj.size();
  vector<int> ans(n, -1);
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(src);
  visited[src] = true;
  ans[src] = 0;

  while(!q.empty()){
    int node = q.front(); q.pop();
    for(int i = 0; i < adj[node].size(); i++){
      if(!visited[adj[node][i]]){
        q.push(adj[node][i]);
        visited[adj[node][i]] = true;
        ans[adj[node][i]] = ans[node] + 1;
      }
    }
  }

  return ans;
}

vector<int> shortestPath(vector<vector<int>>& adj, int src, int dest) {
  //undirected graph (getting actual path from src to dest)
  int n = adj.size();
  vector<int> parent(n, -1);
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(src);
  visited[src] = true;
  parent[src] = -1;

  while(!q.empty()){
    int node = q.front(); q.pop();
    for(int i = 0; i < adj[node].size(); i++){
      if(!visited[adj[node][i]]){
        q.push(adj[node][i]);
        visited[adj[node][i]] = true;
        parent[adj[node][i]] = node;
      }
    }
  }

  vector<int> ans;
  while(dest != -1){
    ans.push_back(dest);
    dest = parent[dest];
  }

  reverse(ans.begin(), ans.end());
  return ans;
}


vector<int> shortestPathDAG(int V, int E, vector<vector<int>>& edges) {
  //in directed acyclic graph with weight
  //NOTE:- It has TLE error
  vector<pair<int, int>> adj[V];
  for(int i = 0; i < E; i++){
    adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
  }
  vector<int> dist(V, -1);
  queue<int>q;
  q.push(0);
  dist[0] = 0;
  while(!q.empty()){
    int node = q.front(); q.pop();
    for(int i = 0; i < adj[node].size(); i++){
      q.push(adj[node][i].first);
      if(dist[adj[node][i].first] == -1){
        dist[adj[node][i].first] = dist[node] + adj[node][i].second;
      }else{
        dist[adj[node][i].first] = min(dist[adj[node][i].first], dist[node] + adj[node][i].second);
      }
    }
  }
  return dist;
}

void topoDFS(vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &s, int node){
  visited[node] = true;
  for(int i = 0; i < adj[node].size(); i++){
    if(!visited[adj[node][i].first]){
      topoDFS(adj, visited, s, adj[node][i].first);
    }
  }
  s.push(node);
}
vector<int> shortestPathDAG2(int V, int E, vector<vector<int>>& edges) {
  //in directed acyclic graph with weight
  //NOTE:- OPTIMIZED using TOPOLOGICAL
  vector<vector<pair<int, int>>> adj(V);
  for(int i = 0; i < E; i++){
    adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
  }
  vector<bool>visited(V, false);
  stack<int> s; //representing topological sort
  topoDFS(adj, visited, s, 0);

  vector<int> dist(V, __INT_MAX__);
  dist[s.top()] = 0;
  while(!s.empty()){
    int node = s.top(); s.pop();
    for(int i = 0; i < adj[node].size(); i++){
      dist[adj[node][i].first] = min(dist[adj[node][i].first], adj[node][i].second + dist[node]);
    }
  }

  for(int i = 0; i < V; i++){
    if(dist[i] == __INT_MAX__){
      dist[i] = -1;
    }
  }
  
  return dist;
}

int main() {
  // int n, m;
  // bool isDirected;
  // cout<<"Enter number of vertices(Node) : ";
  // cin>>n;
  // cout<<"Enter number of edges : ";
  // cin>>m;
  // cout<<"Directed or not (1/0) : ";
  // cin>>isDirected;
  // cout<<"Now enter all edges information"<<endl;

  // Graph<int>gp;
  // for(int i = 0; i < m; i++){
  //   int u, v;
  //   cin>>u>>v;
  //   gp.addEdge(u, v, isDirected);
  // }

  // gp.printGraph();

  // vector<int>ans = bfsTraversal(n, gp.adjList);
  // vector<int>ans = dfsTravsersal(n, gp.adjList);
  // printVector(ans);

  // cout<<detectCycleInUndirected(n, gp.adjList)<<endl;

  // vector<int> topoAns = topologicalSort1(n, gp.adjList);
  // vector<int> topoAns = topologicalSortBFS(n, gp.adjList);
  // printVector(topoAns);

  // cout<<isBipartiteBFS(n, gp.adjList)<<endl;
  // cout<<isBipartiteDFS(n, gp.adjList)<<endl;

  // int row, col;
  // cout<<"Enter row and col : ";
  // cin>>row>>col;
  // cout<<"Now enter all element : ";
  // vector<vector<int>> vec(row, vector<int>(col, 0));
  // for(int i = 0; i < row; i++){
  //   for(int j = 0; j < col; j++){
  //     cin>>vec[i][j];
  //   }
  // }
  // cout<<covidSpread(vec)<<endl;

  // int row, col;
  // cout<<"Enter row and col : ";
  // cin>>row>>col;
  // cout<<"Now enter all element : ";
  // vector<vector<char>> vec(row, vector<char>(col, 'a'));
  // for(int i = 0; i < row; i++){
  //   for(int j = 0; j < col; j++){
  //     cin>>vec[i][j];
  //   }
  // }
  // cout<<numIslands(vec)<<endl;

  // vector<vector<char>> ans = replaceOwithX(vec);
  // for(int i = 0; i < row; i++){
  //   for(int j = 0; j < col; j++){
  //     cout<<ans[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  // int row, col;
  // cout<<"Enter row and col : ";
  // cin>>row>>col;
  // cout<<"Now enter all element : ";
  // vector<vector<int>> vec(row, vector<int>(col, 0));
  // for(int i = 0; i < row; i++){
  //   for(int j = 0; j < col; j++){
  //     cin>>vec[i][j];
  //   }
  // }

  // cout<<numProvinces(vec)<<endl;


  vector<vector<int>> r = {{2,7},{2,6},{3,6},{4,6},{7,6},{2,1},{3,1},{4,1},{6,1},{7,1},{3,8},{5,8},{7,8},{1,9},{2,9},{6,9},{7,9}};
  vector<int> time = {9,5,9,5,8,7,7,8,4};

  cout<<parallelCourse(9, r, time)<<endl;

  return 0;
}