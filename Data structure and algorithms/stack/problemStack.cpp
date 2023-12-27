#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printStack(stack<int>s){
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void printVector(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//recursive solution
void removeMiddle(stack<int>&s, int size, int count=0){
    if(count == size/2){
        s.pop();
        return;
    }

    int elem = s.top();
    s.pop();
    removeMiddle(s, size, count+1);
    s.push(elem);
}

//intrative solution
void removeMiddleIter(stack<int>&s, int size){
    stack<int>rem;
    int count = 0;

    while(count != size/2){
        rem.push(s.top());
        s.pop();
        count++;
    }
    s.pop();

    while(!rem.empty()){
        s.push(rem.top());
        rem.pop();
    }
}

char getOpeningBracket(char c){
    if(c == ')') return '(';
    else if(c == '}') return '{';
    else return '[';
}
bool isValidParanthesis(string exp){
    stack<char>s;
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            s.push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            char cb = getOpeningBracket(exp[i]);
            if(s.empty()){
                return false;
            }
            if(cb == s.top()){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
}

void insertAtBottom(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int elem = myStack.top();
    myStack.pop();
    insertAtBottom(myStack, x);
    myStack.push(elem);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int topNum = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, topNum);
}

void sortedInsert(stack<int>&s, int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	if(s.top() < x){
		s.push(x);
		return;
	}
	int num = s.top();
	s.pop();
	sortedInsert(s, x);
	s.push(num);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack, num);
}

bool hasRedundantBracket(string exp){
    stack<char> s;
    char ch;
    bool isOperator, hasRedundant = false;

    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            s.push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            ch = s.top();
            isOperator = (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? true : false;
            if(isOperator){
                char tp = s.top();
                while(tp == '+' || tp == '-' || tp =='*' || tp == '/'){
                    s.pop();
                    tp = s.top();
                }
                s.pop();
            }else{
                hasRedundant = true;
                break;
            }
        }
    }
    return hasRedundant;
}

vector<int> nextSmallerElement(vector<int> &arr, int size){
    vector<int> ans;
    stack<int> s;
    s.push(-1);

    for(int i = size-1; i > -1; i--){
        while(s.top() >= arr[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(arr[i]);
    }

    int i = 0, j = ans.size() - 1;

    while(i < j){
        int temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
        i++;
        j--;
    }
    return ans;
}

vector<int> nextSmallerIndex(vector<int> &arr){
    int size = arr.size();
    vector<int> ans(size);
    stack<int>s;
    s.push(-1);

    for(int i = size-1; i > -1; i--){
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans[i] = (s.top());
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerIndex(vector<int> &arr){
    int size = arr.size();
    vector<int> ans(size);
    stack<int>s;
    s.push(-1);

    for(int i = 0; i < size; i++){
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans[i] = (s.top());
        s.push(i);
    }
    return ans;
}

int areaOfLargestRectangle(vector<int>heights){
    int size = heights.size();
    vector<int> prevIndex = prevSmallerIndex(heights);
    vector<int> nextIndex = nextSmallerIndex(heights);
    int maxArea = -1;

    for(int i = 0; i < size; i++){
        int height = heights[i];

        if(nextIndex[i] == -1){
            // updating nextIndex[i] to length of heights array will give exact width of the rectangle
            nextIndex[i] = size;
        }

        int width = nextIndex[i] - prevIndex[i] - 1;
        int area = width * height;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int largestRectangleBinaryMat(vector<vector<int>> &mat, int row, int col){
    //this can be done without creating this vector by modifying the matrix
    vector<int>prev(col, 0);
    int maxArea = -1;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] == 0){
                prev[j] = 0;
            }else{
                prev[j] = prev[j] + mat[i][j];
            }
        }
        int area = areaOfLargestRectangle(prev);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int isCelebrity(vector<vector<int>> &mat, int size){
    stack<int> s;

    //pushing in to the stack
    for(int i = 0; i < size; i++){
        s.push(i);
    }

    //evaluating potential celebrity
    while(s.size() != 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(mat[a][b] == 1){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    int potentialCeleb = s.top();
    for(int i = 0; i < size; i++){
        if(mat[potentialCeleb][i] == 1){
            return -1;
        }
    }

    for(int i = 0; i < size; i++){
        if(potentialCeleb == i){
            continue;
        }

        if(mat[i][potentialCeleb] == 0){
            return -1;
        }
    }
    return potentialCeleb;
}
int main() {
    // stack<int>nums;
    // int size = 4;
    // for(int i = 0; i < size; i++){
    //     nums.push(i+10);
    // }

    // printStack(nums);
    // removeMiddle(nums, size);
    // removeMiddleIter(nums, size);
    // insertAtBottom(nums, 100);
    // sortStack(nums);
    // printStack(nums);

    // string exp;
    // cout<<"Enter your expression : ";
    // cin>>exp;
    // // cout<<isValidParanthesis(exp)<<endl;
    // cout<<hasRedundantBracket(exp)<<endl;


    // cout<<is

    // stack<char>s;
    // string str;
    // cout<<"Enter your string : ";
    // cin>>str;

    // for(int i = 0; i < str.length(); i++){
    //     s.push(str[i]);
    // }

    // string ans = "";
    // while (!s.empty()){
    //     ans = ans + s.top();
    //     s.pop();
    // }

    // cout<<"Reverse : "<<ans<<endl;

    // vector<int> arr = {2, 1, 5, 6, 2, 3};
    // vector<int> ans = nextSmallerElement(arr, arr.size());
    // vector<int>ans = nextSmallerIndex(arr);
    // vector<int>ans2 = prevSmallerIndex(arr);
    // printVector(ans);
    // printVector(ans2);

    // int maxArea = areaOfLargestRectangle(arr);
    // cout<<"Largest rectangle is : "<<maxArea<<endl;
    
    return 0;
}