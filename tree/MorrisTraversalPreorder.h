#ifndef _NODE
#define _NODE
struct Node {
    Node *left, *right;
    Node():left(NULL), right(NULL){}
};
#endif

void morrisTraversalPreorder(Node *root, void (*call_back)(Node*))
{
    Node *cur = root;
    while(cur != NULL) {
        if (cur->left == NULL) {
            if (call_back != NULL) {
                call_back(cur);
            }
            cur = cur->right;
        } else {
            Node *next = cur->left;
            while(next->right != NULL && next->right != cur) {
                next = next->right;
            }
            if (next->right == NULL) {
                if (call_back != NULL) {
                    call_back(cur);
                }
                next->right = cur;
                cur = cur->left;
            } else {
                next->right = NULL;
                cur = cur->right;
            }
        }
    }
}

