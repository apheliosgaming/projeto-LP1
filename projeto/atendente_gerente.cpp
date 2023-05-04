#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string> 

using namespace std;

struct Medico{
    string funcao;
};

// Cria um mapa para armazenar os médicos e suas funções
map<string, Medico> medicos; // nome do médico é uma string separada

void carregarValoresMedicos(){
  fstream arquivoCriar;

  //cria o arquivo medicos.txt caso não exista
  arquivoCriar.open("medicos.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  //abre o arquivo medicos.txt para leitura
  fstream arquivoler;
  arquivoler.open("medicos.txt", ios::in);
  string linha;
  vector<string> vetor;
  
  //Lê todas as linhas do arquivo e salva cada linha em um vector
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }
  arquivoler.close(); //fecha o arquivo lido.
  

  //Transfere as linhas do vector para dentro do map
  for(int i = 0; i< vetor.size(); i+=2){
     
    string nomes = vetor[i];

    medicos[nomes].funcao = vetor[i+1];
  }
}

void cadastrarMedico(string nomes, string funcao){
  fstream arquivo;
  arquivo.open("medicos.txt", ios::out | ios::app);
  arquivo << nomes << endl;
  medicos[nomes].funcao = funcao;
  arquivo << funcao << endl;

  arquivo.close(); // Fecha o arquivo

  cout << "Médico cadastrado ( ^_^)／  \n";
}

void mudaFuncao(string nome, string newfunc){
    // verifica se o médico existe no mapa
    int c = 0; // contador
    for(auto i : medicos){
        if(i.first == nome){
            medicos[nome].funcao = newfunc;
            c++;
            cout << "Especialidade alterada com sucesso\n";
        }
    }
        
    if(c == 0){
        cout << "Médico não encontrado no arquivo." << endl;
        }
    }
    
void atualizarArquivoMed(){
  fstream arquivo;
  arquivo.open("medicos.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(auto i : medicos){
    arquivo << i.first << endl;
    arquivo << i.second.funcao << endl;
  }
}

void listaMedicos(){
  cout << "\n (･ω･)☞ ####  Lista de Médicos e suas especialidades   ####\n\n";
  cout << "*************************\n";
  //printa o nome e a função do médio
  for(auto i : medicos){
    cout << "Nome: "<< i.first << endl;
    cout << "Função: "<< i.second.funcao << endl;
    cout << "*************************\n";
}
}

void listaFuncoes(){
  cout << "\n (･ω･)☞ ####  Lista de especialidades disponíveis no Hospital   ####\n\n";
  cout << "*************************\n";
  
  for(auto i : medicos){
    int c = 0; //contador

    cout << "Especialidade: "<< i.second.funcao << endl;
    
    //verifica se uma função é repetida no arquivo;
    for(auto a : medicos){
        if(i.second.funcao == a.second.funcao){
            c++;
        }
    }
    cout << "Quantidade de profissionais: " << c << endl;
    cout << "*************************\n";
  }
}

void DemiteMed(string nome){
    for(auto i : medicos){
        if(i.first == nome){
            medicos.erase(nome); //apaga o nome do médico do arquivo
            atualizarArquivoMed();
            cout << "Médico excluído do hospital >:)\n" << endl;
            return;
    }
    }
    cout << "Médico não existe no arquivo\n";
}
