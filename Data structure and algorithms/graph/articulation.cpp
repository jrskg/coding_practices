#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfsArticulation(int node, int p, int &timer, vector<int> & disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ans){
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    
    for(auto nbr : adj[node]){
        if(nbr == p){
            continue;
        }
        
        if(!vis[nbr]){
            dfsArticulation(nbr, node, timer, disc, low, vis, adj, ans);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] >= disc[node] && p != -1){
                ans.push_back(node);
            }
            child++;
        }else{
            low[node] = min(low[node], disc[nbr]);
        }
    }
    
    if(p == -1 && child > 1){
        ans.push_back(node);
    }
}

int main(){
    int n, e;
    cout<<"Enter n: ";
    cin>>n;
    cout << "Enter e : " << endl;
    cin >> e;
    
    vector<pair<int, int>>edges(e);
    
    cout << "Enter all edges : " << endl;
    for(int i = 0; i < e; i++){
        cin>>edges[i].first;
        cin >> edges[i].second;
    }
    
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i ++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;
    vector<int> ans;
    int timer = 0;
    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfsArticulation(i, -1, timer, disc, low, vis, adj, ans);
        }
    }
    
    cout << "The ans is : ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout<< endl;
    
    return 0;
}