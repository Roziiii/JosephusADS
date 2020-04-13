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

void LinkedList::printList() const {
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

void LinkedList::prepend(int val) { //Just like append but it adds a node behind the first node.
    Node* newNode = new Node();
    newNode->setVal(val);
    if(sentinel->getNext() == nullptr){ //If there is no node, just create the first one.
        sentinel->setNext(newNode);
        sentinel->setPrev(newNode);
        newNode->setPrev(sentinel);
        newNode->setNext(sentinel);
    } else {
        newNode->setNext(sentinel->getNext()); //If there is a node, add it before the first one.
        newNode->setPrev(sentinel);
        sentinel->getNext()->setPrev(newNode);
        sentinel->setNext(newNode);

    }
}

void LinkedList::remove(int val) { //Removes a node from the list using it's value
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

void LinkedList::remove(Node * nodeToRemove) { //Removes a node from the list.
    nodeToRemove->getPrev()->setNext(nodeToRemove->getNext());
    nodeToRemove->getNext()->setPrev(nodeToRemove->getPrev());
    delete(nodeToRemove);
}

Node * LinkedList::nextExecutioner(int val) { //Lists the 3rd element from a given one.
    Node* temp = sentinel;
    while(temp->getVal() != val){
        temp = temp->getNext();
    }
    return temp->getNext()->getNext();
}

Node* LinkedList::findNode(int val) const { //Finds a node using it's value and returns it
    Node* temp = sentinel;
    while(temp->getVal() != val){
        temp = temp->getNext();
    }
    return temp;
}

int LinkedList::size() const { //Gets the list size
    int size = 0;
    Node* temp = sentinel->getNext();
    while(temp != sentinel){
        size++;
        temp = temp->getNext();
    }
    return size;
}


int LinkedList::beginExecution(int startingPoint) { //This is the main part of the program.
    Node *currentExecutioner = this->findNode(startingPoint); //currentExecutioner is, as the variable says, the executioner, in the beginning from the starting point node.
    while (this->size() > 1) { //This will run until the list is of size 1.
        if (currentExecutioner->getNext()->getVal() == 0) { //This will check if the next node to be executed is the sentinel.
            this->remove(currentExecutioner->getNext()->getNext()); //Instead of removing the sentinel, it removes the first node after it
            currentExecutioner = currentExecutioner->getNext()->getNext(); //This sets the executioner to the node after the one which was just removed, skipping the sentinel.
        } else { //Normal case, if it's not the sentinel getting killed.
            this->remove(currentExecutioner->getNext()); //Removes the node after it.
            currentExecutioner = currentExecutioner->getNext(); //And changes the executioner.

        }
        if (currentExecutioner->getVal() == 0) {
            currentExecutioner = currentExecutioner->getNext(); //Basically what this does is if the sentinel IS the executioner, it's going to skip it and make the executioner the next node
        }

    }
}
