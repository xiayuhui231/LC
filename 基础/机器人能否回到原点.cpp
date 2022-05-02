class Solution {
public:
    bool judgeCircle(string moves) {
        int col = 0,row = 0;
        for(auto ch : moves){
            if( ch == 'U') row++;
            else if(ch == 'D') row--;
            else if(ch == 'L') col--;
            else col++;
        }
        return col == 0 && row == 0;

    }
};