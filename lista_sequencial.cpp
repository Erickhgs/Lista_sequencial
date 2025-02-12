#include <iostream>
#include <vector>

using namespace std;

class lista_sequencial{
    private:
    vector <int> lista;

    public:
    lista_sequencial() {}

    bool vazia(){
        return lista.empty();
    }

    bool cheia(){

    }

    int tamanho(){
        return lista.size();
    }

    int elemento(int posicao){
        int dado;
        if( (posicao > lista.size()) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return -1;
        }
        dado = lista[posicao-1];
        return dado;
    }

    void modificar(int posicao, int valor){
         if( (posicao > lista.size()) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return;
        }
        lista[posicao-1] = valor;
    }

    void inserir(int posicao, int valor){
        if( (posicao > lista.size() + 1 ) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return;
        }
        lista.insert(lista.begin() + posicao -1, valor);
    }

    void retirar(int posicao){
        if( (posicao > lista.size() + 1 ) || posicao <= 0){
            cout << "Posição inválida"<< endl;
            return;
        }
        lista.erase(lista.begin() + posicao -1);
    }

    void imprimir(){
        for (int i : lista) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    lista_sequencial lista;

    lista.inserir(1, 2);
    lista.inserir(2, 4);
    lista.inserir(3, 6);
    lista.inserir(4, 8);
    lista.imprimir();

    lista.modificar(3, 60);
    lista.imprimir();

    lista.retirar(2);
    lista.imprimir();

    cout << "Tamanho da lista: " << lista.tamanho() << endl;
    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;

    return 0;
}