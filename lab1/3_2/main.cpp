#include <iostream>

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();
    Node* temp = head;
    for (int i = 1; i <= 5; i++) {
        temp->data = i;
        temp->next = new Node();
        temp = temp->next;
    }
    temp->next = head;

    Node *slow = head, *fast = head;
    bool hasCycle = false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle) {
        std::cout << "No cycle detected." << std::endl;
    } else {
        std::cout << "Cycle detected." << std::endl;
        fast = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        std::cout << "Cycle starts at: " << slow->data << std::endl;

        int cycleCount = 0;
        do {
            fast = fast->next;
            cycleCount++;
        } while (fast != slow);

        std::cout << "Cycle count: " << cycleCount << std::endl;
    }

    if (head != nullptr) {
        Node* current = head->next;

        head->next = nullptr;

        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
    }

    return 0;
}