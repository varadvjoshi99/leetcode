#include<vector>

using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<TreeNode*> generate(int l, int r) {

        if (r < l) return vector<TreeNode*>{nullptr};

        if (l == r) {
            auto tr = new TreeNode(l);
            return vector<TreeNode*>{tr};
        }

        vector<TreeNode*> result;

        for (int i = l; i <= r; i++) {
            auto left = generate(l, i-1);
            auto right = generate(i+1, r);

            for (auto lnode : left) {
                for (auto rnode : right) {
                    auto root = new TreeNode(i);

                    root->left = lnode;
                    root->right = rnode;

                    result.push_back(root);
                }
            }
        }

        return result;
    }
  
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};