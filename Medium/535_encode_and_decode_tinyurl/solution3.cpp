/**
 * Title:  Encode and Decode TinyUrl (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, April, 2022
 * Method: Use base62-like encode method.
 */

class Solution {
private:
    string base = "http://tinyurl.com/";
    string code = "zxcvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLQWERTYUIOP1234567890";
    unordered_map<string, string> h; //tiny, long
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string url = convert();
        while (h.find(url) != h.end()) {
            url = convert();
        }
        h[url] = longUrl;
        return base + url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string url = shortUrl.substr(19);
        return h[url];
    }
    
    string convert() {
        string s = "";
        for (int i = 0; i < 6; i++) {
            s += code[rand() % 62];
        }
        return s;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
