#include <iostream>
using namespace std;

void print2D(int **ptr, int row, int col){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cout<<*(*(ptr+i)+j)<<" ";
    }cout<<endl;
  }
}

void print3D(int ***ptr, int x, int y, int z){
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      for(int k = 0; k < z; k++){
        cout<<*(*(*(ptr+i)+j)+k)<<" ";
      }cout<<endl;
    }cout<<endl;
  }
}

int main() {
  int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
  cout<<"For normal"<<endl;
  cout<<arr<<endl;
  cout<<arr[0]<<endl;
  cout<<arr[0][0]<<endl;


  int row = 3, col = 3;
  int **ptr = new int *[row];
  for(int i = 0; i < row; i++){
    *(ptr+i) = new int[col];
  }

  cout<<"Enter all element : ";
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cin >> *(*(ptr+i)+j);
    }
  }

  cout<<"For pointer"<<endl;
  cout<<ptr<<endl;
  cout<<ptr[0]<<endl;
  cout<<ptr[0][0]<<endl;

  // print2D(ptr, row, col);

  for(int i = 0; i < row; i++){
    delete[] ptr[i];
  }
  delete[] ptr;


  // 3D from here
  // int x, y, z;
  // cout<<"Enter x, y, z : ";
  // cin>>x>>y>>z;

  // int ***ptr = new int **[x];
  // for(int i = 0; i < x; i++){
  //   ptr[i] = new int*[y];
  //   for(int j = 0; j < y; j++){
  //     ptr[i][j] = new int[z];
  //   }
  // }

  // cout<<"Enter all elements : ";
  // for(int i = 0; i < x; i++){
  //   for(int j = 0; j < y; j++){
  //     for(int k = 0; k < z; k++){
  //       cin>> *(*(*(ptr + i)+j)+k);
  //     }
  //   }
  // }

  // print3D(ptr, x, y, z);
  // cout<<endl;

  // for(int i = 0; i < x; i++){
  //   for(int j = 0; j < y; j++){
  //     delete[] ptr[i][j];
  //   }
  //   delete[] ptr[i];
  // }

  // delete[] ptr;
  return 0;
}