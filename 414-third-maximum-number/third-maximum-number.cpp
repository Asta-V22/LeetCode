class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        if(s.size()>2){
            auto it = prev(s.end(),3);
            return *it;
        }
        else{
            // auto it = prev(s.end(),1);    //you can also do this
            // return *it;

            return *prev(s.end());
        }

       
    }
};