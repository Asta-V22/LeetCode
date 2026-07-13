class Solution {

private:
    int sizeOfNum(int num){
        int count = 0;
        while(num>0){
            num=num/10;
            count++;          
        }
        return count;
    }

    int numGen(int start, int length){
        int num =0;
        for(int i=0; i<length; i++){
            num = num*10 + (start+i);
        }

        return num;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        //first we'll find the length of the low and high
        int sizeLow = sizeOfNum(low);
        int sizeHigh = sizeOfNum(high);

        vector<int> ans;

        //for each size we only have 10-k possibilites
        for(int i=sizeLow; i<=sizeHigh; i++){
            for(int j = 1; j<=10-i; j++){
                int number =numGen(j,i);

                if(number>= low && number<=high){
                    ans.push_back(number);
                }
            }
        }


        return ans;
    }
};