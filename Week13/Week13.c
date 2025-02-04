#include <stdio.h>
#include <stdlib.h>

   //   ---------- Singly Linked list -------

// Node struct
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position
void insertAtPosition(Node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node at a specific position
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    Node* prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
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

// insert multiple elements
void insertMultiple(Node** head) {
    int length, data;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}

//   ---------- Doubly Linked list -----

// Node struct
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Insert at the beginning
void insertAtBeginningD(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

// Insert at the end
void insertAtEndD(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    DNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position
void insertAtPositionD(DNode** head, int data, int position) {
    if (position == 0) {
        insertAtBeginningD(head, data);
        return;
    }
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    DNode* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete a node at a specific position 
void deleteAtPositionD(DNode** head, int position) {
    if (*head == NULL) return;
    DNode* temp = *head;
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    free(temp);
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

// insert multiple elements
void insertMultipleD(DNode** head) {
    int length, data;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEndD(head, data);
    }
}

int main() {
    int mainChoice, listChoice, data, position;
    Node* singlyHead = NULL;
    DNode* doublyHead = NULL;

    while (1) {
        printf("\nSelect Linked List Type:\n1. Singly Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ");
        scanf("%d", &mainChoice);

        if (mainChoice == 3) {
            break; 
        }

        while (1) {
            if (mainChoice == 1) {
                printf("\nSingly Linked List Menu:\n");
                printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete at Position\n5. Insert Multiple Elements\n6. Display\n7. Back to Main Menu\nEnter choice: ");
            } else if (mainChoice == 2) {
                printf("\nDoubly Linked List Menu:\n");
                printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete at Position\n5. Insert Multiple Elements\n6. Display\n7. Back to Main Menu\nEnter choice: ");
            }

            scanf("%d", &listChoice);

            if (listChoice == 7) {
                break; 
            }

            switch (listChoice) {
                case 1:
                    printf("Enter data: ");
                    scanf("%d", &data);
                    if (mainChoice == 1) {
                        insertAtBeginning(&singlyHead, data);
                    } else {
                        insertAtBeginningD(&doublyHead, data);
                    }
                    break;
                case 2:
                    printf("Enter data: ");
                    scanf("%d", &data);
                    if (mainChoice == 1) {
                        insertAtEnd(&singlyHead, data);
                    } else {
                        insertAtEndD(&doublyHead, data);
                    }
                    break;
                case 3:
                    printf("Enter data and position: ");
                    scanf("%d %d", &data, &position);
                    if (mainChoice == 1) {
                        insertAtPosition(&singlyHead, data, position);
                    } else {
                        insertAtPositionD(&doublyHead, data, position);
                    }
                    break;
                case 4:
                    printf("Enter position: ");
                    scanf("%d", &position);
                    if (mainChoice == 1) {
                        deleteAtPosition(&singlyHead, position);
                    } else {
                        deleteAtPositionD(&doublyHead, position);
                    }
                    break;
				case 5:
                    if (mainChoice == 1) {
                        insertMultiple(&singlyHead);
                    } else {
                        insertMultipleD(&doublyHead);
                    }
                    break;
                case 6:
                    if (mainChoice == 1) {
                        display(singlyHead);
                    } else {
                        displayDoubly(doublyHead);
                    }
                    break;

                default:
                    printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}
