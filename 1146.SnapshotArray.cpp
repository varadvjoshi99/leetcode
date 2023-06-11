#include<vector>
#include<map>
#include<iostream>
using namespace std;

// class SnapshotArray {

// public:

//     vector<int> arr;
//     map<int, map<int, int>> snaps;
//     int snap_id = 0;
//     map<int, int> changed;

//     SnapshotArray(int length) {
//         arr.assign(length, 0);
//     }
    
//     void set(int index, int val) {
//         arr[index] = val;
//         changed[index] = val;
//     }
    
//     int snap() {
//         for (auto ch: changed) {
//             snaps[snap_id][ch.first] = ch.second;
//             cout << snap_id << ch.first << ch.second;
//         }
//         changed.clear();
//         return snap_id++;
//     }
    
//     int get(int index, int snap_id) {
//         // return snaps[snap_id][index];
//         while (snap_id >= 0) {
//             if (snaps[snap_id].find(index) != snaps[snap_id].end()) {
//                 snap_id--;
//             } else {
//                 return snaps[snap_id][index];
//             }
//         }
//         return 0;
//     }
// };

typedef pair<int, int> pp;
class SnapshotArray {
public:

    vector<int> arr;
    vector<vector<pair<int, int>>> snaps;
    int snap_id = 0;
    map<int, int> changed;

    SnapshotArray(int length) {
        arr.assign(length, 0);
        snaps.assign(length, vector<pair<int,int>>()); 
        for (int i = 0; i < length; i++) {
            changed[i] = 0;
        }
    }
    
    void set(int index, int val) {
        arr[index] = val;
        changed[index] = val;
    }
    
    int snap() {
        for (auto ch: changed) {
            snaps[ch.first].push_back(make_pair(snap_id, ch.second));
            // cout << snap_id << ch.first << ch.second;
        }
        changed.clear();
        return snap_id++;
    }
 
    static bool cmp(const pp &l,const pp &r) {
        return l.first < r.first;
    }
 
    int get(int index, int snap_id) {
        // return snaps[snap_id][index];
        
        int id = upper_bound(snaps[index].begin(), snaps[index].end(), pp(snap_id, 0), cmp) - snaps[index].begin();
        return snaps[index][id-1].second;
        // } else if ()

    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */