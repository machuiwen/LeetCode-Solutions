#include <cmath>
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int start = 0;
        int end = height.size() - 1;
        int maxWater = 0;
        while (start <= end) {
            maxWater = max(maxWater, min(height[start], height[end]) * (end - start));
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return maxWater;
    }
};