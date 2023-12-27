#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printVector(vector<int>v){
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

Node* buildTree(Node* root){
    cout<<"Enter data : ";
    int data;
    cin>>data;

    root = new Node(data);

    //assuming if data is -1 then i dont want to go further means insert null and return
    if(data == -1){
        return NULL;
    }

    cout<<"LEFT of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"RIGHT of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversel(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //this is for newline or seperator
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

    cout<<endl;
}

void reverseLevelOrderTraversel(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*>q;
    stack<Node*>s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            s.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            s.push(temp);
            if(temp->right != NULL){
                q.push(temp->right);
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
        }
    }

    while(!s.empty()){
        if(s.top() == NULL){
            cout<<endl;
        }else{
            cout<<s.top()->data<<" ";
        }
        s.pop();
    }
    cout<<endl;
}

void inorderTraversal(Node* root){
    //LNR
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void inorderIterative(Node* root){
    cout<<endl;
    stack<Node*>s;
    Node*curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }  
}

void preorderTraversal(Node* root){
    //NLR
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void preorderIterative(Node*root){
    cout<<endl;
    stack<Node*>s;
    Node* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            cout<<curr->data<<" ";
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}

void postorderTraversal(Node* root){
    //LRN
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void buildTreeFromLevelOrder(Node* &root){
    queue<Node*>q;
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;
    root = new Node(rootData);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"LEFT of "<<temp->data<<" : ";
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        } 

        int rightData;
        cout<<"RIGHT of "<<temp->data<<" : ";
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        } 
    }
}

void createLeftStore(Node*root, map<int, Node*>&m, int level){
    if(root == NULL){
        return;
    }

    if(m[level] == NULL){
        m[level] = root;
    }

    createLeftStore(root->left, m, level+1);
    createLeftStore(root->right, m, level+1);
}
void leftView(Node* root){
    map<int, Node*>leftStore;
    createLeftStore(root, leftStore, 0);

    cout<<"Left View : ";
    for(int i = 0; i < leftStore.size(); i++){
        cout<<leftStore[i]->data<<" ";
    }
    cout<<endl;
}

void createRightStore(Node*root, map<int, Node*>&m, int level){
    if(root == NULL){
        return;
    }

    m[level] = root;

    createRightStore(root->left, m, level+1);
    createRightStore(root->right, m, level+1);
}
void rightView(Node* root){
    map<int, Node*>rightStore;
    createRightStore(root, rightStore, 0);

    cout<<"Right View : ";
    for(int i = 0; i < rightStore.size(); i++){
        cout<<rightStore[i]->data<<" ";
    }
    cout<<endl;
}

int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return max(leftHeight, rightHeight) + 1;
}

pair<int, int>calculateDiameter(Node* root){
    if(root == NULL){
        pair<int, int>p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = calculateDiameter(root->left);
    pair<int, int> right = calculateDiameter(root->right);
    int overAll = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(left.first, max(right.first, overAll));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(Node* root){
    return calculateDiameter(root).first;
}

pair<bool, int> calculateIsBalanced(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = calculateIsBalanced(root->left);
    pair<bool, int> right = calculateIsBalanced(root->right);
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    ans.first = (left.first && right.first && diff);

    return ans;
}
bool isBalanced(Node* root){
    return calculateIsBalanced(root).first;
}

bool isIdentical(Node* r1, Node* r2){
    if(r1 == NULL && r2  == NULL){
        return true;
    }
    if(r1 != NULL && r2  == NULL){
        return false;
    }
    if(r1 == NULL && r2  != NULL){
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;

    return (left && right && value);
}

pair<bool, int> calculateIsSumTree(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = calculateIsSumTree(root->left);
    pair<bool, int> right = calculateIsSumTree(root->right);
    bool isCurrentSumTree = (left.second + right.second) == root->data;

    pair<bool, int> ans;
    ans.first = (left.first && right.first && isCurrentSumTree);
    ans.second = 2*root->data;

    return ans;
}
bool isSumTree(Node* root){
    return calculateIsSumTree(root).first;
}

vector<int> zigZagTraversal(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*>q;
    bool leftToRight = true;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>temp(size);
        for(int i = 0; i < size; i++){
            Node* front = q.front();
            q.pop();
            int index = leftToRight ? i : size-i-1;
            temp[index] = front->data;
            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto i : temp){
            ans.push_back(i);
        }
    }
    return ans;
}

//code for boundry traversal starts
void traverseLeft(Node* root, vector<int>&ans){
    //this function gets all left nodes expect leaf node
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left, ans);
    }else{
        traverseLeft(root->right, ans);
    }
}

void traverseLeafNode(Node* root, vector<int>& ans){
    //this function gets all leaf nodes
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeafNode(root->left, ans);
    traverseLeafNode(root->right, ans);
}

void traverseRight(Node* root, vector<int>&ans){
    //this function gets all right nodes in reverse order expect leaf node
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right, ans);
    }else{
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> boundryTraversal(Node* root){
    vector<int>ans;

    if(root == NULL){
        return ans;
    }

    //taking root node
    ans.push_back(root->data);

    //taking all the left nodes except leaf node
    traverseLeft(root->left, ans);

    //taking all the leaf nodes from left and right
    //you can directly pass root and call the function olny once but i case of single node(root == leaf node) the root will be added again
    traverseLeafNode(root->left, ans);
    traverseLeafNode(root->right, ans);

    //taking all the right nodes in reverse order except leaf node
    traverseRight(root->right, ans);

    return ans;
}
//code for boundry traversal ends

//TODO:Vertical traversal


int main() {

    Node* root = NULL;

    //10 11 12 -1 -1 13 -1 -1 14 15 -1 -1 16 -1 -1
    //1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 -1 -1 11 -1 -1
    root = buildTree(root);
    // buildTreeFromLevelOrder(root);

    // cout<<"Displaying tree with level order traversel"<<endl;
    // levelOrderTraversel(root);

    // cout<<"Displaying tree with reverse level order traversel"<<endl;
    // reverseLevelOrderTraversel(root);

    // cout<<"Displaying tree with inorder traversel"<<endl;
    // inorderTraversal(root);
    // inorderIterative(root);
    // cout<<endl;

    // cout<<"Displaying tree with preorder traversel"<<endl;
    // preorderTraversal(root);
    // preorderIterative(root);
    // cout<<endl;

    // cout<<"Displaying tree with postorder traversel"<<endl;
    // postorderTraversal(root);
    // cout<<endl;

    // leftView(root);
    // rightView(root);

    // cout<<"Height of tree is : "<<heightOfTree(root)<<endl;
    // cout<<"Diameter of tree is : "<<diameter(root)<<endl;
    // cout<<"Tree is balanced or not : "<<isBalanced(root)<<endl;
    // cout<<"Tree is sum tree or not : "<<isSumTree(root)<<endl;

    // vector<int>ans = zigZagTraversal(root);
    // printVector(ans);

    vector<int> ans = boundryTraversal(root);
    printVector(ans);
 
    return 0;
}