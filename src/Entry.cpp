#include <iostream>
#include "Entry.h"

using namespace std;

Entry::Entry()
{
    key = 0;
    value = "";
}

Entry::Entry(int key,string value)
{
    this->key = key;
    this->value = value;
}

void Entry::random()
{
    key = rand() % 100;
    value = "";
    for (int i = 0; i < VALUE_LENGTH; i++)
    {
        value += (char)((rand() % 26) + 97);
    }
}

int Entry::getKey(){
    return key;
}

void Entry::setKey(int key){
    this->key = key;
}

string Entry::getValue(){
    return value;
}

void Entry::setValue(string value){
    this->value =value;
}

string Entry::toString(){
    return "("+to_string(key)+", "+value+")";
}