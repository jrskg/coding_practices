#include <iostream>
#include <vector>
using namespace std;

void printMaxAndMin(int arr[], int size){
    int min = INT32_MAX;
    int max = INT32_MIN;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout<<"The minimum value is : "<<min<<endl;
    cout<<"The maximum value is : "<<max<<endl;
}

void sumOfArray(int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    cout<<"The sum is : "<<sum<<endl;
}

void reverseArray(int arr[], int size){
    for(int i = 0; i < size/2; i++){
        // arr[i] = arr[i] + arr[size-1-i];
        // arr[size-1-i] = arr[i] - arr[size-1-i];
        // arr[i] = arr[i] - arr[size-1-i];
        swap(arr[i], arr[size-1-i]);
    }
}

void printIntArray(int arr[], int size){
    cout<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printIntVector(vector<int>arr, int size){
    cout<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[], int size){
    for (int i = 0; i < size; i+=2){
        if(i+1 < size){
            swap(arr[i], arr[i+1]);
        }
    }
    
}


// my solution
void uniqueElement(int arr[], int size){
    int unique;
    for (int i = 0; i < size; i++){
        int cur = arr[i];
        if(cur == 0){
            continue;
        }
        for (int j = i+1; j < size; j++){
            if(cur == arr[j]){
                arr[i] = 0;
                arr[j] = 0;
            }
        }
    }
    // sort(arr.begin(), arr.end());

    for (int i = 0; i < size; i++){
        if(arr[i] != 0){
            unique = arr[i];
            break;
        }
        unique = 0;
    }
    // printIntArray(arr, size);
    cout<<"Unique element is : "<<unique<<endl;
}

//optimized solution
void uniqueElementOptimized(int arr[], int size){
    int unique = 0;
    for (int i = 0; i < size; i++){
        unique = unique^arr[i];
        cout<<unique<<endl;
    }
    cout<<"Unique element is : "<<unique<<endl;
}

void duplicateElement(int arr[], int size){
    int total = 0;
    int least = 0;
    for (int i = 0; i < size; i++){
        total = total + arr[i];
        if(i < size-1){
            least = least + (i+1);
        }
    }
    cout<<"Duplicate element is : "<<total-least<<endl;
}

void intersection(int arr1[], int arr2[], int size1, int size2){
    int i = 0, j = 0;
    while(i < size1 && j < size2){
        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else{
            j++;
        }
    }
}

void print2DArray(vector<vector<int>> arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void pairSum(int arr[], int size, int num){
    vector<vector<int>>ans;
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if(arr[i] + arr[j] == num){
                vector<int>temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    print2DArray(ans);
}

void sortZeroOne(int arr[], int size){
    int i = 0, j = size-1;
   while(i < j){
        while(arr[i] == 0 && i<j){
            i++;
        }
        while(arr[j] == 1 && i<j){
            j--;
        }
        if(arr[i] == 1 && arr[j] == 0 && i<j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
   }
    printIntArray(arr, size);
}

void reverseAfterIndex(vector<int> &v, int index, int size){
    int start = index+1;
    int end = size-1;
    while (start <= end){
        swap(v[start], v[end]);
        start++;
        end--;
    }
    
}

void mergeSortedInFirstArray(vector<int> &firstArr, int size1, vector<int> secondArr, int size2){
    int i = 0, j = 0;
    while(i < size1 && j < size2){
        if(firstArr[i] < secondArr[j]){
            i++;
        }else{
            for(int k = size1-1; k >= i; k--){
                firstArr[k+1] = firstArr[k];
            }
            firstArr[i++] = secondArr[j++];
            size1++;
        }
    }
    while(j < size2){
        firstArr[i++] = secondArr[j++];
    }
}  

void moveZeroToRight(vector<int> &v, int size){
    int nonZero = 0;
    for(int i = 0; i < size; i++){
        if(v[i] != 0){
            swap(v[i], v[nonZero]);
            nonZero++;
        }
    }
}

void rotate(vector<int> &v, int size, int key){
    vector<int> temp(size);
    for(int i = 0; i < size; i++){
        temp[(i+key)%size] = v[i];
    }
    v = temp;
}

bool checkSortedRotated(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i-1]>nums[i]){
            count++;
        }
    }
    if(nums[n-1]>nums[0]){
        count++;
    }
    return count <= 1;
}

void sumTwoArray(vector<int> arr1, int size1, vector<int> arr2, int size2){
    int i = size1 - 1;
    int j = size2 - 1;
    int carry = 0;
    string s = "";

    while(i >= 0 && j >= 0){
        int sum = (arr1[i]+arr2[j]+carry)%10;
        carry = (arr1[i]+arr2[j]+carry)/10;
        s = to_string(sum)+s;
        i--;
        j--;
    }
    while(i >= 0){
        int sum = (arr1[i]+carry)%10;
        carry = (arr1[i]+carry)/10;
        s = to_string(sum)+s;
        i--;
    }
    while(j >= 0){
        int sum = (arr2[j]+carry)%10;
        carry = (arr2[j]+carry)/10;
        s = to_string(sum)+s;
        j--;
    }
    while(carry != 0){
        int sum = carry%10;
        carry = carry/10;
        s = to_string(sum)+s;
    }
    cout<<s<<endl;
}

int main()
{
    // int size;
    // cout<<"Enter the size of array : ";   
    // cin>>size; 
    // int arr[100];
    // cout<<"Enter the element of the array"<<endl;
    // for(int i = 0; i < size; i++){
    //     cin>>arr[i];
    // } 

    // printMaxAndMin(arr, size);
    // sumOfArray(arr, size);

    // printIntArray(arr, size);
    // reverseArray(arr, size);
    // printIntArray(arr, size);

    // printIntArray(arr, size);
    // swapAlternate(arr, size);
    // printIntArray(arr, size);

    // uniqueElement(arr, size);
    // uniqueElementOptimized(arr, size);

    // duplicateElement(arr, size);
    // int arr1[] = {1,2,2,3,4};
    // int arr2[] = {3,4,5,6};
    // intersection(arr1, arr2, 5, 4);

    // cout<<"Enter the element to find pair of : "<<endl;
    // int num;
    // cin>>num;
    // pairSum(arr, size, num);

    // sortZeroOne(arr, size);


    int size;
    cout<<"Enter the size of vector : ";   
    cin>>size; 
    vector<int> v(10);
    cout<<"Enter the element of the vector"<<endl;
    for(int i = 0; i < size; i++){
        cin>>v[i];
    } 

    // int index;
    // cout<<"Enter the index : "; 
    // cin>>index;  
    // printIntVector(v, size);
    // reverseAfterIndex(v, index, size);
    // printIntVector(v, size);

    // moveZeroToRight(v, size);
    // printIntVector(v, size);

    // rotate(v, size, 3);
    // printIntVector(v, size);


    int size2;
    cout<<"Enter the size of second vector : ";   
    cin>>size2; 
    vector<int> v2(10);
    cout<<"Enter the element of the second vector"<<endl;
    for(int i = 0; i < size2; i++){
        cin>>v2[i];
    } 

    sumTwoArray(v, size, v2, size2);

    return 0;
}