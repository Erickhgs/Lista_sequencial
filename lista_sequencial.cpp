#include <iostream>

using namespace std;

// Classe que implementa uma lista sequencial estática
class lista_sequencial {
private:
    static const int capacidade = 4; 
    int lista[capacidade]; 
    int tamanho; 

public:
    // Construtor que inicializa o tamanho da lista como 0
    lista_sequencial() : tamanho(0) {}

    // Verifica se a lista está vazia
    bool vazia() {
        return tamanho == 0;
    }

    // Verifica se a lista está cheia
    bool cheia() {
        return tamanho == capacidade;
    }

    // Retorna o tamanho atual da lista
    int tamanho_lista() {
        return tamanho;
    }

    // Retorna o elemento em uma posição específica
    int elemento(int posicao) {
        if (posicao > tamanho || posicao <= 0) {
            cout << "Posição inválida" << endl;
            return -1;
        }
        return lista[posicao - 1];
    }

    // Modifica o valor de um elemento em uma posição específica
    void modificar(int posicao, int valor) {
        if (posicao > tamanho || posicao <= 0) {
            cout << "Posição inválida" << endl;
            return;
        }
        lista[posicao - 1] = valor;
    }

    // Insere um elemento em uma posição específica
    void inserir(int posicao, int valor) {
        if (posicao > tamanho + 1 || posicao <= 0) {
            cout << "Posição inválida" << endl;
            return;
        }
        if (cheia()) {
            cout << "Lista cheia! Não é possível inserir mais elementos." << endl;
            return;
        }

        // Desloca os elementos para a direita para abrir espaço
        for (int i = tamanho; i >= posicao; i--) {
            lista[i] = lista[i - 1];
        }

        lista[posicao - 1] = valor;
        tamanho++;
    }

    // Remove um elemento de uma posição específica
    void retirar(int posicao) {
        if (posicao > tamanho + 1 || posicao <= 0) {
            cout << "Posição inválida" << endl;
            return;
        }
        // Desloca os elementos para a esquerda para preencher o espaço
        for (int i = posicao - 1; i < tamanho; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }

    // Imprime todos os elementos da lista
    void imprimir() {
        for (int i = 0; i < tamanho; ++i) {
            cout << lista[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    lista_sequencial lista;

    // Testes básicos da lista:
    // Inserçao dos elementos
    lista.inserir(1, 2);
    lista.inserir(2, 4);
    lista.inserir(3, 6);
    lista.imprimir();


    // Modifico o elemento da posição 3
    lista.modificar(3, 60);
    lista.imprimir();

    // Retiro o elemento da posição 1
    lista.retirar(1);
    lista.imprimir();

    // Insiro um novo elemento na posição 1
    lista.inserir(1, 5);
    lista.imprimir();

    // Insiro novamente um elemento na posição 1
    lista.inserir(1, 10);
    lista.imprimir();

    // Tento inserir novamente um elemento na posição 1
    lista.inserir(1, 20);
    lista.imprimir();

    // Tento inserir um elemento em uma posiçao fora da lista
    lista.inserir(6, 20);
    lista.imprimir();

    cout << "Tamanho da lista: " << lista.tamanho_lista() << endl;
    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;

    return 0;
}