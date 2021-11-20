/*

Description
In order to decorate your new house, you need to process some sticks with positive integer length.
You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y. Due to the construction needs, you must connect all the bars into one.
Return the minimum cost of connecting all the given sticks into one stick in this way.
Please note that you can choose any order of sticks connection

Example
Example 1:

Input:
[2,4,3]
Output: 
14
Explanation: 
First connect 2 and 3 to 5 and cost 5; then connect 5 and 4 to 9; total cost is 14
Example 2:

Input:
 [1,8,3,5]
Output: 
30
*/

class Solution {
public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int MinimumCost(vector<int> &sticks) {
        // write your code here
        if(sticks.size() <= 1){
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        queue<int> costs;
        int res = 0;

        for(auto& stick : sticks){
            minHeap.push(stick);
        }
        while(minHeap.size() > 1){
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();

            minHeap.push(a+b);
            costs.push(a+b);
        }
        
        while(!costs.empty()){
            res += costs.front();
            costs.pop();
        }

        return res;
    }
};
