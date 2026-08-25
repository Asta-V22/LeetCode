class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        //first convert the array into a hashmap
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        //now everything is in map, now we can just look things up
        int i =1;
        while(true){
            int num = k*i;
            //check if it is there in the map
            if(mp.find(num)==mp.end()){
                //caught the number
                return num;
            }
            i++;
        }

    }
};