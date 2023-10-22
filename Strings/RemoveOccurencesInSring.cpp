class Solution {
public:
    string removeOccurrences(string s, string part) {
        for(;s.size()!=0&&s.find(part)<s.length();){
            s.erase(s.find(part), part.length());
        }
        
       return s; 
    }
};