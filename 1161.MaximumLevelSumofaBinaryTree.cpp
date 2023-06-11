#include<queue>
#include<limits>
using namespace std; 

// Definition for a binary tree node.
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
    int maxLevelSum(TreeNode* root) {
        int maxlevel = 0, maxsum = INT_MIN;
        int level = 1;
        queue<TreeNode*> q;

        q.push(root);

        while (q.size()) {
            
            int sum = 0;
            int n = q.size();
            for(int i=0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxsum) {
                maxsum = sum;
                maxlevel = level;
            }

            level++;
        }

        return maxlevel;
    }
};