// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    // O(n) solution
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; i++) 
            if (knows(res, i))
                res = i;
        // we always have res <= i
        // after this step, we know:
        // res doesn't know anyone behind it
        // So, we are sure that: anyone behind it is not celebrity,
        // because res doesn't know them.
        // And anyone before it is not celebrity,
        // because either someone doesn't know them or they know someone.
        // So res is the only possible celebrity.
        
        // check if res satisfy the rules
        for (int i = 0; i < n; i++) {
            if ((knows(res, i) || !knows(i, res)) && (res != i)) {
                return -1;
            }
        }
        return res;
    }
};