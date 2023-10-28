#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a queue
struct Queue {
    int array[MAX_SIZE];
    int front, rear;
    int sizes;
};
int main() {
    struct Queue queue;
    initializeQueue(&queue);

     int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid queue size. Please choose a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    
    int choice;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (queue.rear == size - 1) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    int item;
                    printf("Enter the item to enqueue: ");
                    scanf("%d", &item);
                      enqueue(&queue, item);
                }
                break;
            case 2:

                dequeue(&queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


    return 0;
}

// Function to initialize an empty queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}



// Function to check if queue is empty
bool isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}



// Function to check if queue is full
bool isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}



// Function enqueue
void enqueue(struct Queue *queue, int value) {

    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}



// Function to dequeue
void dequeue(struct Queue *queue) {
       if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    int frontValue = queue->array[queue->front];

       if (queue->front == queue->rear && queue->front != -1 && queue->rear!=-1) {

        printf("this element [%d] is dequed" ,frontValue);
        
        }
    if (queue->front == queue->rear) {
        // If there was only one element in the queue, reset front and rear
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
         printf("this element [%d] is dequed" ,frontValue);
    }
     printf("\n");
}

//Function to display
void display(struct Queue queue) {
    if (isEmpty(&queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue.front; i <= queue.rear; i++) {
            printf("%d ", queue.array[i]);
        }
        printf("\n");
    }
}










