class Solution {
private:
    void getleftmax(vector<int> &leftmax, vector<int> &height){
        int lefty = height[0];
        for(int i=0; i<height.size(); i++){
            lefty = max(lefty, height[i]);
            leftmax[i]=lefty;
        }
    }
    void getrightmax(vector<int> &rightmax, vector<int> &height){
        int righty = height[height.size()-1];
        for(int i=height.size()-1; i>=0; i--){
            righty=  max(righty, height[i]);
            rightmax[i]=righty;
        }
    }

public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);

        getleftmax(leftmax, height);
        getrightmax(rightmax, height);

        int sum = 0;

        for(int i=0; i<height.size(); i++){ 
            int h = min(leftmax[i], rightmax[i])-height[i];
            sum+=h;
        }
        return sum;
    }
};