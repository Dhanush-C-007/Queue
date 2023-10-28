public int search(int key) {
    if (isEmpty()) {
        System.out.println("Queue is empty.");
    } 
    
    else {
       
        for (int i = front; i <= rear; i++) {
            if(key==array[i]){
                return i+1;
            }
        }
        System.out.println();
    }