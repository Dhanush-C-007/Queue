#include <iostream>

  int size;
int MAX_SIZE=100;


class Queue {
private:
    int* array;
    int front;
    int rear;
  
   

public:
    Queue(int size) {
        array = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
  
        return rear == size-1 ;
    }

    void enqueue(int value) {
    
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        array[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }
        int frontValue = array[front];
        if (front == rear && front != -1 && rear != -1) {
            std::cout << "This element [" << frontValue << "] is dequeued" << std::endl;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
            std::cout << "This element [" << frontValue << "] is dequeued" << std::endl;
        }
        return frontValue;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            std::cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    int search(int key) {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            
            for (int i = front; i <= rear; i++) {
                if(key==array[i]){
                    return i+1;
                } 
            }
            std::cout << std::endl;
        
        }
        return 0;
    }





    ~Queue() {
        delete[] array;
    }
};

int main() {
   
    std::cout << "Enter the size of the queue: ";
    std::cin >> size;
    

    if (size <= 0 || size > MAX_SIZE - 1 ) {
        std::cout << "Invalid queue size. Please choose a size between 1 and " << MAX_SIZE << std::endl;
        return 1;
    }

    Queue queue(size);

    int choice;

    while (true) {
        std::cout << "\nQueue Operations:" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (queue.isFull()) {
                    std::cout << "Queue is full. Cannot enqueue." << std::endl;
                }
                 else {
                    int item;
                    std::cout << "Enter the item to enqueue: ";
                    std::cin >> item;
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
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}