// A majority element in the array ‘a’ is an element that appears more than 'n' / 2 times.
// Find the majority element of the array.
// It is guaranteed that the array 'a' always has a majority element.

// Example:
// Input: ‘n’ = 9, ‘a’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]
// Output: 1
// Explanation: The frequency of ‘1’ is 5, which is greater than 9 / 2.
// Hence ‘1’ is the majority element.


// #include "map"

// int majorityElement(vector<int> v) {
// 	map<int, int>freq;
// 	// int maxi = 0;
// 	for(int i=0; i<v.size(); i++){
// 		freq[v[i]]++;
// 		if(freq[v[i]]>=v.size()/2){
// 			return v[i];
// 		}
// 	}

// 	return -1;
// }

// MOORE's ALGO

int majorityElement(vector<int> v) {
	int element;
	int count = 0;
	for(int i=0; i<v.size(); i++){
		if(count == 0){
			count++;
			element = v[i];
		}
		else if(element == v[i]){
			count++;
		}
		else{
			count--;
		}
	}
	int count_of_ele = 0;
	for(auto num:v){
		if(num == element){
			count_of_ele++;
		}
		
	}
	if(count_of_ele >= v.size()/2){
		return element;
	}
	else{
		return -1;
	}

	return -1;
}