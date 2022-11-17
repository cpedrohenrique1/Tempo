#ifndef TESTATEMPO_H_
#define TESTATEMPO_H_
#include "Tempo.h"

class TestaTempo{
    private:
        Tempo tempo1,tempo2;
    public:
        void menu();
};

void TestaTempo::menu(){
    cout << tempo1.converteTempoSegundos() << endl;
}

#endif