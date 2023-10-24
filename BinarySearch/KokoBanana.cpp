class Solution {
private:
    bool isPossible(vector<int>& piles, int h, int mid){
        
        if(mid==0)return false;
        int hours=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid){
                hours++;
            }
            else{
                hours+=(piles[i]/mid)+(piles[i]%mid!=0);
            }
        }
        if(hours<=h){
            return true;
        }    
        else{
            return false;
        }
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()<2){
            if(piles[0]%h!=0){
                return piles[0]/h +1;
            }
            else{
                return piles[0]/h;
            }
        }
        long long int sum=0, ans=-1;
        for(int i=0;i<piles.size();i++)sum+=piles[i];
        int s=1;
        long long int e=sum, mid=(e-s)/2+s;
        while(s<=e){
            if(isPossible(piles, h, mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=(e-s)/2+s;
        }
        return ans;
    }
};
//OPTIMISED CODE
class Solution {

long long getHours(vector<int>& piles, long long speed) {
    long long count = 0;
    for(auto itr:piles) {
        count += (itr/speed + (itr%speed != 0));
    }
    return count;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long high = 1e10, low = 1;
        long long ans = low;
        while(low <= high) {
            int mid = (low + high)/2;
            if(h >= getHours(piles, mid)) {
                ans = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return (int)ans;
    }
};
//MORE OPTIMISED CODE
class Solution {

long long getHours(vector<int>& piles, long long speed) {
    long long count = 0;
    for(auto itr:piles) {
        count += (itr/speed + (itr%speed != 0));
    }
    return count;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long high = 1e10, low = 1;
        long long ans = low;
        while(low <= high) {
            int mid = (low + high)/2;
            if(h >= getHours(piles, mid)) {
                ans = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return (int)ans;
    }
};