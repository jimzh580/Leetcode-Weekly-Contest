class Solution {
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0,z=0,i,n=instructions.size();
        for(i=0;i<n;i++)
            if(instructions[i]=='G'){
                x+=dx[z];
                y+=dy[z];
            }else if(instructions[i]=='L')
                z=z+3&3;
            else z=z+1&3;
        
        if(!x&&!y) return 1;
        return z;
    }
};