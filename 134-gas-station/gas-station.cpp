class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int tank = 0;
        int total = 0;
        for(int i=0; i<cost.size(); i++){
            if(tank<=0){
                start = i;
                tank = 0;
            }
            total+=gas[i]-cost[i];
            tank+=gas[i]-cost[i];
        }

        return total>=0?start:-1;
    }
};