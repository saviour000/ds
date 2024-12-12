#include <stdio.h>
#define Size 5

int DQ[Size];
int front = -1;
int rear = -1;

// Function to insert at the rear
void insert_rear() {
    int add_item;
    if ((front == 0 && rear == Size - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == Size - 1)
        rear = rear + 1;

    printf("Input the element for adding in Queue : ");
    scanf("%d", &add_item);
    DQ[rear] = add_item;
}

// Function to insert at the front
void insert_front() {
    int add_item;
    if ((front == 0 && rear == Size - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0)
        front = Size - 1;
    else
        front = front - 1;

    printf("Input the element for adding in queue : ");
    scanf("%d", &add_item);
    DQ[front] = add_item;
}

// Function to delete from the front
void delete_front() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", DQ[front]);
    DQ[front] = 0;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == Size - 1)
        front = 0;
    else
        front = front + 1;
}

// Function to delete from the rear
void delete_rear() {
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", DQ[rear]);
    DQ[rear] = 0;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0)
        rear = Size - 1;
    else
        rear = rear - 1;
}

// Function to display the queue
void display_queue() {
    int i;
    printf("\n\t\t\tInformation in DQueue\n\n");
    if (rear == -1) {
        printf("\t\t|");
        for (i = 0; i < Size; i++)
            printf("  |");
        printf("\n\n");
    } else {
        printf("\t\t|");
        for (i = front; i <= rear; i++)
            printf("%d  |", DQ[i]);
        printf("\n\n");
    }
}

// Function for input restricted queue (insert only at the rear and delete from both ends)
void input_que() {
    int choice;
    do {
        printf("1. Insert at rear\n");
        printf("2. Delete from front \n");
        printf("3. Delete from rear\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_rear();
                break;
            case 2:
                delete_front();
                break;
            case 3:
                delete_rear();
                break;
            case 4:
                display_queue();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
}

// Function for output restricted queue (insert only at the front and delete from both ends)
void output_queue() {
    int choice;
    do {
        printf("1. Insert at front\n");
        printf("2. Delete from front\n");
        printf("3. Delete from rear\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_front();
                break;
            case 2:
                delete_front();
                break;
            case 3:
                delete_rear();
                break;
            case 4:
                display_queue();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
}

int main() {
    int choice;
    printf("1. Input restricted dequeue\n");
    printf("2. Output restricted dequeue\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            input_que();
            break;
        case 2:
            output_queue();
            break;
        default:
            printf("Invalid choice\n");
    }
}
