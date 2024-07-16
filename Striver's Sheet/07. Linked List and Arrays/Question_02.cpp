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
        if(!head) return nullptr;

        Node* temp = head;
        Node* newNode;
        while (temp != nullptr) {
            newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        while (temp != nullptr) {
            newNode = temp->next;
            newNode->random =
                (temp->random == nullptr) ? nullptr : temp->random->next;
            temp = newNode->next;
        }

        temp = head;
        Node* newHead = head->next;
        while (temp != nullptr) {
            newNode = temp->next;
            temp->next = newNode->next;
            newNode->next = 
                (temp->next == nullptr) ? nullptr : temp->next->next;
            temp = temp->next;
        }

        return newHead;
    }
};