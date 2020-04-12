#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList generate_list(int size){
    LinkedList josephusCircle;
    for(int i=1;i<=size;i++){
        josephusCircle.append(i);
    }
    return josephusCircle;
}


void begin_execution(LinkedList josephusCircle){
    Node* currentExecutioner = josephusCircle.find_node(1);
    while(josephusCircle.size() > 1){
        if(currentExecutioner->next->val == 0){
            josephusCircle.remove(currentExecutioner->next->next);
            currentExecutioner=currentExecutioner->next->next;
        } else {
            josephusCircle.remove(currentExecutioner->next);
            currentExecutioner = currentExecutioner->next;

        }
        if(currentExecutioner->val == 0){
            currentExecutioner=currentExecutioner->next;
        }

    }
    josephusCircle.print_list();


}

int main() {
    LinkedList josephusCircle = generate_list(4);
    josephusCircle.print_list();
    begin_execution(josephusCircle);

}
