#include <iostream>
using namespace std;


bool isPresent(int arr[][3], int target, int mRows, int nCols){
    for(int i = 0; i < mRows; i++){
        for(int j = 0; j < nCols; j++){
            if(arr[i][j] == target){
                return 1;
            }
        }
    }
    return 0;
}

void rowSum(int arr[][3], int mRows, int nCols){
    for(int i = 0; i < mRows; i++){
        int sum = 0;
        for(int j = 0; j < nCols; j++){
            sum += arr[i][j];
        }
        cout<<"Sum : "<<sum<<endl;
    }
}

void columnSum(int arr[][3], int mRows, int nCols){
    for(int i = 0; i < mRows; i++){
        int sum = 0;
        for(int j = 0; j < nCols; j++){
            sum += arr[j][i];
        }
        cout<<"Sum : "<<sum<<endl;
    }
}

void largestRowSum(int arr[][3], int mRows, int nCols){
    int index = -1, total = INT32_MIN;
    for(int i = 0; i < mRows; i++){
        int sum = 0;
        for(int j = 0; j < nCols; j++){
            sum += arr[i][j];
        }
        if(total < sum){
            total = sum;
            cout<<total<<endl;
            index = i;
        }
    }
    cout<<"Largest Sum : "<<total<<endl;
    cout<<"Row Index : "<<index<<endl;
}

void wavePrint(int arr[][3], int mRows, int nCols){
    //column index is even then top->bottom
    //column index is odd then bottom->top
    cout<<"Wave print start...."<<endl;
    for(int col = 0; col < nCols; col++){
        if(col%2==0){
            for(int row = 0; row < mRows; row++){
                cout<<arr[row][col]<<" ";
            }
        }else{
            for(int row = mRows-1; row >= 0; row--){
                cout<<arr[row][col]<<" ";
            }
        }
    }
    cout<<"Wave print done...."<<endl;
}

void spiralPrint(int arr[][3], int mRows, int nCols){
    int totalElement = mRows * nCols;
    int count = 0;
    int firstRow = 0;
    int firstCol = 0;
    int lastRow = mRows - 1;
    int lastCol = nCols - 1;

    while (count < totalElement){
        //first row
        for(int index = firstRow; count < totalElement && index <= lastCol; index++){
            cout<<arr[firstRow][index]<<" ";
            count++;
        }
        firstRow++;

        //last column
        for(int index = firstRow; count < totalElement && index <= lastRow; index++){
            cout<<arr[index][lastCol]<<" ";
            count++;
        }
        lastCol--;

        //last row
        for(int index = lastCol; count < totalElement && index >= firstCol; index--){
            cout<<arr[lastRow][index]<<" ";
            count++;
        }
        lastRow--;

        //first col
        for(int index = lastRow; count < totalElement && index >= firstRow; index--){
            cout<<arr[index][firstCol]<<" ";
            count++;
        }
        firstCol++;
    }
    cout<<endl;
}

void rotate90Deg(int arr[][3], int mRows, int nCols){
    int result[nCols][mRows];
    for(int row = 0; row < mRows; row++){
        for(int col = 0; col < nCols; col++){
            result[col][mRows-1-row] = arr[row][col];
        }
    }
    cout<<"\nThe output after rotating 90 deg is"<<endl;
    for(int i = 0; i < nCols; i++){
        for(int j = 0; j < mRows; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool binarySearch2D(int arr[][3], int mRows, int nCols, int target){
    int end = (mRows * nCols) - 1;
    int start = 0;

    while(start <= end){
        int mid = start + (end-start)/2;
        int currElem = arr[mid/nCols][mid%nCols];
        if(target == currElem){
            return 1;
        }
        if(target < currElem){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return 0;
}

bool binarySearch2Dii(int arr[][5], int mRows, int nCols, int target){
    int rowIndex = 0;
    int colIndex = nCols - 1;
    int count = 0;//number of times the loop runs to find
    while(rowIndex < mRows && colIndex >= 0){
        count++;
        int elem = arr[rowIndex][colIndex];
        if(target == elem){
            cout<<"Count : "<<count<<endl;
            return 1;
        }
        if(target < elem){
            colIndex--;
        }else{
            rowIndex++;
        }
    }
    cout<<"Count : "<<count<<endl;
    return 0;
}

int main(){
    int arr[5][5];
    cout<<"Enter the elements of the array"<<endl;

    //row wise input taking 
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin>>arr[i][j];
        }
    }

    int target;
    cout<<"Target : ";
    cin>>target;

    // cout<<binarySearch2D(arr, 3, 3, target);
    cout<<binarySearch2Dii(arr, 5, 5, target)<<endl;

    // cout<<"The original array is"<<endl;
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // rotate90Deg(arr, 3, 3);


    //column wise input taking
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         cin>>arr[j][i];
    //     }
    // }
    // int target;
    // cout<<"What you want to search : ";
    // cin>>target;
    // cout<<isPresent(arr, target, 3, 3)<<endl;

    // rowSum(arr, 3, 3);
    // columnSum(arr, 3, 3);
    // largestRowSum(arr, 3, 3);
    // wavePrint(arr, 3, 3);
    // spiralPrint(arr, 3, 3);
    return 0;
}