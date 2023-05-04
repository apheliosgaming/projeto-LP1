#include <iostream>
#include "atendente_gerente.hpp" //importa o arquivo de cabeçalho do atendente_gerente
#include "agenda.hpp" //importa o arquivo do cabeçalho da agenda

using namespace std;

int main(){
    
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout << "\n Hospital EX BBERS  [::+::]  \n";
    cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    
    
    int opcao;

    cout << "\nEscolha qual o seu tipo de usuário.\n";
    cout << "1 - Atendente.\n";
    cout << "2 - Gerente.\n";
    cout << "3 - Encerrar programa.\n";
    cout << "-> :";

    cin >> opcao;
    
    // Lê o arquivo medicos.txt e carrega os dados no sistema
    carregarValoresMedicos();
    // Lê o arquivo agenda.txt e carrega os dados no sistema
    carregarAgenda();
    

// Menu de opções para o perfil Atendente

    if(opcao == 1){
        while(true){
            int buscaAt;

            cout << "\n#####   Perfil Atendente   #####\n\n";
            cout << "1 - Listar todos os médicos por nome e suas respectivas funções\n";
            cout << "2 - Listar todas as especialidades disponíveis e a quantidade de profissionais de cada uma\n";
            cout << "3 - Agendar horário para um determinado médico (nome e dia/horário)\n";
            cout << "4 - Ver todos os agendamentos de um determinado médico (pesquisar pelo nome)\n";
            cout << "5 - Sair.\n";

        cin >> buscaAt;

        if(buscaAt == 1){
            listaMedicos(); //função em atendente_gerente.cpp
        }
        else if(buscaAt == 2){
            listaFuncoes(); //função em atendente_gerente.cpp
        }
        
        else if(buscaAt == 3){
            string paciente, diames, horario, medico;
            
            cout << "Quer agendar consulta para qual médico do hospital?\n";
            getline(cin >> ws, medico);
            cout << "Qual o nome do paciente?\n";
            getline(cin >> ws, paciente);
            cout << "Qual o dia e o mês da consulta?\n";
            getline(cin >> ws, diames);
            cout << "Qual o horário da consulta\n";
            getline(cin >> ws, horario);
            
            cadastrarAgenda(medico, paciente, diames, horario); //função em agenda.cpp
        }
        else if(buscaAt == 4){
    
            MedicoAgenda(); //função em agenda.cpp
        }
        
        else{
            cout << "Opção de saída ou inválida. Encerrando o programa...\n";
            break;
        }
        }
    }

// Menu de opções para o perfil Gerente

    else if(opcao == 2){
        string senha = "senha"; // senha para acesso do perfil do gerente
        
        string tentativaSenha;
        cout << "Senha:\n";
        cin >> tentativaSenha;
        if(tentativaSenha == senha){
            while(true){
            int buscaGe;

            cout << "\n#####   Perfil Gerente   #####\n\n";
            cout << "1 - Listar todos os médicos por nome e suas respectivas funções\n";
            cout << "2 - Listar todas as especialidades disponíveis e a quantidade de profissionais de cada uma\n";
            cout << "3 - Adicionar um novo médico\n";
            cout << "4 - Ver todos os agendamentos de um determinado médico (pesquisar pelo nome)\n";
            cout << "5 - Alterar a especialidade de um médico\n";
            cout << "6 - Excluir um médico\n";
            cout << "7 - Sair.\n";

            cin >> buscaGe;
            
            if(buscaGe == 1){
                listaMedicos(); //função em atendente_gerente.cpp
            }
            else if(buscaGe == 2){
                listaFuncoes(); //função em atendente_gerente.cpp
            }
            else if(buscaGe == 3){
                string nome;
                string funcao;
                cout << "Digite o nome e a especialidade do médico a ser adicionado\n";
                
                getline(cin >> ws, nome); //lê a string incluindo os espaços em branco
                getline(cin >> ws, funcao);
                
                cadastrarMedico(nome, funcao); //função em atendente_gerente.cpp
            }
            else if(buscaGe == 4){
                
                MedicoAgenda(); //função em agenda.cpp
               
            }
            else if(buscaGe == 5){
                string nome;
                string newfunc;
                cout << "Digite o nome do médico a mudar especialidas: \n";
                getline(cin >> ws, nome); //lê a string incluindo os espaços em branco
                cout << "Digite a nova função\n";
                getline(cin >> ws, newfunc);
                
                mudaFuncao(nome, newfunc); //função em atendente_gerente.cpp
            }
            else if(buscaGe == 6){
                string NomeMed;
                
                cout << "Qual médico você deseja excluir do hospital?\n";
                getline(cin >> ws, NomeMed); //lê a string incluindo os espaços em branco
                
                DemiteMed(NomeMed); //função em atendente_gerente.cpp
                
            }
            
            else if(buscaGe == 7){
                cout << "Encerrando o programa\n";
                break;
            }
            else{
                cout << "Por favor, digite um número válido\n";
            }

    }
        }
        else{
            cout << "Senha incorreta!\n";
        }
    }

    else{
        cout << "Encerrando o programa...\n";
    }

    return 0;

}