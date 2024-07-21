/*
2392. Build a Matrix With Conditions

https://leetcode.com/problems/build-a-matrix-with-conditions/

You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

*/

/*
Since the qn constraints are before and after type so its most likely a topological sort problem
We can use the same code as in the cycle detection in directed graph and modify it to solve this problem

*/
class Solution {
public:
    vector<int> detectCycleInDirectedGraph(int n, vector<vector<int>> & edges) {
        vector<int>ans;
        unordered_map<int, list<int>>adj;
        // To calculate the indegrees of a node
        vector<int>indegrees(n);
        //prepare adj list
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            adj[u].push_back(v);
            //counts indegrees
            indegrees[v]++;
        }
        int totalNodesInTopo=0;
        queue<int>q;
        //push all the 0 indegree nodes to queue
        for(int i = 0; i<n; ++i){
           if (indegrees[i] == 0) {
              q.push(i);
           }
        }
        while(!q.empty()){
        	int frontnode=q.front();
        	q.pop();
        	//store the ans
            ans.push_back(frontnode + 1);
        	totalNodesInTopo++;
        	for( auto neighbor: adj[frontnode]){
          //Decrease the no of indegrees instead of marking visited
        		indegrees[neighbor]--;
          //if equal to 0 then push to the queue
        		if(indegrees[neighbor]==0){
        			q.push(neighbor);
        		}
        	}
        }
          //THE TOTAL NO OF NODES IN THE TOPOLOGICAL SORT SHOULD BE EQUAL TO THE NO OF NODES
          //BECAUSE  EVERY NODE IS VISITED ONLY ONCE
          //BUT IF A CYCLE  IS PRESENT THE NO OF NODES  ARE EITHER MORE OR LESS
          if(totalNodesInTopo==n){
            return ans;
          }
          return {};
        }



    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> mat(k, vector<int>(k, 0));

        vector<int>toporow = detectCycleInDirectedGraph(k, rowConditions);
        if(toporow.empty()){
            return {};
        }
        for(int i: toporow){
            cout<<i<<" ";
        }
        cout<<endl;
        vector<int>topocol = detectCycleInDirectedGraph(k, colConditions);
        if(topocol.empty()){
            return {};
        }
        for(int i: topocol){
            cout<<i<<" ";
        }

        for(int i=0; i<k; i++){
            int rownum = toporow[i];
            for(int j=0; j<k; j++){\
                if(rownum == topocol[j]){
                    mat[i][j] = rownum;
                    break;
                }
            }
        }

        return mat;
    }
};