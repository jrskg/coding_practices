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
    //you can directly pass root and call the function only once but in case of single node(root == leaf node) the root will be added again
    traverseLeafNode(root->left, ans);
    traverseLeafNode(root->right, ans);

    //taking all the right nodes in reverse order except leaf node
    traverseRight(root->right, ans);

    return ans;
}
//code for boundry traversal ends

vector<int> verticalTraversal(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    unordered_map<int, vector<int>>ansMap;
    queue<pair<Node*, int>>q;
    int maxi = 0, mini = 0;

    //here 0 is horizontal distance
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int>frontNodePair = q.front();
        q.pop();
        int hd = frontNodePair.second;
        Node* front = frontNodePair.first;

        // if(ansMap.find(hd) != ansMap.end()){
        //     ansMap[hd].push_back(front->data);
        // }else{
        //     vector<int>temp;
        //     temp.push_back(front->data);
        //     ansMap.insert({hd, temp});
        // }
        ansMap[hd].push_back(front->data);
    
        if(front->left){
            q.push(make_pair(front->left, hd-1));
            mini = min(mini, hd-1);
        }
        if(front->right){
            q.push(make_pair(front->right, hd+1));
            maxi = max(maxi, hd+1);
        }
    }

    for(int i = mini; i <= maxi; i++){
        for(int j = 0; j < ansMap[i].size(); j++){
            ans.push_back(ansMap[i][j]);
        }
    }
    return ans;
}

vector<int> topView(Node *root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    
    //horizontal distance and node value
    unordered_map<int, int>ansMap;
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));
    int maxi = 0, mini = 0;
       
    while(!q.empty()){
        pair<Node*, int>frontPair = q.front();
        q.pop();
        int hd = frontPair.second;
        Node* front = frontPair.first;
        
        //when there is no entry then only add in the map
        if(ansMap.find(hd) == ansMap.end()){
            ansMap.insert({hd, front->data});
        }
        
        if(front->left){
            q.push(make_pair(front->left, hd-1));
            mini = min(mini, hd-1);
        }
        if(front->right){
            q.push(make_pair(front->right, hd+1));
            maxi = max(maxi, hd+1);
        }
    }
    
    for(int i = mini; i <= maxi; i++){
        ans.push_back(ansMap[i]);
    }
    return ans;
}

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    //horizontal distance and node value
    unordered_map<int, int>ansMap;
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));
    int maxi = 0, mini = 0;

    while(!q.empty()){
        pair<Node*, int> frontPair = q.front();
        q.pop();
        int hd = frontPair.second;
        Node* front = frontPair.first;

        ansMap[hd] = front->data;

        if(front->left){
            q.push(make_pair(front->left, hd-1));
            mini = min(mini, hd-1);
        }
        if(front->right){
            q.push(make_pair(front->right, hd+1));
            maxi = max(maxi, hd+1);
        }
    }

    for(int i = mini; i <= maxi; i++){
        ans.push_back(ansMap[i]);
    }
    return ans;
}

vector<int>leftViewIterative(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    //level and node value
    unordered_map<int, int>ansMap;
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int>frontPair = q.front();
        q.pop();
        int lvl = frontPair.second;
        Node* front = frontPair.first;

        if(ansMap.find(lvl) == ansMap.end()){
            ansMap[lvl] = front->data;
        }

        if(front->left){
            q.push(make_pair(front->left, lvl+1));
        }
        if(front->right){
            q.push(make_pair(front->right, lvl+1));
        }
    }
    for(int i = 0; i < ansMap.size(); i++){
        ans.push_back(ansMap[i]);
    }
    return ans;
}

vector<int>rightViewIterative(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    //level and node value
    unordered_map<int, int>ansMap;
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int>frontPair = q.front();
        q.pop();
        int lvl = frontPair.second;
        Node* front = frontPair.first;

        ansMap[lvl] = front->data;
        if(front->left){
            q.push(make_pair(front->left, lvl+1));
        }
        if(front->right){
            q.push(make_pair(front->right, lvl+1));
        }
    }
    for(int i = 0; i < ansMap.size(); i++){
        ans.push_back(ansMap[i]);
    }
    return ans;
}

bool solve(Node* l, Node* r){
    if(l == NULL && r == NULL){
        return true;
    }
    if(l != NULL && r == NULL){
        return false;
    }
    if(l == NULL && r != NULL){
        return false;
    }

    bool case1 = l->data == r->data;
    bool case2 = solve(l->left, r->right);
    bool case3 = solve(l->right, r->left);

    return (case1 && case2 && case3);
}
bool isSymmetricTree(Node* root){
    if(root == NULL){
        return true;
    }
    return solve(root->left, root->right);
}

Node* lowestCommontAncestor(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = lowestCommontAncestor(root->left, n1, n2);
    Node* right = lowestCommontAncestor(root->right, n1, n2);

    if(left && right){
        return root;
    }
    else if(left && right == NULL){
        return left;
    }
    else if(left == NULL && right){
        return right;
    }
    return NULL;
}

void solveCount(Node* root, int k, int & count, vector<int> path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    solveCount(root->left, k, count, path);
    solveCount(root->right, k, count, path);

    int sum = 0;
    for(int i = path.size()-1; i >= 0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();
}
int kPathSum(Node* root, int k){
    vector<int>path;
    int count = 0;
    solveCount(root, k, count, path);
    return count;
}

int findPosition(int inorder[], int element, int inorderStart, int inorderEnd){
    for(int i = inorderStart; i <= inorderEnd; i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}
Node* solveBuildTree(int inorder[], int preorder[], int &index, int inorderStart, int inorderEnd, int n){
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    } 

    int element = preorder[index++];
    Node* root = new Node(element);
    //using map for finding position of element will not work in case of duplicate node so using the function
    int position = findPosition(inorder, element, inorderStart, inorderEnd);

    root->left = solveBuildTree(inorder, preorder, index, inorderStart, position-1, n);
    root->right = solveBuildTree(inorder, preorder, index, position+1, inorderEnd, n);
    return root;
}
Node* buildTreeFromInorderAndPreorder(int inorder[], int preorder[], int n){
    int index = 0;
    int inorderStart = 0;
    int inorderEnd = n-1;
    return solveBuildTree(inorder, preorder, index, inorderStart, inorderEnd, n);
}

Node* solveBuildTree1(int inorder[], int postorder[], int &index, int inorderStart, int inorderEnd, int n){
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    int element = postorder[index--];
    Node* root = new Node(element);
    int position = findPosition(inorder, element, inorderStart, inorderEnd);

    root->right = solveBuildTree1(inorder, postorder, index, position+1, inorderEnd, n);
    root->left = solveBuildTree1(inorder, postorder, index, inorderStart, position-1, n);
    return root;
}
Node* buildTreeFromInorderAndPostorder(int inorder[], int postorder[], int n){
    int index = n-1;
    int inorderStart = 0;
    int inorderEnd = n-1;
    return solveBuildTree1(inorder, postorder, index, inorderStart, inorderEnd, n);
}

// Morris Traversel
Node* findInorederPred(Node * treeNode){
    Node * temp = treeNode->left;
    while(temp->right != NULL && temp->right != treeNode){
        temp = temp->right;
    }
    return temp;
}

void morrisInorderTraversal(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }else{
            Node* pred = findInorederPred(curr);
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }else{
                pred->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
    cout<<endl;
}

void morrisPreorderTraversal(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }else{
            Node* pred = findInorederPred(curr);
            if(pred->right == NULL){
                pred->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }else{
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    cout<<endl;
}

void morrisPostorderTraversal(Node* root){
    Node* curr = root;
    vector<int> res;
    while(curr != NULL){
        if(curr->right == NULL){
            res.push_back(curr->data);
            curr = curr->left;
        }else{
            Node* pred = curr->right;
            while(pred->left != NULL && pred->left != curr){
                pred = pred->left;
            }
            if(pred->left == NULL){
                res.push_back(curr->data);
                pred->left = curr;
                curr = curr->right;
            }else{
                pred->left = NULL;
                curr = curr->left;
            }
        }
    }

    //printing vector in reverse order
    for(int i = res.size() - 1; i >= 0; i--){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void flattenTree(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left){
            Node* pred = curr->left;
            while(pred->right != NULL){
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            //marking left NULL
            curr->left = NULL;
        }
        curr = curr->right;
    }

    //printing flattened tree
    curr = root;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->right;
    }
    cout<<endl;
}

Node* flattenedRecursive(Node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        return root;
    }

    Node* leftAns = flattenedRecursive(root->left);
    Node* rightAns = flattenedRecursive(root->right);

    root->left = NULL;
    if(leftAns != NULL){
        root->right = leftAns;
        Node* temp = leftAns;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = rightAns;
    }else{
        root->right = rightAns;
    }
    return root;
}

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

    cout<<"Displaying tree with inorder traversel"<<endl;
    inorderTraversal(root);
    // inorderIterative(root);
    cout<<endl;

    cout<<"Displaying tree with preorder traversel"<<endl;
    preorderTraversal(root);
    // preorderIterative(root);
    cout<<endl;

    cout<<"Displaying tree with postorder traversel"<<endl;
    postorderTraversal(root);
    cout<<endl;

    // leftView(root);
    // rightView(root);

    // cout<<"Height of tree is : "<<heightOfTree(root)<<endl;
    // cout<<"Diameter of tree is : "<<diameter(root)<<endl;
    // cout<<"Tree is balanced or not : "<<isBalanced(root)<<endl;
    // cout<<"Tree is sum tree or not : "<<isSumTree(root)<<endl;
    // cout<<"Tree is symmetric tree or not : "<<isSymmetricTree(root)<<endl;

    // vector<int>ans = zigZagTraversal(root);
    // printVector(ans);

    // vector<int> ans = boundryTraversal(root);
    // vector<int> ans = verticalTraversal(root);
    // printVector(ans);


    // int n1, n2;
    // cout<<"Enter n1 and n2 : ";
    // cin>>n1>>n2;
    // Node* lca = lowestCommontAncestor(root, n1, n2);
    // if(lca){
    //     cout<<"The LCA is : "<<lca->data<<endl;
    // }else{
    //     cout<<"LCA not found"<<endl;
    // }

    // int count = kPathSum(root, 4);
    // cout<<"The count is : "<<count<<endl;

    // morrisInorderTraversal(root);
    // inorderTraversal(root);

    // morrisPreorderTraversal(root);
    // preorderTraversal(root);

    // morrisPostorderTraversal(root);
    // postorderTraversal(root);
    // cout<<endl;

    // flattenTree(root);
    // Node* ans = flattenedRecursive(root);
    // while(ans != NULL){
    //     cout<<ans->data<<" ";
    //     ans = ans->right;
    // }
    // cout<<endl;
    return 0;
}