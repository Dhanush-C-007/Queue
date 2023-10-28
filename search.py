def search(queue , value):
    if queue.front == queue.rear:
        print("Queue is empty.")
    else:
         for i in range(queue.front, queue.rear):
             if queue.array[i]==value:
                 return i+1
    return 0
