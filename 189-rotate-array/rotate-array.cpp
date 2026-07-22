class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void rotatefrom(int l , int r, vector<int> &nums){
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int l =0; 
        int r =nums.size()-1;
        int n = nums.size();
        k = k%n;

        rotatefrom(l,n-k-1, nums);
        rotatefrom(n-k,r, nums);
        rotatefrom(l,r, nums);
       
    }
};