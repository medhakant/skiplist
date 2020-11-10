#include"Entry.h"

#ifndef QUADNODE_H
#define QUADNODE_H
class QuadNode
{
private:
    QuadNode* next;
    QuadNode* prev;
    QuadNode* above;
    QuadNode* below;
    Entry*    data;
public:
    QuadNode();
    QuadNode(Entry* data);
    ~QuadNode();
    void setNext(QuadNode* next);
    void setPrev(QuadNode* prev);
    void setAbove(QuadNode* above);
    void setBelow(QuadNode* below);
    void setData(Entry* data);
    QuadNode* getNext();
    QuadNode* getPrev();
    QuadNode* getAbove();
    QuadNode* getBelow();
    Entry* getData();

};

#endif