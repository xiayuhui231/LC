class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int a1 = stoi(loginTime.substr(0,2)), a2 = stoi(loginTime.substr(3));
        int b1 = stoi(logoutTime.substr(0,2)),b2 = stoi(logoutTime.substr(3));
        if(logoutTime < loginTime){
            b1+=24;
        }
        int t = (b1-a1-1) *4  + (60 -a2) /15 + b2/15;
        return t>0?t:0;
        
    }
};