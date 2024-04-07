#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>

using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, stack<int> &topo){
    vis[node] = true;
    
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr, vis, adj, topo);
        }
    }
    topo.push(node);
}

void dfsTranspose (int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj){
    vis[node] = true;
    
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfsTranspose(nbr, vis, adj);
        }
    }
}


int stronglyConnectedComp(int n, int e, vector<pair<int, int>> &edges){
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool>vis;
    for(int i = 0; i < e; i ++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    stack<int> topo;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, vis, adj, topo);
        }
    }
    unordered_map<int, list<int>> adjTranspose;
    for(int i = 0; i < e; i++){
       vis[i] = false;
       int u = edges[i].first;
       int v = edges[i].second;
       adjTranspose[v].push_back(u);
    }
    
    int count = 0;
    while(!topo.empty()){
        int fr = topo.top();
        topo.pop();
        if(!vis[fr]){
            count++;
            dfsTranspose(fr, vis, adjTranspose);
        }
    }
    return count;
}

int main(){
    int n, e;
    cout<<"Enter n: ";
    cin>>n;
    cout << "Enter e : ";
    cin >> e;
    
    vector<pair<int, int>>edges(e);
    
    cout << "Enter all edges" << endl;
    for(int i = 0; i < e; i++){
        cin>>edges[i].first;
        cin >> edges[i].second;
    }
    cout<<stronglyConnectedComp(n, e, edges)<<endl;
    return 0;
}