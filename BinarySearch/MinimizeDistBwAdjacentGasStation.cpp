/*
Minimize Max Distance to Gas Station

http://geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/0

We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.

Example 1:
Input:
n = 10
stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.

Example 2:
Input:
n = 10
stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
k = 2 
Output: 14.00 
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
*/
class Solution {
    public:
        int countStationsThatCanBePlaced(vector<int> &arr, long double dist){
            int cnt = 0;
            
            for(int i=1; i<arr.size(); i++){
                int noOfStationsBetweenTwoAdj = (int)((arr[i] - arr[i-1]) / dist);
                if(noOfStationsBetweenTwoAdj * dist == (arr[i] - arr[i-1])){
                    noOfStationsBetweenTwoAdj--;
                }
                cnt += noOfStationsBetweenTwoAdj;
            }
            
            return cnt;
        }
        
        double findSmallestMaxDist(vector<int> &stations, int k) {
            long double s = 1e-6, e = 0;
            
            for(int i=1; i<stations.size(); i++){
                e = max(e, (long double)(stations[i] - stations[i-1]));
            }
            
            while(e - s > 1e-6){
                long double mid = s + (e - s) / 2.0;
                int cnt = countStationsThatCanBePlaced(stations, mid);
                
                if(cnt > k){
                    s = mid;
                }
                else{
                    e = mid;
                }
            }
            
            return (double)e;
        }
    };
    