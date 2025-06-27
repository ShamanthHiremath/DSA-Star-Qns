// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.
*/
class Solution 
{
    bool knows(vector<vector<int> >& M, int n,int person1,int person2){
        if(M[person1][person2]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int>st;
        //store all candidate indexes that is 0, 1, 2, .... in the stack
        for(int i=0; i<n; i++){
            st.push(i);
        }
        while(st.size()!=1){
            //take two indexes for comparision ex. 2 and 1
            int person1=st.top();
            //pop it to store  the next
            st.pop();
            int person2=st.top();
            //pop
            st.pop();
            if(knows(M, n, person1, person2)){
                //push back the person2 if p1 knows p2, cuz p1 isnt celeb if he knows someone
                st.push(person2);
            }
            else{
                //push back person1 if p2 knows p1, cuz if p2 isnt celeb if he knows someone
                st.push(person1);
            }
        }
        //The topmost remaining is a potential celebrity
        int potentialCeleb=st.top();
        // NOTE the rowelements of potential cleebrity will have all zeros, because he doesnt knwo anyone
        //and at the same time his index col elements will be all 1 excpet one 0 which is [n][n] so n-1
        int zerocount=0;
        for(int i=0; i<n; i++){
            if(M[potentialCeleb][i]==0){
                zerocount++;
            }
        }
        if(zerocount!=n)return -1;
        //now count col elements if they are one
        int onecount=0;
        for(int i=0; i<n; i++){
            if(M[i][potentialCeleb]==1){
                onecount++;
            }
        }
        if(onecount!=n-1)return -1;
        return potentialCeleb;
        
        
    }
};


// OR EASY ONE O(1) SPACE

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int top = 0;
        int down = n-1;
        
        
        // A celebrity is a person who is known to all (all other's connection to this person should be 1)
        // but does not know anyone at a party (his entire row should be zero)
        
        while(top < down){
            // if the top pointerptr person knows down, he cannot be a CELEB
            if(mat[top][down]){
                top++;
            }
            // if the down pointerptr person knows top, he cannot be a CELEB
            else if(mat[down][top]){
                down--;
            }
            // if both dont know each other, maybe tehy're not friends, but they're not CELEBs either
            // because a CELEB is known by everyone!!
            else{
                top++;
                down--;
            }
        }
        
        // no one is a CELEB
        if(top>down){
            return -1;
        }
        
        // CELEB's row is zero
        for(int i=0; i<n; i++){
            if (i == top) continue;
            // if he knows anyone OR someone doesnt know him 
            if(mat[top][i] or !mat[i][top]){
                return -1;
            }
        }
        
        return top;
    }
};