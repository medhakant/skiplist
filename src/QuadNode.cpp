#include "QuadNode.h"
#include <iostream>

using namespace std;

QuadNode::QuadNode(){
    data = NULL;
    next = NULL;
    prev = NULL;
    above = NULL;
    below = NULL;
}

QuadNode::QuadNode(Entry* data){
    this->data = data;
    next = NULL;
    prev = NULL;
    above = NULL;
    below = NULL;
}

QuadNode::~QuadNode(){
    free(data);
    free(next);
    free(prev);
    free(above);
    free(below);
}

void QuadNode::setNext(QuadNode* next){
    this->next = next;
}

void QuadNode::setPrev(QuadNode* prev) {
    this->prev = prev;
}
void QuadNode::setAbove(QuadNode* above) {
    this->above=above;
}
void QuadNode::setBelow(QuadNode* below) {
    this->below = below;
}
void QuadNode::setData(Entry* data) {
    this->data = data;
}
QuadNode* QuadNode::getNext(){
    return next;
}

QuadNode* QuadNode::getPrev(){
    return prev;
}
QuadNode* QuadNode::getAbove() {
    return above;
}
QuadNode* QuadNode::getBelow() {
    return below;
}
Entry* QuadNode::getData() {
    return data;
}