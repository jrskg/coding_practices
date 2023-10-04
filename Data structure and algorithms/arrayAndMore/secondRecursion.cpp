#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>v){
    int size = v.size();
    if(size == 0){
        cout<<"The vector is empty"<<endl;
        return;
    }
    for(int i = 0; i < size; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void print2DVector(vector<vector<int>> &arr){
    cout<<endl;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printArr(int* arr, int size){
    if(size == 0){
        cout<<"The array is empty"<<endl;
        return;
    }
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int sumOfDigit(int num){
    if(num == 0){
        return 0;
    }
    return num%10 + sumOfDigit(num/10);
}

int productOfDigit(int num){
    if(num == 0){
        return 1;
    }
    return num%10 * productOfDigit(num/10);
}

int reverseNum(int num, int rev = 0){
    if(num == 0){
        return rev;
    }
    
    rev = (rev * 10)+ (num%10);
    return reverseNum(num/10, rev);
}

int countZero(int num, int count = 0){
    if(num == 0){
        return count;
    }

    if(num%10 == 0){
        count++;
    }
    return countZero(num/10, count);

}

int numberOfSteps(int num, int count = 0){
    if(num == 0){
        return count;
    }
    if(num & 1){
        return numberOfSteps(num-1, count+1);
    }else{
        return numberOfSteps(num/2, count+1);
    }
}

bool isSorted(int *arr, int size, int i=0){
    if(i == size-1){
        return true;
    }
    if(arr[i] > arr[i+1]){
        return false;
    }
    return isSorted(arr, size, i+1);
}

int linearSearch(int *arr, int size, int target, int i = 0){
    if(i >= size){
        return -1;
    }
    if(arr[i] == target){
        return i;
    }
    return linearSearch(arr, size, target, i+1);
}

void findAllOccurances(int *arr, int size, int target, vector<int> &ans, int i = 0){
    if(i >= size){
        return;
    }
    if(arr[i] == target){
        ans.push_back(i);
    }
    findAllOccurances(arr, size, target, ans, i+1);
}
vector<int> getAllOccurances(int *arr, int size, int target, vector<int> list, int i = 0){
    if(i >= size){
        return list;
    }
    if(arr[i] == target){
        list.push_back(i);
    }
    return getAllOccurances(arr, size, target, list, i+1);
}

//without argument will create another list type vector for all function calls
vector<int> withOutArg(int *arr, int size, int target, int i = 0){
    //its not good approach because you are creating vector again and again which will increase space complexity
    vector<int>list;
    if(i >= size){
        return list;
    }
    if(arr[i] == target){
        list.push_back(i);
    }
    vector<int>fromAbove = getAllOccurances(arr, size, target, list, i+1);
    if(list.size() > 0){
        //collecting answer
        fromAbove.push_back(list[0]);
    }
    return fromAbove;
}

void triangle(int row, int col = 0){
    if(row == 0){
        return;
    }
    if(col < row){
        cout<<"*";
        triangle(row, col+1);
    }else{
        cout<<endl;
        triangle(row-1, 0);
    }
}
void triangleBackTrack(int row, int col = 0){
    if(row == 0){
        return;
    }
    if(col < row){
        triangleBackTrack(row, col+1);
        cout<<"*";
    }else{
        triangleBackTrack(row-1, 0);
        cout<<endl;
    }
}
void triangle1(int n, int row = 0, int col = 0){
    if(row >= n){
        return;
    }
    if(col <= row){
        cout<<"*";
        triangle1(n, row, col+1);
    }else{
        cout<<endl;
        triangle1(n, row+1, 0);
    }
}

void bubbleSortRec(int *arr, int i, int j = 0){
    if(i <= 0){
        return;
    }
    if(j<i){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
        bubbleSortRec(arr, i, j+1);
    }else{
        bubbleSortRec(arr, i-1, 0);
    }
}

//selection sort using minimum approach
void selectionSortRec(int *arr, int size, int i = 0, int j = 1, int min = 0){
    if(i >= size-1){
        return;
    }

    if(j <= size-1){
        if(arr[min] > arr[j]){
            min = j;
        }
        selectionSortRec(arr, size, i, j+1, min);
    }else{
        swap(arr[min], arr[i]);
        selectionSortRec(arr, size, i+1, i+2, i+1);
    }
}

void mergeSorted(int *arr, int s, int e){
    int size = e-s+1;
    int *mix = new int[size];
    int mid = (s+e)/2;

    int i = s;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            mix[k++] = arr[i++];
        }else{
            mix[k++] = arr[j++];
        }
    }

    while(i <= mid){
        mix[k++] = arr[i++];
    }
    while(j <= e){
        mix[k++] = arr[j++];
    }

    for(int i = 0; i < size; i++){
        arr[i+s] = mix[i];
    }
    delete []mix;
}

int partitionAgain(int *arr, int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pIndex = count+s;
    swap(arr[s], arr[pIndex]);

    int i =s, j = e;
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

void quickSortAgain(int *arr, int s, int e){
    if(s >= e){
        return;
    }
    int p = partitionAgain(arr, s, e);
    quickSortAgain(arr, s, p-1);
    quickSortAgain(arr, p+1, e);
}
void mergeSortAgain(int *arr, int s, int e){
    if(s >= e){
        return;
    }

    int mid = (s+e)/2;

    mergeSortAgain(arr, s, mid);
    mergeSortAgain(arr, mid+1, e);
    mergeSorted(arr, s, e);
}

string removeChar(string s, char ch, string ans="", int i = 0){
    if(i >= s.length()){
        return ans;
    }

    if(s[i] != ch){
        ans.push_back(s[i]);
    }
    return removeChar(s, ch, ans, i+1);
}

string removeCharAgain(string s, char ch, int i = 0){
    if(i >= s.length()){
        return "";
    }

    if(s[i] != ch){
        return s[i] + removeCharAgain(s, ch, i+1);
    }
    return removeCharAgain(s, ch, i+1);
}

bool startWith(string s1, string s2, int index){
    for(int i = 0; i < s2.length(); i++){
        if(s2[i] != s1[i+index]){
            return false;
        }
    }
    return true;
}

string removeStr(string s, string key, int i = 0){
    if(i >= s.length()){
        return "";
    }

    if(startWith(s, key, i)){
        return removeStr(s, key, i+key.length());
    }
    return s[i] + removeStr(s, key, i+1);
}

//this is for checking if starts with "app" and not startswith "apple" but the above startWith can be used for with ! operator for the same task thats why not using this
bool startWithCondition(string s1, string s2, string s3, int index){
    bool isTrue = true;
    for(int i = 0; i < s2.length(); i++){
        if(s2[i] != s1[i+index]){
            isTrue = false;
            break;
        }
    }
    if(isTrue){
        return false;
    }

    for(int i = 0; i < s3.length(); i++){
        if(s3[i] != s1[i+index]){
            return false;
        }
    }
    return true;
}

string removeStrWithCondition(string s,string notSkip, string key, int i = 0){
    if(i >= s.length()){
        return "";
    }

    if(startWith(s, key, i) && !startWith(s, notSkip, i)){
        return removeStrWithCondition(s, notSkip, key, i+key.length());
    }
    return s[i] + removeStrWithCondition(s, notSkip, key, i+1);
}

void subStr(string s, string output, vector<string> &ans, int i = 0){
    //if you are taking character first then you have to remove the character when returning (backtracking) else in first rec call do not take character and in second rec call take the character if you don't want to backtrack 
    if(i >= s.length()){
        ans.push_back(output);
        return;
    }
    output.push_back(s[i]);
    subStr(s, output, ans, i+1);
    output.pop_back();
    subStr(s, output, ans, i+1);
}

void subSet(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int size, int i = 0){
    if(i >= size){
        ans.push_back(output);
        return;
    }
    output.push_back(nums[i]);
    subSet(nums, output, ans, size, i+1);
    output.pop_back();
    subSet(nums, output, ans, size, i+1);
}

void towerOfHanoi(int n, char source, char dest, char helper){
    if(n == 1){
        cout<<"1\t"<<source<<" ---> "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1, source, helper, dest);
    cout<<n<<"\t"<<source<<" ---> "<<dest<<endl;
    towerOfHanoi(n-1, helper, dest, source);
}

int main() {
    // int num;
    // cout<<"Enter a number : ";
    // cin>>num;
    // cout<<"Sum is "<<sumOfDigit(num)<<endl;
    // cout<<"Product is "<<productOfDigit(num)<<endl;
    // cout<<"Reverse is "<<reverseNum(num)<<endl;
    // cout<<"Count is "<<countZero(num)<<endl;
    // cout<<"Count is "<<numberOfSteps(num)<<endl;

    // int arr[20];
    // int size;
    // cout<<"Enter the size : ";
    // cin>>size;
    // cout<<"Enter elements : ";
    // for(int i = 0; i < size; i++){
    //     cin>>arr[i];
    // }

    // cout<<isSorted(arr, size)<<endl;
    // int target;
    // cout<<"Enter a target : ";
    // cin>>target;
    // cout<<linearSearch(arr, size, target)<<endl;
    // vector<int>ans;
    // findAllOccurances(arr, size, target, ans);

    // vector<int>list;
    // list = getAllOccurances(arr, size, target, list);
    // list = withOutArg(arr, size, target);
    // printVector(list);

    // triangle(4);
    // cout<<endl;
    // triangle1(4);
    // cout<<endl;
    // triangleBackTrack(4);
    // cout<<endl;

    // bubbleSortRec(arr, size-1);
    // selectionSortRec(arr, size);
    // printArr(arr, size);
    // mergeSortAgain(arr, 0, size-1);
    // quickSortAgain(arr, 0, size-1);
    // printArr(arr, size);

    // string s, key, notSkip;
    // char ch;
    // cout<<"Enter a string : ";
    // cin>>s;

    // cout<<"Enter a character : ";
    // cin>>ch;

    // cout<<"Enter the string to remove : ";
    // cin>>key;

    // cout<<"Enter the string not to skip : ";
    // cin>>notSkip;
    // string ans = removeChar(s, ch);
    // string ans1 = removeCharAgain(s, ch);
    // cout<<ans<<endl;
    // cout<<ans1<<endl;
    // string ans2 = removeStr(s, key);
    // cout<<ans2<<endl;

    // string ans3 = removeStrWithCondition(s, notSkip, key);
    // cout<<ans3<<endl;

    // vector<string>data;
    // subStr(s, "", data);
    // for(int i = 0; i < data.size(); i++){
    //     cout<<data[i]<<endl;
    // }

    // vector<int> nums(10);
    // int size;
    // cout<<"Enter size : ";
    // cin>>size;
    // vector<int>output;
    // vector<vector<int>>data;

    // cout<<"Enter numbers : ";
    // for(int i = 0; i < size; i++){
    //     cin>>nums[i];
    // }
    // subSet(nums, output, data, size);
    // print2DVector(data);

    int n;
    cout<<"Enter a number : ";
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}