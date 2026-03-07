#include <iostream>

struct Node {
    Node* next;
    int data;
};

class LinkedList {
    Node* head;

    public:
    LinkedList() {
        head = nullptr;
    }

    void push_back(int data) {
        Node* temp = new Node(), *iter = head;
        temp->data = data;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            return;
        }

        while ( iter->next != nullptr) {
            iter = iter->next;
        }

        iter->next = temp;
    }

    void pop_back() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void push_front(int data) {
        if (head == nullptr) return;

        Node* temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop(int idx) {
        if (idx == 1) {
            pop_front();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < idx - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            std::cout << "Index out of bounds" << std::endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void insert(int idx, int data) {
        if (idx == 1) {
            push_front(data);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < idx - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Index out of bounds" << std::endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int get(int idx) {
        Node* temp = head;
        for (int i = 0; i < idx - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return -1;
        return temp->data;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(3);
    list.insert(2, 4);
    std::cout << list.get(2) << std::endl;
    list.pop_back();
    list.pop_front();
    std::cout << list.get(2) << std::endl;
    list.pop(1);
    std::cout << list.get(1) << std::endl;
    return 0;
}