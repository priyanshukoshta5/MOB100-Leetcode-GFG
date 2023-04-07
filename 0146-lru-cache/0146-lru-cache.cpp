struct DoubleLL{
    int key;
    int val; 
    DoubleLL *prev;
    DoubleLL *next;
    DoubleLL(int k, int data){
        key = k;
        val = data;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    DoubleLL *head = new DoubleLL(0,0);
    DoubleLL *tail = new DoubleLL(0,0);
    int size;
    unordered_map<int,DoubleLL* > mp;

public:
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(DoubleLL *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    
    void insertNodeAtStart(DoubleLL *node){
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        DoubleLL *temp = mp[key];
        deleteNode(temp);
        insertNodeAtStart(temp);

        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            DoubleLL *temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            insertNodeAtStart(temp);
        }
        else if(mp.size() == size)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            DoubleLL *temp = new DoubleLL(key,value);
            insertNodeAtStart(temp);
            mp[key] = temp;
        }
        else if(mp.size() < size)
        {
            DoubleLL *temp = new DoubleLL(key,value);
            insertNodeAtStart(temp);
            mp[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */