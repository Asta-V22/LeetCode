class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        if(n==10) return true;
        int chance = 1;   // here 1 is a1ice and 0 is b0b  :)

        // int remStones = n;

        int toRemove = 10;  
        

        while(n>=toRemove && toRemove>0){
            n = n - toRemove;   //2
            chance = !chance;
            toRemove--;
        }

        return chance==1?false:true;


    }
};