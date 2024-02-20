#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *link;
};

Node *GetNode(); // This function returns pointer to the Node structure. whenever we want to create node, we can use start = GetNode();
Node *insertLast(Node* start, int val);
Node *createList(Node *start);
void Display(Node *start); // Argument to display function is pointer to the first node
Node *findMiddle(Node *start);
Node *merge2SortedLists(Node *head1,  Node *head2);
Node *MergeSort(Node *start);

Node *GetNode(){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    if(!temp) {
        printf("Memory error\n"); //Out of memory
        exit(1);
    }
    return temp;
}

Node *insertLast(Node* start, int val){
    Node *p, *temp;
    temp = GetNode();
    temp->data=val;
    temp->link=NULL;
    if(start==NULL) {
        start=temp;  //If list is empty make new node the head
    } else {
        p=start;   //Point to the current last node
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link=temp;//Make next of last node point to new node
        
    }
    return start;
}

Node *createList(Node *start){
    int i, n, val;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    start = NULL;
    for (i = 0; i < n; i++)
    {
        printf("Enter value to be inserted : ");
        scanf("%d", &val);
        start = insertLast(start, val);
    }
    return start;
}

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

Node *findMiddle(Node* start){
    // If the linked list is empty
    if (start == NULL) return NULL;
    Node *slow_ptr = start;
    if(start->link==NULL) return  slow_ptr;
    Node *fast_ptr = start->link;
    while(fast_ptr!=NULL && fast_ptr->link != NULL){
        slow_ptr = slow_ptr->link;
        fast_ptr = fast_ptr->link->link;
    }
    return slow_ptr;

}

Node *merge2SortedLists(Node *head1,  Node *head2){
    Node *start = NULL;
    while(head1 != NULL && head2 != NULL ){
        if(head1->data < head2->data){
            start = insertLast(start , head1->data);
            head1 = head1->link;
        }
        else if(head2->data < head1->data){
            start = insertLast(start , head2->data);
            head2 = head2->link;
        }
        else if(head1->data == head2->data){
            start = insertLast(start , head1->data);
            head1 = head1->link;
            head2 = head2->link;
        }
    }
        while(head1!=NULL){
            start = insertLast(start, head1->data);
            head1 = head1->link;
        }
        while(head2!=NULL){
            start = insertLast(start, head2->data);
            head2 = head2->link;
        }
        return start;
    }

Node *MergeSort(Node *start){
    Node *left, *right, *middle;
    if(start == NULL || start->link==NULL){
        return start;
    }
    middle = findMiddle(start);
    left = start;
    right = middle->link;
    middle->link = NULL;
    left = MergeSort(left);
    right = MergeSort(right);
    return merge2SortedLists(left, right);
}

int main(){
    Node *start, *mid, *p1, *p2, *p3;
    start = createList(start);
    Display(start);
    // mid = findMiddle(start);
    // printf( "The middle element of the LinkedList is: %d\n", mid->data );
    // p1 =createList(p1);
    // Display(p1);
    // p2 = createList(p2);
    // Display(p2);
    // p3 = merge2SortedLists(p1, p2);
    // printf("\n The merged and sorted list is : \n");
    // Display(p3);
    start = MergeSort(start);
    printf("The linked list after sorting is:\n");
    Display(start);


    return 0;
}
















// MERGING 2 SORTED LISTS 
// Enter number of nodes : 5
// Enter value to be inserted : 7
// Enter value to be inserted : 8
// Enter value to be inserted : 9
// Enter value to be inserted : 41
// Enter value to be inserted : 287
// List is :
// 7 8 9 41 287

// Enter number of nodes : 3
// Enter value to be inserted : 89
// Enter value to be inserted : 478
// Enter value to be inserted : 2358
// List is :
// 89 478 2358


// The merged and sorted list is :
// 7 8 9 41 89 287 478 2358