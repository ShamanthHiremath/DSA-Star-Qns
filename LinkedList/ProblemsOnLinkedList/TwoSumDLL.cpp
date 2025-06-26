/*
Find pairs with given sum in doubly linked list

https://www.naukri.com/code360/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172?leftPanelTabValue=PROBLEM

 Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.

Find out all the pairs in the doubly linked list with sum equal to 'k'.

Example :

Input: Linked List: 1 <-> 2 <-> 3 <-> 4 <-> 9 and 'k' = 5

Output: (1, 4) and (2, 3)

Explanation: There are 2 pairs in the linked list having sum 'k' = 5.
Detailed explanation ( Input/output format, Notes, Images )
Sample input 1:
5
1 2 3 4 9
5


Sample output 1
2
1 4
2 3


Explanation for sample input 1 :
There are 2 pairs in the linked list having sum equal to 'k' (= 5).


Sample input 2:
5
1 10 11 12 27
7


Sample output 2:
0


Explanation for sample output 2
There is no pair in the linked list with sum equal to 'k' (= 7).
*/
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // TWO SUM PROBLEM

    Node* left = head;
    Node* right = head;

    while(right->next){
        right = right->next;
    }

    vector<pair<int, int>>ans;
    // TWO SUM Now

    while(left && right && left != right && left->prev != right){
        long long int sum = left->data + right->data;
        if(sum == k){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum < k){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }

    return ans;
}