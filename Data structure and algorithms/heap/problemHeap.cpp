#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void takeInut(vector<int> &v){
    int n, temp;
    cout<<"Enter size : ";
    cin>>n;
    cout<<"Enter total "<<n<<" elements : ";
    for(int i = 0; i < n; i++){
        cin>>temp;
        v.push_back(temp);
    }
}

int kThSmallestElement(vector<int>arr, int k){
    priority_queue<int>pq;

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < arr.size(); i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int kthLargestElement(vector<int> arr, int k){
    priority_queue <int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < arr.size(); i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

//***************************************************************************************
int countNode(struct Node* tree){
    if(tree == NULL){
        return 0;
    }
    
    int left = countNode(tree->left);
    int right = countNode(tree->right);
    
    return 1 + left + right;
}

bool isCBT(struct Node* tree, int i, int totalNode){
    if(tree == NULL){
        return true;
    }
    if(i >= totalNode){
        return false;
    }
    
    bool left = isCBT(tree->left, 2*i+1, totalNode);
    bool right = isCBT(tree->right, 2*i+2, totalNode);
    
    return (left && right);
}
bool isMaxOrder(struct Node* tree){

    if(tree->left == NULL && tree->right == NULL){
        return true;
    }
    
    if(tree->right == NULL){
        return tree->data > tree->left->data;
    }   
    else{
        bool left = isMaxOrder(tree->left);
        bool right = isMaxOrder(tree->right);
        
        return (left && right && (tree->data > tree->left->data && tree->data > tree->right->data));
    }
}
bool isHeap(struct Node* tree) {
    int totalNode = countNode(tree);
    //here isCBT is first beacuse is MaxOrder will only work if the tree is a CBT
    return (isCBT(tree, 0, totalNode) && isMaxOrder(tree));
}
//***************************************************************************************

void heapify(vector<int> &ans, int i, int size){
    int largest = i;
    int leftIndex = i*2+1;
    int rightIndex = i*2+2;

    if(leftIndex < size && ans[leftIndex] > ans[largest]){
        largest = leftIndex;
    }
    if(rightIndex < size && ans[rightIndex] > ans[largest]){
        largest = rightIndex;
    }
    if(largest != i){
        swap(ans[largest], ans[i]);
        heapify(ans, largest, size);
    }
}
vector<int>mergeTwoHeap(vector<int>&a, vector<int>&b){
    int m = a.size();
    int n = b.size();
    vector<int>ans(m+n);
    int i, k = 0;
    for(i = 0; i < m; i++){
        ans[k++] = a[i];
    }
    for(i = 0; i < n; i++){
        ans[k++] = b[i];
    }

    for(i = (m+n)/2-1; i >= 0; i--){
        heapify(ans, i, m+n);
    }
    return ans;
}

int main() {
    vector<int>v;
    takeInut(v);
    int key;
    cout<<"Enter key : ";
    cin>>key;
    // int smallest = kThSmallestElement(v, key);
    int largest = kthLargestElement(v, key);
    cout<<"Ans : "<<largest<<endl;

    return 0;
}