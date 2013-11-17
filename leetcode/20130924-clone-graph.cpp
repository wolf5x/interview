/*
 * Clone Graph
 * http://oj.leetcode.com/problems/clone-graph/
 *
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (node == NULL)
            return NULL;
        unordered_map<int, UndirectedGraphNode *> newNode;
        queue<UndirectedGraphNode *> que;
        que.push(node);
        while(!que.empty()) {
            UndirectedGraphNode *now = que.front();
            que.pop();
            if (newNode.count(now->label) == 0) {
                newNode[now->label] = new UndirectedGraphNode(now->label);
            }
            UndirectedGraphNode *newNow = newNode[now->label];
            for (auto &nb : now->neighbors) {
                if (newNode.count(nb->label) == 0) {
                    UndirectedGraphNode *newNb = new UndirectedGraphNode(nb->label);
                    newNode[nb->label] = newNb;
                    que.push(nb);
                }
                newNow->neighbors.push_back(newNode[nb->label]);
            }
        }
        return newNode[node->label];
    }
};
