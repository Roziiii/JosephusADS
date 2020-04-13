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
        void printList();
        void remove(int);
        void remove(Node*);
        int size();
        Node* nextExecutioner(int);
        Node* findNode(int);
        int beginExecution();

};


#endif //JOSEPHUSADS_LINKEDLIST_H
