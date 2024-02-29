#include <iostream>
#include <unordered_map>
#include <list>
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

int main() {
    int n, m;
    cout<<"Enter number of vertices(Node) : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>m;

    Graph<int> gp;
    for(int i = 0; i < m; i++){
        int u, v;
        cout<<"Enter edges "<<i+1<<" : ";
        cin>>u>>v;
        gp.addEdge(u, v, false);
    }

    gp.printGraph();

    return 0;
}