class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //smart approach: if the majority element is guranteed then after sorting
        // the majority element should lie on the n/2th place
/*
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];

*/

        //hashmap approach
        //building the unordered map
/*        unordered_map<int, int> mp;

        for(int x : nums){
            mp[x]++;
        }
        
        for(auto it : mp){
            if(it.second > nums.size()/2){
                return it.first;
            }
        }

        return 0;
 */
//OPTIMAL SOLUTION: VOTING MOORE ALGORITHM
    
    int candidate = nums[0];
    int count = 0;

    for(int i =0; i<nums.size(); i++){
        if(nums[i]==candidate){
            count++;
        }
        else{
            count--;
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }
        }
    }

    return candidate;



    }
};