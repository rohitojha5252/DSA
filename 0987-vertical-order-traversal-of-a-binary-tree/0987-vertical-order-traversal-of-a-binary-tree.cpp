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
    void solve(TreeNode* root,int i, int j, map<int, vector<pair<int, int>>> &mp){
        if(root == NULL)return;
        // cout<<root->val<<endl;
        if(root->left){
            mp[j-1].push_back({i+1, root->left->val});
            solve(root->left, i+1, j-1, mp);
        }
        if(root->right){
             mp[j+1].push_back({i+1, root->right->val});
             solve(root->right, i+1, j+1, mp);
        }
        return;

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>>mp;
        mp[0].push_back({0,root->val});
        solve(root,0, 0, mp);
        vector<vector<int>>ans;
        for(auto &x : mp) {
            vector<int> temp;
            sort(x.second.begin(), x.second.end());
            for(auto &z : x.second) {
                temp.push_back(z.second);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};