#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> m;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->value;
            deleteNode(resNode);
            addNode(resNode);
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
            delete existingNode;
        }

        if (m.size() == cap) {
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main() {
    cout << "[null";

    LRUCache* lRUCache = new LRUCache(2);

    lRUCache->put(1, 1);
    cout << ",null";

    lRUCache->put(2, 2);
    cout << ",null";

    cout << "," << lRUCache->get(1);

    lRUCache->put(3, 3);
    cout << ",null";

    cout << "," << lRUCache->get(2);

    lRUCache->put(4, 4);
    cout << ",null";

    cout << "," << lRUCache->get(1);

    cout << "," << lRUCache->get(3);

    cout << "," << lRUCache->get(4);

    cout << "]" << endl;

    delete lRUCache;

    return 0;
}