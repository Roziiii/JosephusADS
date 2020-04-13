#include <iostream>
#include "include/linkedlist.h"

using namespace std;

LinkedList generate_list(int size){
    LinkedList josephusCircle;
    for(int i=1;i<=size;i++){
        josephusCircle.append(i);
    }
    return josephusCircle;
}


int main() {
    LinkedList josephusCircle = generate_list(100000);
    josephusCircle.printList();
    josephusCircle.beginExecution();
    josephusCircle.printList();

}
