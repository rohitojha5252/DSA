/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>result;
    // void solve(Node *root){
    //     if(root == NULL)return;
    //     vector<int>ans;
    //     for(auto child: root->children){
    //         ans.push_back(child->val);
    //     }
    //     result.push_back(ans);
    //     for(auto child: root->children){
    //         solve(child);
    //     }
    // }
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)return result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>lev;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                for(auto child: node->children){
                    q.push(child);
                }
                lev.push_back(node->val);
            }
            result.push_back(lev);
        }
        return result;

    }
};