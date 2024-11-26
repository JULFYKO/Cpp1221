#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        clear();
    }

    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    List clone() const {
        List clonedList;
        if (!head) return clonedList;

        Node* temp = head;
        while (temp) {
            clonedList.add(temp->data);
            temp = temp->next;
        }

        return clonedList;
    }

    List operator+(const List& other) const {
        List newList = this->clone();
        Node* temp = other.head;
        while (temp) {
            newList.add(temp->data);
            temp = temp->next;
        }
        return newList;
    }

    List operator*(const List& other) const {
        List intersectionList;
        Node* temp1 = head;

        while (temp1) {
            Node* temp2 = other.head;
            while (temp2) {
                if (temp1->data == temp2->data) {
                    if (!intersectionList.contains(temp1->data)) {
                        intersectionList.add(temp1->data);
                    }
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return intersectionList;
    }

    void clear() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool contains(int value) const {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    List list1, list2;

    list1.add(1);
    list1.add(2);
    list1.add(3);

    list2.add(2);
    list2.add(3);
    list2.add(4);

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    List clonedList = list1.clone();
    cout << "Cloned List 1: ";
    clonedList.print();

    List combinedList = list1 + list2;
    cout << "List1 + List2: ";
    combinedList.print();

    List intersectionList = list1 * list2;
    cout << "List1 * List2: ";
    intersectionList.print();

    return 0;
}
