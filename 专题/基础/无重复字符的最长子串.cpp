class Solution {
public:
int hashmap[130];
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int n = s.size();
        for(int i = 0,j=0;j<n;j++){
            hashmap[s[j]]++;
            while(hashmap[s[j]]>1){
                hashmap[s[i++]]--;
            }
            if(j-i+1 > max){
                max = j-i+1;
            }
        }
        return max;
    }
};