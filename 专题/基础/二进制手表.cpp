class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> times;
        for(int i = 0; i<12;++i){
            bitset<4> hour(i);
            for(int j = 0;j<60; ++j){
                bitset<6> min(j);
                if(hour.count() + min.count() == turnedOn){
                    times.push_back(to_string(i) + (j<10?":0" : ":")+to_string(j));
                }
            }
        }
        return times;
    }
};