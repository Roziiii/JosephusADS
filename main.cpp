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
    int numberOfPeople, startingPoint;
    cout<<"Enter the number of people: ";
    cin>>numberOfPeople;
    cout<<endl<<"Enter the starting person's number: ";
    cin>>startingPoint;
    LinkedList josephusCircle = generate_list(numberOfPeople); //Just a simple function that appends as many nodes as numberOfPeople, giving them values from 1 to numberOfPeople
    josephusCircle.beginExecution(startingPoint); //Begins the execution simulation
    josephusCircle.printList(); //Prints the list, which should now be only 1 element, the position of the survivor.

}
