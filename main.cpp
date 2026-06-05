#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <array>

void printMenu();

void removeItem();

void printEstoque();

using namespace std;

int count = 0;

array<string, 100> lsnit;

array<int, 100> lsqit;

int main() {
    char zeg;

    string txt = "Controle de Estoque";

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


    for (int i = 0; i != '4'; i++) {
        printMenu();

        cin >> zeg;
        if (cin.fail()) {
            // "cin, você falhou?"
            cin.clear(); // limpa o estado de erro
            cin.ignore(1000, '\n'); // joga fora tudo que está no "buffer"
            cout << "Entrada inválida! Digite um número." << endl;
            continue; // volta para início do "loop"
        }

        if (zeg == '4') {
            cout << "Obrigado por usar o Controle de Estoques! Até a próxima.";
            break;
        }
        if (zeg >= '1' && zeg <= '4') {
            switch (zeg) {
                case '1':
                    cout << "Digite o nome do item:";
                    cin >> nmditem;
                    cout << "Digite a quantidade de items:";
                    cin >> qntditem;
                    cout << "Item adicionado com sucesso!" << endl;

                    lsnit[i] = nmditem;
                    lsqit[i] = qntditem;
                    break;
                case '2':
                    removeItem();
                    break;
                case '3':
                    printEstoque();
                    break;
            }
        } else {
            cout << "erro!" << endl;;
        }

        cout << "Deseja continuar o programa: s/n?" << endl;

        cin >> sorn;

        count++;
        count -= (count - 1);

        if (sorn == 'n') {
            cout << "Obrigado por usar o Controle de Estoques! Até a próxima.";
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        if (arquivo.is_open()) {
            arquivo << lsnit[i];
            arquivo << endl;
            if (lsqit[i] >= 1) {
                arquivo << lsqit[i];
                arquivo << endl;
            }
        } else {
            cout << "Erro na abertura do arquivo.";
        }
    }
    arquivo.close();

    return 0;
}

void printMenu() {
    cout << "==============================" << endl;
    cout << setw(15) << "Controle " << "de estoque" << endl;
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
    int qntRemovida;
    char option;
    int total;
    bool itemExists = false;


    for (int j = 0; j != 'n'; j++) {

        cout << "Digite nome do item que você quer remover:" << endl;
        cin >> name;

        for (int i = 0; i < 100; i++) {
            if (lsnit[i] == name) {
                itemExists = true;
                cout << "Digite a quantidade a ser removida:" << endl;
                cin >> qntRemovida;

                total = lsqit[i] - qntRemovida;

                if (total >= 1) {
                    lsnit[i] = name;
                    lsqit[i] = total;
                    cout << "Quantidade atualizada com sucesso!" << endl;
                }
                if (lsnit[i] == name && total == 0) {
                    lsqit[i] = 0;
                    cout << "Item removido com sucesso!" << endl;
                }
                if (lsnit[i] == name && total < 0) {
                    cout << "Estoque insuficiente. Quantidade disponivel: " << lsqit[i] << endl;
                }
            }
        }
        if (!itemExists) {
            cout << "Item não encontrado no estoque." << endl;
        }

        cout << "Quer remover mais algum item s/n?" << endl;

        cin >> option;

        if (option == 'n') {
            break;
        }
    }
}
void printEstoque() {
    bool estoqueExists = false;
    cout <<"=============================\n"
         <<setw(8)<<"Estoque Atual\n"
         <<"=============================\n";
    for (int i = 0; i < 100; i++) {
        if (lsnit[i] != "") {
            estoqueExists = true;
            cout << "Nome do item: " << lsnit[i] << endl;
            cout <<"Quantidade: " << lsqit[i] << endl;
        }
    }
    if (!estoqueExists) {
        cout <<"O estoque está vazio." << endl;
    }
}