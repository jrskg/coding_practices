#include <iostream>
using namespace std;

int main(){

    // int num = 5;
    // int *ptr = &num;

    // cout<<num<<endl;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;
    // cout<<&num<<endl;


    // char st[] = "ABCD";
    // for(int i = 0; st[i] != '\0'; i++) {
    //     cout << st[i] << *(st)+i << *(i+st) << i[st];
    // }

    // int arr[10] = {1, 21, 32, 43, 54, 65, 77, 88, 99, 180};

    // cout<<"arr : "<<arr<<endl;
    // cout<<"&arr[0] : "<<&arr[0]<<endl;
    // cout<<"*arr : "<<*arr<<endl;
    // cout<<"*arr+1 : "<<*arr+1<<endl;
    // cout<<"*(arr+1) : "<<*(arr+1)<<endl;
    // cout<<"arr[0] : "<<arr[0]<<endl;
    // cout<<"0[arr] : "<<0[arr]<<endl;
    // cout<<"arr[2] : "<<arr[2]<<endl;
    // cout<<"*(arr+2) : "<<*(arr+2)<<endl;

    // bool isTrue = &arr[3] == arr+3;
    // cout<<"isTrue "<<isTrue<<endl;

    int val = 5;
    int *p = &val;
    int **p2 = &p;

    cout<<"val : "<<val<<endl;
    cout<<"val : "<<*p<<endl;
    cout<<"val : "<<**p2<<endl;

    cout<<"Address of val : "<<&val<<endl;
    cout<<"Address of val : "<<p<<endl;
    cout<<"Address of val : "<<*p2<<endl;

    cout<<"Address of p : "<<&p<<endl;
    cout<<"Address of p : "<<p2<<endl;

    cout<<"Address of p2 : "<<&p2<<endl;
    
    return 0;
}