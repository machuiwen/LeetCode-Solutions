// Naive Python solution
// class Solution(object):
//     def multiply(self, num1, num2):
//         """
//         :type num1: str
//         :type num2: str
//         :rtype: str
//         """
//         return str(eval(num1) * eval(num2))

// Naive Java solution
// import java.math.BigInteger;
// public class Solution {
//     public String multiply(String num1, String num2) {
//         BigInteger n1 = new BigInteger(num1);
//         BigInteger n2 = new BigInteger(num2);
//         BigInteger n = n1.multiply(n2);
//         String res = "" + n;
//         return res;
//     }
// }
     
class Solution {
public:
    // https://leetcode.com/discuss/71593/easiest-java-solution-with-graph-explanation
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return 0;
        int n = num1.size(), m = num2.size();
        vector<int> accumulator(n + m, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int d1 = num1[j] - '0';
                int d2 = num2[i] - '0';
                int temp = d1 * d2 + accumulator[i + j + 1];
                accumulator[i + j] += temp / 10;
                accumulator[i + j + 1] = temp % 10;
            }
        }
        string res;
        for (int i: accumulator) {
            if (!(res.empty() && i == 0)) {
                res += to_string(i);
            }
        }
        return res.empty() ? "0" : res;
    }
};   