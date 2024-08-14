#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning(int n);
void insertAtEnd(int n);
void insertAtPosition(int n, int pos);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int pos);
void search(int val);
void display();

int main() 
{
    int choice, n, pos, val;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &n);
                insertAtBeginning(n);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &n);
                insertAtEnd(n);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &n);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insertAtPosition(n, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insertAtBeginning(int n) 
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    new->data = n;
    new->next = head;
    head = new;
}

void insertAtEnd(int n) 
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    new->data = n;
    new->next = NULL;
    
    if (head == NULL) 
    {
        head = new;
    } 
    else 
    {
        struct node *ptr = head;
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void insertAtPosition(int n, int pos) 
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    new->data = n;
    
    if (pos == 1) 
    {
        new->next = head;
        head = new;
    } 
    else 
    {
        struct node *ptr = head;
        for (int i = 1; i < pos - 1 && ptr != NULL; i++) 
        {
            ptr = ptr->next;
        }
        if (ptr != NULL) 
        {
            new->next = ptr->next;
            ptr->next = new;
        } 
        else 
        {
            printf("Invalid position!\n");
            free(new);
        }
    }
}

void deleteAtBeginning() 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted node at the beginning.\n");
}

void deleteAtEnd() 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    struct node *ptr = head;
    struct node *prev = NULL;
    while (ptr->next != NULL) 
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev != NULL) 
    {
        prev->next = NULL;
    } 
    else 
    {
        head = NULL;
    }
    free(ptr);
    printf("Deleted node at the end.\n");
}

void deleteAtPosition(int pos) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    struct node *ptr = head;
    struct node *prev = NULL;
    
    if (pos == 1) 
    {
        head = head->next;
        free(ptr);
        printf("Deleted node at position %d.\n", pos);
        return;
    }
    
    for (int i = 1; i < pos && ptr != NULL; i++) 
    {
        prev = ptr;
        ptr = ptr->next;
    }
    
    if (ptr == NULL) 
    {
        printf("Invalid position!\n");
    } 
    else 
    {
        prev->next = ptr->next;
        free(ptr);
        printf("Deleted node at position %d.\n", pos);
    }
}

void search(int val) 
{
    struct node *ptr = head;
    int pos = 1;
    
    while (ptr != NULL) 
    {
        if (ptr->data == val) 
        {
            printf("Value %d found at position %d.\n", val, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Value %d not found.\n", val);
}

void display() 
{
    struct node *ptr = head;
    if (ptr == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    printf("List elements: ");
    while (ptr != NULL) 
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
