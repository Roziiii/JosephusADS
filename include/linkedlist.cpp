//
// Created by Pop Rosian on 12/04/2020.
//
#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList(){ //Declaration of the constructor
    sentinel = new Node();
    sentinel->setNext(nullptr);
    sentinel->setPrev(nullptr);
}


void LinkedList::append(int val) {
    Node* newNode = new Node(); //Creating a new node and allocating it's memory
    newNode->setVal(val); //Setting the value to the new node.
    if(sentinel->getNext() == nullptr){ //Checks if the sentinel is the only node.
        sentinel->setNext(newNode); //If the sentinel is the only node, it links it up with the newly created node.
        sentinel->setPrev(newNode);
        newNode->setNext(sentinel);
        newNode->setPrev(sentinel);
    } else {
        sentinel->getPrev()->setNext(newNode); //If there are more nods, link the last element's next to the new node (Which is sentinel.prev)
        newNode->setPrev(sentinel->getPrev());
        newNode->setNext(sentinel);
        sentinel->setPrev(newNode);
    }
}

void LinkedList::printList() {
    if(sentinel->getNext() == nullptr){ //Checks if the list is empty.
        std::cout<<"List is empty!";
    } else {
        Node* temp = sentinel->getNext(); //If it's not empty, temp will be the first element in the list
        while(temp->getNext() != sentinel){ //Loops through the whole list and prints it in the console.
            std::cout<<temp->getVal()<<" ";
            temp = temp->getNext();
        }
        std::cout<<temp->getVal()<<" ";
        std::cout<<std::endl;
    }
}

void LinkedList::prepend(int val) {
    Node* newNode = new Node();
    newNode->setVal(val);
    if(sentinel->getNext() == nullptr){
        sentinel->setNext(newNode);
        sentinel->setPrev(newNode);
        newNode->setPrev(sentinel);
        newNode->setNext(sentinel);
    } else {
        newNode->setNext(sentinel->getNext());
        newNode->setPrev(sentinel);
        sentinel->getNext()->setPrev(newNode);
        sentinel->setNext(newNode);

    }
}

void LinkedList::remove(int val) {
    Node* temp = sentinel;
    while(temp->getVal() != val){
        temp = temp->getNext();
    }
    Node* toRemove = temp;
    temp = temp->getPrev();
    temp->setNext(temp->getNext()->getNext());
    temp->getNext()->setPrev(temp);
    delete(toRemove);
}

void LinkedList::remove(Node * nodeToRemove) {
    nodeToRemove->getPrev()->setNext(nodeToRemove->getNext());
    nodeToRemove->getNext()->setPrev(nodeToRemove->getPrev());
    delete(nodeToRemove);
}

Node * LinkedList::nextExecutioner(int val) {
    Node* temp = sentinel;
    while(temp->getVal() != val){
        temp = temp->getNext();
    }
    return temp->getNext()->getNext();
}

Node* LinkedList::findNode(int val) {
    Node* temp = sentinel;
    while(temp->getVal() != val){
        temp = temp->getNext();
    }
    return temp;
}

int LinkedList::size() {
    int size = 0;
    Node* temp = sentinel->getNext();
    while(temp != sentinel){
        size++;
        temp = temp->getNext();
    }
    return size;
}


int LinkedList::beginExecution() {
    Node* currentExecutioner = this->findNode(1);
    while(this->size() > 1){
        if(currentExecutioner->getNext()->getVal() == 0){
            this->remove(currentExecutioner->getNext()->getNext());
            currentExecutioner=currentExecutioner->getNext()->getNext();
        } else {
            this->remove(currentExecutioner->getNext());
            currentExecutioner = currentExecutioner->getNext();

        }
        if(currentExecutioner->getVal() == 0){
            currentExecutioner=currentExecutioner->getNext();
        }

    }
}