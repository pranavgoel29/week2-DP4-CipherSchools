class LRUCache {
    int capacity;
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        auto it = cache[key];
        int value = it->second;
        lru.erase(it);
        lru.push_front({key, value});
        cache[key] = lru.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            auto it = cache[key];
            lru.erase(it);
            lru.push_front({key, value});
            cache[key] = lru.begin();
        } else {
            if (size == capacity) {
                auto it = lru.back();
                cache.erase(it.first);
                lru.pop_back();
                size--;
            }
            lru.push_front({key, value});
            cache[key] = lru.begin();
            size++;
        }
    }
};