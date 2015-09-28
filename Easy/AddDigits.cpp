class Solution {
public:
    int addDigits(int num) {
        // Hints: 1. A naive implementation of the above process is trivial. Could you come up with other methods?
        //        2. What are all the possible results?
        //        3. How do they occur, periodically or randomly?
        //        4. https://en.wikipedia.org/wiki/Digital_root
        return (num - 1) % 9 + 1; // This formula looks tricky, but basically it just map (9*x) to 9, rather than 0
    }
};