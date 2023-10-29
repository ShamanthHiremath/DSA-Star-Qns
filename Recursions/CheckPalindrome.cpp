#include <bits/stdc++.h>
bool checkpal(vector<int>& binary, int i=0, int j = -1){
	if (j == -1) {
        j = binary.size() - 1;
    }
	if(i>j) return true;
	if(binary[i]!=binary[j]) return false;
	return checkpal(binary, i+1, j-1);
}

bool checkPalindrome(long long N)
{
	vector<int> binary;	
	while(N>0){
		binary.push_back(N%2);
		N/=2;
	}
	return checkpal(binary);
}