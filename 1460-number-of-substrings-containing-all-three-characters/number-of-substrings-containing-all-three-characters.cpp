//original bruteforce approach O(n2) passes 53/54 , fails due to - TLE
// class Solution {
// public:
//     int numberOfSubstrings(string s) {

//         int k=0;
//         int n = s.size();

//         int count = 0;

//         while(k<s.size()){
//             unordered_map<char, int> mp;
//             for(int i =k; i<s.size(); i++ ){
//                 if(s[i]=='a') mp['a'] = 1;
//                 if(s[i] == 'b') mp['b'] = 1;
//                 if(s[i]=='c') mp['c'] =1;

//                 if(mp['a']==1 && mp['b']==1 && mp['c']==1){
//                     count = count+(n-i);
//                     break;
//                 }
//             }
//             k++;
//         }

//         return count;
        
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int left = 0;
        int right = 0;
        int count = 0;

        unordered_map<char, int> mp;

        while (right < n) {

            // Expand the window
            mp[s[right]]++;

            // While the current window contains a, b and c
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {

                // Every substring ending from 'right' to n-1 is valid
                count += (n - right);

                // Shrink the window
                mp[s[left]]--;
                left++;
            }

            right++;
        }

        return count;
    }
};