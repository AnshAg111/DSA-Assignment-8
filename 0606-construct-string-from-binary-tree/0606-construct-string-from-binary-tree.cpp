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
    void preorder(string &s, TreeNode*root){
        if(root!=nullptr){
            if(root->val<0) s.push_back('-');
            int num=abs(root->val);
            string st;
            if(num==0) st.push_back('0');
            while(num>0){
                char c=(char)(num%10+'0');
                st.push_back(c);
                num/=10;
            }
            reverse(st.begin(), st.end());
            s+=st;
            if(root->left!=nullptr and root->right!=nullptr){
                s.push_back('(');
                preorder(s, root->left);
                s.push_back(')');
                s.push_back('(');
                preorder(s, root->right);
                s.push_back(')');
            }
            else if(root->left==nullptr and root->right!=nullptr){
                s+="()(";
                preorder(s, root->right);
                s.push_back(')');
            }
            else if(root->left!=nullptr){
                s.push_back('(');
                preorder(s, root->left);
                s.push_back(')');
            }
        }
    }
public:
    string tree2str(TreeNode* root) {
        string s;
        preorder(s, root);
        return s;
    }
};