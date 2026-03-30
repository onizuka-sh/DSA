class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};
class MyLinkedList {
private:
    int size = 0;
    Node* head = nullptr;
public:
    MyLinkedList() {}
    int get(int index) {
        if(index >= size) return -1;
        Node* curr = head;
        for(int i = 0; i < index; ++i) curr = curr->next;
        return curr->val;
    }
    void addAtHead(int val) {
        addAtIndex(0 , val);
    }
    void addAtTail(int val) {
        addAtIndex(size , val);
    }
    void addAtIndex(int index, int val) {
        if(index > size) return;
        ++size;
        if(index == 0){
            Node* next = new Node(val);
            next->next = head;
            head = next;
            return;
        }
        Node* node = new Node(val);
        Node* curr = head;
        for(int i = 1; i < index; ++i) curr = curr->next;
        node->next = curr->next;
        curr->next = node;
    }
    void deleteAtIndex(int index) {
        if(index >= size) return;
        --size;
        Node* curr = head;
        if(index == 0){
            head = head->next;
            return;
        }
        for(int i = 1; i < index; ++i) curr = curr->next;
        curr->next = curr->next->next;
    }
};