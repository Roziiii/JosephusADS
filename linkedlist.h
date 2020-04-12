//
// Created by Pop Rosian on 12/04/2020.
//

#ifndef JOSEPHUSADS_LINKEDLIST_H
#define JOSEPHUSADS_LINKEDLIST_H


#include "node.h"

class LinkedList {
    private:
        Node* sentinel;
    public:
        LinkedList();
        void append(int);
        void prepend(int);
        void print_list();
        void remove(int);
        void remove(Node*);
        int size();
        Node* next_executioner(int);
        Node* find_node(int);

};


#endif //JOSEPHUSADS_LINKEDLIST_H
