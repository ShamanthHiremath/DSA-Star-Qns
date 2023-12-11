#include <bits/stdc++.h> 
/*
GREEDY SOLN DOESNT WORK BECAUSE WE ONLY LOOK FOR THE STEP WITH A DIFFERENCE OF MINIMUM ENERGY 
BUT NEVER CHECK THE COMPLETE SOLN AND FIND THE MIN SOLS

EX: 30 10 60 10 60 50
GREEDY===== Goes to 30, checks for min diff so goes to 10, totalenergy=20, goes to 10, totalenergy=20, now goes to 50, totalenergy is 60
BUTTTT THE ACTUAL SOLN IS DIFFERENT
DP======= Goes to 30, then to 60, then to 60 again, then to 50, totalenergy is 40, which is minimum!!!!!1
*/

//DP BABBBBBYYYYYYYYYYYYYYYYYY

#include <bits/stdc++.h> 
int solve(int n, vector<int> &heights, int i,  vector<int>&dp) {
    //the 0th step will use 0 energy
    if(i<=0)return 0;
    //the min energy spent which if has been already stored in dp[i]i.e dp[i]!=-1(unsaved)is returned
    if(dp[i]!=-1)return dp[i];
    //this the total energy spent on jumping 1 step ahead + the min of all the steps behind
    int jump1=abs(heights[i]-heights[i-1])+solve(n, heights, i-1, dp);
    //for the first/last but one/ n-1/1st index the min would be jump1, so take jump2 as INT_MAX
    int jump2=INT_MAX;
    if(i>1){
    //this the total energy spent on jumping 1 step ahead + the min of all the steps behind
        jump2=abs(heights[i]-heights[i-2])+solve(n, heights, i-2, dp);
    }
    //return dp[i]=min(jump1, jump2);
    //check which is the min when u jumped 1 step or 2 steps
    int minways=min(jump1, jump2);
    //store it in dp[i] cuz that step index will have min energy computed
    dp[i]=minways;
    //return it
    return minways;
}

int frogJump(int n, vector<int> &heights)
{
    //initialise a vector to  store the returned minvalue for each jump
    vector<int>dp(n+1,-1);
    return solve(n, heights, n-1, dp);

}

//BAKI SAB THEEK HAIN PAR SOCHNE KA TAREEKA TODA CAZUAL HAIN
int solve(int n, std::vector<int> &heights, int i) {
    int lost;
    if (i == n - 1) {
        return 0;
    }
    if (i + 1 == n - 1) {
        lost = (abs(heights[i] - heights[i + 1]));
        return lost;
    }
    if ((abs(heights[i] - heights[i + 1])) < (abs(heights[i] - heights[i + 2]))) {
        lost = (abs(heights[i] - heights[i + 1]));
        return lost + solve(n, heights, i + 1);
    } else {
        lost = (abs(heights[i] - heights[i + 2]));
        return lost + solve(n, heights, i + 2);
    }
}

int frogJump(int n, std::vector<int> &heights) {
    long long int energy = 0;
    int i = 0;
    while (i < n - 1) {
        int lost = 0;
        if (i + 1 == n - 1) {
            lost = (abs(heights[i] - heights[i + 1]));
            i++;
        } else if ((abs(heights[i] - heights[i + 1])) < (abs(heights[i] - heights[i + 2]))) {
            lost = (abs(heights[i] - heights[i + 1]));
            i++;
        } else {
            lost = (abs(heights[i] - heights[i + 2]));
            i = i + 2;
        }
        energy += lost;
    }
    return energy;
}

int main() {
    // Add code here to test the frogJump function with sample inputs
    return 0;
}
