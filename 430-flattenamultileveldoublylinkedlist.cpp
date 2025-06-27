class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* next = curr->next;
                Node* child = flatten(curr->child);

                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;

                Node* t*
