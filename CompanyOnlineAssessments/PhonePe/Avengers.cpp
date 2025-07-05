// 


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i=2; i*i<=num; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

// DFS to find path from u to v
bool dfs(int curr, int target, vector<int>& path, vector<bool>& visited, vector<vector<int>>& adj) {
    if (curr == target) {
        path.push_back(curr);
        return true;
    }
    visited[curr] = true;
    for (int nbrr : adj[curr]) {
        if (!visited[nbrr]) {
            if (dfs(nbrr, target, path, visited, adj)) {
                path.push_back(curr);
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n+1); // adjacency list

    for (int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Mark prime nodes
    vector<bool> is_prime(n+1,false);
    for (int i=1; i<=n; i++) {
        if (isPrime(i)){
            is_prime[i] = true;
        }
    }

    int count_paths = 0;

    // Try all pairs (u,v) with u < v
    for (int u=1; u<=n; u++) {
        for (int v=u+1; v<=n; v++) {
            vector<bool> visited(n+1,false);
            vector<int> path;
            if (dfs(u, v, path, visited, adj)) {
                int prime_count = 0;
                for (int node : path) {
                    if (is_prime[node]){
                        prime_count++;
                    }
                }
                if (prime_count == k){
                    count_paths++;
                }
            }
        }
    }

    cout << count_paths << endl;

    return 0;
}