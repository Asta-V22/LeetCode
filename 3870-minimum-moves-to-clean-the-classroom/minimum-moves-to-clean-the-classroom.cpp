class Solution {
public:
    using VB  = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>; 

    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    struct State{
        int row;
        int col;
        int energy;
        int mask;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int maxenergy = energy;

        //now we need to find where to start and where are the litters
        int litterbitposition[20][20];
        int littercount = 0;
        int startrow;
        int startcol;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                litterbitposition[i][j]=-1;
                if(classroom[i][j]=='S'){
                    startrow = i;
                    startcol = j;
                }
                else if(classroom[i][j]=='L'){
                    litterbitposition[i][j] = littercount;
                    littercount++;
                }
            }
        }

        if(littercount==0) return 0;

        int allcollected  = (1<<littercount)-1;

        VVVVB visited(m, VVVB(n,VVB(maxenergy+1,VB(1<<littercount, false))));   //crazy!!

        queue<State> q;
        q.push({startrow, startcol, maxenergy, 0});   //at the start the bit masking will have 0 0 0 0 at the indices so it will give 0

        visited[startrow][startcol][maxenergy][0] = true;
        
        int moves = 0;
        
        while(!q.empty()){
            int currsize  = q.size();
            while(currsize--){
                State curr = q.front();
                q.pop();
                
                if(curr.mask==allcollected) return moves;

                if(curr.energy == 0){
                    continue;
                }

                for(auto &dir: directions){
                    int nextrow = curr.row+ dir[0];
                    int nextcol = curr.col+dir[1];

                    //check if valid
                    if(nextrow<m && nextrow>=0 && nextcol<n && nextcol>=0){
                        char cell = classroom[nextrow][nextcol];

                        if(cell == 'X') continue;  //dead end
                        
                        int nextenergy  = curr.energy - 1;
                        int nextcollectedbitmask = curr.mask;

                        if(cell == 'R'){
                            nextenergy = maxenergy;
                        }
                        else if(cell == 'L'){
                            nextcollectedbitmask |= (1<<litterbitposition[nextrow][nextcol]);
                        }

                        if(!visited[nextrow][nextcol][nextenergy][nextcollectedbitmask]){
                            visited[nextrow][nextcol][nextenergy][nextcollectedbitmask] = true;
                            q.push({nextrow, nextcol, nextenergy, nextcollectedbitmask});
                        }
                    }

                }



            }
            moves++;
        }
        return -1;
    }
};