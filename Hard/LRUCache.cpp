// The key to solve this problem is using a double linked list
// which enables us to quickly move nodes. 
// The LRU cache is a hash table of keys and double linked nodes.
// The hash table makes the time of get() to be O(1). The list of
// double linked nodes make the nodes adding/removal operations O(1).
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int value = -1;
        if (keyLoc.count(key)) {
            auto itr = keyLoc[key];
            value = itr->second;
            touch(itr);
        }
        return value;
    }
    
    void set(int key, int value) {
        list<pair<int, int>>::iterator itr;
        if (keyLoc.count(key)) {
            itr = keyLoc[key];
            itr->second = value;
            touch(itr);
        } else {
            cache.push_back(pair<int, int>(key, value));
            itr = --(cache.end());
            keyLoc[key] = itr;
            if (cache.size() > capacity) {
                keyLoc.erase(cache.front().first);
                cache.pop_front();
            }
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> keyLoc;
    list<pair<int, int>> cache;
    int capacity;
    
    void touch(list<pair<int, int>>::iterator &itr) {
        cache.push_back(*itr);
        keyLoc[itr->first] = --(cache.end());
        cache.erase(itr);
    }
};