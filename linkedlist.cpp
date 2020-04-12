//
// Created by Pop Rosian on 12/04/2020.
//
#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList(){ //Declaration of the constructor
    sentinel = new Node();
    sentinel->next = nullptr;
    sentinel->prev = nullptr;
}


void LinkedList::append(int val) {
    Node* newNode = new Node(); //Creating a new node and allocating it's memory
    newNode->val = val; //Setting the value to the new node.
    if(sentinel->next == nullptr){ //Checks if the sentinel is the only node.
        sentinel->next = newNode; //If the sentinel is the only node, it links it up with the newly created node.
        sentinel->prev = newNode;
        newNode->next = sentinel;
        newNode->prev = sentinel;
    } else {
        sentinel->prev->next = newNode; //If there are more nods, link the last element's next to the new node (Which is sentinel.prev)
        newNode->prev = sentinel->prev;
        newNode->next = sentinel;
        sentinel->prev = newNode;
    }
}

void LinkedList::print_list() {
    if(sentinel->next == nullptr){ //Checks if the list is empty.
        std::cout<<"List is empty!";
    } else {
        Node* temp = sentinel->next; //If it's not empty, temp will be the first element in the list
        while(temp->next != sentinel){ //Loops through the whole list and prints it in the console.
            std::cout<<temp->val<<" ";
            temp = temp->next;
        }
        std::cout<<temp->val<<" ";
        std::cout<<std::endl;
    }
}

void LinkedList::prepend(int val) {
    Node* newNode = new Node();
    newNode->val = val;
    if(sentinel->next == nullptr){
        sentinel->next = newNode;
        sentinel->prev = newNode;
        newNode->prev = sentinel;
        newNode->next = sentinel;
    } else {
        newNode->next = sentinel->next;
        newNode->prev = sentinel;
        sentinel->next->prev = newNode;
        sentinel->next = newNode;

    }
}