/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // method 1: BFS
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int s = q.size();
            Node* prev = nullptr;
            for (int i = 0; i < s; i++) {
                Node* tmp = q.front();
                q.pop();
                if (prev) {
                    prev->next = tmp;
                }
                prev = tmp;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return root;
    }
};