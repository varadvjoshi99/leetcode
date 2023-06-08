#include<vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:

    static bool comp(vi& a, vi&b) {
        if (a[1] != b[1]) {
            return a[1] < b[1];
        } else {
            return a[0] > b[0];
        }

    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        vvi q;
        sort(people.begin(), people.end(), comp);


        for (auto person: people) {
            int count = person[1];
            auto it = q.begin();
            for (; it != q.end() && count > 0; it++) {
                if ((*it)[0] >= person[0]) 
                {
                    count--;
                }
            }

            q.insert(it, person);
        }

        return q;
    }
};