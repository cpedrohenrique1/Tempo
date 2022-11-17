#ifndef TESTATEMPO_H_
#define TESTATEMPO_H_
#include "Tempo.h"

class TestaTempo{
    private:
        Tempo tempo1,tempo2;
    public:
        void menu();
        long long diferencaTempo(Tempo, Tempo);
};

long long TestaTempo::diferencaTempo(Tempo tempo1, Tempo tempo2){
    return abs(tempo1.converteTempoSegundos() - tempo2.converteTempoSegundos());
}

void TestaTempo::menu(){
    int entrada[3];
    int flag;
    do{
        try{
            cout << "Digite as horas para o tempo 1: ";
            cin >> entrada[0];
            cout << "Digite os minutos para o tempo 1: ";
            cin >> entrada[1];
            cout << "Digite os segundos para o tempo 1: ";
            cin >> entrada[2];
            tempo1.setTempo(entrada[0],entrada[1],entrada[2]);
            
            cout << "Digite as horas para o tempo 2: ";
            cin >> entrada[0];
            cout << "Digite os minutos para o tempo 2: ";
            cin >> entrada[1];
            cout << "Digite os segundos para o tempo 2: ";
            cin >> entrada[2];
            tempo2.setTempo(entrada[0],entrada[1],entrada[2]);

            cout << "Os tempos digitados foram: " << endl;
            cout << "Tempo 1: ";
            tempo1.getTempo();
            cout << endl;
            cout << "Tempo 2: ";
            tempo2.getTempo();
            cout << endl;

            cout << "O total de segundos foram: " << endl;
            cout << "Tempo 1: " << tempo1.converteTempoSegundos() << endl;
            cout << "Tempo 2: " << tempo2.converteTempoSegundos() << endl;

            cout << "A diferenca de tempo foi: \n";
            tempo1.converteSegundosTempo(diferencaTempo(tempo1, tempo2)).getTempo();
            cout << endl;
        }
        catch(string erro){
            cout << "Erro: " << erro << endl;
        }
        cout << "Insira 0 para encerrar\n";
        cin >> flag;
    }while (flag != 0);
}

#endif