#include <unordered_map>

int maximumFrequency(vector<int> &arr, int n)
{
    int ans;
    unordered_map<int,int>count;
    for(int i=0; i<arr.size(); i++){
        count[arr[i]]++;
    }
    int maxi=INT_MIN;
    for (auto i : count) {
        maxi = max(maxi, i.second);
    }
    for(auto i: arr){
        if(count[i]==maxi){
            return i;
        }
    }
    
    return -1;
}