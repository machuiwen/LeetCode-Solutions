class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_str;
        encoded_str += to_string(strs.size()) + '.';
        for (string& s: strs) {
            encoded_str += to_string(s.size()) + '.';
        }
        for (string& s: strs) {
            encoded_str += s;
        }
        cout << encoded_str << endl;
        return encoded_str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        stringstream ss;
        ss << s;
        int n;
        char trash;
        ss >> n >> trash;
        vector<int> len(n);
        for (int i = 0; i < n; i++) {
            ss >> len[i] >> trash;
        }
        string raw;
        getline(ss, raw);
        int start = 0;
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = raw.substr(start, len[i]);
            start += len[i];
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));