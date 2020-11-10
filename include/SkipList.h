#include<iostream>
#include"Entry.h"
#include"QuadNode.h"
#include<limits.h>

#ifndef SKIPLIST_H
#define SKIPLIST_H

class SkipList
{
private:
    const int PLUS_INF=INT_MAX; 
    const int MINUS_INF=INT_MIN;
    const int HEADS=0;
    const int TAILS=1;
    int maxlevel = 0;
    Entry* head_entry;
    Entry* tail_entry;
    QuadNode* head;
    QuadNode* tail;
    int maxLevel();
public:
    SkipList();
    ~SkipList();
    Entry* find(int key);
    Entry* greaterEntry(int key);
    Entry* lessEntry(int key);
    void put(int key,std::string value);
    void erase(int key);
    void clear();
    int size();
    bool empty();
    std::string toString();

};

#endif