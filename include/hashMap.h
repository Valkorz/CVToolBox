#ifndef HASHMAP_H
#define HASHMAP_H
#define DEFAULT_START_SIZE 10
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Hash{
    char* key;
    char* value;
}Hash;

typedef struct HashMap{
    Hash* map;
    int size;
    int count;
}HashMap;

//Initialize hashmap with default values
HashMap* createHashMap(){
    HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
    Hash* newMap = (Hash*)malloc(sizeof(Hash) * DEFAULT_START_SIZE);

    // printf("\n Memory allocated for hashMap: hashMap: %p , hash Array: %p", hashMap, newMap);

    //Loop to set all hashes to null, just to make sure.
    int i = 0;
    for(i = 0; i < DEFAULT_START_SIZE; i++){
        newMap[i].key = NULL;
        newMap[i].value = NULL;
    }
    hashMap->map = newMap;
    hashMap->size = DEFAULT_START_SIZE;
    hashMap->count = 0;


    if(hashMap == NULL || newMap == NULL){
        printf("\n Error while allocating memory for hashmap. Exiting function call.");
        free(hashMap);
        free(newMap);
        return NULL;
    }

    return hashMap;
    // printf("\n Created hashmap %p with size %i and map %p. \n",hashMap, DEFAULT_START_SIZE, newMap);
}

//adds or modifies a value into the hash map with a specified key.
void add(HashMap* hashMap, char* _key, char* value){
    if(hashMap == NULL){
        printf("\n The provided hashmap is NULL! Exiting function...");
        return;
    }
    // printf("\nAdding entry '%s':'%p' to %p", _key, value, hashMap);


    //Will modify the 'value' and 'key' properties inside the array of hashes (KeyValuePairs) if:
    //The _key matches an existing key or if there is a hash with a NULL key. The new value will
    //replace whatever was there before.

    int i = 0;
    Hash* currentHash = NULL;
    for(i = 0;i < hashMap->size; i++){
        currentHash = hashMap->map + i; 
        // printf("\n current key: %s", currentHash->key);
        if(currentHash->key == NULL){
            currentHash->value = strdup(value);
            currentHash->key = strdup(_key);
            // printf("\n (HashMap: %p) Set key %s to %s in hash: %p. depth: %d", hashMap, currentHash->key, currentHash->value, currentHash, i);
            hashMap->count++;
            return;
        }
        // printf("\n is %s equal to %s? %d", currentHash->key, _key, strcmp(currentHash->key, _key));
        if(strcmp(currentHash->key, _key) == 0){
            currentHash->value = strdup(value);
            // printf("\n Modified key %s to %p in hash: %p. depth: %d", currentHash->key, value, currentHash, i);
            return;
        }
    }

    //If no NULL keys have been found inside the hashes array, it means the hashmap is
    //fully populated... in which case, the size is extended by DEFAULT_START_SIZE

    int newSize = hashMap->size + DEFAULT_START_SIZE;
    Hash* newMap = (Hash*)realloc(hashMap->map, sizeof(Hash) * newSize);
    if(newMap == NULL){
        fprintf(stderr, "\nFailed to reallocate memory for hash map\n");
        return;
    }

    for(i = newSize - DEFAULT_START_SIZE; i < newSize; i++){
        newMap[i].key = NULL;
        newMap[i].value = NULL;
    }

    hashMap->map = newMap;
    hashMap->size = newSize;

    hashMap->map[newSize - DEFAULT_START_SIZE].key = strdup(_key);
    hashMap->map[newSize - DEFAULT_START_SIZE].value = strdup(value);
    printf("\n Resized hashmap to: %d entries.\n", newSize);
}

//Removes a specified keyvalue from the hashmap. Throws an error if key is not found.
void removeEntry(HashMap* hashMap, char* key){
    if(hashMap == NULL){
        printf("\n The provided hashmap is NULL! Exiting function...");
        return;
    }

    int i = 0;
    Hash* currentHash = hashMap->map + i;

    for(i = 0; i < hashMap->size; i++){
        currentHash = hashMap->map + i;
        if(currentHash->key == key){
            currentHash->value = NULL;
            currentHash->key = NULL;
            hashMap->count--;
            return;
        }
    }
    fprintf(stderr, "\nKey %s not found in %p.\n", key, hashMap);
}

//Returns a pointer to the value defined by the key in the hashmap
char* get(HashMap* hashMap, char* key){
    if(hashMap == NULL){
        printf("\n The provided hashmap is NULL! Exiting function...");
        return NULL;
    }

    int i = 0;
    Hash* currentHash = hashMap->map + i;
    for(i = 0; i < hashMap->size; i++){
        // printf("\n Reading hash: %p of key %s...", currentHash, currentHash->key);
        currentHash = hashMap->map + i;
        if(strcmp(currentHash->key, key) == 0){
            return currentHash->value;
        }
    }
    fprintf(stderr, "\nKey %s not found in %p.\n", key, hashMap);
    return NULL;
}

char** get_keys(HashMap* hashMap){
    printf("\n KEYS: ");
    char** keylist = (char**)malloc(sizeof(char*) * hashMap->count);
    int i;
    for(i = 0; i < hashMap->count; i++){
        printf(" %s ", (*(hashMap->map + i)).key);
        *(keylist + i) = strdup((*(hashMap->map + i)).key);
    }

    printf("\n Keylist: %p", keylist);
    return keylist;
}

void printAll(HashMap* hashMap){
    int i = 0;
    Hash* currentHash = hashMap->map + i;
    for(i = 0; i < hashMap->size; i++){
        currentHash = hashMap->map + i;
        printf("\n {%s:%s}", currentHash->key, currentHash->value);
    }
}

void clearMap(HashMap* hashMap){
    free(hashMap->map);
    free(hashMap);
}



#endif