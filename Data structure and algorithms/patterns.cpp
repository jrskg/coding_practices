#include <iostream>
using namespace std;

void hologramRectangle(){
    int row, col;
    cout<<"Enter rows and columns\n";
    cin>>row>>col;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(i == 0 || i == row-1 || j == 0 || j == col-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void invertedHalfPyramid(){
    int n;
    cout<<"Enter a number\n";
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < n - i){
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

void reversedHalfPyramid(){
    int n;
    cout<<"Enter a number\n";
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < n - i - 1){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

void pyramidNumber(){
    int n;
    cout<<"Enter a number\n";
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout<<i+1;
        }
        cout<<endl;
    }
}

void floydTriangle(){
    int n;
    int toBePrint = 1;
    cout<<"Enter a number\n";
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout<<toBePrint++;
        }
        cout<<endl;
    }
}

void butterflyPattern(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        for(int k = 1; k <= 2*n-2*i; k++){
            cout<<" ";
        }
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i = n; i != 0; i--){
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        for(int k = 1; k <= 2*n-2*i; k++){
            cout<<" ";
        }
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void invertedPatternNumber(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i; j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}

void zeroOnePattern(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i+1; j++){
            if((i+j) % 2 == 0){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
}

void rhombusPattern(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            cout<<" ";
        }
        for(int j = 0; j < n; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pyramidNumberPattern(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            cout<<" ";
        }
        for(int j = 0; j < i+1; j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void palindromicPattern(){
    int n, space = 0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        space = 0;
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
            space++;
        }
        for(int k = n-space; k >= 1; k--){
            cout<<k;
        }
        for(int m = 2; m <= i; m++){
            cout<<m;
        }
        cout<<endl;
    }
}

void zigZagPattern(){
    int n, space = 0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= n; j++){
            if((i+j) % 4 == 0 || (i == 2 && j%4 == 0)){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void pyramidUpDown(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= 2*i-1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = n; i != 0; i--){
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= 2*i-1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void hollowDiamondPattern(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= 2*i-1; j++){
            if(j == 1 || j == 2*i-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i = n; i != 0; i--){
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= 2*i-1; j++){
            if(j == 1 || j == 2*i-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void hollowDiamondRectangle(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            cout<<"*";
        }
        for(int j = 1; j <= 2*i-1; j++){
            if(j == 1 || j == 2*i-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        for(int j = 1; j <= n-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = n; i != 0; i--){
        for(int j = 1; j <= n-i; j++){
            cout<<"*";
        }
        for(int j = 1; j <= 2*i-1; j++){
            if(j == 1 || j == 2*i-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        for(int j = 1; j <= n-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void hollowRhombus(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= n; j++){
            if(i == 1 || i == n){
                cout<<"*";
            }else{
                if(j == 1 || j == n){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
}

void hollowButterfly(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1 || j == i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        for(int j = 1; j <= 2*n-2*i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= i; j++){
          if(j == 1 || j == i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for (int i = n; i != 0; i--){
        for(int j = 1; j <= i; j++){
            if(j == 1 || j == i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        for(int j = 1; j <= 2*n-2*i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= i; j++){
           if(j == 1 || j == i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int fact(int num){
    int factorial = 1;
    for(int i = num; i > 0; i--){
        factorial *= i;
    }
    return factorial;
}

void pascalTriangle(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cout<<fact(i)/(fact(i-j)*fact(j));
        }
        cout<<endl;
    }
}

int main(){
    hologramRectangle();
    // invertedHalfPyramid();
    // reversedHalfPyramid();
    // pyramidNumber();
    // floydTriangle();
    // butterflyPattern();
    // invertedPatternNumber();
    // zeroOnePattern();
    // rhombusPattern();
    // pyramidNumberPattern();
    // palindromicPattern();
    // pyramidUpDown();
    // zigZagPattern();
    // hollowDiamondPattern();
    // hollowDiamondRectangle();
    // hollowRhombus();
    // hollowButterfly();
    // pascalTriangle();
    return 0;
}