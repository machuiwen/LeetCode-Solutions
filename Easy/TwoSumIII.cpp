class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    M[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto p: M) {
	        int num = p.first;
	        if (value != 2 * num && M.count(value - num)) {
	            return true;
	        } else if (value == 2 * num && M[num] >= 2) {
	            return true;
	        }
	    }
	    return false;
	}
    
private:
    unordered_map<int, int> M;
};