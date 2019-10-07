#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// classe No
class No
{
private:
	string nome;
    string sexo;
	No* prox;
public:
	No(string nome, string sexo) // construtor
	{
		this->nome = nome;
		this->sexo = sexo;
		this->prox = NULL;
	}

	string getNome() // obtém o nome
	{
		return nome;
	}

	string getSexo() // obtém o sexo
	{
		return sexo;
	}

	No* obterProx() // obtém o próximo No
	{
		return prox;
	}

	void setProx(No* p) // seta o próximo No
	{
		prox = p;
	}
};

// classe Lista
class ListaMacho
{
private:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento

public:
	ListaMacho()
	{
		// se não passar elemento, então cabeca e cauda são NULL
		cabeca = NULL;
		cauda = NULL;
	}

	ListaMacho(string nome, string sexo)
	{
		// se passar elemento, então cria novo No
		cabeca = new No(nome, sexo);
		cauda = cabeca;
	}

	void mostrar() // mostra todos os elementos da lista
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a lista
			{
				cout << "Nome: " << c->getNome() << endl;
				cout << "Sexo: " << c->getSexo() << endl << endl;
				c = c->obterProx();
			}
			cout << endl;
		}
	}

	bool vazia() // verifica se a lista está vazia
	{
		return (cabeca == NULL);
	}

	// insere no início (semelhante a push_front da list)
	void inserir_inicio(string nome, string sexo)
	{
		No* novo_no = new No(nome, sexo);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			novo_no->setProx(cabeca);
			cabeca = novo_no;
		}
	}

	// retorna o tamanho da lista
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = cabeca;
		int tam = 0;
		
		// percorre a lista
		do
		{
			c = c->obterProx();
			tam++;
		}
		while(c);
		
		return tam;
	}

	// verifica se um elemento existe na lista
	int posicao(string nome, string sexo)
	{
		No* c = cabeca;
		int i = 0;
		
		while(c)
		{
			if(c->getNome() == nome && c->getSexo() == sexo)
				return i;
			c = c->obterProx();
			i++;
		}
		return -1;
	}

	// remove da lista, remoção do final (semelhante a pop_back da list)
	void remover()
	{
		if(!vazia())
		{
			// se houver só 1 elemento
			if(cabeca->obterProx() == NULL){
				cabeca = NULL;
			}
			else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
				cabeca->setProx(NULL);
			else // > 2 elementos
			{
				No* ant_ant = cabeca;
				No* ant = cabeca->obterProx();
				No* corrente = cabeca->obterProx()->obterProx();

				while(corrente)
				{
					No* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->obterProx();
				}
				delete ant_ant->obterProx(); // libera memória
				ant_ant->setProx(NULL); // seta o prox como NULL
				cauda = ant_ant; // atualiza a cauda
			}
		}
	}
};

#endif // LISTA_ENC_H_INCLUDED