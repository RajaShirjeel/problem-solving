class Node {
public:
    int val;
    int key;
    Node *prev;
    Node *next;

    Node(int val, int key){
        this->val = val;
        this->key = key;
        prev = NULL;
        next = NULL;
    }

};

class LRUCache {
public:
    int capacity;
    Node *head = new Node(-1, -1);
    Node *tail = new Node (-1, -1);

    unordered_map<int, Node*>map;

    void deleteNode(Node *node){
        Node *nextNode = node->next;
        Node *prevNode = node->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node *node){
        Node *nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()){
            Node *node = map[key];
            deleteNode(node);
            addNode(node);
            return node->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {

        if (map.find(key) != map.end()){
            Node *node = map[key];
            deleteNode(node);
            addNode(node);
            node->val = value;
        }

        else{
            if (map.size() == capacity){
                Node *node = tail->prev;
                map.erase(node->key);
                deleteNode(node);
            }

            Node *newNode = new Node(value, key);
            map[key] = newNode;
            addNode(newNode);

        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */