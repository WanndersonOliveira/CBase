#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*Issue #1 Implementar deleção completa da tabela OK*/
/*Issue #2 Implementar atualização da tabela */
/*Issue #3 Implementar deleção de linha */

bool delReg(){
	ofstream f;
	
	f.open("Pessoa.dat", ios::out);
	
	if(!f){
		return false;
	}
	
	return true;
}


int getMaxId(){
  	int id;
	
	ifstream file;
	
	file.open("Pessoa.dat", ios::in);
	
	if(!file){
		return 1;
	}
	
	while(!file.eof()){
		file >> id;
	}
	
	file.close();
	return id;
}


void leitura(){
	int id, idade;
	string nome;
	char sexo;
	
	ifstream file;
	
	file.open("Pessoa.dat", ios::in);
	
	if(!file){
		cout << "Banco de dados nao pode ser aberto!";
		abort();
	}
	
	cout << "id\t|nome\t|idade\t|sexo\n";
	
	while(file >> id >> nome >> idade >> sexo){
		cout << id << "\t" << nome << "\t" << idade << "\t" << sexo << "\n";
	}
	
	file.close();
}


int main(int argc, char** argv) {
	string nome;
	char sexo;
	int idade, id;
	
	ofstream file;
	
	file.open("Pessoa.dat", ios::app);
	
	if(!file)
	{
		cout << "Arquivo não pode ser aberto" << endl;
		abort();
	}
	
	
	id = getMaxId();
	
    char choice = 'N';
	
	while(choice == 'N')
	{
		cout << "\n\t\tCadastro\n\n";
		cout << "Digite o seu nome: ";
		getline(cin, nome);
		cout << "\nDigite a sua idade: ";
		cin >> idade;
		cout << "\nDigite o seu sexo (M/F): ";
		cin >> sexo;
		cout << "\n\nDeseja parar? (Y/N)\n";
		cin >> choice;
		choice = toupper(choice);
		
		file << id << " " << nome << " " << idade << " " << sexo << "\n";
		
		id++;
	}
	
	file << flush;
	file.close();
	
	leitura();
	
	system("pause");
	return 0;
}

