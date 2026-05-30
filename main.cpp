#include <iomanip>
#include <iostream>
#include <stack>
#include <fstream>
#include <stdlib.h>
#include <string>

void printMenu();
void removeItem();
using namespace std;

string lsnit[100];

int lsqit[100];

int main() {
    int zeg;

    string txt = "Controle de teste";

    string item;

    string nmditem;

    int qntditem;

    char sorn;
    ofstream arquivo("estoque.txt");

    if (arquivo.is_open()) {
        arquivo << "=============" << endl;
        arquivo << setw(10) << "estoque" << endl;
        arquivo << "=============\n" << endl;
    }


    for (int i = 0; i != 4;) {

        printMenu();

        cin >> zeg;
        if (cin.fail()) {       // "cin, você falhou?"
            cin.clear();        // limpa o estado de erro
            cin.ignore(1000, '\n'); // joga fora tudo que está no buffer
            cout << "Entrada inválida! Digite um número." << endl;
            continue;// volta pro início do loop
        }

        if (zeg == 4) {
            i = zeg;
        }
        if (zeg >= 1 && zeg <= 4) {
            switch (zeg) {
                case 1:
                    cout << "Digite o nome do item:";
                    cin >> nmditem;
                    cout << "Digite a quantidade de items:";
                    cin >> qntditem;
                    cout << "Item adicionado com sucesso!" << endl;
                    break;
                case 2:
                    removeItem();
                    break;
            }
        }else {
            cout <<"erro!" << endl;;
        }

        lsnit[i] = nmditem;
        lsqit[i] = qntditem;
        cout << "Deseja continuar o programa: s/n?" << endl;



        if (arquivo.is_open()) {
            arquivo << lsnit[i];
            arquivo << endl;
            arquivo << lsqit[i];
            arquivo << endl;
        } else {
            cout << "Erro na abertura do arquivo.";
        }

        cin >> sorn;
        if (sorn == 'n') {
            cout << "Obrigado por usar o Controle de Estoques! Até a próxima.";
            break;
        }
    }

    arquivo.close();


    return 0;
}

void printMenu() {
    cout << "==============================" << endl;
    cout << setw(15) << "Controle " << "de teste" << endl;
    cout << "==============================" << endl;

    cout << "Selecione uma opção:\n"
            "1. Adicionar item\n"
            "2. Remover item\n"
            "3. Listar estoque\n"
            "4. Sair\n"
            "Opção:";
}
void removeItem() {
    string name;
    int qnt;
    char option;
    for (int i = 0; i != 4;) {
        cout << "Digite nome do item que você quer remover:" << endl;
        cin >> name;
        cout <<"Digite a quantidade a ser removida:" << endl;
        cin >> qnt;
        if (lsnit[i] == name) {
            if (lsqit[i] - qnt == 0) {
                lsnit[i] = " ";
                cout << "Item removido com sucesso!" << endl;
            }
            if ((lsqit[i] - qnt) < 1) {
                cout << "Estoque insuficiente. Quantidade disponivel: " <<lsnit[i] << endl;
            }
            lsqit[i] -= qnt;
            cout <<"Quantidade atualizada com sucesso!" << endl;
        }else
            cout <<"Item não encontrado." << endl;
        cout << "Quer remover mais algum item s/n?" << endl;
        cin >> option;
        if (option == 'n') {
            break;
        }
    }

}