/*
https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&leftPanelTabValue=PROBLEM

Problem statement
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

Sample Input 1:
2
2 
2 5
1 4 25    
7
1 3 4 5 7 8 10
2 7 20
Sample Output 1:
2
11
Explanation For sample input 1:
For the first test case, 
On Day 2, Ninja will buy a 1-day pass with 1 coin.
On Day 5, Ninja will buy a 1-day pass with 1 coin.
In total, Ninja will spend 2 coins. Hence the answer is 2.

For the second test case,
On Day 1, Ninja will buy a 1-day pass with 2 coins.
On Day 3, Ninja will buy a 7-day pass with 7 coins valid for days 3,4,5...9.
On Day 10, Ninja will buy a 1-day pass with 2 coins.
In total, Ninja will spend 11 coins. Hence the answer is 11.
*/

int solve(int n, vector<int> &days, vector<int> &cost){

    // queue to store day & anscost in monthly and weekly pases
    queue<pair<int, int>> monthly;
    queue<pair<int, int>> weekly;

    int ans = 0;

    for(auto day : days){
        //Remove expired days from Queue
        //Ex: Current day is 46 and  the date in the front pair of queue is 1, 3, 4, 9, 11 and 16
        // U remove all of that
        while(!monthly.empty() && monthly.front().first + 30 <= day){
            monthly.pop();
        }
        while(!weekly.empty() && weekly.front().first + 7 <= day){
            weekly.pop();
        }

        //adding cost for current day
        monthly.push({day, ans+cost[2]});
        weekly.push({day, ans+cost[1]});

        ans = min(ans+cost[0], min(monthly.front().second, weekly.front().second ));
    }


    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost);
}