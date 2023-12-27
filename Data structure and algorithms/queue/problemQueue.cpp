#include <iostream>
#include<stack>
#include<queue>

using namespace std;

void printQueue(queue<int> q){
    cout<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void printVector(vector<int> v){
    cout<<endl;
    int size = v.size();
    for(int i = 0; i < size; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

queue<int> reverse(queue<int> q){
    stack<int>s;
    while(!q.empty()){
        int data = q.front();
        q.pop();
        s.push(data);
    }
    while(!s.empty()){
        int data = s.top();
        s.pop();
        q.push(data);
    }
    return q;
}

queue<int> reverseRecursion(queue<int> q){
    if(q.empty()){
        return q;
    }
    int data = q.front();
    q.pop();
    q = reverseRecursion(q);
    q.push(data);
    return q;
}

vector<int> firstNegativeInteger(vector<int> arr, int n, int k){
    vector<int>ans;
    deque<int>dq;

    for(int i = 0; i < k; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0){
        ans.push_back(arr[dq.front()]);
    }else{
        arr.push_back(0);
    }

    for(int i = k; i < n; i++){
        if(!dq.empty() && i-k == dq.front()){
            dq.pop_front();
        }

        if(arr[i] < 0){
            dq.push_back(i);
        }

        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}

queue<int> reverseKElement(queue<int> q, int k) {
    stack<int>s;
    int temp;

    for(int i = 0; i < k; i++){
        temp = q.front();
        q.pop();
        s.push(temp);
    }

    while(!s.empty()){
        temp = s.top();
        s.pop();
        q.push(temp);
    }

    for(int i = 0; i < q.size() - k; i++){
        temp = q.front();
        q.pop();
        q.push(temp);
    }

    return q;
}

int main() {
    int size, temp;
    queue<int>q;
    cout<<"Enter size : ";
    cin>>size;

    cout<<"Enter all numbers : ";
    for(int i = 0; i < size; i++){
        cin>>temp;
        q.push(temp);
    }
    printQueue(q);
    // q = reverseRecursion(q);
    q = reverseKElement(q, 2);
    printQueue(q);

    // vector<int>arr;
    // int size, temp, window;
    // cout<<"Enter size : ";
    // cin>>size;

    // cout<<"Enter all the elements : ";
    // for(int i = 0; i < size; i++){
    //     cin>>temp;
    //     arr.push_back(temp);
    // }
    // cout<<"Enter the window size : ";
    // cin>>window;

    // vector<int>ans = firstNegativeInteger(arr, size, window);
    // printVector(ans); 
    return 0;
}