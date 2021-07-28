// Heap.hpp
typedef int ElementType;

class Heap
{
private:
public:
    int size_;
    int capacity_;
    ElementType *arr_;

    Heap (int _size);
    ~Heap (void);
    
    void Swap (int _index_a, int _index_b);
    void ResizeBigger (void);
    void Insert (ElementType _data);
    
    ElementType DeleteMin (void);

    void PrintNodes (void);

    
};