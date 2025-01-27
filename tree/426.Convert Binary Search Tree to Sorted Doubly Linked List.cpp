// Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

// You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

// We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        inorder(root);
        prev->right = head;
        head->left = prev;
        return head;
    }
private:
    Node* head = nullptr;
    Node* prev = nullptr;
    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);
        if (!head) {
            head = root;
        }
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        inorder(root->right);
    }
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        // method 2: inorder iterative approach
        if (!root) return nullptr;

        Node* head = nullptr;
        Node* prev = nullptr;
        Node* curr = root;
        
        stack<Node*> s;
        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                Node* tmp = s.top();
                s.pop();

                if (!head) {
                    head = tmp;
                    prev = tmp;
                }
                else {
                    tmp->left = prev;
                    prev->right = tmp;
                    prev = tmp;
                }
                curr = tmp->right;
            }
        }

        head->left = prev;
        prev->right = head;
        return head;
    }
};