class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comparator = [](vector<int>& vec1, vector<int>& vec2){
            return vec1[1]<vec2[1];
        };
        sort(intervals.begin(), intervals.end(), comparator);
        
        int discard = 0;
        int lastseen = INT_MIN;
        for(auto &vec : intervals){
            if(vec[0]>=lastseen){  //non overlapping interval
                lastseen = vec[1];
            }
            else{
                discard++;
            }
        }
        return discard;
    }
};