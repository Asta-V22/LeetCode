class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //we are already given that seq is a VPS , so we do not require to do the checks
        //we just need to find how many pairs of (), we can make from the seq
        int n = seq.size();

        int depth = 0;
        vector<int> res(n);
        //we'll keep even depth in group 0 and odd depth in group 1

        for(int i=0; i<n; i++){
            if(seq[i]=='('){
                depth++;
                if(depth%2==0){
                    res[i]=0;
                }
                else{
                    res[i]=1;
                }
            }
            else if(seq[i]==')'){
                //we'll check what is the current value of the depth?
                if(depth%2==0){
                    res[i]=0;
                }
                else{
                    res[i]=1;
                }
                depth--;
            }
        }

        return res;
        
    }
};