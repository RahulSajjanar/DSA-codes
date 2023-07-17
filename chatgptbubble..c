
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to swap the data values of two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform bubble sort on a linked list
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // If list is empty, return
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to add a new node to the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function to test the code
int main() {
    struct Node* head = NULL;

    // Add some nodes to the list
    append(&head, 5);
    append(&head, 2);
    append(&head, 8);
    append(&head, 1);
    append(&head, 3);

    printf("Before sorting: ");
    printList(head);

    bubbleSort(head);

    printf("\nAfter sorting: ");
    printList(head);

    return 0;
}
