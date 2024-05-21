class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // To find the closest element to x
        int s=0, e=n-1;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] ==  x){
                s = mid + 1;
                e = mid - 1;
                break;
            }
            else if(arr[mid] > x){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        

        // Initialize pointers for two-way comparison
        int left = e;
        int right = s;
        vector<int> ans;
        int count = 0;

        // Find k closest elements
        while (count < k) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            } else if (right >= n) {
                ans.push_back(arr[left--]);
            } else {
                int diff1 = abs(arr[left] - x);
                int diff2 = abs(arr[right] - x);
                if (diff1 < diff2) {
                    ans.push_back(arr[left--]);
                } else {
                    ans.push_back(arr[right++]);
                }
            }
            count++;
        }

        return ans;
    }
};