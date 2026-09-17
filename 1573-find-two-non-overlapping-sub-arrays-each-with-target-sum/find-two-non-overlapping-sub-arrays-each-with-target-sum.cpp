class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        //INITIAL BRUTE FORCE THAT I TRIED, PASSES 57/61, BUT AT THE END THE LAST ASSUMPTION IS WRONG AND ON IMPORVING THAT THE T.C. GOES TO O(N2) WHICH WILL HIT TLE HENCE DP BELOW

        // int n = arr.size();
        // vector<pair<int,int>> vec;
        // int l = 0;
        // int r = 0;
        // int sum = 0;

        // while(r<n){
        //    sum+=arr[r];
        //    if(sum==target){
        //     vec.push_back({l,r});
        //    }
        //    while(sum>=target){
        //     sum-=arr[l];
        //     l++;
        //     if(sum==target){
        //         vec.push_back({l,r});
        //     }
        //    }
        //    r++;
        // }

        // if(vec.size()<2) return -1;

        // auto comparator = [](const pair<int,int>& a, const pair<int,int>& b){
        //     return a.second-a.first+1 < b.second-b.first+1;
        // };

        // sort(vec.begin(), vec.end(), comparator);

        // int a = vec[0].first;
        // int b = vec[0].second;
        // int ans = b - a +1;
        // for(int i=1; i<vec.size(); i++){
        //     int c = vec[i].first;
        //     int d = vec[i].second;

        //     if(c>b || d<a){
        //         ans+=d-c+1;
        //         break;
        //     }
        // }
        // return ans;


        //ONE PASS APPROACH
        int n = arr.size();
        const int INF = 1e9;
        int sum = 0;
        int l=0;
        int ans= INF;
        int bestSoFar = INF;

        vector<int> min_len(n,INF);

        for(int r=0; r<n; r++){
            sum+=arr[r];

            while(sum>target){
                sum-=arr[l];
                l++;
            }
            if(sum==target){
                int currlen = r-l+1;
                //if we have already encountered some subarray (non-overlapping) previously already

                if(l>0 && min_len[l-1]!=INF){
                    ans = min(ans, currlen+min_len[l-1]);
                }
                bestSoFar = min(bestSoFar, currlen);
            }
            min_len[r] = bestSoFar;
        }

        return (ans>=INF)?-1:ans;

    }
};