#include <stdio.h>
#include <stdlib.h>

                      // ------- Single Linked List --------- 

// Node struct
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert func
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display func
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

                      // ------- Doubly Linked List --------- 

// Node struct
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Insert func
void insertDoubly(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        DNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Display func
void displayDoubly(DNode* head) {
    DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* singlyHead = NULL;
    DNode* doublyHead = NULL;
    
	int length;
	int item;
	
	printf("insert list Length: ");
	scanf("%i",&length);
	
	for(int i = 0 ; i < length ; i++ ){
		printf("insert the item %i: ",i+1);
		scanf("%i",&item);
		insert(&singlyHead, item);
		insertDoubly(&doublyHead, item);
	}
    printf("Singly Linked List: ");
    display(singlyHead);
	
    printf("Doubly Linked List: ");
    displayDoubly(doublyHead);
    
    return 0;
}
