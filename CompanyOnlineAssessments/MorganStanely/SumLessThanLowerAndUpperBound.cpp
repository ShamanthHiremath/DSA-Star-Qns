#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int lower, upper;
    cin >> lower >> upper;

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (sum >= lower && sum <= upper) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}