class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isLeaf = false;
    }
    unordered_map<char, TrieNode*> children;
    bool isLeaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int i = 0;
        int len = word.size();
        TrieNode* cur = root;
        while (i < len) {
            if (cur->children.count(word[i])) {
                cur = cur->children[word[i]];
                i++;
            } else {
                break;
            }
        }
        while (i < len) {
            TrieNode* newNode = new TrieNode();
            cur->children[word[i]] = newNode;
            cur = newNode;
            i++;
        }
        cur->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int i = 0;
        int len = word.size();
        TrieNode* cur = root;
        while (i < len) {
            if (cur->children.count(word[i])) {
                cur = cur->children[word[i]];
                i++;
            } else {
                return false;
            }
        }
        return cur->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i = 0;
        int len = prefix.size();
        TrieNode* cur = root;
        while (i < len) {
            if (cur->children.count(prefix[i])) {
                cur = cur->children[prefix[i]];
                i++;
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
// if assuming only a-z lowercase characters:
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isLeaf = false;
        children = vector<TrieNode*> (26, NULL);
    }
    vector<TrieNode*> children;
    bool isLeaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int i = 0;
        int len = word.size();
        TrieNode* cur = root;
        while (i < len) {
            if (cur->children[word[i] - 'a']) {
                cur = cur->children[word[i] - 'a'];
                i++;
            } else {
                break;
            }
        }
        while (i < len) {
            TrieNode* newNode = new TrieNode();
            cur->children[word[i] - 'a'] = newNode;
            cur = newNode;
            i++;
        }
        cur->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int i = 0;
        int len = word.size();
        TrieNode* cur = root;
        while (i < len) {
            if (cur->children[word[i] - 'a']) {
                cur = cur->children[word[i] - 'a'];
                i++;
            } else {
                return false;
            }
        }
        return cur->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i = 0;
        int len = prefix.size();
        TrieNode* cur = root;
        while (i < len) {
            if (cur->children[prefix[i] - 'a']) {
                cur = cur->children[prefix[i] - 'a'];
                i++;
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};
