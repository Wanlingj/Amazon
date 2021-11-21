/*
Description
Give the names of a group of students and their grades, find the highest average score(A student may have multiple scores of different course).

Example
Example 1:

Input:names = ["bob","ted","ted"]
grades=[88,100,20]
Output:88
Example 2:

Input: names = ["john","xisa","xisa","liajd","alice","john","xisa","mark","ted","xlisa"]
grades = [95,83,33,50,78,91,80,67,85,87]
Output:93
*/

class Solution {
public:
    /**
     * @param names: the name
     * @param grades: the grade
     * @return: the maximum average score
     */
    double maximumAverageScore(vector<string> &names, vector<int> &grades) {
        // Write your code here
        unordered_map<string,double> m;
        unordered_map<string,double> n;
        unordered_set<string> name;
        for(int i=0;i<names.size();i++){
          m[names[i]]+=grades[i];
          n[names[i]]+=1;
          name.insert(names[i]);
        }
        double res=0;
        for(string str: name){
          m[str]/=n[str];
          if(m[str]>res)
            res=m[str];
        }
        return res;

    }
};
