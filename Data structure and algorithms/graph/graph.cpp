#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
class Graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool isDirected){
        adj[u].push_back(v);
        if(!isDirected){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<", ";
            }cout<<endl;
        }
    }
};


void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, unordered_map<int, list<int>> &adj){
    unordered_map<int, bool> visited;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bfs(adj, visited, ans, i);
        }
    }

    return ans;
}

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &temp){
    temp.push_back(node);
    visited[node] = true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, temp);
        }
    }
}

vector<vector<int>> dfsTraversal(int n, unordered_map<int, list<int>> &adj){
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(i, adj, visited, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}


bool checkCycleBfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited){
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(visited[i] && parent[front] != i){
                return true;
            }

            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    return false;
}
string undirectedCycle(int n, unordered_map<int, list<int>> &adj){
    unordered_map<int, bool> visited;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bool ans = checkCycleBfs(i, adj, visited);
            if(ans){
                return "Yes";
            }
        }
    }

    return "No";
}
bool checkDirectedCycleDfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int, bool> &dfsVisited){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            bool ans = checkDirectedCycleDfs(i, adj, visited, dfsVisited);
            if(ans){
                return true;
            }
        }
        else if(dfsVisited[i]){
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}
bool directedCycleDfs(int n, unordered_map<int, list<int>> &adj){
    unordered_map<int , bool> visited;
    unordered_map<int , bool> dfsVisited;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bool ans = checkDirectedCycleDfs(i, adj, visited, dfsVisited);
            if(ans){
                return ans;
            }
        }
    }
    return false;
}

void topoSortDfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &st){
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            topoSortDfs(i, adj, visited, st);
        }
    }
    st.push(node);
}
vector<int> topologicalSortDfs(int n, unordered_map<int, list<int>> &adj){
    unordered_map<int, bool> visited;
    stack<int> st;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            topoSortDfs(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> topoSortKahnAlgo(int n, unordered_map<int, list<int>> &adj){
    vector<int>indegree(n, 0);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i : adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}

bool cycleInDirectedBfs(int n, unordered_map<int, list<int>> &adj){
    vector<int> indegree(n, 0);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    queue<int>q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        count++;

        for(auto i : adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }

    return n != count;
}

vector<int> shortestPathBfsUnweighted(int n, unordered_map<int, list<int>> &adj, int s, int t){
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    vector<int>ans;
    int temp = t;
    ans.push_back(temp);
    while(temp != s){
        temp = parent[temp];
        ans.push_back(temp);
    }

    int start = 0, end = ans.size()-1;
    while(start < end){
        swap(ans[start++], ans[end--]);
    }

    return ans;
}

void dfsForBridge(int node, int parent, int &timer, vector<int> &low, vector<int> &disc, unordered_map<int, bool> &vis,unordered_map<int, list<int>> &adj, vector<vector<int>> &result){
    vis[node] = true;
    low[node] = disc[node] = timer++;

    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }

        if(!vis[nbr]){
            dfsForBridge(nbr, node, timer, low, disc, vis, adj, result);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }else{
            low[node] = min(low[node], disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(int n, unordered_map<int,list<int>> &adj){
    vector<int> low(n, -1);
    vector<int> disc(n, -1);
    int parent = -1;
    int timer = 0;
    unordered_map<int, bool> vis;
    vector<vector<int>> result;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfsForBridge(i, parent, timer, low, disc, vis, adj, result);
        }
    }

    return result;
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

    Graph<int> gp;
    for(int i = 0; i < m; i++){
        int u, v;
        // cout<<"Enter edges "<<i+1<<" : ";
        cin>>u>>v;
        gp.addEdge(u, v, isDirected);
    }

    gp.printGraph();

    // vector<int> ans = bfsTraversal(n, gp.adj);
    // for(int i = 0; i < ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }cout<<endl;

    // vector<vector<int>> ans = dfsTraversal(n, gp.adj);
    // for(int i = 0; i < ans.size(); i++){
    //     for(int j = 0; j < ans[i].size(); j++){
    //         cout<<ans[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;

    // cout<<undirectedCycle(n, gp.adj)<<endl;
    // cout<<directedCycleDfs(n, gp.adj)<<endl;

    // vector<int> ans = topologicalSortDfs(n, gp.adj);
    // vector<int> ans = topoSortKahnAlgo(n, gp.adj);
    // for(int i = 0; i < ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }cout<<endl;

    // cout<<cycleInDirectedBfs(n, gp.adj)<<endl;

    // int s, t;
    // cout<<"Enter start and destination : ";
    // cin >> s >> t;
    // vector<int> ans = shortestPathBfsUnweighted(n, gp.adj, s, t);
    // for(int i = 0; i < ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }cout<<endl;

    vector<vector<int>> ans = findBridges(n, gp.adj);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}

