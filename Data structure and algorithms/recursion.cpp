#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int factorial(int num){
    if(num == 0)
        return 1;

    return num * factorial(num-1);
}

int power(int num, int p){
    if(p == 0)
        return 1;

    return num*power(num, p-1);
}

void count(int n){
    if(n == 0){
        return ;
    }
    cout<<n<<endl;
    count(n-1);
}

void count2(int n){
    if(n == 0){
        return ;
    }
    count2(n-1);
    cout<<n<<endl;
}

int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return fib(n-1)+fib(n-2);
}

int stairPath(int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;

    return stairPath(n-1)+stairPath(n-2)+stairPath(n-3);
}

bool isSorted(int *arr, int size){
    if(size == 1 || size == 0){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        return isSorted(arr+1, size-1);
    }
}

int arraySumRec(int *arr, int size){
    if(size == 0)
        return 0;

    if(size == 1)
        return arr[0];

    return arr[0] + arraySumRec(arr+1, size-1);
}

bool linearSearchRec(int *arr, int size, int elem){
    if(size == 0){
        return false;
    }

    if(arr[0] == elem){
        return true;
    }else{
        return linearSearchRec(arr+1, size-1, elem);
    }
}

bool binarySearchRec(int *arr, int start, int end, int elem){
    if(end < start){
        return false;
    }

    int mid = start+(end-start)/2;
    if(arr[mid] == elem){
        return true;
    }else if(arr[mid] < elem){
        return binarySearchRec(arr, mid+1, end, elem);
    }else{
        return binarySearchRec(arr, start, mid-1, elem);
    }
}

void reverseStringRec(string& str, int i){
    if(i > str.size() - 1 - i){
        return ;
    }
    swap(str[i], str[str.size() - 1 - i]);
    reverseStringRec(str, i+1); 
}

bool palindromeStrRec(string str, int i, int j){
    if(i > j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }else{
        return palindromeStrRec(str, i+1, j-1);
    }
}

int power2(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    int ans =  power2(a, b/2);

    if(b&1)
        return a * ans * ans;
    else
        return ans * ans;
}

void bubbleSortRec(int *arr, int n){
    if(n == 0 || n == 1){
        return ;
    }

    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSortRec(arr, n-1);
}

void selectionSortRec(int *arr, int n, int i){
    if(n == 0 || n == 1){
        return ;
    }
    if(i >= n-1){
        return ;
    }

    int min = i;
    for(int j = i+1; j < n; j++){
        if(arr[j] < arr[min]){
            min = j;
        }
    }
    swap(arr[min], arr[i]);
    selectionSortRec(arr, n, i+1);
}

void insertionSortRec(int *arr, int n, int i){
    if(n == 0 || n == 1){
        return ;
    }
    if(i >= n){
        return ;
    }
    int key = arr[i];
    int j = i - 1;
    while(j >= 0){
        if(key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }else{
            break;
        }
    }
    arr[j+1] = key;
    insertionSortRec(arr, n, i+1);
}

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainIndex = s;
    for(int i = 0; i < len1; i++){
        first[i] = arr[mainIndex++];
    }

    mainIndex = mid+1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[mainIndex++];
    }

    int index1 = 0, index2 = 0;
    mainIndex = s;
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainIndex++] = first[index1++];
        }else{
            arr[mainIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    // merge(arr, s, e);

    int index1 = s, index2 = mid+1;
    int len1 = mid-s+1+index1;
    int len2 = e - mid+index2;

    while(index1 < len1 && index2 < len2){
        if(arr[index1] < arr[index2]){
            index1++;
        }else{
            int temp = arr[index2];
            int p = index2;
            while(p > index1){
                arr[p] = arr[p-1];
                p--;
            }
            arr[index1++] = temp;
            index2++;
        }
    }
    // while(index1 < len1){
    //     arr[mainIndex++] = arr[index1++];
    // }
    // while(index2 < len2){
    //     arr[mainIndex++] = arr[index2++];
    // }
}

int partition(int *arr, int s, int e){
    //taking pivot
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    //placing pivot to its right place
    int pIndex = s + count;
    swap(arr[pIndex], arr[s]);

    //making sure left of pivot is less than pivot and right is greater
    int i = s, j = e;
    while(i < pIndex && j > pIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pIndex && j > pIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pIndex;
}

void quickSort(int *arr, int s, int e){
    if(s >= e){
        return ;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);

}

void solve(vector<int>arr,vector<int>output, vector<vector<int>>&ans, int i, int size){
    if(i >= size){
        ans.push_back(output);
        return;
    }

    solve(arr, output, ans, i+1, size);
    output.push_back(arr[i]);
    solve(arr,  output, ans, i+1, size);
}

vector<vector<int>>subset(vector<int>&arr, int size){
    vector<int>output;
    vector<vector<int>>ans;
    int index = 0;
    solve(arr, output, ans, index, size);
    return ans;
}

void print(vector<vector<int>> &arr){
    cout<<endl;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solveStr(string s, string output, int i, vector<string> &ans){
    if(i >= s.length()){
        if(output.length() > 0){
            ans.push_back(output);
        }
        return;
    }

    solveStr(s, output, i+1, ans);
    output.push_back(s[i]);
    solveStr(s, output, i+1, ans);
}
vector<string> subSequence(string s){
    vector<string> ans;
    int index = 0;
    string output = "";
    solveStr(s, output, index, ans);
    return ans;
}

int decToBin(int num){
    int ans = 0, p = 0;
    while(num){
        int bit = num&1;
        int times = pow(10, p);
        ans = (bit * times) + ans;
        num = num >> 1;
        p++;
    }
    return ans;
}
void subset2(vector<int> arr, int size){
    int totalSubsets = pow(2, size);
    for(int i = 0; i < totalSubsets; i++){
        int bn = decToBin(i);
        int div = pow(10, size-1);
        for(int j = 0; j < size; j++){
            int q = bn/div;
            if(q == 0){
                cout<<"-\t";
            }else{
                cout<<arr[j]<<"\t";
            }
            bn = bn%div;
            div = div/10;
        }
        cout<<endl;
    }
}

void subSequence2(string s){
    int size = s.length();
    int totalSubsets = pow(2, size);
    for(int i = 0; i < totalSubsets; i++){
        int bn = decToBin(i);
        int div = pow(10, size-1);
        for(int j = 0; j < size; j++){
            int q = bn/div;
            if(q == 0){
                cout<<"- ";
            }else{
                cout<<s[j]<<" ";
            }
            bn = bn%div;
            div = div/10;
        }
        cout<<endl;
    }
}

void phoneKeypadSolve(string digit, string output, int i, vector<string>&ans, string map[]){
    if(i >= digit.length()){
        ans.push_back(output);
        return;
    }
    int num = digit[i] - '0';
    string value = map[num];
    for(int j = 0; j < value.length(); j++){
        output.push_back(value[j]);
        phoneKeypadSolve(digit, output, i+1, ans, map);
        output.pop_back();
    }
}

void permutationOfStr(string str, int i, vector<string>&ans){
    if(i >= str.length()){
        ans.push_back(str);
    }

    for(int j = i; j < str.size(); j++){
        swap(str[i], str[j]);
        permutationOfStr(str, i+1, ans);
        swap(str[i], str[j]);
    }
}

//*********************************RAT IN MAZE => starts*****************
void print2DArray(vector<vector<int>>&arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>m, vector<vector<int>>v, int x, int y, int rows, int cols){
    if((x >= 0 && x < rows) && (y >= 0 && y < cols) && (m[x][y] == 1) && (v[x][y] == 0)){
        return true;
    }else{
        return false;
    }
}

void ratInMazeSolve(vector<vector<int>>m, vector<vector<int>>v, int x, int y, int rows, int cols, vector<string>&ans, string path){

    // base case
    if(x == rows-1 && y == cols-1){
        ans.push_back(path);
        return;
    }

    v[x][y] = 1;

    //down
    int newX = x+1;
    int newY = y;
    if(isSafe(m, v,newX, newY, rows, cols)){
        path.push_back('D');
        ratInMazeSolve(m, v, newX, newY, rows, cols, ans, path);
        path.pop_back();
    }

    //left
    newX = x;
    newY = y-1;
    if(isSafe(m, v,newX, newY, rows, cols)){
        path.push_back('L');
        ratInMazeSolve(m, v, newX, newY, rows, cols, ans, path);
        path.pop_back();
    }

    //right
    newX = x;
    newY = y+1;
    if(isSafe(m, v,newX, newY, rows, cols)){
        path.push_back('R');
        ratInMazeSolve(m, v, newX, newY, rows, cols, ans, path);
        path.pop_back();
    }

    //up
    newX = x-1;
    newY = y;
    if(isSafe(m, v,newX, newY, rows, cols)){
        path.push_back('U');
        ratInMazeSolve(m, v, newX, newY, rows, cols, ans, path);
        path.pop_back();
    }
    v[x][y] = 0;
}

vector<string>ratInMaze(vector<vector<int>>&maze, int rows, int cols){
    vector<string>ans;
    if(maze[0][0] == 0){
        return ans;
    }
    vector<vector<int>>visit(rows, vector<int>(cols, 0));
    int x = 0;
    int y = 0;
    string path = "";
    ratInMazeSolve(maze, visit, x, y, rows, cols, ans, path);
    return ans;
}
//*********************************RAT IN MAZE => ends*****************

int main(){
    //did you mean recursion ?

    // int num;
    // cout<<"Enter a number : ";
    // cin>>num;
    // int ans = factorial(num);    
    // cout<<"Ans : "<<ans<<endl;

    // int ans = power(3, num);
    // cout<<"Ans : "<<ans<<endl;

    // count(num);
    // count2(num);
    // cout<<fib(num)<<endl;
    // cout<<stairPath(num)<<endl;

    // int arr[20];
    // int size;
    // cout<<"Enter size : ";
    // cin>>size;
    // cout<<"Enter array : ";
    // for(int i = 0; i < size; i++){
    //     cin>>arr[i];
    // }
    // int elem;
    // cout<<"Enter element to search : ";
    // cin>>elem;
    // cout<<isSorted(arr, size)<<endl;
    // cout<<arraySumRec(arr, size)<<endl;
    // cout<<linearSearchRec(arr, size, elem)<<endl;
    // cout<<binarySearchRec(arr, 0, size-1, elem)<<endl;

    // bubbleSortRec(arr, size);
    // selectionSortRec(arr, size, 0);
    // insertionSortRec(arr, size, 1);
    // mergeSort(arr, 0, size-1);
    // quickSort(arr, 0, size-1);

    // for(int i = 0; i < size; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    // string str;
    // cout<<"Enter a string : ";
    // cin>>str;
    // reverseStringRec(str, 0);
    // cout<<str<<endl;

    // cout<<palindromeStrRec(str, 0, str.size()-1)<<endl;

    // int a, b;
    // cout<<"Enter a and b : ";
    // cin>>a>>b;
    // cout<<power2(a, b)<<endl;


    // vector<int>arr(20);
    // int size;
    // cout<<"Enter size : ";
    // cin>>size;
    // cout<<"Elements : ";
    // for (int i = 0; i < size; i++) {
    //     cin>>arr[i];
    // }
    // vector<vector<int>> ans = subset(arr, size);
    //  print(ans);
    // subset2(arr, size);


    // string s = "abcd";
    // vector<string>ans = subSequence(s);
    // for(int i = 0; i < ans.size(); i++){
    //     cout<<ans[i]<<endl;
    // }
    // subSequence2(s);


    // string digit = "23";
    // vector<string> ans;
    // string output = "";
    // int index = 0;
    // string map[10] = {"", "","abc","def","ghi","jkl","mno","pgrs","tuv", "wxyz"};
    // phoneKeypadSolve(digit, "", 0, ans, map);

    // string str = "abc";
    // permutationOfStr(str, 0, ans);

    // for(int i = 0; i < ans.size(); i++){
    //     cout<<ans[i]<<endl;
    // }

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string>ans = ratInMaze(maze, 4, 4);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}