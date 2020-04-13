//
// Created by Pop Rosian on 13/04/2020.
//

#include "node.h"

void Node::setVal(int val) {
    this->val = val;
}

int Node::getVal() const {
    return this->val;
}

void Node::setNext(Node * node) {
    this->next = node;
}

Node* Node::getNext() const {
    return this->next;
}

void Node::setPrev(Node * node) {
    this->prev = node;
}

Node * Node::getPrev() const {
    return this->prev;
}