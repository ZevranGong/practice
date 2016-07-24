/**
 * Convert Sorted Array to Binary Search Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Using offset without copying vector
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelp(nums, 0, nums.size());
    }
    
    TreeNode* sortedArrayToBSTHelp(vector<int>& nums, int start, int end){
        if (end==start){
            return NULL;
        }
        else if (end-start==1){
            return new TreeNode(nums[start]);
        }
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelp(nums,start,mid);
        root->right = sortedArrayToBSTHelp(nums,mid+1,end);
        return root;
    }
};

//Rebuild vectors using v.assign(), slightly slower
class Solution2 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()){
            return NULL;
        }
        else if (nums.size()==1){
            return new TreeNode(nums[0]);
        }
        TreeNode* root = new TreeNode(nums[nums.size()/2]);
        vector<int> temp;
        temp.assign(nums.begin(), nums.begin()+nums.size()/2);
        root->left = sortedArrayToBST(temp);
        temp.assign(nums.begin()+nums.size()/2+1, nums.end());
        root->right = sortedArrayToBST(temp);
        return root;
    }
};