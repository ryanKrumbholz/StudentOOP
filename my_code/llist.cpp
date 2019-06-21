#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) os  << "nullptr";
    else {
        os << "data: " << nd->data << " next: " << nd->next; //pointer to a node that you're passing; memory access is through the arrow.
    }
    return os;
}

/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
     if (!head) {
        head = new Node(d, nullptr);
    }
    else {
        add_at_end(head->next,d); // recursion
    }
}

/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    os << curr;
    if (curr) {print_list(os, curr->next);}
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if(!head) return nullptr;
    else if (!head->next) return head;
    else return last(head->next);
}

bool del_head(Node*& head) {
    if (!head) return false;
    else {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return true;
    }
}

bool del_tail(Node* prev_next) {
    if ((prev_next) == nullptr) return false;
    Node* curr = prev_next;
    while (curr->next) {
        prev_next = (curr->next);
        curr = curr->next;
    }
    delete curr;
    (prev_next) = nullptr;
    return true;
}

Node* duplicate(Node* head) {
    Node* new_head = nullptr;
    Node* curr = head;
    while (curr) {
        add_at_end(new_head, curr->data);
        curr = curr->next;
    }
    return new_head;
}

Node* reverse(Node* curr) {
    if (!curr) return nullptr;
    else return new Node(curr->data, duplicate(curr->next));
}

Node* join(Node* curr_list, Node* next_list) {
    if (!curr_list) return nullptr;
    else {
        if (curr_list->next != nullptr) {
            join(curr_list->next, next_list);
        }
        else {
            curr_list->next = next_list;
        }
    }
}