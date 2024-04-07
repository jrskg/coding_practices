#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int getParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    int getP = getParent(parent, parent[node]);
    parent[node] = getP;
    return getP;
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    int uParent = getParent(parent, u);
    int vParent = getParent(parent, v);

    int uRank = rank[uParent];
    int vRank = rank[vParent];

    if(uRank == vRank){
        parent[uParent] = vParent;
        rank[vParent]++;
    }else if(uRank < vRank){
        parent[uParent] = vParent;
    }else{
        parent[vParent] = uParent;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n){
    vector<int> rank(n);
    vector<int> parent(n);
    makeSet(parent, rank, n);

    sort(edges.begin(), edges.end(), cmp);
    int ed = edges.size();
    int totalWeight = 0;

    for(int i = 0; i < ed; i++){
        int uParent = getParent(parent, edges[i][0]);
        int vParent = getParent(parent, edges[i][1]);

        if(uParent != vParent){
            totalWeight += edges[i][2];
            unionSet(uParent, vParent, parent, rank);
        }
    }


    return totalWeight;
}


int main() {
    int size, vertices;
    cout<<"Enter size : ";
    cin>>size;
    cout<<"Enter vertices : ";
    cin>>vertices;

    vector<vector<int>> edges(size, vector<int>(3));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 3; j++){
            cin>>edges[i][j];
        }
    }

    minimumSpanningTree(edges, vertices);
    return 0;
}