package Java.map;

class HashMapImpl<K,V> {

    private static final int DEFAULT_BUCKET_SIZE = 16;

    private Entry<K,V>[] buckets;

    private int count;

    public HashMapImpl() {
        this.buckets = new Entry[DEFAULT_BUCKET_SIZE];
    }

    public HashMapImpl(int capacity) {
        this.buckets = new Entry[capacity];
    }

    public void put(K key, V value) {
        if (key == null) {
            throw new IllegalArgumentException("null cannot be used to retrieve a map value");
        }
        int bucketId = key.hashCode() % this.buckets.length;
        Entry<K,V> bucket = buckets[bucketId];
        if (bucket == null) {
            buckets[bucketId] = new Entry<>(key, value, null);
        } else {
            while (bucket.getNext() != null) {
                bucket = bucket.getNext();
            }
            bucket.setNext(new Entry<>(key, value, null));
        }
        count++;
    }

    public V get(K key) {
        if (key == null) {
            throw new IllegalArgumentException("null cannot be used to retrieve a map value");
        }
        int bucketId = key.hashCode() % this.buckets.length;
        Entry<K,V> bucket = buckets[bucketId];
        if (bucket == null) {
            throw new IllegalArgumentException("No entry found for key: " + key);
        } else {
            while (!bucket.getKey().equals(key)) {
                bucket = bucket.getNext();
                if (bucket == null) {
                    throw new IllegalArgumentException("No entry found for key: " + key);
                }
            }
            return bucket.getValue();
        }
    }

    public V remove(K key) {
        if (key == null) {
            throw new IllegalArgumentException("null cannot be used as a valid map key");
        }
        int bucketId = key.hashCode() % this.buckets.length;
        Entry<K,V> bucket = buckets[bucketId];
        if (bucket == null) {
            throw new IllegalStateException("No entry found for key: " + key);
        } else {
            if (bucket.getNext() == null) {
                V value = bucket.getValue();
                buckets[bucketId] = null;
                count--;
                return value;
            } else {
                while(bucket.getNext() != null) {
                    Entry<K, V> nextEntry = bucket.getNext();
                    if (nextEntry.getKey().equals(key)) {
                        V value = nextEntry.getValue();
                        bucket.setNext(nextEntry.getNext());
                        count--;
                        return value;
                    } else {
                        bucket = bucket.getNext();
                    }
                }
                throw new IllegalStateException("Failed to remove key from map");
            }
        }
    }

    public int size() {
        return this.count;
    }
}