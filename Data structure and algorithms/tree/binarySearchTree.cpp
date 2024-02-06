#include <iostream>
#include<queue>
#include<vector>
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


Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertIntoBST(root->left, data);
    }else{
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInputStreamAndCreateBST(Node* &root){
    int data;
    cout<<"Enter data stream : ";
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

bool searchRecursive(Node* root, int d){
    if(root == NULL){
        return false;
    }
    if(root->data == d){
        return true;
    }

    if(d < root->data){
        return searchRecursive(root->left, d);
    }else{
        return searchRecursive(root->right, d);
    }
}

bool searchIterative(Node* root, int d){
    Node* temp = root;

    while(temp != NULL){
        if(temp->data == d){
            return true;
        }

        if(d < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }

    return false;
}

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}


int getPred(Node* node){
    Node* temp = node;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int getSucc(Node* node){
    Node* temp = node;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
pair<int, int>inorderPredSucc(Node* root, int key, int p, int s){
    if(root == NULL){
        //returning p and s in case of no key exists then it will correctly return the approx pred and succ
        return make_pair(p, s);
    }

    if(root->data == key){
        int pred = root->left ? getPred(root->left) : p;
        int succ = root->right ? getSucc(root->right) : s;
        return make_pair(pred, succ);
    }

    if(root->data < key){
        return inorderPredSucc(root->right, key, root->data, s);
    }else{
        return inorderPredSucc(root->left, key, p, root->data);
    }
}

pair<int, int>inorderPredSuccIterative(Node* root, int key){
    int pred = -1;
    int succ = -1;

    Node* temp = root;
    while(temp->data != key){
        if(temp->data < key){
            pred = temp->data;
            temp = temp->right;
        }else{
            succ = temp->data;
            temp = temp->left;
        }
    }

    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    return {pred, succ};
}

Node* deleteFromBST(Node* root, int key){
    if(root == NULL){
        return root;
    }

    if(root->data == key){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            //you can get min from right or max from left
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    if(root->data < key){
        root->right = deleteFromBST(root->right, key);
        return root;
    }else{
        root->left = deleteFromBST(root->left, key);
        return root;
    }
}

int kThSmallest(Node* root, int k, int &i){
    if(root == NULL){
        return -1;
    }

    int leftAns = kThSmallest(root->left, k, i);
    if(leftAns != -1){
        return leftAns;
    }
    i = i+1;
    if(i == k){
        return root->data;
    }

    return kThSmallest(root->right, k, i);
}

void getInorderData(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    getInorderData(root->left, v);
    v.push_back(root->data);
    getInorderData(root->right, v);
}
bool twoSumInBST(Node* root, int target) {
	vector<int>inorderVal;
    getInorderData(root, inorderVal);

    int i = 0, j = inorderVal.size()-1;
    int sum;

    while(i < j){
        sum = inorderVal[i] + inorderVal[j];
        if(sum == target){
            return true;
        }
        else if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

void getInorderRoot(Node* root, vector<Node*> &v){
    if(root == NULL){
        return;
    }
    getInorderRoot(root->left, v);
    v.push_back(root);
    getInorderRoot(root->right, v);
}

Node* flatten(Node* root)
{
    vector<Node*>inorder;
    getInorderRoot(root, inorder);
    int i;
    for(i = 0; i < inorder.size()-1; i++){
        inorder[i]->left = NULL;
        inorder[i]->right = inorder[i+1];
    }
    inorder[i]->left = NULL;
    inorder[i]->right = NULL;

    return inorder[0];
}

Node* buildBalanced(vector<int>v, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* root = new Node(v[mid]);
    root->left = buildBalanced(v, s, mid-1);
    root->right = buildBalanced(v, mid+1, e);

    return root;
}
Node* convertIntoBalanced(Node* root){
    vector<int> inorder;
    getInorderData(root, inorder);

    return buildBalanced(inorder, 0, inorder.size()-1);
}

Node* buildFormPreorder(vector<int> &preorder, int mini, int maxi, int &i){
    if(i >= preorder.size()){
        return NULL;
    }
    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }

    Node* root = new Node(preorder[i++]);
    root->left = buildFormPreorder(preorder, mini, root->data, i);
    root->right = buildFormPreorder(preorder, root->data, maxi, i);
    return root;
}

Node* preorderToBST(vector<int> &preorder){
    int mini = INT16_MIN;
    int maxi = INT16_MAX;
    int i = 0;

    return buildFormPreorder(preorder, mini, maxi, i);
}


int main() {
    // cout<<"Okay"<<endl;

    Node* root = NULL;
    takeInputStreamAndCreateBST(root);
    levelOrderTraversel(root);

    // int okay;
    // cout<<"What to search : ";
    // cin>>okay;
    // cout<<searchRecursive(root, okay)<<endl;
    // cout<<searchIterative(root, okay)<<endl;

    // cout<<minVal(root)->data<<endl;
    // cout<<maxVal(root)->data<<endl;

    int n;
    cout<<"Enter n : ";
    cin>>n;
    // pair<int, int> predSucc = inorderPredSucc(root, n, -1, -1);
    pair<int, int> predSucc = inorderPredSuccIterative(root, n);
    cout<<"Predessor : "<<predSucc.first<<endl;
    cout<<"Successor : "<<predSucc.second<<endl;

    // int n;
    // cout<<"Enter n : ";
    // cin>>n;
    // root = deleteFromBST(root, n);
    // levelOrderTraversel(root);

    // int key;
    // cout<<"Enter key : ";
    // cin>>key;
    // int i = 0;
    // cout<<endl<<key<<" th smallest element : "<<kThSmallest(root, key, i)<<endl;

    return 0;
}