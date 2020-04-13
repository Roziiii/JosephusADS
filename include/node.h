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
        int getVal() const;
        void setNext(Node*);
        Node* getNext() const;
        void setPrev(Node*);
        Node* getPrev() const;

};


#endif //JOSEPHUSADS_NODE_H
