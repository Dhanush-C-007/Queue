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
        