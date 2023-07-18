struct doublyLL{
    int key;
    int val;
    doublyLL *next;
    doublyLL *prev;
    doublyLL(int k, int value){
        key = k;
        val = value;
        next = prev = nullptr;
    }
};

class LRUCache {
private:
    int size;
    int cnt;
    doublyLL *head; 
    doublyLL *tail;
    unordered_map<int, doublyLL *> mp;  // to store key:value pairs

public:
    LRUCache(int capacity) {
        size = capacity;
        cnt = 0;
        head = new doublyLL(-1, -1);
        tail = new doublyLL(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(doublyLL *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertAtStart(doublyLL *node){
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            doublyLL *node = mp[key];
            deleteNode(node);
            insertAtStart(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            doublyLL *node = mp[key];
            deleteNode(node);
            insertAtStart(node);
            node->val = value;
        }
        else if(cnt == size)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            doublyLL *node = new doublyLL(key, value);
            insertAtStart(node);
            mp[key] = node;
        }
        else
        {
            doublyLL *node = new doublyLL(key, value);
            insertAtStart(node);
            mp[key] = node;
            cnt++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */