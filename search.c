void search(struct Queue queue, int value) {
    if (isEmpty(&queue)) {
        printf("Queue is empty.\n");
    } else {
        
        for (int i = queue.front; i <= queue.rear; i++) {
            if(value==queue.array[i]){
                return i+1;    //i+1 is position of element
            }
        }
        printf("\n");
     
    }

   return 0;
}