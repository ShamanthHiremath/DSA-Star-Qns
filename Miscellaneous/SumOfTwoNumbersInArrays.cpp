#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
	int sum=0, carry=0;
	int i=n-1, j=m-1;
	for(; i>=0&&j>=0; i--,j--){
		sum=a[i]+b[j]+carry;
		if(sum>=10){
			ans.push_back((sum)%10);
			carry=1;
		}
		else{
			ans.push_back(sum);
			carry=0;
		}
	}
	if(i>j){
		while(i>=0||carry!=0){
		// part=a[i]+carry
		sum.push_back(a[i]+carry);
		carry=0;
		i--;}
	}
	else{
		while(j>=0||carry!=0){
		ans.push_back(b[j]+carry);
		carry=0;
		j--;}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}