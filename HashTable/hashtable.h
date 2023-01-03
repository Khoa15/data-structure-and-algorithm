#pragma once
#ifndef _H_HASH_TABLE_
#define _H_HASH_TABLE_
#define THRESHOLD 0.6
#define KEYSIZE 10
#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;

    Node() : value(0), next(NULL) {}
    Node(int x): value(x), next(NULL) {}
};

struct HashTable{
    Node* bucket;
    int size;
    int count;

    HashTable(){
        bucket = new Node(10);
        size = 10;
        for(int i = 0; i < size; i++){
            bucket[i] = NULL;
        }
    }

    ~HashTable(){
        for(int i = 0; i < size; i++){
            Node* tmp = (bucket + i);
            while(tmp != NULL){
                Node* del = tmp;
                tmp = tmp->next;
                delete del;
            }
        }
        delete[] bucket;
    }
};
#endif