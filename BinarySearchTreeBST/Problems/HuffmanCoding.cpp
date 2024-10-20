/*
Huffman Encoding

https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

Example 1:
S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
Explanation:
Steps to print codes from Huffman Tree
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary 
Tree.
*/

class Node{
    public:
        Node* left;
        Node* right;
        int data;
        
        Node (int x){
            data = x;
            left = NULL;
            right = NULL;
        }
};

class cmp{
    public:
    
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

class Solution
{
	public:
	
	    void HuffmanTraverse(Node* root, vector<string>&ans, string path){
	        
	        if(root->left == NULL && root->right == NULL){
	            ans.push_back(path);
	            return ;
	        }
	        
	       // if(root->left){
	        HuffmanTraverse(root->left, ans, path + "0");
	       // }
	        
	       // if(root->right){
            HuffmanTraverse(root->right, ans, path + "1");
	       // }
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N){

		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    
		    for(int num: f){
		        Node* insertNode = new Node(num);
		        pq.push(insertNode);
		    }
		    
		    while(pq.size() > 1){
		        Node* left = pq.top();
		        pq.pop();
		        
		        Node* right = pq.top();
		        pq.pop();
		        
		        Node* newnode = new Node(left->data + right->data);
		        newnode->left = left;
		        newnode->right = right;
		        pq.push(newnode);
		    }
		    
		    Node* root = pq.top();
		    
		    vector<string>ans;
		    string path = "";
		    HuffmanTraverse(root, ans, path);
		    
		    
		    return ans;
		}
};