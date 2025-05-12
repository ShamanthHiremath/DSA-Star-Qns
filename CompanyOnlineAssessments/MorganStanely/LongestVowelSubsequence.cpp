#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    int n = s.length();

    int l = 0;
    int r = 0;
    int ans = 0;

    while(r < n){

        while(r < n && !(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u')){
            r++;
        }
        l = r;
        
        while(r < n && (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u')){
            if(r + 1 < n && s[r] == s[r + 1]){
                l = r+1;
                break; 
            }
            ans = max(ans, r - l+1); 
            r++;
        }
    r++;
        
    }

    cout << ans << endl;

    return 0;
}