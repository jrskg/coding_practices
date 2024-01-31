#include <iostream>
#include<queue>
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

    // int n;
    // cout<<"Enter n : ";
    // cin>>n;
    // pair<int, int> predSucc = inorderPredSucc(root, n, -1, -1);
    // cout<<"Predessor : "<<predSucc.first<<endl;
    // cout<<"Successor : "<<predSucc.second<<endl;

    int n;
    cout<<"Enter n : ";
    cin>>n;
    root = deleteFromBST(root, n);
    levelOrderTraversel(root);

    return 0;
}