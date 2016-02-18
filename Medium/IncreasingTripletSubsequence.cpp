class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        for (int i: nums) {
            // if v is empty, add i to v
            if (v.empty()) v.push_back(i);
            // if the last element in v is less than i, add i to v
            else if (v.back() < i) v.push_back(i);
            // if size(v) = 1 or size(v) = 2 but i <= v[0], change v[0] to be i
            else if (v.size() == 1 || i <= v[0]) v[0] = i;
            // if size(v) = 2 and v[0] <= i, but we know i < v[1], change v[1] to be i
            else v[1] = i;
            // when we find a increasing triplet, return true
            if (v.size() == 3) return true;
        }
        return false;
    }
};