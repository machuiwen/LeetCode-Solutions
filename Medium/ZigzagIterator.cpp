// C++ solution using queue. Simple and concise.
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            q.push(make_pair(v1.begin(), v1.end()));
        }
        if (!v2.empty()) {
            q.push(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        auto p = q.front();
        q.pop();
        auto beginItr = p.first;
        auto endItr = p.second;
        if (beginItr + 1 != endItr) {
            q.push(make_pair(beginItr + 1, endItr));
        }
        return *beginItr;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

// My naive solution
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(v1);
        cur.push_back(0);
        v.push_back(v2);
        cur.push_back(0);
        which = 0;
    }

    int next() {
        assert(hasNext());
        int result;
        while (cur[which] >= v[which].size()) {
            which = incBy(which, 1);
        }
        result = v[which][cur[which]];
        cur[which]++;
        which = incBy(which, 1);
        return result;
    }

    bool hasNext() {
        for (int i = 0; i < v.size(); i++) {
            if (cur[incBy(which, i)] < v[incBy(which, i)].size()) return true;
        }
        return false;
    }
private:
    vector<vector<int>> v;
    vector<int> cur;
    int which;
    
    int incBy(int n, int step) {
        n = (n + step) % v.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */