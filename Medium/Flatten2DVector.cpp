class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x = 0;
        y = -1;
        this->vec2d = vec2d;
    }

    int next() {
        if (y < int(vec2d[x].size()) - 1) {
            return vec2d[x][++y];
        }
        y = 0;
        x++;
        while (x < vec2d.size()) {
            if (vec2d[x].size() > 0) {
                return vec2d[x][0];
            }
            x++;
        }
        return -1;
    }

    bool hasNext() {
        if (x >= vec2d.size()) return false;
        if (y < int(vec2d[x].size()) - 1) return true;
        int cur = x + 1;
        while (cur < vec2d.size()) {
            if (vec2d[cur].size() > 0) {
                return true;
            }
            cur++;
        }
        return false;
    }
    
private:
    int x, y;
    vector<vector<int>> vec2d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */