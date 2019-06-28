#include "templ_ll.h"
#include <fstream>
#include <iostream>

using namespace std;

/*
 * Output a Node pointer.
 * */
template <typename DATA>
ostream& operator<<(ostream& os, const Node<DATA>* nd) {
    if (!nd) os  << "null";
    else {
        os << " data: " << nd->data << " --> ";
    }
    return os;
}

/*
 * Add a node to the end of a list.
 * */
template <typename DATA>
void add_at_end(Node<DATA>*& head, DATA d) {
    if (!head) {
        head = new Node<DATA>(d,nullptr);
    }
    else {
        add_at_end(head->next,d); 
    }
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
template <typename DATA>
void print_list(ostream& os, const Node<DATA>* curr) {
    os << curr;
    if (curr) {
        print_list(os,curr->next);
    } else {
        os << endl;
    }
}

/*
 * Add a node at the front of a linked list.
 * */
template <typename DATA>
void add_at_front(Node<DATA>*& head, DATA d) {
    head = new Node<DATA>(d, head);
}


/*
 * Get the last node of a list.
 * */
template <typename DATA>
Node<DATA>* last(Node<DATA>* head) {
    if (!head) return nullptr;
    else if (!head->next) return head;
    else return last(head->next);
}

/*
 * These are coming:
 */

/*
 * Delete the first node and attach head to the 2nd node:
 * */
template <typename DATA>
bool del_head(Node<DATA>*& head) {
    if (!head) {
        return false;
    }
    else {
        Node<DATA>* temp = head;
        head = head ->next;
        delete temp;
    }
    return true;
}

/*
 * Delete the last node and set prev->next to nullptr:
 LOL I CAN'T DO THIS WITHOUT MAKING IT A POINTER TING... PLEASE HELP
 * */
template <typename DATA>
bool del_tail(Node<DATA>*& curr){
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

/*
 * Duplicate the entire list -- you must not share memory!
 * */
template <typename DATA>
Node<DATA>* duplicate(Node<DATA>* head) {
    //this does not share memory
    head->next = new Node<DATA>(*head->next);
    // this shares memory
    // copy = copy->next = new Listnode;
    return head;
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
template <typename DATA>
Node<DATA>* reverse(Node<DATA>* curr, Node<DATA>* new_next){
    if (curr == nullptr) return new_next;
    else {
        new_next = new Node<DATA>(curr->data,new_next);
        return reverse(curr->next,new_next);
    }
}
template <typename DATA>
Node<DATA>* join(Node<DATA>*& list1, Node<DATA>* list2) {
    last(list1) -> next = list2;
    return list1;
}
