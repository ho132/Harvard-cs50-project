#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

int main(void)
{
    int element;
    struct Node* head = NULL;
    struct Node* current = NULL;

    // Input the number of elements to store in the linked list
    printf("Input number of elements to store in the linked list: ");
    scanf("%i", &element);

    // Input elements into the linked list
    for (int i = 0; i < element; i++)
    {
        // Allocate memory for a new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        // Input data for the new node
        printf("Element - %i: ", i);
        scanf("%i", &newNode->data);

        // Set the next pointer of the new node
        newNode->next = NULL;

        // If it's the first node, set it as the head
        if (head == NULL) {
            head = newNode;
            current = head;
        }
        else {
            // Otherwise, link the new node to the current node
            current->next = newNode;
            // Move the current pointer to the new node
            current = newNode;
        }
    } // Print the elements of the linked list
    printf("Elements in the linked list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Element: %i\n", current->data);
        current = current->next;
    }

    // Free the allocated memory for the linked list
    current = head;
    while (current != NULL)
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}



