class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        //days spent together = if in the same month -> if dates overlap -> whoever arrived earlier - whoever departed the earliest + 1; 

        //ariving in different months -> return 0;
        //arriving in the same month but on non overlapping schedule -> return 0;

        int arriveAliceMonth = stoi(arriveAlice.substr(0,2));
        int arriveAliceDay = stoi(arriveAlice.substr(3,2));

        int arriveBobMonth = stoi(arriveBob.substr(0,2));
        int arriveBobDay = stoi(arriveBob.substr(3,2));
        
        int leaveAliceMonth = stoi(leaveAlice.substr(0,2));
        int leaveAliceDay = stoi(leaveAlice.substr(3,2));

        int leaveBobMonth = stoi(leaveBob.substr(0,2));
        int leaveBobDay = stoi(leaveBob.substr(3,2));

        vector<int> year = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for(int i=1; i<year.size(); i++){
            year[i] = year[i]+year[i-1];
        }

        int alicearrive = year[arriveAliceMonth-1] + arriveAliceDay;
        int aliceleave = year[leaveAliceMonth-1] + leaveAliceDay;

        int bobarrive = year[arriveBobMonth-1] + arriveBobDay;
        int bobleave = year[leaveBobMonth-1] + leaveBobDay;

        int overlapstart = max(alicearrive, bobarrive);
        int overlapend = min(aliceleave, bobleave);

        if(overlapend < overlapstart) return 0;
        
        return overlapend - overlapstart + 1;

    }
};