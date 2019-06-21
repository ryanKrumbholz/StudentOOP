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

bool del_tail(Node*& curr){
    if (!curr) {
        return false;
    }
    else {
        if (curr->next == nullptr) {
            delete curr;
            curr = nullptr;
        }
        else {
            del_tail(curr->next);
        }
    }
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

Node* reverse(Node* curr, Node* new_next) {
    if (curr == nullptr) return new_next;
    else {
        new_next = new Node(curr->data, new_next);
        return reverse(curr->next, new_next);
    }
}

Node* join(Node* curr_list, Node* next_list) {
    if (!curr_list) return nullptr;
    last(curr_list)->next = next_list;
    return curr_list;
}