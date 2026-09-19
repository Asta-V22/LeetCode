class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nx = max(x1, min(x2,xCenter));
        int ny = max(y1, min(y2,yCenter));

        //nx and ny is closest point to the center of the circle

        int distance = ((nx-xCenter)*(nx-xCenter) +  (ny-yCenter)*(ny-yCenter));

        if(distance<=radius*radius){
            return true;
        }
        return false;
    }
};