#include <iostream>
#include "SkipList.h"
#include "QuadNode.h"

using namespace std;

SkipList::SkipList()
{
    head_entry = new Entry();
    tail_entry = new Entry();
    head_entry->setKey(MINUS_INF);
    tail_entry->setKey(PLUS_INF);
    head = new QuadNode(head_entry);
    tail = new QuadNode(tail_entry);
    head->setNext(tail);
    tail->setPrev(head);
}

SkipList::~SkipList()
{
    free(head);
    free(tail);
    free(head_entry);
    free(tail_entry);
}

Entry *SkipList::find(int key)
{
    QuadNode *temp = head;
    while (temp != NULL)
    {
        while (temp->getNext()->getData()->getKey() < key)
        {
            temp = temp->getNext();
        }
        if (temp->getNext()->getData()->getKey() == key)
        {
            return temp->getNext()->getData();
        }
        temp = temp->getBelow();
    }
    return NULL;
}

Entry *SkipList::greaterEntry(int key)
{
    QuadNode *temp = head;
    while (temp->getBelow() != NULL)
    {
        while (temp->getNext()->getData()->getKey() < key)
        {
            temp = temp->getNext();
        }
        if (temp->getNext()->getData()->getKey() == key)
        {
            return temp->getNext()->getData();
        }
        temp = temp->getBelow();
    }
    while (temp->getData()->getKey() < key)
    {
        temp = temp->getNext();
    }
    return temp->getData();
}

Entry *SkipList::lessEntry(int key)
{
    QuadNode *temp = head;
    while (temp->getBelow() != NULL)
    {
        while (temp->getNext()->getData()->getKey() < key)
        {
            temp = temp->getNext();
        }
        if (temp->getNext()->getData()->getKey() == key)
        {
            return temp->getNext()->getData();
        }
        temp = temp->getBelow();
    }
    while (temp->getData()->getKey() < key)
    {
        temp = temp->getNext();
    }
    return temp->getPrev()->getData();
}

void SkipList::put(int key, std::string value)
{
    if (find(key) != NULL)
    {
        return;
    }
    Entry *new_entry = new Entry(key, value);
    int level_curr = maxLevel();
    for (int i = 0; i < level_curr - maxlevel; i++)
    {
        QuadNode *temp1 = new QuadNode();
        QuadNode *temp2 = new QuadNode();
        temp1->setData(head->getData());
        temp2->setData(tail->getData());
        temp1->setNext(temp2);
        temp2->setPrev(temp1);
        temp1->setBelow(head);
        temp2->setBelow(tail);
        head->setAbove(temp1);
        tail->setAbove(temp2);
        head = temp1;
        tail = temp2;
    }
    if (level_curr > maxlevel)
    {
        maxlevel = level_curr;
    }
    QuadNode *temp = head;
    for (int i = 0; i < maxlevel + 1 - level_curr; i++)
    {
        temp = temp->getBelow();
    }
    QuadNode *prev_node = NULL;
    while (temp != NULL)
    {
        while (temp->getNext()->getData()->getKey() < key)
        {
            temp = temp->getNext();
        }
        QuadNode *new_node = new QuadNode();
        new_node->setData(new_entry);
        new_node->setPrev(temp);
        new_node->setNext(temp->getNext());
        temp->getNext()->setPrev(new_node);
        temp->setNext(new_node);
        if (prev_node != NULL)
        {
            prev_node->setBelow(new_node);
            new_node->setAbove(prev_node);
        }
        prev_node = new_node;
        temp = temp->getBelow();
    }
}

void SkipList::erase(int key)
{
    QuadNode *temp1 = head;
    while (temp1 != NULL)
    {
        while (temp1->getNext()->getData()->getKey() < key)
        {
            temp1 = temp1->getNext();
        }
        if (temp1->getNext()->getData()->getKey() == key)
        {
            QuadNode *temp2 = temp1->getNext()->getNext();
            temp1->setNext(temp2);
            temp2->setPrev(temp1);
        }
        temp1 = temp1->getBelow();
    }
    while (head->getBelow()->getNext()->getData()->getKey() == PLUS_INF)
    {
        head = head->getBelow();
        tail = tail->getBelow();
        head->setAbove(NULL);
        tail->setAbove(NULL);
        maxlevel--;
    }
}

int SkipList::size()
{
    QuadNode *temp = head;
    while (temp->getBelow() != NULL)
    {
        temp = temp->getBelow();
    }
    int count = 0;
    while (temp->getNext() != NULL)
    {
        if (temp->getData()->getKey() < PLUS_INF && temp->getData()->getKey() > MINUS_INF)
        {
            count++;
        }
        temp = temp->getNext();
    }
    return count;
}

bool SkipList::empty()
{
    return size() == 0 ? true : false;
}

string SkipList::toString()
{
    string represenation = "";
    string array[maxlevel + 1][size() + 2];
    QuadNode *iter = head;
    while (iter->getBelow() != NULL)
    {
        iter = iter->getBelow();
    }
    int j = 0;
    while (iter != NULL)
    {
        int i = maxlevel;
        QuadNode *temp = iter;
        int key = temp->getData()->getKey();
        while (temp != NULL && i >= 0)
        {
            if (key == MINUS_INF)
            {
                array[i][j] = "-inf--";
            }
            else if (key == PLUS_INF)
            {
                array[i][j] = "inf";
            }
            else
            {
                if (key < 10)
                {
                    array[i][j] = "0" + to_string(key) + "--";
                }
                else
                {
                    array[i][j] = to_string(key) + "--";
                }
            }
            temp = temp->getAbove();
            i--;
        }
        while (i >= 0)
        {
            array[i][j] = "----";
            i--;
        }
        iter = iter->getNext();
        j++;
    }

    for (int i = 0; i < maxlevel + 1; i++)
    {
        for (j = 0; j < size() + 2; j++)
        {
            represenation += array[i][j];
        }
        if (i != maxlevel)
        {
            represenation += "\n";
        }
    }
    return represenation;
}

void SkipList::clear(){
    head->setBelow(NULL);
    tail->setBelow(NULL);
    maxlevel = 0;
}

int SkipList::maxLevel()
{
    int count = 0;
    while (rand() % 2 != TAILS)
    {
        count++;
    }
    return count + 1;
}