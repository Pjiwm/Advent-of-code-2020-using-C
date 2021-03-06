#pragma once
#define TABLE_SIZE 20000
typedef struct entry_t {
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct {
    entry_t **entries;
} ht_t;

unsigned int hash(const char* key);
entry_t* ht_pair(const char* key, const char* value);
ht_t* ht_init(void);
void ht_put(ht_t *hashtable, const char *key, const char *value);
char *ht_get(ht_t *hashtable, const char *key);
void ht_del(ht_t *hashtable, const char *key);
void ht_deallocate(ht_t *hashtable);