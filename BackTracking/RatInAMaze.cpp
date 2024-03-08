#include <bits/stdc++.h> 

bool validMove(int x, int y, int n, vector<vector<int>> &arr, vector<vector<bool>> &visited){
    if(( x>=0 && x<=n-1) && ( y>=0 && y<=n-1) && ( visited[x][y]!=1 ) && ( arr[x][y]==1 ) ){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x, int y, int n, string path, vector<vector<int>> &arr, vector<string> &ans, vector<vector<bool>> &visited){
    //Base case condition
    //Index out of range
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    
    //Mark Visited
    visited[x][y]=1;

    //Moving Down D
    if(validMove(x+1, y, n, arr, visited)){
        path.push_back('D');
        solve(x+1, y, n, path, arr, ans, visited);
        path.pop_back();
    }
    //Moving Left L
    if(validMove(x, y-1, n, arr, visited)){
        path.push_back('L');
        solve(x, y-1, n, path, arr, ans, visited);
        path.pop_back();
    }
    //Moving Right R
    if(validMove(x, y+1, n, arr, visited)){
        path.push_back('R');
        solve(x, y+1, n, path, arr, ans, visited);
        path.pop_back();
    }
    //Moving Up U
    if(validMove(x-1, y, n, arr, visited)){
        path.push_back('U');
        solve(x-1, y, n, path, arr, ans, visited);
        path.pop_back();
    }

    //Unmark visited for other iterations
    visited[x][y]=0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>>visited(n, vector<bool>(n, 0));
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0, 0, n, path, arr, ans, visited);
    return ans;
}