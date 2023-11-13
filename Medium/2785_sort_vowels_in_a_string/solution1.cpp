/**
 * Title:  Sort Vowels in a String (Leetcode Medium 2785)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, November, 2023
 */

class Solution {
private:
    void print(vector<int>& v) {
        for (auto& e: v)
            cout << e << " ";
        cout << "\n";
    }
public:
    int toidx(char c) {
        if (c == 'A') return 0;
        if (c == 'E') return 1;
        if (c == 'I') return 2;
        if (c == 'O') return 3;
        if (c == 'U') return 4;
        if (c == 'a') return 5;
        if (c == 'e') return 6;
        if (c == 'i') return 7;
        if (c == 'o') return 8;
        if (c == 'u') return 9;
        return -1;
    }
    string sortVowels(string s) {
        vector<int> vowel(10, 0); // AEIOUaeiou
        for (char& c: s) {
            int idx = toidx(c);
            if (idx != -1) vowel[idx]++;
        }
        // print(vowel);
        string t = "";
        int v = 0;
        string vowels = "AEIOUaeiou";
        for (char& c: s) {
            int idx = toidx(c);
            if (idx == -1) {
                t += c;
            } else {
                while (vowel[v] == 0)
                    v++;
                t += vowels[v];
                vowel[v]--;
            }
        }
        return t;
    }
};
