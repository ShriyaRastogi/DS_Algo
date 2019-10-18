/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct cases
{
    int cs0,cs1,cs2;
    cases(int x, int y, int z)
    {
        cs0 = x;
        cs1 = y;
        cs2 = z;
    }
};
class Solution {
public:
    cases doIt(TreeNode* root)
    {
        if(root==NULL) return cases(0,0,99999);
        auto l = doIt(root->left);
        auto r = doIt(root->right);
        int mil = min(l.cs1,l.cs2);
        int mir = min(r.cs1,r.cs2);
        int d0 = l.cs1 + r.cs1;
        int d1 = min(mil+r.cs2,mir+l.cs2);
        int d2 = 1 + min(mil,l.cs0) + min(mir,r.cs0);
        return cases(d0,d1,d2);
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        auto well = doIt(root);
        return min(well.cs2,well.cs1);
    }
};