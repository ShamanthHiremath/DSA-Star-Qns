

//O(n*m)

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";

    for(int i=0; i<arr[0].size(); i++){
        char ch= arr[0][i];
        bool match=true;
        for(int j=1; j<n ; j++){
            if(arr[j].size() < i || ch!=arr[j][i]){
                match=false;
            }
        }
        if(match){
            ans.push_back(ch);
        }
        else{
            return ans;
        }
    }
    return ans;
}

//USING TRIEEEEEEEEEEEE
//LONGGERRR METHODDDDDD USING TRIEEEEEEEEEEE


class TrieNode
{
public:
    char data;
    // A-Z children for each node
    TrieNode *children[26];
    // To check if the node is an end point of a word
    bool isTerminal;
    int childCount;
    TrieNode(char d)
    {
        data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount=0;
    }
};

class Trie
{
public:
    TrieNode *root;

    // Initialize root with an empty character
    Trie()
    {
        root = new TrieNode('\0');
    }

    // Insert helper fn
    void insertUtil(TrieNode *root, string word)
    {
        // size of word is 0
        if (!word.length())
        {
            root->isTerminal = true;
            return;
        }
        // a-z indexing
        int index = word[0] - 'a';
        // to store that position node in child
        TrieNode *child;

        // node is present
        if (root->children[index])
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // RecursiveCall
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    string LongestCommonPrefix(string str){
        //storing answer, ie, longest common prefix
        string ans="";
        //iterate through the length of the first string
        for(int i=0; i<str.length(); i++){
            char ch=str[i];
            //if the childcount is 1
            if(root->childCount==1){
                ans.push_back(ch);
                int index= ch - 'a';
                root=root->children[index];
            }
            //more no of children present
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
        return ans;
    }


};


string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t= new Trie();
    for(auto i: arr){
        t->insertWord(i);
    }
    string firststr=arr[0];
    return t->LongestCommonPrefix(firststr);
}
