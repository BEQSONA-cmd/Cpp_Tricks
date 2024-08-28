#include <iostream>

// Hash Map

struct Hash_Map_Enter
{
    int key;
    int value;
    Hash_Map_Enter *next;
};

struct Hash_Map
{
    struct Hash_Map_Enter **array;
    int size;
};

class HashMap
{
    private:
        Hash_Map *hash_map;
    public:
        void createHashMap(int size);
        void add(int key, int value);
        int get(int key);
        void printHashMap();
        void deleteHashMap();
};

void HashMap::createHashMap(int size)
{
    int i = 0;
    hash_map = new Hash_Map;
    hash_map->size = size;
    hash_map->array = new Hash_Map_Enter*[hash_map->size];

    while(i < hash_map->size)
    {
        hash_map->array[i] = NULL;
        i++;
    }
}

void HashMap::add(int key, int value)
{
    int index = key % hash_map->size;
    Hash_Map_Enter *newEnter = new Hash_Map_Enter;
    newEnter->key = key;
    newEnter->value = value;
    newEnter->next = NULL;
    if (hash_map->array[index] == NULL)
        hash_map->array[index] = newEnter;
    else
    {
        Hash_Map_Enter *current = hash_map->array[index];
        while (current->next != NULL)
            current = current->next;
        current->next = newEnter;
    }
}

void HashMap::printHashMap()
{
    int i = 0;
    while (i < hash_map->size)
    {
        Hash_Map_Enter *current = hash_map->array[i];
        while (current != NULL)
        {
            std::cout << "Key: " << current->key << " Value: " << get(current->key) << std::endl;
            current = current->next;
        }
        i++;
    }
}

void HashMap::deleteHashMap()
{
    for (int i = 0; i < hash_map->size; i++)
    {
        Hash_Map_Enter *current = hash_map->array[i];
        Hash_Map_Enter *next;
        while (current != NULL)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] hash_map->array;
    delete hash_map;
}

int HashMap::get(int key)
{
    int index = key % hash_map->size;
    Hash_Map_Enter *current = hash_map->array[index];
    while (current != NULL)
    {
        if (current->key == key)
            return current->value;
        current = current->next;
    }
    return -1;
}

int main(void)
{
    // Hash Map
    HashMap hashmap;

    hashmap.createHashMap(10);
    hashmap.add(1, 10);
    hashmap.add(2, 20);
    hashmap.add(3, 30);
    hashmap.add(4, 40);
    hashmap.add(5, 50);

    hashmap.printHashMap();

    hashmap.deleteHashMap();

    return 0;
}
