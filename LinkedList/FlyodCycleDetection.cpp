
    /*
    REFERENCES 
    https://www.codingninjas.com/studio/library/floyds-cycle-finding-algorithm
    */

   /* detect if there is a loop
    in the linked list*/
    bool detectLoop()
    {
        Node *slowPointer = head,
             *fastPointer = head;
 
        while (slowPointer != NULL
               && fastPointer != NULL
               && fastPointer->next != NULL) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
                return 1;
        }
 
        return 0;
    }