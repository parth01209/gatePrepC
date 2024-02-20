#include <stdio.h>
#include <stdlib.h>

typedef struct node Node; //Instead of writing struct node all the time, we will use Node instead. 

struct node{
    int data;
    Node* link;
};

// Generally we create pointers to the node because we want to create nodes dynamically at 

Node *GetNode(); // This function returns pointer to the Node structure. whenever we want to create node, we can use start = GetNode();
void Display(Node *start); // Argument to display function is pointer to the first node
void Search(Node *start, int val); 
int count(Node *start);
Node *insertAtBeg(Node* start, int val);


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

void Search(Node *start, int val){
    Node *p = start; //temporary pointer pointing to same thing where start is pointing
    int pos = 1; //Like index of the required element
    while(p!=NULL){
        if(p->data == val){
            printf("Value found at position %d\n", pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Element not found\n");
}

int count(Node *start){
    int counter = 0;
    Node *p = start;
    while(p!=NULL){
        p = p->link;
        counter++;
    }
    return counter; 
}

Node *insertAtBeg(Node* start, int val){
    Node *temp = GetNode();
    if(temp){
        temp->data =val;
        temp->link = start;
        start = temp;
    }
    return start;
}

int main(){
    int value;
    // Node *start, *middle, *last;
     //These are all pointers to the node structures
    // start = GetNode(); // start will hove address of particular node. Node created by GetNode() function (temp) is now pointed at by start
    // i.e. start is pointing to that node
    // middle = GetNode();
    // last = GetNode();
    // start->data = 25;
    // start->link = middle;
    // middle->data = 15;
    // middle->link = last;
    // last->data = 5;
    // last->link = NULL;
    Node *head = NULL;

    head = insertAtBeg(head, 15);
    head = insertAtBeg(head, 10);
    head = insertAtBeg(head, 5);

    Display(start); // Display function will create pointer p which will point to start, print data, point to p->link.
    printf("Enter the element to be searched : ");
    scanf(" %d", &value);
    Search(start, value);
    printf("\nNumber of elements in linked list: %d \n",count(start));


    return 0;

}

// Output - 

// List is :
// 25 15 5

// Enter the element to be searched : 5
// Value found at position 3

// Number of elements in linked list: 3
