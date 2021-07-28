// OpenAddressing.hpp

#define KEY_MAX_LEN 9
#define VALUE_MAX_LEN 99

class HashNode
{
private:

public:
    HashNode (const char *_key, const char *_value);
    ~HashNode (void);

    char *key_;
    char *value_;
};

class HashTable
{
private:
    int Pow (int _base, int _exponent);

public:
    int arr_size_;
    int num_nodes;
    HashNode **hash_table_;

    HashTable (int _arr_size);
    ~HashTable (void);

    void AddNode (HashNode *_new_node);
    int Hash (const char *_key);
    int Hash2 (const char *_key);

    void ReHash (void);
    void ReHashAddNode (HashNode *_node, HashNode **_new_table);

    const char *GetNodeValue (const char *_key);
    void PrintHashTable (void);
};