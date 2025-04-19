'''
3219. Minimum Cost for Cutting Cake II

https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/

There is an m x n cake that needs to be cut into 1 x 1 pieces.

You are given integers m, n, and two arrays:

horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.
In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:

Cut along a horizontal line i at a cost of horizontalCut[i].
Cut along a vertical line j at a cost of verticalCut[j].
After the cut, the piece of cake is divided into two distinct pieces.

The cost of a cut depends only on the initial cost of the line and does not change.

Return the minimum total cost to cut the entire cake into 1 x 1 pieces.

 

Example 1:

Input: m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]

Output: 13

Explanation:

Perform a cut on the vertical line 0 with cost 5, current total cost is 5.
Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
The total cost is 5 + 1 + 1 + 3 + 3 = 13.

Example 2:

Input: m = 2, n = 2, horizontalCut = [7], verticalCut = [4]

Output: 15

Explanation:

Perform a cut on the horizontal line 0 with cost 7.
Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
The total cost is 7 + 4 + 4 = 15.
'''

class Solution(object):
    def minimumCost(self, m, n, horizontalCut, verticalCut):
        # make a cuts array with 0 indicating the horizCut, and 1 indicating vertiCut
        cuts = [(cost, 0) for cost in horizontalCut] + [(cost, 1) for cost in verticalCut]
        # sort it in descending order
        cuts.sort(reverse=True, key=lambda x: x[0])
        
        # initially there is 1 horizontal and 1 vertically cut peiece (which is the paper itself)
        h =  v = 1
        res = 0
        for cost,cut in cuts:
            # If it's a horizontal cut:
            # It affects all current vertical pieces → cost is cost * v.
            # After the cut, horizontal pieces increase (h += 1)
            if cut == 0:
                res += cost * v
                h += 1
            # If it's a vertical cut:
            # It affects all current horizontal pieces → cost is cost * h.
            # After the cut, vertical pieces increase (v += 1)
            else:
                res += cost * h
                v += 1
        return res