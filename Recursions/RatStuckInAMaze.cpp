class Solution{
    private:
    
    bool allowOrBlock(vector<vector<int>>& m, int n, int x, int y, vector<vector<int>>& visited) {
        if (x < 0 || x >= n || y < 0 || y >= n || m[x][y] == 0 || visited[x][y] == 1) {
            return false; // block
        }
        return true; // allows
    }
    
    void solve(vector<string>&ans, string output, vector<vector<int>> &m, int n, int x, int y, vector<vector<int>>visited){
        if(x==(n-1) && y==(n-1)){
            ans.push_back(output);
            return ;
        }
        visited[x][y]=1;
        //Downward
        if(allowOrBlock(m, n, x+1, y, visited)){
            output.push_back('D');
            solve(ans, output, m, n, x+1, y, visited);
            output.pop_back();
        }
        //Upward
        if(allowOrBlock(m, n, x-1, y, visited)){
            output.push_back('U');
            solve(ans, output, m, n, x-1, y, visited);
            output.pop_back();
        }
        //Leftward
        if(allowOrBlock(m, n, x, y-1, visited)){
            output.push_back('L');
            solve(ans, output, m, n, x, y-1, visited);
            output.pop_back();
        }
        //Rightward
        if(allowOrBlock(m, n, x, y+1, visited)){
            output.push_back('R');
            solve(ans, output, m, n, x, y+1, visited);
            output.pop_back();
        }
        visited[x][y]=0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0) return {};
        vector<string> ans;
        string output="";
        vector<vector<int>>visited=m;
        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        solve(ans, output, m, n, 0, 0, visited);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
