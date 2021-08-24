#ifndef QUEUE
#define QUEUE

#define NULL 0

template<class T>
struct Node {

    T val_;
    Node * next_;

    explicit Node(T val) {
        val_ = val;
        next_ = nullptr;
    }

    Node(T val, Node * next) {
        val_ = val;
        next_ = next;
    }
};

template <class T>
class Queue {

    Node<T> * head_;
    Node<T> * tail_;
    int size_;

    void DeleteRecursively(Node<T> * head) {
        if (head == nullptr)
        {
            return;
        }

        DeleteRecursively(head->next_);

        delete head;
    }

public:

    Queue() {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    ~Queue() {
        Clear();
    }

    void Enqueue(T val) {
        if (Empty())
        {
            tail_ = new Node<T>(val);
            head_ = tail_;
        }
        else
        {
            tail_->next_ = new Node<T>(val);
            tail_ = tail_->next_;
        }
        size_++;
    }

    T Dequeue() {
        if (Empty())
        {
            return NULL;
        }

        if (size_ == 1)
        {
            tail_ = nullptr;
        }

        Node<T> * to_delete = head_;
        T val = head_->val_;

        head_ = head_->next_;
        size_--;

        delete to_delete;
        return val;
    }

    T Peek() {
        return head_ ? head_->val_ : NULL;
    }

    int Size() {
        return size_;
    }

    bool Empty() {
        return size_ == 0;
    }

    void Clear() {
        DeleteRecursively(head_);
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
};


#endif
