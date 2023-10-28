def peek(queue):
     if queue.front == queue.rear:
        print("Queue is empty.")
     else:
         
         print("front element of queue",queue.array[queue.front])