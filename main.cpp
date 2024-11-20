#include "OrderedList.h"
#include "iostream"

typedef char byte;

int main(int argc, byte **argv){
    OrderedList<const byte*> *ls = new OrderedList<const byte*>();
    ls->add("test");
    ls->add("test3");
    ls->add("90");
    std::cout << *ls << "\n";
    return 0;
}