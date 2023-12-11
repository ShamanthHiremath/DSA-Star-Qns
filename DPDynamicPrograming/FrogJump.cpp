#include <bits/stdc++.h> 
/*
GREEDY SOLN DOESNT WORK BECAUSE WE ONLY LOOK FOR THE STEP WITH A DIFFERENCE OF MINIMUM ENERGY 
BUT NEVER CHECK THE COMPLETE SOLN AND FIND THE MIN SOLS

EX: 30 10 60 10 60 50
GREEDY===== Goes to 30, checks for min diff so goes to 10, totalenergy=20, goes to 10, totalenergy=20, now goes to 50, totalenergy is 60
BUTTTT THE ACTUAL SOLN IS DIFFERENT
DP======= Goes to 30, then to 60, then to 60 again, then to 50, totalenergy is 40, which is minimum!!!!!1
*/
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
