#include <iostream>
#include <string>
#include "lista_enc.h"

using namespace std;

int main()
{
	ListaMacho l;
	
	if(l.vazia())
		cout << "Lista vazia!!\n";
	else
		cout << "Lista NAO vazia!!\n";
	
	l.mostrar();
		
	l.inserir_inicio("Zezo", "masculino");
	l.inserir_inicio("Cleonice", "feminino");
	l.inserir_inicio("Matheus", "feminino");
	l.inserir_inicio("Cimara", "Feminino");
	
	l.mostrar();
	
	if(l.vazia())
		cout << "Lista vazia!!\n";
	else
		cout << "Lista NAO vazia!!\n";

	int i = l.posicao("Cleonice", "feminino");
	
	if(i >= 0)
		cout << "\nO elemento existe na lista, posição " << i << endl;
	else
		cout << "\nO elemento NAO existe na lista!!" << endl;
	
	l.remover();
	
	l.mostrar();
	
	cout << "Tamanho da lista: " << l.tamanho() << endl;
	
	return 0;
}