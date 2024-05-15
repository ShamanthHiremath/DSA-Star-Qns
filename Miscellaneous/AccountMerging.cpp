/*
Given a list of accounts of size n where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
Geek wants you to merge these accounts. Two accounts belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts have the same name.
After merging the accounts, return the accounts in the following format: The first element of each account is the name, and the rest of the elements are emails in sorted order.

Note: Accounts themselves can be returned in any order.

Example 1:

Input:
n = 4
accounts [ ] =
[["John","johnsmith@mail.com","john_newyork@mail.com"],
["John","johnsmith@mail.com","john00@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]
Output:
[["John","john00@mail.com","john_newyork@mail.com", "johnsmith@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com". The third John and Mary are different people as none of their email addresses are used by other accounts.We could return these arrays in any order, for example, the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Map to store email - OwnerName and No
        map<string, pair<string, int>> emailToOwner;
        // int ownerNo = 0;
        
        for (int i = 0; i < accounts.size(); i++) {
            string name = accounts[i][0];
            
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                
                // Check if a key exists in the map
                auto it = emailToOwner.find(email);
                if (it != emailToOwner.end()) {
                    int ownerNo = it->second.second;
                    string owner = it->second.first;
                    
                    // Update owner name and number for all emails in that row
                    for (int k = 1; k < accounts[i].size(); k++) {
                        string dupOwnermail =accounts[i][k] ;
                        emailToOwner[dupOwnermail] = {owner, ownerNo};
                    }
                    break;
                }
                else {
                    emailToOwner[email] = {name, i};
                }
            }
            // ownerNo++;
        }
        
        // Map to store owner number to merged account
        map<int, vector<string>> ownerToMergedAccount;
        
        // Construct merged accounts
        for (const auto& pair : emailToOwner) {
            const string& email = pair.first;
            const string& ownerName = pair.second.first;
            int ownerNo = pair.second.second;
            
            ownerToMergedAccount[ownerNo].push_back(ownerName);            
            ownerToMergedAccount[ownerNo].push_back(email);
        }
        
        // Construct result
        vector<vector<string>> result;
        for (const auto& pair : ownerToMergedAccount) {
            vector<string> account;
            string ownerName = pair.second[0];
            account.push_back(ownerName); // Owner's name
            
            // Add emails to the merged account, starting from the first index
            for (size_t i = 1; i < pair.second.size(); ++i) {
                if(pair.second[i] == ownerName){
                    continue;
                }
                account.push_back(pair.second[i]);
            }
            result.push_back(account);
        }
        
        return result;
    }
};


