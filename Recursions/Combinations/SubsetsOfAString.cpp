#include <bits/stdc++.h>
void solve (vector<string>& ans, string output,string str, int index){
    //base condition
    if(index>=str.size()){
        if(output=="")return ;
        //if(output.length()>0){
            ans.push_back(output);
        //}
        return ;     
    }
    //exclusion
    solve(ans, output, str, index+1);
    //inclusion
    output.push_back(str[index]);
    solve(ans, output, str, index+1);
}

vector<string> subsequences(string str){
	vector<string>ans;
	string output="";
	int index=0;
	solve(ans, output, str, index);
	return ans;
}