class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //edge cases
        //if need1 or need1 is 0 
        if(need1==0 && need2==0) return 0;
        if(need1 == 0) return (long long)(min(cost2,costBoth)*need2);
        if(need2 == 0) return (long long)(min(cost1,costBoth)*need1);

        if(min(cost1,cost2)>=costBoth) return (long long)(max(need1,need2)*(long long)costBoth);

        if((cost1 +cost2)<costBoth){
            return (long long)((cost1*(long long)need1) + (cost2*(long long)need2));
        }

        //else if (cost1 +cost2)>=costBoth
        long long k = min(need1, need2);
        long long cost = k * costBoth;
        need1 -= k;
        need2 -= k;

        if(need1!=0){
            cost+= (long long)need1*min(cost1,costBoth);
        }
        else{
            cost+=(long long)need2*min(cost2,costBoth);
        }

        return cost;

    }
};