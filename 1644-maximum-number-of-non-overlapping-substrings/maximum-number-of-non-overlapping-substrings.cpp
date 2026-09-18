class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);

        for(int i=0; i<s.size(); i++){
            int ch = s[i]-'a';
            if(first[ch]==-1) first[ch] = i;
            last[ch] = i; 
        }

        vector<pair<int,int>> candidate;

        for(int i=0; i<26; i++){
            if(first[i]==-1) continue;  //character not in the string

            int L = first[i];   //starting index of the char
            int R = last[i];    //last index of the char

            bool valid = true;

            //iterate inside the range L-R to find if the character inside the range are wholly encompassed in it or not
            for(int j=L; j<=R; j++){
                int ch = s[j]-'a';

                if(first[ch]<L){   //it means this has already ocurred outside of the range
                    valid = false;
                    break; 
                }
                R = max(R,last[ch]);    

            }

            if(valid){
                candidate.push_back({L,R});
            }
        }

        //now we have all our candidates in our vector, we'll sort them on the basis of the j of the i,j interval, because the sooner our candidate ends, the more space it leaves for the others to occupy

        auto comparator = [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second<b.second;
        };

        sort(candidate.begin(), candidate.end(), comparator);

        //now we just need to pick up the non overlapping intervals from the sorted array
        vector<string> result;
        int lastpickedindex = -1;
        for(auto &[L,R]: candidate){
            if(L>lastpickedindex){   //not overlapping with the ending of the previous interval
                result.push_back(s.substr(L,R-L+1));
                lastpickedindex = R;  //substrings starting from index after this are free to be picked.
            }
        }

        return result;
    }
};