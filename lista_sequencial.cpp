#include <iostream>


using namespace std;

class lista_sequencial{
    private:
    static const int capacidade = 4;
    int lista[capacidade];
    int tamanho;

    public:
    lista_sequencial() : tamanho(0) {}

    bool vazia(){
        return tamanho == 0;
    }

    bool cheia(){
        return tamanho == capacidade;
    }

    int tamanho_lista(){
        return tamanho;
    }

    int elemento(int posicao){
        int dado;
        if( (posicao > tamanho) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return -1;
        }
        dado = lista[posicao-1];
        return dado;
    }

    void modificar(int posicao, int valor){
         if( (posicao > tamanho) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return;
        }
        lista[posicao-1] = valor;
    }

    void inserir(int posicao, int valor){
        if( (posicao > tamanho + 1 ) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return;
        }
        if (cheia()) {
            cout << "Lista cheia! Não é possível inserir mais elementos." << endl;
            return;
        }

        for(int i = tamanho; i >= posicao; i--){
            lista[i] = lista[i-1];
        }

        lista[posicao - 1] = valor;
        tamanho++;
        
    }

    void retirar(int posicao){
        if( (posicao > tamanho + 1 ) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return;
        }
        for(int i = posicao-1; i < tamanho; i++){
            lista[i] = lista[i+1];
        }
        tamanho--;
    }

    void imprimir(){
        for (int i = 0; i < tamanho; ++i) {
            cout << lista[i] << " ";
        }
        cout << endl;

    }
};

int main(){
    lista_sequencial lista;

    lista.inserir(1, 2);
    lista.inserir(2, 4);
    lista.inserir(3, 6);
    lista.imprimir();

    lista.modificar(3, 60);
    lista.imprimir();

    lista.retirar(1);
    lista.imprimir();

    lista.inserir(1, 5);
    lista.imprimir();

    lista.inserir(1,10);
    lista.imprimir();

    lista.inserir(1,20);
    lista.imprimir();

    lista.inserir(6,20);
    lista.imprimir();

    cout << "Tamanho da lista: " << lista.tamanho_lista() << endl;
    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;

    return 0;
}