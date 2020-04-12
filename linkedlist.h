//
// Created by Pop Rosian on 12/04/2020.
//

#ifndef JOSEPHUS_PROBLEM_HW1_LINKEDLIST_H
#define JOSEPHUS_PROBLEM_HW1_LINKEDLIST_H


#include "node.h"

class LinkedList {
    private:
        Node* sentinel;
    public:
        LinkedList();
        void append(int val);
        void prepend(int val);
        void print_list();
        void delete_element(int val);

};


#endif //JOSEPHUS_PROBLEM_HW1_LINKEDLIST_H
