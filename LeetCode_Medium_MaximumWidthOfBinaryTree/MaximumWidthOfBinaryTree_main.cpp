#include <iostream>
#include <queue>

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

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    using node = pair<TreeNode*, pair<unsigned int, int>>;

    int bfs(TreeNode* root)
    {
        unsigned int ans = 0;
        queue<node> q;
        q.push({ root, {1, 0} });
        int start = -1;
        int level = -1;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (level != curr.second.second)
            {
                start = curr.second.first;
                level = curr.second.second;
            }
            ans = max(ans, curr.second.first - start + 1);
            if (curr.first->left) q.push({ curr.first->left, {curr.second.first * 2 - 1, curr.second.second + 1} });
            if (curr.first->right) q.push({ curr.first->right, {curr.second.first * 2, curr.second.second + 1} });
        }
        return ans;
    }

    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};


int main()
{

	return 0;
}