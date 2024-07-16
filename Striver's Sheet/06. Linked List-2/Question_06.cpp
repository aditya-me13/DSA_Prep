Node* mergeTwoLists(Node* list1, Node* list2) {
    
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        Node* newHead;

        if(list1->data < list2->data){
            newHead = list1;
            list1 = list1->bottom;
        }

        else{
            newHead = list2;
            list2 = list2->bottom;
        }
        
        Node* temp = newHead;
        while(list1 != NULL && list2 != NULL){
            if(list1->data > list2->data){
                temp->bottom = list2;
                list2 = list2->bottom;
            }  
            else{
                temp->bottom = list1;
                list1 = list1->bottom;
            }
            temp = temp->bottom;
        }

        if(list1 == NULL){
            temp->bottom = list2;
            return newHead;
        }
        else{
            temp->bottom = list1;
            return newHead; 
        }
    }

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root) {
    
    if(!root || !root->next) return root;
    
    root->next = flatten(root->next);
    
    root = mergeTwoLists(root, root->next);
    
    return root;
    
}