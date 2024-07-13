/*
2751. Robot Collisions

https://leetcode.com/problems/robot-collisions/

There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.

Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].

Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].
*/

// Optimal solution

#define nline '\n'
#define sp ' '
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> Robots(n);

        for (int i = 0; i < n; i++)
        {
            Robots[i] = make_tuple(positions[i], healths[i], directions[i], i);
        }

        sort(all(Robots));

        stack<tuple<char, int, int>> stk;
        vector<int> result(n, -1);

        for (int i = 0; i < n; i++)
        {
            char direction = get<2>(Robots[i]);
            int health = get<1>(Robots[i]);
            int originalIndex = get<3>(Robots[i]);

            while (!stk.empty() && get<0>(stk.top()) == 'R' && direction == 'L')
            {
                if (get<1>(stk.top()) == health)
                {
                    result[get<2>(stk.top())] = 0;
                    result[originalIndex] = 0;
                    stk.pop();
                    health = 0;
                    break;
                }
                else if (get<1>(stk.top()) > health)
                {
                    get<1>(stk.top()) -= 1;
                    result[originalIndex] = 0;
                    health = 0;
                    break;
                }
                else
                {
                    health -= 1;
                    result[get<2>(stk.top())] = 0;
                    stk.pop();
                }
            }

            if (health > 0)
            {
                stk.push({direction, health, originalIndex});
            }
        }

        while (!stk.empty())
        {
            tuple<char, int, int> top = stk.top();
            stk.pop();
            result[get<2>(top)] = get<1>(top);
        }

        result.erase(remove(result.begin(), result.end(), 0), result.end());

        return result;
    }
};

// (or) (Doesnt pass huge testt cases)

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // first make a map to store the info of a robot accordingly as pos, health, dirn
        map<int, pair<int, char>> info;

        long long int lcnt = 0, rcnt = 0;
        for(long long int i = 0; i < positions.size(); i++){
            info[positions[i]] = {healths[i], directions[i]};
            if(directions[i] == 'R'){
                rcnt += 1;
            }
            else{
                lcnt += 1;
            }
        }

        if(rcnt == positions.size() || lcnt == positions.size()){
            return healths;
        }

        // since a map is already sorted no need to sort it based on positions
        // create a stack to iterate through the positions

        stack<vector<int>>st;
        for(auto element : info){
            int pos = element.first;
            int health = element.second.first;
            char dirn = element.second.second;
            if(dirn == 'R'){
                vector<int> add = {pos, health, dirn};
                st.push(add);
            }
            else{
                // collision happens handle constraints
                while(!st.empty() && st.top()[2] == 'R'){
                    // stack top robo info
                    vector<int>& roboinfo = st.top();
                    int tophealth = roboinfo[1];

                    // st top robo wins
                    // keep it and decr its health by 1, skip the incoming robo
                    if (tophealth > health) {
                        roboinfo[1]--;
                        // skip the incoming robo
                        health = 0;
                        break;
                    }
                    // incoming left robo better
                    else if(tophealth < health){
                        // go through the contents of the stack
                        health--;
                        st.pop();
                    }
                    // equal strength remove the top and ignore incoming
                    else{
                        st.pop();
                        health = 0;
                        break;
                    }
                }
                if(health > 0){
                    vector<int> add = {pos, health, dirn};
                    st.push(add);
                }
            }
        }

        // Collect remaining healths in the order of input positions
        vector<int> rem_health(positions.size(), 0);
        while (!st.empty()) {
            for (int i = 0; i < positions.size(); ++i) {
                if (positions[i] == st.top()[0]) {
                    rem_health[i] = st.top()[1];
                }
            }
            st.pop();
        }
        rem_health.erase(remove(rem_health.begin(), rem_health.end(), 0), rem_health.end());
        return rem_health;
    }
};