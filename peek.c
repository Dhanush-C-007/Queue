void peek(struct Queue queue){
    if (isEmpty(&queue)) {
        printf("Queue is empty.\n");}

    else{
        printf("front element is :%d",queue.array[queue.front]);
    }


}