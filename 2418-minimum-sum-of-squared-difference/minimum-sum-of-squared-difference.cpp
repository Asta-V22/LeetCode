class Solution {
public:
    int n;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        n = nums1.size();
        int k = k1+k2;
        

        vector<int> diff(n);

        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            diff[i] = abs(nums1[i]-nums2[i]);
            maxi = max(diff[i],maxi);
        }

        //now we need to set the feq of the numbers occuring in the diff
        vector<int> freq(maxi+1);
        for(int i=0; i<diff.size(); i++){
            freq[diff[i]]++;
        }


        for(int i=freq.size()-1; i>0; i--){
            if(k>0 && freq[i]==0){
                continue;
            }
            if(freq[i]>k){
                freq[i] = freq[i]-k;
                freq[i-1]+=k;
                k=0;
                break;
            }
            if(freq[i]<=k){
                freq[i-1]+=freq[i];
                k = k-freq[i];
                freq[i]=0;
            }
        }
        long long res = 0;
        for(int i=1; i<freq.size(); i++){
            res += (long long)i*i*freq[i];
        }

        return res;


    }
};