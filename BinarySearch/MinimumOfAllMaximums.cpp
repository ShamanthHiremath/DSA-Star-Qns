#include <bits/stdc++.h>
//Added
// You calculate the sum of the array first
// The min pos arrangement/disbn is to place/allote all the vlaues in the first such that all the task is done in 1 day/by 1st person
// The max pos arrangement/disbn is to place/allote all the values to the highest of the array such that the task is done in the maximum of day/ maximum of persons
// Next we apply binary search to reduce our search space
bool isPossible(int n, int m, int mid, vectors<int> time){
	long int partSum=0;//alloted sum of time/pages/task in general
	int allotedNo=1; //no of allotments untill equal to n
	for(int i=0;i<m;i++){
		if(partSum+time[i]<=mid){
			partSum+=time[i];
		}
		else{
			allotedNo++;
			if(allotedNo>n || time[i]>mid){
				return false;
			}
			partSum=time[i];
		}
	}
	return true;
}

long long MinimumOfAllMaximums(int n, int m, vector<int> time) 
{	
	long int sum=0;
	int ans=-1;
	for(int i=0;i<m;i++){
		sum+=time[i];
	}
	int s=0, e=sum, mid=s+(e-s)/2;
	while(s<=e){
		//The value beyond/after mid are all possible values
		//But u need the minimum of all
		//So search for values before mid by storing mid as a possible value in ans
		//Shift end to mid-1
		if(isPossible(n, m, mid, time)){
			ans=mid;
			e=mid-1;
		}
		//WKT if a mid value aint the possible value then the values before it are neither the possible values as well
		//Shift start to mid+1
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}