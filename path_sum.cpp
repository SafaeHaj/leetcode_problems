 #include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int* pathSum(TreeNode* root, int sum, int answer[1], int target) {

    if (root != nullptr) {
        
        sum += root->val;  
        if(!root->right && !root->left) {
            if(sum == target)
                answer[0] = sum;
        }

        pathSum(root->left, sum, answer, target);
        pathSum(root->right, sum, answer, target);
    }
    
    return answer;
} 
    
bool hasPathSum(TreeNode* root, int targetSum) {
    
    int arr[1];
    int* ans = pathSum(root, 0, arr, targetSum);
    
    if(ans[0] == targetSum)
        return true;
    
    return false;
}


int main(int argc, char **argv) {

    TreeNode t = TreeNode(2, nullptr, nullptr);
    TreeNode root = TreeNode(1, nullptr, &t);

    if (hasPathSum(&root, 1))
        cout << "true";
    else
        cout << "false";

    return 0;
}