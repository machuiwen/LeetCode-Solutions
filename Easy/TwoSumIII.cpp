// fast add, slow find
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
	        if ((value == 2 * num && M[num] >= 2) ||
	            (value != 2 * num && M.count(value - num))) {
	                return true;
	        }
	    }
	    return false;
	}
    
private:
    unordered_map<int, int> M;
};

// fast find, slow add
class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    if (nums.count(number)) {
	        sums.insert(number * 2);
	    } else {
    	    for (int n: nums) {
    	        sums.insert(n + number);
    	    }
    	    nums.insert(number);
	    }
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    return sums.count(value);
	}
    
private:
    unordered_set<int> sums;
    unordered_set<int> nums;
};

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);