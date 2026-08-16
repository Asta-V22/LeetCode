class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        //lets keep a track of how many 0(mod 3) , 1(mod 3), 2(mod 3) we have
        int track[3] = {0,0,0};

        for(int stone : stones){
            track[stone%3]++;
        }

        //two cases, when the number of passes (0s) are even or odd
        //if 0s are even --> they will cancel each other hence net 0 impact in the game scenario

        if(track[0]%2==0){
            //alice wins if she forces bob to end with the stack having less numbers, 
            // 1->1->2->1->2->1  we can see that the sequence forces bob to choose only 1 number, its in alice's hand where to start from
            //if alice starts with 1, 1->1->2->1->2.....
            //if alice starts with 2, 2->2->1->2->1..... therefore she needs enough stones of 1 type to force bob to choose wrong stone, she must choose that 1 or 2 which will leave bob exhausted with one of them so he has to choose one illegal one
            //By observation we can see that alice wins if she has c1>=1 && c2>=1 she can force bob to choose wrong one by handling bob with the lesser one every turn
            return track[1]>=1 && track[2]>=1;
        }

        //if number of 0s is odd -> one person has one pass oportunity
        //this will be used one either of them want to pass the infavourable condition to another, by observation we get to know that this can be overcome of the difference between track[1] and track[2] is more than 2 for alice, beacause in that case even if bob plays the stall card she has enough in backup that she can transfer the condition back

        return abs(track[1]-track[2])>2;
    }
}; 