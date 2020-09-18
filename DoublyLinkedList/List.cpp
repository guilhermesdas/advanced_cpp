#include "List.h"

template<typename T>
List<T>::List(){
    this->count = 0;
    head = NULL;
}

template<typename T>
List<T>::~List(){
    while( this->head != NULL ){
        this->remove(this->head);
    }
}

template<typename T>
void List<T>::addFront(T obj){
    // if list is empty create a new head where
    // data = obj, and both prev and next are null
    if ( this->head == NULL ){
        this->head = new node(obj);   
    }
    // otherwise, create a new node to put in the beginning of the list
    // null <- old_head -> 2nd -> ...
    // null <- new_head <- old_head -> 2nd -> ...
    else {
        // the new head's next is now the old head
        node * new_head = new node(obj,this->head);
        // the old head is now the second element and
        // its previous it's the new head 
        this->head->prev = new_head;
        // new head
        this->head = new_head;
    }
    count++;
}

template<typename T>
void List<T>::addEnd(T obj){
    // if list is empty, create a new head where
    // data = obj, and both prev and next are null
    if ( this->head == NULL ){
        this->head = new node(obj);   
    }
    // otherwise, iterate until the end and create a
    // new node to put it there
    // ... <- old_end -> null
    // ... <- old_end -> new_end -> null
    else {

        // Search for the end
        node * i(this->head);
        while( i->next != NULL ){
            i = i->next;
        }

        // the new end node's previous it's now the old end element
        node * new_end = new node(obj,NULL,i);
        new_end->next = NULL;
        // the old end node's next it's now the the new end
        i->next = new_end;

    }
    count++;
}

template<typename T>
typename List<T>::node * List<T>::addBefore(node * n, T obj){

    // If its null, there's nothing to do
    if ( n == NULL ){
        return NULL;
    }

    // create the node
    node * new_node = new node(obj,NULL,n->prev);

    // Make previous of N the new_node
    n->prev = new_node;
    new_node->next = n;

    // Make the new node the next in the sequence
    if ( new_node->prev != NULL ){
        new_node->prev->next = new_node;
    // Otherwise it's the head
    } else {
        this->head = new_node;
    }

    count++;
    return n;

}

template<typename T>
typename List<T>::node * List<T>::addAfter(node * n, T obj){

    // If its null, there's nothing to do
    if ( n == NULL ){
        return NULL;
    }

    // create the node
    node * new_node = new node(obj,n->next);

    // Make previous of N the new_node
    n->next = new_node;
    new_node->prev = n;

    // Make the new node the next in the sequence
    if ( new_node->next != NULL ){
        new_node->next->prev = new_node;
    }

    count++;

    return n;

}

template<typename T>
void List<T>::print(){
    if ( this->head != NULL ){
        node * i(this->head);
        while( i != NULL ){
            std::cout << i->data << " ";
            i = i->next;
        }
        std::cout << std::endl;
    }
}

template<typename T>
bool List<T>::remove(node * n){
    
    // If it's null, there's nothing to do
    if ( n == NULL ){
        return false;
    }

    // Fix next's previous
    if ( n->next != NULL ){
        n->next->prev = n->prev;
    }

    // Fix previous' next
    if ( n->prev != NULL ){
         n->prev->next = n->next;
    // Otherwise, it's the head  
    } else {
        this->head = n->next;
    }

    delete n;
    count--;
    return true;

}

template<typename T>
bool List<T>::remove(T obj){
    
    // If the list is empty, there's nothing to do
    if ( this->head == NULL ){
        return false;
    }

    // Iterate through the list until find the object
    node * i(this->head);
    while ( i != NULL ){
        // if found the obj, remove it
        if ( i->data == obj ){
            return this->remove(i);
        }
        // otherwise, search the next
        i = i->next;
    }

    // obj not founded
    return false;

}

template<typename T>
typename List<T>::node * List<T>::begin(){
    return this->head;
}

template<typename T>
int List<T>::size(){
    return this->count;
}

template<typename T>
typename List<T>::node * List<T>::get(T obj){
    
    // If the list is empty, there's nothing to do
    if ( this->head == NULL ){
        return NULL;
    }

    // Iterate through the list until find the object
    node * i(this->head);
    while ( i != NULL ){
        if ( i->data == obj ){
            return i;
        }
        // otherwise, search the next
        i = i->next;
    }

    // obj not founded
    return NULL;

}
