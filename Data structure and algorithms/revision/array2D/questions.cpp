#include <iostream>
#include <vector>
using namespace std;

void print2DVector(vector<vector<int>>& matrix){
  cout<<"2D array"<<endl;
  int row = matrix.size();
  for(int i = 0; i < row; i++){
    int col = matrix[i].size();
    for(int j = 0; j < col; j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}

void wavePrint(vector<vector<int>> &matrix){
  int row = matrix.size(), col = matrix[0].size();
  cout<<"Wave print"<<endl;
  for(int i = 0; i < col; i++){
    for(int j = 0; j < row; j++){
      int idx = i%2 == 0 ? j : row-1-j;
      cout<<matrix[idx][i]<<" ";
    }
  }
  cout<<endl;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int>ans;
  int row = matrix.size(), col = matrix[0].size();
  int n = row%2 == 0 ? row/2 : (row/2)+1;
  int count = 0, total = row*col;;

  for(int i = 0; i < n; i++){
    for(int c = i; c < col-i && count != total; c++){
      ans.push_back(matrix[i][c]);
      count++;
    }

    for(int r = i+1; r < row-i && count != total; r++){
      ans.push_back(matrix[r][col-i-1]);
      count++;
    }

    for(int c = col-i-2; c >= i && count != total; c--){
      ans.push_back(matrix[row-i-1][c]);
      count++;
    }

    for(int r = row-i-2; r > i && count != total; r--){
      ans.push_back(matrix[r][i]);
      count++;
    }
  }
  return ans;
}

void transpose(vector<vector<int> >& matrix, int n){ 
  for(int row = 1; row < n; row++){
    for(int col = 0; col < row; col++){
      swap(matrix[row][col], matrix[col][row]);
    }
  }
}

void rotate90Deg(vector<vector<int>> &matrix){
  int n = matrix.size();
  vector<vector<int>> changed(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      changed[j][n-i-1] = matrix[i][j];
    }
  }

  print2DVector(changed);
}

void rotate90DegWithoutSpace(vector<vector<int>> &matrix){
  int n = matrix.size();
  //transposing 
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  int start = 0, end = n-1;
  while(start < end){
    for(int i = 0; i < n; i++){
      swap(matrix[i][start], matrix[i][end]);
    }
    start++, end--;
  }
}

void rotate90DegAntiClock(vector<vector<int>> &matrix){
  int n = matrix.size();
  //transposing
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  int start = 0, end = n-1;
  while(start < end){
    for(int i = 0; i < n; i++){
      swap(matrix[start][i], matrix[end][i]);
    }
    start++, end--;
  }
}

void rotate180AntiClock(vector<vector<int>> &matrix){
  int n = matrix.size(), start = 0, end = n - 1;

  while(start < end){
    for(int i = 0; i < n; i++){
      swap(matrix[start][i], matrix[end][i]);
    }
    start++, end--;
  }

  start = 0, end = n - 1;
  while(start < end){
    for(int i = 0; i < n; i++){
      swap(matrix[i][start], matrix[i][end]);
    }
    start++, end--;
  }
}

void rotateKTimes(vector<vector<int>> &matrix, int k){
  k = k % 4;
  if(k == 1)
    rotate90DegWithoutSpace(matrix);
  else if(k == 2)
    rotate180AntiClock(matrix);
  else if(k == 3)
    rotate90DegAntiClock(matrix);
}

int main() {
  int row, col;
  cout<<"Enter row and column : ";
  cin>>row>>col;

  vector<vector<int>> matrix(row, vector<int>(col, -1));
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cin>>matrix[i][j];
    }
  }
  
  // wavePrint(matrix);
  // rotate90Deg(matrix);
  // rotate90DegWithoutSpace(matrix);
  // rotate180AntiClock(matrix);
  // rotate90DegAntiClock(matrix);
  int k;
  cout<<"Enter k : ";
  cin>>k;
  rotateKTimes(matrix, k);
  print2DVector(matrix);

  return 0;
}