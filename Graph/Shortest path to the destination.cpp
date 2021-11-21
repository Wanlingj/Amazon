
/*
Description
Given a 2D array representing the coordinates on the map, there are only values 0, 1, 2 on the map. value 0 means that it can pass, value 1 means not passable, value 2 means target place. Starting from the coordinates [0,0],You can only go up, down, left and right. Find the shortest path that can reach the destination, and return the length of the path.

Example
Example 1

Input:
[
 [0, 0, 0],
 [0, 0, 1],
 [0, 0, 2]
]
Output: 4
Explanation: [0,0] -> [1,0] -> [2,0] -> [2,1] -> [2,2]
Example 2

Input:
[
    [0,1],
    [0,1],
    [0,0],
    [0,2]
]
Output: 4
Explanation: [0,0] -> [1,0] -> [2,0] -> [3,0] -> [3,1]
*/

using namespace std;
#define BLOCK 1
#define END 2
#define VISIT 3
class Solution {
public:
    /**
     * @param targetMap: 
     * @return: nothing
     */
    
    int shortestPath(vector<vector<int>> &targetMap) {
        // Write your code here
        int n = targetMap.size();
        int m = targetMap[0].size();
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        pair<int, int> pt;
        int x = 0, y = 0, len = 0, level = 0;
        while (!queue.empty()) {
            len = queue.size();
            level++;
            //iterate through all possible directions
            for (int i = 0; i < len; i++) {
                pt = queue.front();
                queue.pop();
                for (int j = 0; j < 4; j++) {
                    x = pt.first + dx[j];
                    y = pt.second + dy[j];
                    if (x < 0 || x >= n || y < 0 || y >= m || targetMap[x][y] == BLOCK || targetMap[x][y] == VISIT) {
                        continue;
                    }
                    if (targetMap[x][y] == END) {
                        return level;
                    }  
                    //if haven't been to x,y before, push
                    queue.push({x, y});
                    //mark as visited
                    targetMap[x][y] = VISIT;
                }
            }
        }
        return -1;
    }
    
};
