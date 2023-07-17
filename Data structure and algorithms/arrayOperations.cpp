#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

void linearSearch(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter an element to search : ";
    cin>>key;
    for(int i = 0; i < n; i++){
        if(key == arr[i]){
            cout<<key<<" is at index "<<i<<endl;
            return;
        }
    }
    cout<<key<<" doesn't exists in the array !!"<<endl;
}

void binarySearch(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter an element to search : ";
    cin>>key;

    int start = 0, end = n-1;
    while (start <= end){
        int mid = (start+end)/2;
        if(key == arr[mid]){
           cout<<key<<" is at index "<<mid<<endl;
           return;
        }else if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    cout<<key<<" doesn't exists in the array !!"<<endl;
}

void selectionSort(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array to sort"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<"Array before sorting"<<endl;
    printArray(arr, n);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"\nArray after sorting"<<endl;
    printArray(arr, n);

}

void findNumberOfChocolates(){
    int money, wrapperPerChoco;
    cout<<"Enter the amount and wrapper per chocolates"<<endl;
    cin>>money>>wrapperPerChoco;

    int numOfChocolates = money;
    int wrapper = money;

    while(wrapper >= wrapperPerChoco){
        if(wrapper % wrapperPerChoco == 0){
            numOfChocolates = numOfChocolates+(wrapper/wrapperPerChoco);
            wrapper = wrapper/wrapperPerChoco;
        }else{
            numOfChocolates = numOfChocolates+(wrapper/wrapperPerChoco);
            wrapper = (wrapper/wrapperPerChoco)+(wrapper%wrapperPerChoco);
        }
    }

    cout<<numOfChocolates<<" chocolates can be purchased."<<endl;
}

void bubbleSort(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array to sort"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<"Array before sorting"<<endl;
    printArray(arr, n);
    bool isSorted = false;
    for(int i = 0; i < n-1; i++){
        isSorted = true;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = false;
            }
        }
        if(isSorted){
            break;
        }
    }
    cout<<"\nArray after sorting"<<endl;
    printArray(arr, n);

}

void insertionSort(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array to sort"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<"Array before sorting"<<endl;
    printArray(arr, n);

    for(int i = 1; i < n; i++){
        int current = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    cout<<"\nArray after sorting"<<endl;
    printArray(arr, n);

}

void maxTillI(){
    int n, mx = -99999999;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        mx = max(mx, arr[i]);
        cout<<"Till index "<<i<<" max is : "<<mx<<endl;
    }
}

void sumOfSUbArray(){
    int n, curr = 0;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        curr = 0;
        for(int j = i; j < n; j++){
            curr = curr + arr[j];
            cout<<curr<<endl;
        }
    }
}

void longestArithmetic(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int ans = 2, curr = 2, j = 2, pd = arr[1] - arr[0];
    while(j<n){
        if(pd == arr[j]-arr[j-1]){
            curr++;
        }else{
            pd = arr[j]-arr[j-1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }

    cout<<ans<<endl;
}

int main(){
    // linearSearch();
    // binarySearch();
    // selectionSort();
    // findNumberOfChocolates();
    // bubbleSort();
    // insertionSort();
    // maxTillI();
    // sumOfSUbArray();
    longestArithmetic();
    return 0;
}