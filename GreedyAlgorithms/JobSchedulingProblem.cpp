/*
Job Sequencing Problem

Given a set of n jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

Examples :

Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
*/

class Solution 
{
    public:
    
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,  arr + n, cmp);
        
        int max_deadline = 0;
        for(int i = 0; i < n; i++) {
            max_deadline = max(max_deadline, arr[i].dead);
        }

        // Create a time slot array to track if a slot is occupied
        vector<int> slot(max_deadline + 1, -1);  // Slots start from 1, so size is max_deadline + 1
        
        int count = 0, totalProfit = 0;
        
        for(int i = 0; i < n; i++) {
            // Find a free slot for this job (starting from its deadline)
            for(int j = arr[i].dead; j > 0; j--) {
                if(slot[j] == -1) {  // If the slot is free
                    slot[j] = i;  // Assign this job to the slot
                    count++;
                    totalProfit += arr[i].profit;
                    break;  // Job assigned, break the loop
                }
            }
        }

        return {count, totalProfit};  // Return the number of jobs done and total profit
    } 
};