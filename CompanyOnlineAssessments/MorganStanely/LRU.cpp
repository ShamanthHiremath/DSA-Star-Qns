#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cap;
    cin >> cap;
    
    unordered_map<int, int> mp;

    int timer = 0;
    
    int miss = 0;
    
    for(int i = 0; i < n; i++){
        if(mp.size() == 0){
            mp[arr[i]] = 1;
            miss++;
        }
        else if(mp.find(arr[i]) != mp.end()){
            mp[arr[i]] = timer;

        }
        else if(mp.size() < cap){
            mp[arr[i]] = timer;
            miss++;

        }
        else{
            int min_time = INT_MAX;
            int lru_key;
            for(auto it : mp){
                if(it.second < min_time){
                    min_time = it.second;
                    lru_key = it.first;
                }
            }
            miss++;
            mp.erase(lru_key);
            mp[arr[i]] = timer;
        }
            
        timer++;
    }
    
    cout<<miss<<endl;
    return 0;
}