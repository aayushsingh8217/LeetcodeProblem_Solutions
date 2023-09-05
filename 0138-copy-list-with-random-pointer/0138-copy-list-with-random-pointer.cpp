/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if (!head) return nullptr;
    
    // Step 1: Duplicate each node and insert it after the original node.
    Node* current = head;
    while (current) {
        Node* newNode = new Node(current->val);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }
    
    // Step 2: Update the random pointers of the new nodes.
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }
    
    // Step 3: Separate the original and copied linked lists.
    Node* newHead = head->next;
    Node* original = head;
    Node* copied = newHead;
    while (original) {
        original->next = copied->next;
        original = original->next;
        if (original) {
            copied->next = original->next;
            copied = copied->next;
        }
    }
    
    return newHead;
    }
};