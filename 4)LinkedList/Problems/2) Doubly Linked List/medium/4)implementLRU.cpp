// Implement LRU CACHE

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//  int get(int key) Return the value of the key if the key exists, otherwise return -1.
//  void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// Problem Link: https://www.codingninjas.com/studio/problems/lru-cache-implementation_670276

// Approach: We will use a doubly linked list and a map to implement LRU cache.
// We will use the map to store the address of the node corresponding to the key.
// We will use the doubly linked list to store the keys in the order of their usage(most recently used key will be at the front of the list and least recently used key will be at the back of the list).

class LRUCache
{
    struct Node
    {
        int val, key;
        Node *next, *prev;

        Node() { next = prev = nullptr; }

        Node(int key, int val)
        {
            this->val = val;
            this->key = key;
            next = prev = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node *> hashMap;
    Node *head;
    Node *tail;

    // Inserts a new node with the given key and value at the beginning of the list.
    Node *insertAtHead(int key, int val)
    {
        Node *newNode = new Node(key, val);
        Node *nextNode = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        hashMap[key] = newNode; // Update the hash map with the new node.
        return newNode;
    }

    // Deletes the least recently used node from the end of the list.
    void deleteFromTail()
    {
        if (tail->prev == head)
        {
            return; // Skip if the list is empty.
        }
        Node *nodeToBeDeleted = tail->prev;
        nodeToBeDeleted->prev->next = tail;
        tail->prev = nodeToBeDeleted->prev;
        hashMap.erase(nodeToBeDeleted->key); // Remove the deleted node from the hash map.
        delete nodeToBeDeleted;              // Free the memory occupied by the deleted node.
    }

    // Deletes the given node from the list
    Node *delNode(Node *nodeToBeDeleted)
    {
        // delete the node from its current position
        nodeToBeDeleted->prev->next = nodeToBeDeleted->next;
        nodeToBeDeleted->next->prev = nodeToBeDeleted->prev;
        hashMap.erase(nodeToBeDeleted->key); // Remove the node from the hash map.
        delete nodeToBeDeleted;              // Free the memory occupied by the node.
    }

public:
    // Constructor to initialize the LRUCache with the given capacity.
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Retrieves the value of a key from the LRUCache.
    int get(int key)
    {
        if (hashMap.find(key) == hashMap.end())
        {
            return -1; // Key not found in the LRUCache.
        }

        // If the key exists in the LRUCache, update its position in the linked list.
        // by deleting the node from its current position and inserting it at the beginning.
        Node *targetNode = hashMap[key];
        int val = targetNode->val;
        delNode(targetNode);
        insertAtHead(key, val);

        return val; // Return the value of the key.
    }

    // Adds or updates a key-value pair in the LRUCache.
    void put(int key, int value)
    {
        if (hashMap.find(key) != hashMap.end())
        {
            // If the key already exists in the LRUCache,delete the node from its current position and insert it at the beginning.
            Node *targetNode = hashMap[key];
            delNode(targetNode);
        }
        else
        {
            if (hashMap.size() == capacity)
            {
                deleteFromTail(); // Remove the least recently used node if the LRUCache is full.
            }
        }
        Node *insertedNode = insertAtHead(key, value); // Insert the new node at the beginning.
    }
};
