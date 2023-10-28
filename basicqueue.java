import java.util.Scanner;

public class basicqueue {
    private int[] array;
    private int front;
    private int rear;
    private static int max_size=100;
  

    public basicqueue(int size) {
        array = new int[size];
        front = -1;
        rear = -1;
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public boolean isFull() {
        return rear == array.length - 1;
    }

    public void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full. Cannot enqueue.");
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        array[rear] = value;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty. Cannot dequeue.");
            return -1; // Return a sentinel value to indicate an error
        }
        int frontValue = array[front];
        if (front == rear && front != -1 && rear != -1) {
            System.out.println("This element [" + frontValue + "] is dequeued");
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
            System.out.println("This element [" + frontValue + "] is dequeued");
        }
        return frontValue;
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty.");
        } else {
            System.out.print("Queue elements: ");
            for (int i = front; i <= rear; i++) {
                System.out.print(array[i] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the queue: ");
        int size = scanner.nextInt();

        if (size <= 0 || size>max_size ) {
            System.out.printf("Invalid queue size. Please choose a size between 1 and max size");
            return;
        }

        basicqueue queue = new basicqueue(size);

        int choice;

        while (true) {
            System.out.println("\nQueue Operations:");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Quit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    if (queue.isFull()) {
                        System.out.println("Queue is full. Cannot enqueue.");
                    } else {
                        System.out.print("Enter the item to enqueue: ");
                        int item = scanner.nextInt();
                        queue.enqueue(item);
                    }
                    break;
                case 2:
                    queue.dequeue();
                    break;
                case 3:
                    queue.display();
                    break;
                case 4:
                    System.out.println("Exiting the program.");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}