class Solution {
public:
    vector<int> beautifulArray(int N) {
vector<int> vec;
        if(1 == N)
        {
            vec.push_back(1);
            return vec;
        }
        else
        {
            vector<int> vTemp1 = beautifulArray((N+1)/2);
            for(int i = 0;i<vTemp1.size();i++)
                vec.push_back(vTemp1[i]*2-1);
            vector<int> vTemp2 = beautifulArray(N/2);
            for(int i = 0;i<vTemp2.size();i++)
                vec.push_back(vTemp2[i]*2);
        }
		return vec;
    }
};