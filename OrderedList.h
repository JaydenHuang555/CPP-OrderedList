#pragma once

#include <new>
#include <stdexcept>
template<typename T>
class OrderedList {
    unsigned long long size, cap;
    T *subList, tail;

public:
    OrderedList(){
        this->cap = 1 << 3;
        this->size = 0;
        this->subList = new T[this->cap];
        this->tail = subList;
    }

    OrderedList(OrderedList<T> &other){
         this->cap = other->cap;
         this->size = other->size;
         this->subList = new T[this->cap];
         for(int i = 0; i < cap; i++) subList[i] = other.subList[i];
         this->tail = other.tail;
    }

    ~OrderedList(){
        delete[] subList;
    }

    void add(T item){
        subList[size++] = item;
        if(size == cap){
            T *next = new T[cap *= 2];
            for(unsigned long long i = 0; i < cap / 2; i++) next[i] = subList[i];
            delete[] subList;
            subList = next;
        }
    }

    T get(int index){
        if(index > size || index < 0) throw std::invalid_argument("invalid index given");
        return subList[index];
    }

    bool contains(T item){
        for(int i = 0; i< size; i++) if(subList[i] == item) return true;
        return false;
    }
};