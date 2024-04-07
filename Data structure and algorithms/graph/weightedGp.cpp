#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight, bool isDirected){
        adj[u].push_back(make_pair(v, weight));
        if(!isDirected){
            adj[v].push_back(make_pair(u, weight));
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }cout<<endl;
        }
    }
};

template <typename T>
void printVector(vector<T> v){
    int size = v.size();
    for(int i = 0; i < size; i++){
        if(v[i] == INT32_MAX){
            cout<<"INF ";
        }else{
            cout<<v[i]<<" ";
        }
    }cout<<endl;
}

void dfs(int node, unordered_map<int, list<pair<int, int>>> &adj, unordered_map<int, bool> &visited, stack<int> &topo){
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i.first]){
            dfs(i.first, adj, visited, topo);
        }
    }
    topo.push(node);
}

vector<int> getShortestPathDAG(unordered_map<int, list<pair<int, int>>> &adj, int src, int vertices){
    unordered_map<int, bool> visited;
    stack<int> topo;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            dfs(i, adj, visited, topo);
        }
    }

    vector<int> ans(vertices, INT32_MAX);
    ans[src] = 0;

    while(!topo.empty()){
        int top = topo.top();
        topo.pop();
        if(ans[top] != INT32_MAX){
            for(auto i : adj[top]){
                if(ans[top] + i.second < ans[i.first]){
                    ans[i.first] = ans[top] + i.second;
                }
            }
        }
    }

    return ans;
}

vector<int> dijkstra(unordered_map<int, list<pair<int, int>>> &adj, int source, int vertices){
    vector<int> ans(vertices, INT32_MAX);
    ans[source] = 0;
    set<pair<int, int>> distNode;
    distNode.insert(make_pair(0, source));

    while(!distNode.empty()){
        pair<int, int> top = *distNode.begin();
        distNode.erase(distNode.begin());

        for(auto i : adj[top.second]){
            int sum = top.first + i.second;
            if(sum < ans[i.first]){
                ans[i.first] = sum;
                distNode.insert(make_pair(sum, i.first));
            }
        }
    }

    return ans;
}

vector<pair<pair<int, int>, int>>primsMST(unordered_map<int, list<pair<int, int>>> &adj, int vertices){
    //assuming node starts from 1 - vertices
    vector<int> key(vertices+1, INT32_MAX);
    vector<bool> mst(vertices+1, false);
    vector<int> parent(vertices+1, -1);

    parent[1] = -1;
    key[1] = 0;

    for(int i = 1; i <= vertices; i++){
        int minWeigthNode;
        int mini = INT32_MAX;

        for(int v = 1; v <= vertices; v++){
            if(mst[v] == false && key[v] < mini){
                mini = key[v];
                minWeigthNode = v;
            }
        }

        mst[minWeigthNode] = true;

        for(auto it : adj[minWeigthNode]){
            if(mst[it.first] == false && it.second < key[it.first]){
                key[it.first] = it.second;
                parent[it.first] = minWeigthNode;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= vertices; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

vector<int> bellmonFord(int n, int e, int src, vector<vector<int>> &edges){
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < e; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + wt) < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    //checking for loop
    bool flag = false;
    for(int j = 0; j < e; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && (dist[u] + wt) < dist[v]){
            flag = true;
        }
    }

    return !flag ? dist : vector<int>(n+1, 1e9);
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

    vector<vector<int>> edges(m);

    Graph gp;
    cout<<"Enter all edges"<<endl;
    for(int i = 0; i < m; i++){
        int u, v, weight;
        cin>>u>>v>>weight;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(weight);
        gp.addEdge(u, v, weight, isDirected);
    }

    gp.printGraph();

    // int src;
    // cout<<"Enter source node : ";
    // cin>>src;

    // // vector<int> paths = getShortestPathDAG(gp.adj, src, n);
    // vector<int> paths = dijkstra(gp.adj, src, n);
    // printVector(paths);

    int src;
    cout<<"Enter src : ";
    cin>>src;
    vector<int> ans = bellmonFord(n, m, src, edges);

    for(int i = 1; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}