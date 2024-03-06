class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if(n==1){
            return 0;
        }
        
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for(int i=0;i<n; i++){
            pq.push(arr[i]);
        }
        long long int total=0;
        for(int i=1; i<n; i++){
            long long int sum=pq.top();
            pq.pop();
            sum+=pq.top();
            pq.pop();
            pq.push(sum);
            total+=sum;
        }
        return total;
    }
};