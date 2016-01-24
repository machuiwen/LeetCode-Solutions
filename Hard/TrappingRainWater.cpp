class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int waterLevel = 0;
        int waterAmount = 0;
        while (start <= end) {
            if (height[start] < height[end]) {
                waterLevel = max(waterLevel, height[start]);
                waterAmount += waterLevel - height[start];
                start++;
            } else {
                waterLevel = max(waterLevel, height[end]);
                waterAmount += waterLevel - height[end];
                end--;
            }
        }
        return waterAmount;
    }
};