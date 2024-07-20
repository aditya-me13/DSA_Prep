class LFUCache {
public:
    class Node{
    public:
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;

        Node(int _key, int _val, int _freq){
            key = _key;
            val = _val;
            freq = _freq;
        }
    };

    Node* head = new Node(-1, -1, -1);
    Node* tail = new Node(-1, -1, -1);

    int cap;
    unordered_map<int, Node*> map;

    void addNode(Node* _add){
        Node* itr = head;
        while(itr->next->freq > _add->freq){
            itr = itr->next;
        }
        _add->next = itr->next;
        itr->next = _add;
        _add->prev = itr;
        _add->next->prev = _add;
    }

    void deleteNode(Node* _delete){
        Node* left = _delete->prev;
        Node* right = _delete->next;
        left->next = right;
        right->prev = left;
    }

    LFUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            Node* curr_node = map[key];
            int val = curr_node->val;
            int freq = curr_node->freq;
            map.erase(key);
            deleteNode(curr_node);
            curr_node = new Node(key, val, freq + 1); 
            addNode(curr_node);
            map[key]=curr_node;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {

        int freq = 1;
        Node* curr_node;

        if(map.find(key) != map.end()){
            curr_node = map[key];
            freq += curr_node->freq;
            map.erase(key);
            deleteNode(curr_node);
        }

        if(map.size() == cap){
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        curr_node = new Node(key, value, freq);
        addNode(curr_node);
        map[key] = curr_node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */