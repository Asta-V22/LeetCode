class Solution {
public:
    typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> cumSum(n);
        cumSum[0] =  nums[0];
        for(int i=1; i<n; i++){
            cumSum[i] = nums[i]+cumSum[i-1];
        }

        //making a lambda function to access rangesum
        auto rangeSum = [&](int i, int j)-> long long{
            if(i>j) return 0;
            return cumSum[j] - ((i>0)?cumSum[i-1]:0);
        };

        //next greater element nge
        vector<int> nge(n,n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<ll> ops(n+1,0);

        for(int i=n-1; i>=0; i--){
            int m = nge[i];

            ll segs = (1LL*nums[i]*(m-i)) - rangeSum(i,m-1);
            ops[i] = segs + ops[m];

        }

        deque<ll> deq;
        ll result = 0;
        int i=0;
        int j=0;

        while(j<n){
            while(!deq.empty() && nums[deq.back()] < nums[j]){
                deq.pop_back();

            }
            deq.push_back(j);

            while(i<=j){
                //current window maximum element
                int m = deq.front();

                ll opCount = (ops[i]-ops[m]) + (1LL*nums[m]*(j-m+1)) - rangeSum(m,j);

                if(opCount<=k) break;

                i++;
                if(deq.front()<i){
                    deq.pop_front();
                }
            }
            result +=(j-i+1);
            j++;
        }

        return result;
    }
};