#ifndef _NODE
#define _NODE
struct Node {
    Node *left, *right;
    Node():left(NULL), right(NULL){}
};
#endif

void morrisTraversalPreorder(Node *root, void (*call_back)(Node*))
{
    Node vroot;
    vroot->left = root;
    Node *cur = vroot;
    while(cur != NULL) {
        if (cur->left == NULL) {
            cur = cur->right;
        } else {
            Node *next = cur->left;
            while(next->right != NULL && next->right != cur) {
                next = next->right;
            }
            if (next->right == NULL) {
                next->right = cur;
                cur = cur->left;
            } else {
                next->right = NULL;
                traverseReverseOrder(cur->left, next, call_back);
                cur = cur->right;
            }
        }
    }
}


void traverseReverseOrder(Node *head, Node *tail, void (*call_back)(Node *))
{
    reverse(head, tail);
    for (Node *cur = tail; cur != NULL; cur = cur->right)
    {
        call_back(cur);
    }
    revese(tail, head);
}


void reverse(Node *head, Node *tail)
{
   for (Node *cur = head; cur != tail; )
   {
        Node *next = cur->right;
        cur->right = tail->right;
        tail->right = cur;
        cur = next;
   }
}

