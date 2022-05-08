class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int div = x / mid;
            if (div > mid) left = mid +1;
            if (div < mid) right = mid -1;
            if (div == mid) return mid;
        }
        return right;
    }
};