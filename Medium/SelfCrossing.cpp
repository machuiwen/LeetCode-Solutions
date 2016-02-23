class Solution {
public:
    // Categorize the self-crossing scenarios, there are 3 of them: 
    // 1. Fourth line crosses first line and works for fifth line crosses second line and so on...
    // 2. Fifth line meets first line and works for the lines after
    // 3. Sixth line crosses first line and works for the lines after
    bool isSelfCrossing(vector<int>& x) {
        int l = x.size();
        if (l <= 3) return false;

        for (int i = 3; i < l; i++) {
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;  //Fourth line crosses first line and onward
            if (i >=4 ) {
                if(x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true; // Fifth line meets first line and onward
            }
            if (i >=5) {
                if(x[i-2] - x[i-4] >= 0 && x[i] >= x[i-2] - x[i-4] && x[i-1] >= x[i-3] - x[i-5] && x[i-1] <= x[i-3]) return true;  // Sixth line crosses first line and onward
            }
        }
        return false;
    }
};