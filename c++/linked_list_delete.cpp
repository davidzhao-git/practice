#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

    SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
    if (head == nullptr) {
        head = temp;
        return head;
    }

    // SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *front = head;

    while (front->next != nullptr) {
        front = front->next;
    }
    front->next = temp;
    
    /* front = head;
    while (front != nullptr) {
        cout << front->data;
        front = front->next;
    } 
    */
    
    return head;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

    SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);

    if (llist == nullptr) {
        llist = temp;
        return llist;
    }
    
    temp->next = llist;
    llist = temp;
    return llist;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    
    if (head == nullptr) {
        return head;
    }
    
    SinglyLinkedListNode *new_node = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *front = head;
    int i = 0;
    while (i < position-1) {
        front = front->next;
        i++;
    }
    SinglyLinkedListNode *temp = front->next;
    front->next = new_node;
    new_node->next = temp;
    
    return head;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    if (head == nullptr) {
        return head;
    }
    
    int i = 0;
    SinglyLinkedListNode *front = head;
    
    // delete the first node 
    if (i == position) {
        head = head->next;
        delete front;
        return head;
    }

    while (i < position-1) {
        front = front->next;
        i++;
    }
    SinglyLinkedListNode *temp = front->next;
    front->next = temp->next;
    delete temp;
    
    return head;
}

int main() {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(16);
    // node = insertNodeAtHead(node, 20);
    // node = insertNodeAtHead(node, 4);
    node = insertNodeAtTail(node, 13);
    node = insertNodeAtTail(node, 7);
    node = insertNodeAtTail(node, 20);
    // node = insertNodeAtTail(node, 30);
    // node = insertNodeAtPosition(node, 1, 2);
    
    /*
    cout << "original list " << endl;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    */
    
    node = deleteNode(node, 3);
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

