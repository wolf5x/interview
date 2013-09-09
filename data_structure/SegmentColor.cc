class SegmentTree{
    struct Node {
        int lb, rb;
        int left, right;
        set<int> color;

        Node(int _lb, int _rb)
            : lb(_lb), rb(_rb), left(-1), right(-1)
        {}
    };

    vector<Node> node;
    int lmost, rmost;

    void update(int k, int l, int r, int c)
    {
        if (node[k].l <= l && r <= node[k].r) {
            node[k].color.insert(c);
        } else {
            int m = (node[k].l+node[k].r)>>1;
            if (l < m) {
                if (node[k].left == -1) {
                    node.push_back(Node(l, m));
                    node[k].left = node.size()-1;
                }
                update(node[k].left, l, r, c);
            }
            if (r > m) {
                if (node[k].right == -1) {
                    node.push_back(Node(m, r));
                    node[k].right = node.size()-1;
                }
                update(node[k].right, l, r, c);
            }
        }
    }

    void checkColor(int k, int l, int r, set<int> &ans) {
        ans.insert(node[k].color.begin(), node[k].color.end());
        if (node[k].l+1 < node[k].r) {
            int m = (node[k].l+node[k].r)>>1;
            if (l < m && node[k].left != -1) {
                checkColor(node[k].left, l, r, ans);
            }
            if (r > m && node[k].right != -1) {
                checkColor(node[k].right, l, r, ans);
            }
        }
    }

public:
    SegmentTree(int _lmost, int _rmost) {
        lmost = _lmost;
        rmost = _rmost;
        node.insert(Node(lmost, rmost));
    }

    void update(int l, int r, int color) {
        assert(l < r && "Not a segment.");
        update(0, l, r, color);
    }

    set<int> checkColor(int l, int r) {
        assert(l < r && "Not a segment.");
        set<int> ans;
        checkColor(0, l, r, ans);
        return ans;
    }
};

