#include <iostream>
using namespace std;

int arraySum(int *arr, int n){
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    //for 1D array
    // int n;
    // cout<<"Enter a number : ";
    // cin>>n;

    //int arr[n]; //its a bad practice cause this will allocate memory in run time in stack. At that time if n is very large then, it will be crashed

    // int *arr = new int[n]; //this is good because it allocate memory for arr in heap memory 

    // cout<<"Enter the value now : ";
    // for(int i = 0; i < n; i++){
    //     cin>>arr[i];
    // }
    // cout<<"The sum is : "<<arraySum(arr, n)<<endl;

    // delete [] arr;


    // ******************************************************************************************
    //for 2D array

    int row, col;
    cout<<"Row : ";
    cin>>row;
    cout<<"Column : ";
    cin>>col;

    //array creation
    int ** arr = new int * [row];
    for(int i = 0; i < row; i++){
        arr[i] = new int [col];
    }

    //taking input
    cout<<"Now enter "<<row*col<<" elements : "<<endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin>>arr[i][j];
        }
    }

    //printing
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    for(int i = 0; i < row; i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}