#include <limits.h>


// NOTE: C++, not C

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
*/
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

    // Constraints 0 <= data <= 10^4
    bool checkBST(Node* root, int curr_min_value = 0, int curr_max_value = 10000) {

        if (root == nullptr) {
            // Managed to get to the end of a branch without failing, so we're good.
            return true;
        }

        if (root->data <= curr_min_value || root->data >= curr_max_value) {
            return false;
        }

        // Don't need to explicitly update the min/max values because if the above check passes then data *becomes* the min value on the left and the max value
        // on the right. This is what the rules dictate. Otherwise it's not a true binary tree and we can fail it.

        bool left_check = checkBST(root->left, curr_min_value, root->data);
        bool right_check = checkBST(root->right, root->data, curr_max_value );

        return left_check && right_check;
    }