int tmp = 0, res = 0;
        for (int i = 0; i < k; i++) {
            if (foo(s[i])) {
                tmp++;
            }
            if(tmp==k) return k;
        }
        res=max(res,tmp);
        for (int i = k; i < s.size(); i++) {
            if (foo(s[i])) {
                tmp++;
            }
            if (foo(s[i - k])) {
                tmp--;
            }
            res = max(res, tmp);
        }

        return res;
    }
    bool foo(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;