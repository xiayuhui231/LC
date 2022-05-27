class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> va(26),vb(26);
        for(char c:a){
            va[c - 'a'] ++;
        }
        for(char c:b){
            vb[c - 'a'] ++;
        }
        int t = 0;
        for(int i =0;i<26;i++){
            t = max(t,va[i] + vb[i]);
        }
        int sa = a.size(), sb = b.size();
        int res = sa+sb-t;
        for(int i =25,ta = 0,tb = 0; i>0;i--){
            ta += va[i];
            tb += vb[i];
            res = min(res,min(ta+sb - tb, tb + sa -ta));
        }
        return res;

    }
};