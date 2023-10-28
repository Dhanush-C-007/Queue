MAX_SIZE = 100

class Queue:
    def __init__(self):
        self.array = [0] * MAX_SIZE
        self.front = 0
        self.rear = 0
        self.size = 0

def initializeQueue(queue):
    queue.front = 0
    queue.rear = 0
    queue.size = 0

def enqueue(queue, item):

    
    queue.array[queue.rear] = item
    queue.rear += 1
    queue.size += 1

def dequeue(queue):
    if queue.front == queue.rear:
        print("Queue is empty. Cannot dequeue.")
    else:
        item = queue.array[queue.front]
        queue.front += 1
        queue.size -= 1

        print( "this item has been dequeued ",item)

def display(queue):
    if queue.front == queue.rear:
        print("Queue is empty.")
    else:
        print("Queue elements:")
        for i in range(queue.front, queue.rear):
            print(queue.array[i])

queue = Queue()
initializeQueue(queue)

size = int(input("Enter the size of the queue: "))
if size <= 0 or size > MAX_SIZE:
    print("Invalid queue size. Please choose a size between 1 and", MAX_SIZE)
    exit(1)

while True:
    print("\nQueue Operations:")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Display")
    print("4. Quit")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        if queue.rear == size :
            print("Queue is full. Cannot enqueue.")
        else:
            item = int(input("Enter the item to enqueue: "))
            enqueue(queue, item)
    elif choice == 2:
        dequeue(queue)
    elif choice == 3:
        display(queue)
    elif choice == 4:
        print("Exiting the program.")
        exit(0)
    else:
        print("Invalid choice. Please choose a valid option.")