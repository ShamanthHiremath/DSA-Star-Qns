/*
135. Candy

https://leetcode.com/problems/candy/

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.


Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
*/

/*

A kind of peak and fall problem, where we need to give more candies to the higher rating, and less to the lower rating, and if they are same, then we can give them one candy each.
During the rise in the peak, we need to give one more candy than the previous one, and during the fall, we need to give one less candy than the previous one, but we need to make sure that we don't violate the condition of giving more candies to the higher rating.

The idea is to traverse the ratings array and keep track of the peak and fall. We can use two pointers to traverse the array, one for the peak and one for the fall. We can also keep track of the total number of candies we need to give.
Instead of having two separate loops for peak and fall, we can combine them into a single loop. We can keep track of the peak and fall counts and add them to the total number of candies. We also need to subtract the minimum of the peak and fall counts from the total number of candies to avoid double counting.

this is possible since, a fall can only happen after a peak, and a peak can only happen after a fall, so we can just keep track of the peak and fall counts and add them to the total number of candies. and when calculating a fall, we can just subtract the minimum of the peak and fall counts from the total number of candies to avoid double counting, so that we the peak element is not counted twice, and we can just add the peak and fall counts to the total number of candies.

It will look like this:
Ratings: 1 2 3 4 3 3 3 4 5 4 3 2 1 2 2 3 4

                        .   
              .       .   .             .
            .   . . .      .          .
          .                  .   .  .  
        .                     .
*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int total = n;

        int i=1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                // all have alreqady been given a single chocolate and when they have same rating across, then there's no higher lower ranking shit
                i++;

            }

            // if the ratings keep increasing, we need to give one more candy than the previous one, which is if we start a peak with 0, the previous guy will get less candies than the higher one, we add peak since, it indicates icnrease, and how much should be added to that person
            int peak = 0;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                total += peak;
                i++;
            }

            
// fall indicates opposite, we need to assume that we start a reverse peak, adn add the contro as sum, not accordingly.
            int fall = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                fall++;
                total += fall;
                i++;
            }

            // we remove the minimum most of the peak, fall (since both are for same element, and we need more chocolates to satisyfy condition)
            total -= min(peak, fall);
        }


        return total;
    }
};


