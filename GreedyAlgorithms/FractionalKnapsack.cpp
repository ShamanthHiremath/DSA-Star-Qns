/*
Fractional Knapsack

https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Given two arrays value[] and weight[], you need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack. Return a double value representing the maximum value in the knapsack, rounded to 6 decimal places.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the comments above the given function.

Examples :

Input: values[] = [60, 100, 120], weights[] = [10, 20, 30], w = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 

Input: values[] = [60, 100], weights[] = [10, 20], w = 50
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
        // Your code here
        vector<pair<double, pair<int, int>>> items;
        
        for(int i=0; i<values.size(); i++){
            double valuePerWt  = 1.0 * values[i] / weights[i];
            items.push_back({valuePerWt, {weights[i], values[i]}});
        }

        // Sorting the items based on valuePerWt, so that we choose the items with highest valuePerWt first
        sort(items.begin(), items.end());
        
        double total = 0;
        
        // start from the end of the items array, so that we can choose the items with highest valuePerWt first
        for(int i=items.size()-1; i>=0; i--){
            if(items[i].second.first > w){
                total += items[i].first * w;
                w = 0;
                // break;
            }
            else{
                total += items[i].second.second;
                w -= items[i].second.first;
            }
        }
        
        return total;
    }
};