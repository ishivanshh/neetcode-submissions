class MyHashMap {
public:
    vector<list<pair<int, int>>> buckets;
    int size = 10000;

    MyHashMap() {
        buckets.resize(size);
    }

    void put(int key, int value) {

        int bucketno = key % size;
        auto &chain = buckets[bucketno];

        // If key already exists, update its value
        for(auto &it : chain) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }

        // Key doesn't exist, so insert it
        chain.push_back({key, value});
    }

    int get(int key) {

        int bucketno = key % size;
        auto &chain = buckets[bucketno];

        for(auto &it : chain) {
            if(it.first == key) {
                return it.second;
            }
        }

        return -1;
    }

    void remove(int key) {

        int bucketno = key % size;
        auto &chain = buckets[bucketno];

        for(auto it = chain.begin(); it != chain.end(); it++) {

            if(it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }
};
