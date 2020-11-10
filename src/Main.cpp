#include<iostream>
#include"SkipList.h"

using namespace std;

int main(){
    SkipList* s = new SkipList();  // initialise a skip list
    s->put(11,"abc");
    s->put(14,"def");
    s->put(45,"ghi");
    s->put(21,"jkl");
    s->put(67,"mno");
    s->put(99,"pqr");
    s->put(7,"stu");
    s->put(53,"vwx");
    cout << "*****PRINTING SKIP LIST*****\n";
    cout << s->toString() << endl << endl;  // print the skip list
    s->erase(21);                           // delete element from skip list
    cout << "*****PRINTING SKIP LIST*****\n";
    cout << s->toString() << endl << endl;  // print the skip list

    Entry* op_result;
    op_result = s->find(45);
    if(op_result!=NULL){
        cout << "Search result: " << op_result->toString() << endl;
    }else{
        cout << "Entry not saved.\n";
    }

    op_result = s->find(21);
    if(op_result!=NULL){
        cout << "Search result: " << op_result->toString() << endl;
    }else{
        cout << "Entry not saved.\n";
    }
    
    op_result = s->greaterEntry(21);
    cout << "Greater entry: " << op_result->toString() << endl;

    op_result = s->lessEntry(21);
    cout << "Lesser entry: " << op_result->toString() << endl;

    s->clear();
    while(s->size()<40){
        Entry e;
        e.random();
        s->put(e.getKey(),e.getValue());
    }

    cout << "*****PRINTING SKIP LIST*****\n";
    cout << s->toString() << endl << endl;  // print the skip list
}