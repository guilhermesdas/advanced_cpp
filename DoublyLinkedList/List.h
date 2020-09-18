#include <cstddef>
#include <iostream>


/**
 * Class to represent a Doubly Linked List
 * */
template<typename T>
class List {
    public:

        /**
         * Initialize the node as NULL and count as 0
         * */
        List();
        /**
         * Remove all allocated data when finish the program.
         * */
        ~List();

        /**
         * Struct to represent each node in the Doubly Linked List
         * */
        struct node{
            T data;         // Data
            node * prev;    // A reference to the previous node
            node * next;    // A reference to the next node
            node(T _data) : data(_data), prev(NULL), next(NULL) {}
            node(T _data, node *_next) : data(_data), next(_next), prev(NULL) {}
            node(T _data, node *_next, node *_prev) : data(_data), next(_next), prev(_prev) {}
        };

        /**
         * Add a obj in the beginning of the list
         * */
        void addFront(T obj);
        /**
         * Add a obj in the end of the list
         * */
        void addEnd(T obj);
        /**
         * Add a obj before a node n
         * */
        node * addBefore(node * n, T obj);
        /**
         * Add a obj after a node n
         * */
        node * addAfter(node * n, T obj);
        /**
         * Remove a given node
         * */
        bool remove(node * n);
        /**
         * Remove the node within first founded obj
         * */
        bool remove(T obj);
        /**
         * Get the list size
         * */
        int size();
        /**
         * Search for the node within the first founded obj
         * */
        node* get(T obj);
        /**
         * Print all values of the list
         * */
        void print();
        /**
         * Get the list's head
         * */
        node* begin();

    private:
        /**
         * Count number of elements
         * */
        int count = 0;
        /**
         * Node to the list's head
         * */
        node * head;

};