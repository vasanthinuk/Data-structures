
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Define a structure for a hash node
struct Node {
    int key;
    int value;
    struct Node* next;
};

// Define the hash table
struct Node* hashTable[TABLE_SIZE];

// Hash function to map keys to an index in the hash table
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(int key, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // Calculate the hash index
    int index = hashFunction(key);

    // Insert the new node at the beginning of the linked list at that index
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Function to retrieve the value associated with a key from the hash table
int get(int key) {
    // Calculate the hash index
    int index = hashFunction(key);

    // Traverse the linked list at the calculated index
    struct Node* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            // Key found, return the associated value
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return -1;  // You might choose a different way to indicate that the key is not present
}

int main() {
    // Insert some key-value pairs into the hash table
    insert(1, 10);
    insert(2, 20);
    insert(11, 30);

    // Retrieve values using keys
    printf("Value for key 1: %d\n", get(1));
    printf("Value for key 2: %d\n", get(2));
    printf("Value for key 11: %d\n", get(11));

    // Try to retrieve a value for a key that doesn't exist
    printf("Value for key 5: %d\n", get(5));

    return 0;
}
