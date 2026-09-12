// class Solution {
// public:
//     struct Node{
//         int score = -1;
//         vector<int> idxs;
//     };
//     int n;
//     vector<int> nextidx;
//     vector<vector<Node>> t;

//     Node solve(vector<int> intervals, int i, int k){
//         if(k==0 || i>=n){
//             return Node();
//         }

//         if(t[i][k].score!=-1){
//             return t[i][k];
//         }

//         //we can take the index in our solution or not
//         Node skip = solve(intervals, i+1, k);
//         int wt = intervals[i][2];
//         int index = intervals[i][3];
//         int j = nextidx[i];

//         Node temp = solve(intervals, nextidx[i], k--);
//         Node take;
//         take.score = temp.score +wt;
//         take.idxs = temp.idxs;
//         take.idxs.push_back(index);

//         sort(begin(take.idxs), end(take.idxs));

//         Node result;
//         if(skip.score> take.score){
//             result = skip;
//         }
//         else if(skip.score < take.score){
//             result = take;
//         }
//         else{
//             result = (skip.idxs<take.idxs) ? skip:take;
//         }
//         return t[i][k]=result;

//     }

//     vector<int> maximumWeight(vector<vector<int>>& intervals) {
//         n = intervals.size();
        
//         //we'll need to preserve the index of the intervals before sorting them
//         for(int i=0; i<n; i++){
//             intervals[i].push_back(i);
//         }

//         //we'll sort the array so that we can apply B.S. on the later parts in order to find the index that may hold the next non overlapping interval
//         sort(intervals.begin(), intervals.end());

//         nextidx.resize(n);
//         //now we'll precomput the next index for each of the index in order to not to find them every time later
//         for(int i=0; i<n; i++){
//             int curRightBound = intervals[i][1];
//             nextidx[i] = findnext(intervals, currRightBound);    //B.S. function to find the next interval
//         }

//         t.assign(n, vector<Node>(5));

//         int k = 4;   //max element that we can take

//         solve(intervals,0,k).idxs;

//     }
// };

class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    int n;
    vector<int> nextidx;
    vector<vector<Node>> t;

    int findNext(const vector<vector<int>>& intervals, int rightBound, int start) {
        int l = start, r = n, ans = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] > rightBound) {
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    Node solve(const vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n) {
            return Node{0, {}};
        }

        if (t[i][k].score != -1) {
            return t[i][k];
        }

        Node skip = solve(intervals, i + 1, k);

        int wt = intervals[i][2];
        int index = intervals[i][3];
        int j = nextidx[i];

        Node temp = solve(intervals, j, k - 1);
        Node take;
        take.score = temp.score + wt;
        take.idxs = temp.idxs;
        take.idxs.push_back(index);
        
        // Keep indices sorted for lexicographical comparison
        sort(take.idxs.begin(), take.idxs.end());

        Node result;
        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return t[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort intervals by start time or end time depending on binary search logic
        sort(intervals.begin(), intervals.end());

        nextidx.resize(n);
        for (int i = 0; i < n; i++) {
            int curRightBound = intervals[i][1];
            nextidx[i] = findNext(intervals, curRightBound, i + 1);
        }

        // Initialize memoization table: n rows, 5 columns (for k from 0 to 4)
        t.assign(n, vector<Node>(5));

        int k = 4;
        return solve(intervals, 0, k).idxs;
    }
};