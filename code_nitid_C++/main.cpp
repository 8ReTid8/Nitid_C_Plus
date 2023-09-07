#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next = nullptr;
};

class LinkedList {
public:
    Node* head = new Node();
    int listSize = 0;

    void insert_before(int data, int id) {
        Node* ptr1 = head;
        if (!this->search(data)) {
            if(!this->search(id)) {
                this->push_after(data);
            }
            else {
                if(ptr1->data == id || head->data == 0) {
                    this->push_before(data);
                }
                else {
                    Node* ptr2 = head->next;

                    while(ptr2->data != id) {
                        ptr1 = ptr2;
                        ptr2 = ptr2->next;
                    }

                    Node* x = new Node();
                    x->data = data;
                    ptr1->next = x;
                    x->next = ptr2;
                }
            }
            this->print();
        }
    }
    void insert_after(int data, int id) {
        Node* x = new Node();
        x->data = data;
        if (!this->search(data)) {
            if(!this->search(id)) {
                this->push_after(data);
            }
            else {
                Node* ptr = head;
                while(ptr->data != id) {
                    ptr = ptr->next;
                }
                x->next = ptr->next;
                ptr->next = x;
            }
            this->print();
        }
    }
    bool search(int id) {
        Node* ptr = head;
        while(ptr != nullptr) {
            if(ptr->data == id) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
    void push_after(int data) {
        Node* ptr = head;
        Node* x = new Node();
        x->data = data;

        while(ptr->next->data != 0) {
            ptr = ptr->next;
        }
        x->next = ptr->next;
        ptr->next = x;
    }
    void push_before(int data) {
        Node* x = new Node();
        x->data = data;
        x->next = head;
        head = x;
    }

    void print() {
        Node* ptr = head;
        while (ptr != nullptr) {
            if (ptr->data != 0)
                cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void del(int data) {
        if(data == head->data) {
            head = head->next;
        }
        else {
            Node* ptr = head;
            while (ptr->next->data != data) {
                ptr = ptr->next;
            }
            ptr->next = ptr->next->next;
        }
        this->print();
    }
};

int main() {
    LinkedList* list = new LinkedList();
    char command = ' ';
    while (command != 'E') {
        cin >> command;
        switch (command) {
            int data, id;
            case 'I':
                cin >> data;
                cin >> id;
                list->insert_before(data, id);
                break;
            case 'A':
                cin >> data;
                cin >> id;
                list->insert_after(data, id);
                break;
            case 'P':
                list->print();
                break;
            case 'D':
                cin >> data;
                list->del(data);
                break;
        }
    }
    return 0;
}
