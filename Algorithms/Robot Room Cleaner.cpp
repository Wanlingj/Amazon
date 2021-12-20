/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    set<pair<int,int>> s;
    int x = 0;
    int y = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dir = 0;
    void cleanRoom(Robot& robot) {
        //write your code here 
        if(s.count({x,y})) {
             return;
         }
        s.insert({x,y});
        robot.clean();
        for(int i = 0; i < 4; i++) {
            // 沿当前的方向走一格
            if(robot.move()) { 
                // 如果能走通，修改x,y坐标
                x += dx[dir];
                y += dy[dir];
                cleanRoom(robot);
                // 沿当前方向走了一格之后，需要回到之前的位置遍历其他方向
                // 先让方向反向，再移动一格，从而回到之前的位置
                robot.turnRight();
                robot.turnRight();
                robot.move(); 
                // 调整机器人回到之前的方向
                robot.turnRight();
                robot.turnRight();
                // 已经回到之前的位置，修改机器人坐标
                x -= dx[dir];
                y -= dy[dir];
            }
            robot.turnRight();
            dir = (dir + 1) %4;
        }
    }
};
