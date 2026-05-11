Question Link: https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
unordered_map<int, Node *> trackNodesMap;

Node * dfs(Node *root)
{
    if(!root) return NULL;

    // If the value of the node is already present, it means that Node is already created
    if(trackNodesMap.find(root -> val) != trackNodesMap.end() ) return trackNodesMap[root -> val];

    // Else the root is not formed 

    Node *newRoot = new Node(root -> val);
    trackNodesMap[root -> val] = newRoot;

    for(Node *neigh: root -> neighbors)
    {
        Node *newNeighbor = dfs(neigh);
        newRoot -> neighbors.push_back(newNeighbor);
    }

    return newRoot;
}

public:
    Node* cloneGraph(Node* node) 
    {
        return dfs(node);
    }
};
