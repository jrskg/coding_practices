#include <iostream> 
#include <vector> 
using namespace std;

void addToAns(vector<vector<int>>& ans, vector<vector<int>> &board, int n){
	vector<int>temp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>>&board, int n){
	//check back row
	int x = row, y = col;
	while(y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
	}

	//check upperLeft diagonal
	x = row, y = col;
	while(x >= 0 && y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		x--;
		y--;
	}

	//check lowerLeft diagonal
	x = row, y = col;
	while(x < n && y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		x++;
		y--;
	}
	return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
	if(col >= n){
		addToAns(ans, board, n);
		return;
	}

	for(int i = 0; i < n; i++){
		if(isSafe(i, col, board, n)){
			board[i][col] = 1;
			solve(col+1, ans, board, n);
			board[i][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n){
	vector<vector<int>>board(n, vector<int>(n, 0));
	vector<vector<int>>ans;
	solve(0, ans, board, n);

	return ans;
}

//***********************************************************************************************
bool canMove(int r, int c, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n){
    if((r >= 0 && r < n && c >= 0 && c < n) && !visited[r][c] && arr[r][c] == 1){
        return true;
    }
    return false;
}
void solveMaze(int r, int c, vector<vector<int>> &arr, vector<vector<bool>> &visited, vector<string> &ans, string path, int n){
    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    visited[r][c] = true;

    //down
    if(canMove(r+1, c, visited, arr, n)){
        solveMaze(r+1, c, arr, visited, ans, path+"D", n);
    }
    //left
    if(canMove(r, c-1, visited, arr, n)){
        solveMaze(r, c-1, arr, visited, ans, path+"L", n);
    }
    //right
    if(canMove(r, c+1, visited, arr, n)){
        solveMaze(r, c+1, arr, visited, ans, path+"R", n);
    }
    //up
    if(canMove(r-1, c, visited, arr, n)){
        solveMaze(r-1, c, arr, visited, ans, path+"U", n);
    }

    visited[r][c] = false;
}
vector<string> searchMaze(vector<vector<int>> &arr, int n){
    vector<string>ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    if(arr[0][0] == 0){
        return ans;
    }
    solveMaze(0, 0, arr, visited, ans, path, n);
    return ans;
}

int main(){

    return 0;
}