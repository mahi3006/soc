class LRUCache {
public:
    int capacity;
    list<pair<int, int>> lruList;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        auto it = cache[key];
        int value = it->second;

        lruList.erase(it);
        lruList.push_front({key, value});
        cache[key] = lruList.begin();

        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        } else if (lruList.size() == capacity) {
            int oldKey = lruList.back().first;
            lruList.pop_back();
            cache.erase(oldKey);
        }

        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};
