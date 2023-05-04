#ifndef _ATENDENTE_HPP
#define _ATENDENTE_HPP

void carregarValoresMedicos();
void listaMedicos();
void listaFuncoes();
void cadastrarMedico(std::string nomes, std::string funcao);
void mudaFuncao(std::string nome, std::string newfunc);
void DemiteMed(std::string nome);
void atualizarArquivoMed();

#endif