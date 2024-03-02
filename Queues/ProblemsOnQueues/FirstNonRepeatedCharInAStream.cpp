/*
Input: "aabc"
Output: "a#bb"

Input: 
abcabcabczzzzz
Output: 
aaabc####z####
*/

class Solution {
	public:
		string FirstNonRepeating(string A){
		    if(A.size()==0){
		        return {};
		    }
		    if(A.size()==1){
		        return A;
		    }
		    queue<char>q;
		    string ans="";
		    vector<int>count(26, 0);
		    for(int i=0; i<A.size(); i++){
		        char ch=A[i];
		        count[ch-97]++;
		        q.push(ch);
		        while(!q.empty()){
		            //repeated
		            if(count[q.front()-97]>1){
		                q.pop();
		            }
		            //non repeated
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }

		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}
};