class LRUCache {
private:
    // class inside a class to create node
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            // parametrized constructor, no return type
            Node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };

int cap;
unordered_map<int, Node*> m;

public:

    Node* head = new Node(-1, -1); // garbage values
    Node* tail = new Node( -1, -1); // garbage values
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(int key, int val){
        Node* to_add = new Node(key, val);
        to_add->next = head->next;
        head->next = to_add;
        to_add->prev = head;
        to_add->next->prev = to_add; 
    }

    void deleteNode(Node* address){
        Node* left = address->prev;
        Node* right = address->next;
        right->prev = left;
        left->next = right;
    }

    int get(int key) {
        if(m.find(key) != m.end()){
            Node* curr_node = m[key];
            int val = curr_node->val;
            m.erase(key);
            addNode(key, val);
            deleteNode(curr_node);
            m[key] = head->next;
            return val;
        }   
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr_node = m[key];
            m.erase(key);
            deleteNode(curr_node);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(key, value);
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */