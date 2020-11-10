#include<iostream>

#ifndef ENTRY_H
#define ENTRY_H

class Entry
{
private:
    const int VALUE_LENGTH = 3;
    int key;
    std::string value;
public:
    Entry();
    Entry(int key,std::string value);
    void random();
    int getKey();
    void setKey(int key);
    std::string getValue();
    void setValue(std::string value);
    std::string toString();
};


#endif