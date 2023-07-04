// You need to construct a binary tree from a string consisting of parenthesis and integers.

// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
// You always start to construct the left child node of the parent first if it exists.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *str2tree(string s)
    {
        if (s == "")
            return nullptr;
        int p = s.find("(");
        if (p == s.npos)
            return new TreeNode(stoi(s));
        TreeNode *root = new TreeNode(stoi(s.substr(0, p)));
        int start = p;
        int cnt = 0;
        for (int i = p; i < s.size(); ++i)
        {
            if (s[i] == '(')
                ++cnt;
            else if (s[i] == ')')
                --cnt;
            if (cnt == 0)
            {
                if (start == p)
                {
                    root->left = str2tree(s.substr(start + 1, i - start - 1));
                    start = i + 1;
                }
                else
                    root->right = str2tree(s.substr(start + 1, i - start - 1));
            }
        }
        return root;
    }
};