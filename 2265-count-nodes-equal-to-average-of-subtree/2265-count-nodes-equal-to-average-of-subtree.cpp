/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void move(TreeNode *root, unordered_map<int, int>&mp){
        mp[root->val]++;
        if(root->left != NULL){
            move(root->left, mp);
        }
        if(root->right != NULL){
            move(root->right, mp);
        }
        return;
    }
    pair<int,int> avg(TreeNode *root, unordered_map<int, int> &mp){
        if (root == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = avg(root->left, mp);
        pair<int, int> right = avg(root->right, mp);

        int sum = root->val + left.first + right.first;
        int cnt = 1 + left.second + right.second;

        // if(mp[sum/cnt] > 0){
        //     mp[sum/cnt]--;
        //     ans++;
        // }
        if(sum/cnt == root->val)ans++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        unordered_map<int, int>mp;
        move(root, mp);
        avg(root, mp);
        return ans;
    }
};