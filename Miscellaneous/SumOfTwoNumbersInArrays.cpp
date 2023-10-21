#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> sum;
	int part=0, carry=0;
	int i=n-1, j=m-1;
	for(; i>=0&&j>=0; i--,j--){
		part=a[i]+b[j]+carry;
		if(part>=10){
			sum.push_back((part)%10);
			carry=1;
		}
		else{
			sum.push_back(part);
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
		sum.push_back(b[j]+carry);
		carry=0;
		j--;}
	}
	reverse(sum.begin(), sum.end());
	return sum;
}