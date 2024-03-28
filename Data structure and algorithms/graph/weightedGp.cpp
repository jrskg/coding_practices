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

int main() {

    int n, m;
    bool isDirected;
    cout<<"Enter number of vertices(Node) : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>m;
    cout<<"Directed or not (1/0) : ";
    cin>>isDirected;

    Graph gp;
    for(int i = 0; i < m; i++){
        int u, v, weight;
        cin>>u>>v>>weight;
        gp.addEdge(u, v, weight, isDirected);
    }

    gp.printGraph();

    int src;
    cout<<"Enter source node : ";
    cin>>src;

    // vector<int> paths = getShortestPathDAG(gp.adj, src, n);
    vector<int> paths = dijkstra(gp.adj, src, n);
    printVector(paths);
    
    return 0;
}