class Solution {
public:
    int minAddToMakeValid(string s) {
        int open, ans;
        open = ans = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') open++;
            else open--;
            if (open < 0) {
                ans++;
                open++; //adding one open
            }
        }
        return ans + open; // open number of closings should be added
    }
};