bool isPossible(vector<int> &stalls, int k, int n, int mid) {
    int cows=1;
    int minposition=stalls[0];
    for (int i = 0; i < n; i++) {
        if(stalls[i]-minposition>=mid){
            cows++;
            if(cows==k){
                return true;
            }
            minposition=stalls[i];
        }
    }
    return false;

}


int aggressiveCows(vector<int> &stalls, int k) {
  sort(stalls.begin(), stalls.end());
  // MaximumsOfAllMinimums
  int n=stalls.size();
  int max=stalls[n-1];
  int min=stalls[0];
  int ans=-1;
//   for(int i=0;i<n;i++){
//       max=(arr[i]>max)?arr[i]:max;
//       min=(arr[i]<min)?arr[i]:min;
//   }
  int s=0, e=max, mid=s+(e-s)/2;
  while(s<=e){
      if(isPossible(stalls, k, n, mid)){
          ans=mid;
          s=mid+1;
      }
      else{
          e=mid-1;
      }
      mid=s+(e-s)/2;
  }
  return ans;
}