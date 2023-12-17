// Implement LFU cache
// Problem Link: https://leetcode.com/problems/lfu-cache/

// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

// Video explanation: https://youtu.be/0PSB9y8ehbk
// Solution: https://www.youtube.com/watch?v=mzqHlAW7jeE

class LFUCache
{
public:
    struct Node
    {
        int key, val, freq;
        Node *next, *prev;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            freq = 1;
            next = prev = nullptr;
        }
    };

    struct List
    {
        Node *head, *tail;
        int size;
        List()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void insertAtHead(Node *node)
        {
            Node *nextNode = head->next;
            head->next = node;
            node->prev = head;
            node->next = nextNode;
            nextNode->prev = node;
            size++;
        }

        void deleteNode(Node *node)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node *deleteFromTail()
        {
            if (tail->prev == head)
            {
                return nullptr;
            }
            Node *nodeToBeDeleted = tail->prev;
            deleteNode(nodeToBeDeleted);
            return nodeToBeDeleted;
        }
    };

    unordered_map<int, Node *> hashMap;
    unordered_map<int, List *> freqMap;
    int capacity, minFreq;

    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key)
    {
        if (hashMap.find(key) == hashMap.end())
        {
            return -1;
        }
        Node *node = hashMap[key];
        int val = node->val;
        int freq = node->freq;
        List *oldList = freqMap[freq];
        oldList->deleteNode(node);
        if (oldList->size == 0 && minFreq == freq)
        {
            minFreq++;
        }
        List *newList = freqMap[freq + 1];
        if (newList == nullptr)
        {
            newList = new List();
            freqMap[freq + 1] = newList;
        }
        node->freq++;
        newList->insertAtHead(node);
        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }
        if (hashMap.find(key) != hashMap.end())
        {
            Node *node = hashMap[key];
            node->val = value;
            get(key);
            return;
        }
        if (hashMap.size() == capacity)
        {
            List *list = freqMap[minFreq];
            Node *nodeToBeDeleted = list->deleteFromTail();
            hashMap.erase(nodeToBeDeleted->key);
            delete nodeToBeDeleted;
        }
        Node *node = new Node(key, value);
        hashMap[key] = node;
        List *list = freqMap[1];
        if (list == nullptr)
        {
            list = new List();
            freqMap[1] = list;
        }
        list->insertAtHead(node);
        minFreq = 1;
    }
};