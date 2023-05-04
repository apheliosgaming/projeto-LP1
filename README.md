# projeto-LP1

Projeto D da disciplina LP1.

O projeto desse repositório se caracteriza em criar um sistema simplificado de visualização de médicos e suas especialidades, assim como suas consultas agendadas. No sistema, o usuário pode acessar dois tipos de perfis diferentes, sendo eles o do Gerente e o do Atendente. Segue abaixo a diferença entre os perfis:

I. Atendente:
  As funções referentes ao trabalho do atendente se encontram em "atendente_gerente.cpp" e "agenda.cpp".
  Esse perfil é limitado e não pode alterar nada do arquivo designado aos médicos, o "medicos.txt". Apesar disso, o atendente, diferente do Gerente, pode alterar os dados do arquivo "agenda.txt" com a função de adicionar agendamentos para o médico. Segue as opções de acesso disponíveis para o atendente:
  
  1.	Listar todos os médicos por nome e suas respectivas funções;
  2.	Listar todas as especialidades disponíveis e a quantidade de profissionais de cada uma;
  3.	Agendar horário para um determinado médico (nome e dia/horário);
  4.	Ver todos os agendamentos de uma determinado médico (pesquisar pelo nome);
  5.	Sair do sistema;

II. Gerente:
  Todas as funções do trabalho do gerente se encontram em "atendente_gerente.cpp" exceto a de consultar agendamentos que se encontra em "agenda.cpp".
  Para acessar esse perfil é necessárrio que o usuário insira uma senha no sistema, essa a qual é "senha". Para o Gerente, é ppossível mudar dados do arquivo "medicos.txt", tendo a possibilidade de adicionar novos médicos, excluir médicos e mudar sua especialidade. Já quando se refere ao arquivo "agenda.txt", o gerente pode apenas visualizar, visto que o trabalho de agendar consultas é do atendente. Segue abaixo as opções disponíveis no sistema para o gerente:
  1.	Listar todos os médicos por nome e suas respectivas funções;
  2.	Listar todas as especialidades disponíveis e a quantidade de profissionais de cada uma;
  3.	Adicionar um novo médico;
  4.	Ver todos os agendamentos de uma determinado médico (pesquisar pelo nome);
  5.	Alterar a especialidade de um médico;
  6.	Excluir um médico;
  7.	Sair do sistema;

