class Node {
public: 
    int key;
    int val;
    int cnt;
    Node *next;
    Node *prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

class NodeList {
public:
    int size;
    Node *head;
    Node *tail;

    NodeList(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNode(Node *node){
        Node *nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;
        size++;
    }

    void deleteNode(Node *node){
        Node *nextNode = node->next;
        Node *prevNode = node->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }

};

class LFUCache {
public:

    unordered_map<int, Node*>nodeMap;
    unordered_map<int, NodeList*>nodeFreqMap;
    int cap;
    int minFreq;
    int currSize;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void update(Node *node){
        NodeList *Nlist = nodeFreqMap[node->cnt];
        Nlist->deleteNode(node);

        if (node->cnt == minFreq && Nlist->size == 0){
            minFreq++;
        }

        NodeList *newList = new NodeList();
        if (nodeFreqMap.find(node->cnt + 1) != nodeFreqMap.end()){
            newList = nodeFreqMap[node->cnt+1];
        }
        node->cnt++;
        newList->addNode(node);
        nodeFreqMap[node->cnt] = newList;
    }
    
    int get(int key) {
        if (nodeMap.find(key) != nodeMap.end()){
            Node *node = nodeMap[key];
            int val = node->val;
            update(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cap == 0){
            return;
        }

        if (nodeMap.find(key) != nodeMap.end()){
            Node *node = nodeMap[key];
            node->val = value;
            update(node);
        }
         
        else {
            if (cap == currSize){
                NodeList *leastFreqList = nodeFreqMap[minFreq];
                Node *node = leastFreqList->tail->prev;
                leastFreqList->deleteNode(node);
                nodeMap.erase(node->key);
                currSize--;
            }

            currSize++;
            minFreq = 1;

            Node *newNode = new Node(key, value);
            nodeMap[key] = newNode;
            NodeList *newList = new NodeList();
            
            if (nodeFreqMap.find(minFreq) != nodeFreqMap.end()){
                newList = nodeFreqMap[minFreq];
            }

            newList->addNode(newNode);

            nodeFreqMap[minFreq] = newList;
        }
    }
};