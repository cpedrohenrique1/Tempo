#ifndef TEMPO_H_
#define TEMPO_H_
#include <ctime>

class Tempo{
    private:
        int horas, minutos, segundos;
    public:
        Tempo();
        ~Tempo();
        void validaTempo();
        long long converteTempoSegundos();
        Tempo converteSegundosTempo();
        void setTempo(int,int,int);
        int getTempo();
};

Tempo::Tempo(){
    time_t timer;
    struct tm *horariolocal;
    time(&timer);
    horariolocal = localtime(&timer);
    horas = horariolocal->tm_hour;
    minutos = horariolocal->tm_min;
    segundos = horariolocal->tm_sec;
}

Tempo::~Tempo(){
    horas = 0;
    minutos = 0;
    segundos = 0;
}

void Tempo::validaTempo(){
    if(horas<0 || horas>23 || minutos<0 || minutos>59 || segundos<0 || segundos>59){
        throw 0;
    }
}

void Tempo::setTempo(int horas, int minutos, int segundos){
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
    validaTempo();
}

long long Tempo::converteTempoSegundos(){
    return ((horas*3600)+(minutos*60)+segundos);
}

Tempo Tempo::converteSegundosTempo(){
    Tempo tempo;
    tempo.setTempo((segundos/3600), ((segundos%3600)/60), ((segundos%3600)%60));
    return tempo;
}

#endif