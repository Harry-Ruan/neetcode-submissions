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
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* newnode = new Node(1);
        Node* cursor = newnode;
        unordered_map<Node*, Node*> visited;
        BFS(node, cursor, visited);
        return newnode;
    }

    void BFS(Node* cur, Node* cursor, unordered_map<Node*, Node*>& visited){
        if (!cur || cur->neighbors.empty()) return;
        visited[cur] = cursor;
        for (Node* neighbor : cur->neighbors){
            if (!visited.count(neighbor)){
                Node* next = new Node(neighbor->val);
                cursor->neighbors.push_back(next);
                BFS(neighbor, next, visited);
            }
            else{
                Node* next = visited[neighbor];
                cursor->neighbors.push_back(next);
            }
        }
    }
};
