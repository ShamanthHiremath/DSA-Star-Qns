/*

2976. Minimum Cost to Convert String I

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

source, target consist of lowercase English letters.

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.

Problem in Simpler Terms
Imagine you have a word game where you need to change one word (let's call it the "source" word) into another word (the "target" word). Here are the rules:

Both words have the same length.
You can only change one letter at a time.
Each letter change has a specific cost.
You're given a list of allowed letter changes and their costs.
You can use these changes as many times as you want.
Your goal is to find the cheapest way to change the source word into the target word.

Here's a breakdown of the key elements:

source and target: These are the starting and ending words.
original and changed: These lists show what letter changes are allowed.
cost: This list shows how much each allowed change costs.
For example:

If you're allowed to change 'a' to 'b' for a cost of 5
And 'b' to 'c' for a cost of 3
Then you could change 'a' to 'c' for a total cost of 8 (5 + 3)
The tricky part is that sometimes it's cheaper to make multiple small changes rather than one big change. Your job is to figure out the cheapest overall path to change the source word into the target word.

If it's impossible to change the source word into the target word using the allowed changes, you should return -1.

Intuition
When first approaching this problem, we need to understand that we're essentially dealing with a graph problem. Each character in the alphabet can be thought of as a node in a graph, and the allowed character conversions represent the edges between these nodes. The cost of each conversion is the weight of the edge.

The core challenge is to find the cheapest way to transform the source string into the target string. This immediately brings to mind the concept of finding the shortest path in a weighted graph. However, we're not just finding a single path - we need to find the shortest path between every pair of characters, as we might need to transform any character into any other character.

This realization leads us to consider algorithms for finding all-pairs shortest paths in a graph. The Floyd-Warshall algorithm is a perfect fit for this scenario, as it efficiently computes the shortest paths between all pairs of nodes in a weighted graph.

Approach
1. Building the Conversion Graph
The first step is to represent our problem as a graph. We'll use a 2D array (matrix) to represent this graph, where each cell [i][j] represents the cost of converting character i to character j.

Pseudo-code for this step:

function buildConversionGraph(original, changed, cost):
    // Initialize graph with all edges set to infinity
    graph = 2D array of size [CHAR_COUNT][CHAR_COUNT] filled with INF

    // Set cost of converting a character to itself to 0
    for i from 0 to CHAR_COUNT - 1:
        graph[i][i] = 0

    // Fill in the known conversion costs
    for i from 0 to length of cost - 1:
        from = index of original[i] in alphabet
        to = index of changed[i] in alphabet
        graph[from][to] = minimum of (graph[from][to], cost[i])

    return graph
This function creates our initial graph representation. Here's a detailed breakdown of what's happening:

We start by creating a 2D array filled with a very large value (INF). This represents that initially, we assume there's no direct way to convert any character to any other character.

We then set the cost of converting a character to itself to 0. This is logical - it costs nothing to keep a character as is.

Finally, we iterate through the given conversion rules (original, changed, and cost arrays). For each rule, we update our graph. The from character is represented by the row index, and the to character by the column index. We use the minimum of the current value and the new cost in case there are multiple ways to perform the same conversion.

Now, why do we use minimum of (graph[from][to], cost[i]) here? well, we might have multiple ways to change one letter to another. like, we might be told we can change 'a' to 'b' for 5 points, but later we're told we can do it for 3 points. we want to keep the cheaper option, so we use minimum of (graph[from][to], cost[i]).

After all this, we end up with a grid that shows the cheapest way to directly change any letter to any other letter, based on the rules we were given.

This step gives us a graph that represents all direct conversions we can make based on the given rules.

PS: I've seen a lot of people getting confused with this, so let me explain:

the reason we use graph[from][to] = Math.min(graph[from][to], cost[i]); instead of just graph[from][to] = cost[i]; is because there might be multiple ways to convert one character to another, with different costs. by using Math.min(), we're always keeping the lowest cost option for converting from one character to another.

here's an example: let's say in our input we have:
original = ['a', 'a']
changed = ['b', 'b']
cost = [5, 3]

this means we have two ways to convert 'a' to 'b': one costs 5 and another costs 3. if we just used graph[from][to] = cost[i];, the cost of converting a to b would be set to 5 first and then overwritten with 3. but we want to keep the lower cost of 3.

so by using math.min(graph[from][to], cost[i]) we make sure we always keep the lowest cost for each character conversion, even if there are multiple conversion options in the input.

2. Optimizing Conversion Paths
Now that we have our initial graph, we need to find the cheapest way to convert any character to any other character, even if it requires multiple steps. This is where the Floyd-Warshall algorithm comes in.

Pseudo-code for this step:

function optimizeConversionPaths(graph):
    for k from 0 to CHAR_COUNT - 1:
        for i from 0 to CHAR_COUNT - 1:
            if graph[i][k] < INF:
                for j from 0 to CHAR_COUNT - 1:
                    if graph[k][j] < INF:
                        graph[i][j] = minimum of (graph[i][j], graph[i][k] + graph[k][j])
This is the heart of the Floyd-Warshall algorithm. Here's what's happening:

We iterate through all possible intermediate nodes (k).

For each pair of nodes (i and j), we check if going through k gives us a cheaper path than the one we currently know.

If we find a cheaper path, we update our graph.

The brilliance of this algorithm is that it considers all possible paths between all pairs of nodes. After this step, graph[i][j] will contain the cost of the cheapest possible way to convert character i to character j, even if it requires multiple intermediate steps.

A key optimization in our implementation is the check if graph[i][k] < INF and if graph[k][j] < INF. This prevents unnecessary calculations when there's no path between nodes, significantly speeding up the algorithm for sparse graphs.

3. Computing the Total Conversion Cost
With our fully optimized conversion graph, we can now calculate the cost of converting the source string to the target string.

Pseudo-code for this step:

function computeTotalConversionCost(source, target, graph):
    totalCost = 0
    for i from 0 to length of source - 1:
        sourceChar = index of source[i] in alphabet
        targetChar = index of target[i] in alphabet
        if sourceChar != targetChar:
            if graph[sourceChar][targetChar] == INF:
                return -1  // Conversion is impossible
            totalCost += graph[sourceChar][targetChar]
    return totalCost
Here's what this function does:

We iterate through each position in the source and target strings simultaneously.

If the characters at the current position are different, we need to perform a conversion.

We look up the cost of this conversion in our optimized graph.

If the cost is INF, it means there's no way to perform this conversion, so we return -1 to indicate that the overall conversion is impossible.

Otherwise, we add the cost to our total.

After checking all positions, if we haven't returned -1, we return the total cost.

This approach ensures that we're always using the cheapest possible way to convert each character, even if it involves multiple steps.
*/
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    static constexpr int CHAR_COUNT = 26;
    static constexpr int INF = 1e9;

    std::vector<std::vector<int>> buildConversionGraph(const std::vector<char>& original, const std::vector<char>& changed, const std::vector<int>& cost) {
        std::vector<std::vector<int>> graph(CHAR_COUNT, std::vector<int>(CHAR_COUNT, INF));
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0;
        }
        for (size_t i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from][to] = std::min(graph[from][to], cost[i]);
        }
        return graph;
    }

    void optimizeConversionPaths(std::vector<std::vector<int>>& graph) {
        for (int k = 0; k < CHAR_COUNT; k++) {
            for (int i = 0; i < CHAR_COUNT; i++) {
                if (graph[i][k] < INF) {
                    for (int j = 0; j < CHAR_COUNT; j++) {
                        if (graph[k][j] < INF) {
                            graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }
    }

    long long computeTotalConversionCost(const std::string& source, const std::string& target, const std::vector<std::vector<int>>& graph) {
        long long totalCost = 0;
        for (size_t i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INF) {
                    return -1;
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }

public:
    long long minimumCost(std::string source, std::string target, std::vector<char>& original, std::vector<char>& changed, std::vector<int>& cost) {
        auto conversionGraph = buildConversionGraph(original, changed, cost);
        optimizeConversionPaths(conversionGraph);
        return computeTotalConversionCost(source, target, conversionGraph);
    }
};