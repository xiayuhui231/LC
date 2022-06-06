class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
 int n = (int)people.size();
        if (n == 1) return 1;
        sort(people.begin(), people.end());
        int left = 0, right = n - 1, ans = 0; 
        long long sum = accumulate(people.begin(), people.end(), 0), count = 0;
        while(left < right) {
            if (people[left] + people[right] > limit) {
                count += people[right--];
                ++ans;
            } else {
                count += people[left++];
                count += people[right--];
                ++ans;
            }
        }
        if (sum != count)   return ans + 1;
        return ans;
    }
};