#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// PROBLEM 1 START
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> memm; // val -> index
    while(head != NULL) {
        printf("%d \n", head->val);
        if(memm.find(head) != memm.end()) {
            return true;
        }
        memm.insert(head);
        head = head->next;
    }
    printf("HERE \n");
    return false;
}
// PROBLEM 1 END

// PROBLEM 2 START
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return root;

    if(root->val < key)
        root->right = deleteNode(root->right, key);
    else if(root->val > key)
        root->left = deleteNode(root->left, key);
    else {
        if(root->left == NULL && root->right == NULL)
            return NULL;
        if(root->left == NULL) {
            return root->right;
        } else if(root->right == NULL) {
            return root->left;
        } else {
            TreeNode * curr_node = root->right;
            while(curr_node->left != NULL) {
                curr_node = curr_node->left;
            }
            root->val = curr_node->val;
            root->right = deleteNode(root->right, curr_node->val);
        }
    }
    return root;
}
// PROBLEM 2 END

// PROBLEM 3 START

int calculate(string s) {
    int len = s.length();
    if (len == 0) return 0;
    stack<int> stack;
    int currentNumber = 0;
    char operation = '+';
    for (int i = 0; i < len; i++) {
        char currentChar = s[i];
        if (isdigit(currentChar)) {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }
        if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
            if (operation == '-') {
                stack.push(-currentNumber);
            } else if (operation == '+') {
                stack.push(currentNumber);
            } else if (operation == '*') {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop * currentNumber);
            } else if (operation == '/') {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop / currentNumber);
            }
            operation = currentChar;
            currentNumber = 0;
        }
    }
    int result = 0;
    while (stack.size() != 0) {
        result += stack.top();
        stack.pop();
    }
    return result;
}
// PROBLEM 3 END

//[5,3,6,2,4,null,7], key = 3
int main() {
    printf("%d == 7\n",calculate("3+2*2"));
    //printf("%d == 1\n",calculate("3/2"));
    //printf("%d == 5\n",calculate("3+5/2"));
}
