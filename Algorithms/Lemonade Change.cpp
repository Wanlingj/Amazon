class Solution {
public:
    /**
     * @param bills: the Bill
     * @return: Return true if and only if you can provide every customer with correct change.
     */
    bool lemonadeChange(vector<int> &bills) {
        // Write your code here.
        unordered_map<int,int> m;
        int n=bills.size();
        for(int i=0;i<n;i++){
          m[bills[i]]++;
          if(bills[i]==10){
            if(--m[5]<0)
              return false;
          }
          if(bills[i]==20){
            if(m[5]>=1&&m[10]>=1){
              m[5]--;m[10]--;
            }
            else if(m[5]>=3){
              m[5]-=3;
            }
            else{
              return false;
            }
          }
        }
        return true;

    }
};
