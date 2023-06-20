#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int res = 0;
        for (int i = 0; i < letters.size(); i++) {
            char ch = letters[i];
            vector<int> present(s.size(), 0);

            for (int j = 0; j < present.size(); j++) {
                if (s[j] == ch) present[j] = 1;
            }

            int com = compute(present, k);

            // cout << com << " " << ch << endl;
            res = max(res, com);
        }

        return res;
    }

    int compute(vector<int>& present, int k) {
        
        int l = 0;
        int count = 0, res = 0;
        for (int r = 0; r < present.size(); r++) {
            
            if (present[r] == 0) {
                count++;
            }
            while (count > k && l <= r) {
                if (present[l] == 0) {
                    count--;
                }
                l++;
            }

            res = max(res, r - l + 1);
        }
        
        return res;
    }
};