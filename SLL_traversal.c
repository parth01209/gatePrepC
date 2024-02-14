#include <stdio.h>
#include <stdlib.h>

typedef struct node Node; //Instead of writing struct node all the time, we will use Node instead. 

struct node{
    int data;
    Node* link;
};

// Generally we create pointers to the node because we want to create nodes dynamically at 

Node *GetNode(); // This function returns pointer to the Node structure. whenever we want to create node, we can use start = GetNode();

void Display(Node *start); //Argument to display function is pointer to the first node

Node *GetNode(){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node)); // Allocating memory for new temp pointer to node structure
    if(!temp) {
        printf("Memory error\n"); //Out of memory
        exit(1);
    }
    return temp;
    
}
//Basically when we create Node *ptr and ptr = GetNode(), temp will create a particular memory in heap and that is returned to ptr

void Display(Node *start){
    Node *p;
    if(start==NULL){
        printf("Empty List");
        return ;
    }
    p=start;
    printf("List is : \n");
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n\n");
}

int main(){
    Node *start, *middle, *last; //These are all pointers to the node structures
    start = GetNode(); // start will hod address of particular node. Node created by GetNode() function (temp) is now pointed at by start
    // i.e. start is pointing to that node
    middle = GetNode();
    last = GetNode();
    start->data = 25;
    start->link = middle;
    middle->data = 15;
    middle->link = last;
    last->data = 5;
    last->link = NULL;
    Display(start); // Display function will create pointer p which will point to start, print data, point to p->link.

    return 0;

}

// Output - 

// List is :
// 25 15 5
