class Solution {
public:
    typedef long long ll;

    string filler(ll req, int length){
        string str;

        //we'll start filling from the largest to lowest i.e. 9-->2
        //we'll check if it divides, if yes we'll exhaust it and then move on to the next digit

        for(int i = 9; i>=2; i--){
            while(req%i==0){
                str.push_back(i + '0');
                req/=i;
            }
        }

        //if still length remains yet to be filled, fill them with 1s

        while(str.size()<length){
            str.push_back('1');
        }

        reverse(str.begin(), str.end());

        return str;

    }

    string smallestNumber(string num, long long t) {
        int n = num.size();

        ll temp = t;
        //we'll check if t has any 2 digit prime factor 
        for(int primefact : {2,3,5,7}){
            while(temp%primefact==0){
                temp = temp/primefact;
            }
        }

        //if it had any other factor other than 2,3,5,7 it will leave some residue in temp
        if(temp!=1) return "-1";     //return -1 straightforward

        //PRECOMPUTE step to know what number is left to fit when we fix some part and try to compute the next places

        vector<ll> remainingFactor(n+1, t);
        for(int i=0; i<n; i++){
            int digit = num[i]-'0';    //this will give us the digit in int format

            if(digit==0){
                break;
            }
            remainingFactor[i+1] = remainingFactor[i]/gcd(remainingFactor[i],(ll)digit);


        }

        //if the digits in the number are alone enough we return instantly
        if(remainingFactor[n]==1 && num.find('0') == string::npos) return num;

        //we'll can't fix part of the string which contains '0' so we need to find the index where zero comes, part before it will only be fixed rest we'll take in consideration

        int zeroPos = num.find('0');     //this will give us the index of '0'
        int zeroIndx = n-1;          //if there will be no-'0' we'll obviously start from the very back, trying to keep the number as close as possible to the real number

        if(zeroPos!=-1){
            zeroIndx = zeroPos;
        }

        for(int i = zeroIndx; i>=0; i--){
            ll req = remainingFactor[i];
            int freeSlots = n-1-i;

            for(int digit = (num[i]-'0')+1; digit <=9; digit++){
                ll furtherReq = req/gcd(req, digit);
                string reqNum = filler(furtherReq, freeSlots);

                if(reqNum.size()==freeSlots){
                    return num.substr(0,i) + char(digit +'0')+reqNum;
                }
            }
        }

        return filler(t, n+1);
    }
};