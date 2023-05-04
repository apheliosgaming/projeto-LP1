#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string> 
#include "atendente_gerente.hpp"

using namespace std;

struct Agenda{
    string paciente;
    string diames;
    string horario;
};

map<string, Agenda> agenda;

void carregarAgenda(){
  fstream arquivoCriar;
  arquivoCriar.open("agenda.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  fstream arquivoler;
  arquivoler.open("agenda.txt", ios::in);
  string linha;
  vector<string> vetor;
  
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }

  arquivoler.close();
  
  for(int i = 0; i< vetor.size(); i+=4){
    string nomes = vetor[i];
    agenda[nomes].paciente = vetor[i+1];
    agenda[nomes].diames = vetor[i+2];
    agenda[nomes].horario = vetor[i+3];
  }
}

void cadastrarAgenda(string nomes, string paciente, string diames, string horario){
  fstream arquivo;
  
  arquivo.open("agenda.txt", ios::out | ios::app);
  arquivo << nomes << endl;
  agenda[nomes].paciente = paciente;
  arquivo << paciente << endl;
  agenda[nomes].diames = diames;
  arquivo << diames << endl;
  agenda[nomes].horario = horario;
  arquivo << horario << endl;

  arquivo.close(); // Fecha o arquivo

  cout << "Consulta agendada ᕦ(ò_ó)ᕤ  \n";
}

void MedicoAgenda(){
    
    cout << "Médicos disponíveis:\n" << endl;
    listaMedicos();
    
    string medico;
    cout << "Deseja conferir a agenda de qual médico?\n";
    getline(cin >> ws, medico);
    int c = 0;
    
    for(auto i : agenda){
    if(i.first == medico){
        c++;
        cout << "\n####  Abrindo agenda do médico..   ####\n";
        cout << "\n Agenda de " << medico << " ヽ(´▽｀)/ \n" << endl;
            cout << "\n*************************\n";
            cout << "Nome do médico: " << i.first;
            cout << "\nNome do paciente: " << i.second.paciente;
            cout << "\nDia e mês da consulta: " << i.second.diames;
            cout << "\nHorário: " << i.second.horario << endl;
            cout << "*************************\n";
            cout << endl;
    }
  }
  if(c ==0){
      cout << "Médico não encontrado ou não há consultas.\n";
  }
}

