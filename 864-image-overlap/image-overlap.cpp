class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int,int>,int> mp;
        int m = img1.size();
        int n = img2.size();

        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                if(img1[i][j]==1){
                    for(int k=0; k<n; k++){
                        for(int l=0; l<n; l++){
                            if(img2[k][l]==1){
                                int ri = k-i;
                                int rj = l-j;
                                mp[{ri,rj}]++;
                            }
                        }
                    }
                            
                }
            }
        }

        //now we need to return the value in the map with the heighest freq.

        int largest = 0;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            largest = max(largest, it->second);
        }

        return largest;
    }
};