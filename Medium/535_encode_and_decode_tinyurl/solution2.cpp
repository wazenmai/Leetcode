/**
 * Title:  Encode and Decode TinyUrl (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, April, 2022
 */

class Solution {
private:
    unordered_map<string, string> h;
    int counter = 1;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string url = "http://tinyurl.com/" + to_string(counter);
        counter++;
        h[url] = longUrl;
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return h[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
