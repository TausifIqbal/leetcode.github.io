// https://leetcode.com/problems/clone-graph/


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
    unordered_map<Node*,Node*> mp; // original to clone
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return node;
        }
        if(mp.find(node)==mp.end()){
            mp[node]=new Node(node->val,{});
            for( auto n: node->neighbors){
                mp[node]->neighbors.emplace_back(cloneGraph(n));
            }
        }
        return mp[node];
    }
};
