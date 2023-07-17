#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){
    while (start <= end) {
        int mid = start+(end-start)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}

//search for left only
int leftMostIndex(int arr[], int size, int elem){
    int start = 0;
    int end = size -1;
    int left = -1;
    while (start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == elem){
            left = mid;
            end = mid -1;
        }else if(arr[mid] < elem){
            start = mid+1;
        }else{
            end = mid -1;
        }
    }
    return left;
}

//search for right only
int rightMostIndex(int arr[], int size, int elem){
    int start = 0;
    int end = size -1;
    int right = -1;
    while (start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == elem){
            right = mid;
            start = mid + 1;
        }else if(arr[mid] < elem){
            start = mid+1;
        }else{
            end = mid -1;
        }
    }
    return right;
}

void leftRightIndex1(int arr[], int size, int elem){
    int leftMost = leftMostIndex(arr, size, elem);
    int rightMost = rightMostIndex(arr, size, elem);
    cout<<"Left Most : "<<leftMost<<" Right Most : "<<rightMost<<endl;
    cout<<"Number of occurences : "<<rightMost-leftMost+1<<endl;
}

void leftRightIndex2(int arr[], int size, int elem){
    int ind = binarySearch(arr, 0, size-1, elem);
    int left = ind;
    int right = ind;

    if(ind == -1){
        cout<<"Left Most : "<<left<<" and Right Most : "<<right<<endl;
        return;
    }

    while (left >= 0 && arr[left-1] == elem){
        left--;
    }
    while (right <= size-1 && arr[right+1] == elem){
        right++;
    }
    
    cout<<"Left Most : "<<left<<" and Right Most : "<<right<<endl;
}

int findPivot(int arr[], int size){
    int start = 0;
    int end = size-1;
    while (start < end){
        int mid = start + (end-start)/2;
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }else{
            end = mid;
        }
    }
    return start;
}

int searchInSortedRotated(int arr[], int size, int elem){
    int pivot = findPivot(arr, size);
    if(elem >= arr[pivot] && elem <= arr[size-1]){
        return binarySearch(arr, pivot, size-1, elem);
    }else{
        return binarySearch(arr, 0, pivot-1, elem);
    }
}

int squareRootInt(int x) {
    if(x == 0)
        return 0;

    int ans;
    int start = 1;
    int end = x;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(mid == x/mid){
            return mid;
        }
        if(mid > x/mid){
            end = mid-1;
        }else{
            ans = mid;
            start = mid+1;
        }
        
    }
    return ans;
}

double morePrecision(int precision, int tempSol, int num){
    double ans = tempSol;
    double factor = 1;
    for (int i = 0; i < precision; i++){
        factor = factor/10;
        for (double j = ans; j*j < num; j = j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    // int size;
    // cout<<"Enter the size of array : ";   
    // cin>>size; 

    // int arr[100];
    // cout<<"Enter the element of the array"<<endl;
    // for(int i = 0; i < size; i++){
    //     cin>>arr[i];
    // }

    // int elem;
    // cout<<"Enter the element to search : ";   
    // cin>>elem; 
    // leftRightIndex2(arr, size, elem);
    // leftRightIndex1(arr, size, elem);

    // int indexOfPivot = findPivot(arr, size);
    // cout<<"The index is : "<<indexOfPivot<<" and the element is : "<<arr[indexOfPivot]<<endl;

    // int elem;
    // cout<<"Enter the element to search : ";
    // cin>>elem;
    // int elemIndex = searchInSortedRotated(arr, size, elem);
    // cout<<"The index is : "<<elemIndex<<endl;

    int number;
    cout<<"Enter a number : ";
    cin>>number;
    int tempSol = squareRootInt(number);
    cout<<morePrecision(3, tempSol, number);
    return 0;
}