

class LRUCache {

private:
    struct Node{
        int key;
        int val;

        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
    };

public:
    unordered_map<int, Node*> mp;
    int limit = 0;
    Node* head;
    Node* tail;


    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        tail->prev = head;
        head->next = tail;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        //map中取中Node
        Node* node = mp[key];

        //刪除node
        deleteNode(node);
        
        //插入至最前方
        insertToFront(node);

        return node->val;
    }
    
    void put(int key, int value) {
        //存在
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            node->val = value;
            insertToFront(node);
        }
        else {
            //滿
            if(mp.size() == limit) {
                Node* lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insertToFront(node);
        }
    }
};
