#include <iostream>
#include "linkedlist.h"



int main() {
    LinkedList josephusCircle;
    josephusCircle.append(1);
    josephusCircle.append(2);
    josephusCircle.prepend(0);
    josephusCircle.print_list();
}
