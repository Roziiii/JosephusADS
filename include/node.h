//
// Created by Pop Rosian on 13/04/2020.
//

#ifndef JOSEPHUSADS_NODE_H
#define JOSEPHUSADS_NODE_H


class Node {
    private:
        int val;
        Node* prev;
        Node* next;
    public:
        void setVal(int);
        int getVal();
        void setNext(Node*);
        Node* getNext();
        void setPrev(Node*);
        Node* getPrev();

};


#endif //JOSEPHUSADS_NODE_H
