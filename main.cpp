#include <iomanip>
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main() {
    int zeg;

    string txt = "Controle de teste";

    string item;

    string lsnit[100];

    int lsqit[100];

    string nmditem;

    int qntditem;

    char sorn;
    ofstream arquivo("estoque.txt");

    if (arquivo.is_open()) {
        arquivo << "=============" << endl;
        arquivo << setw(10) << "estoque" << endl;
        arquivo << "=============\n" << endl;
    }

    for (int i = 0; i != 4; i++) {
        cout << "==============================" << endl;
        cout << setw(15) << "Controle " << "de teste" << endl;
        cout << "==============================" << endl;

        cout << "Selecione uma opção:\n"
                "1. Adicionar item\n"
                "2. Remover item\n"
                "3. Listar estoque\n"
                "4. Sair\n"
                "Opção:";

        cin >> zeg;

        if (zeg == 4) {
            break;
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
                    cout << "Digite o nome do item:";
                    cin >> nmditem;
                    cout << "Digite a quantidade de items:";
                    cin >> qntditem;
                    cout << "Item removido com sucesso!" << endl;
                    break;
            }
            lsnit[i] = nmditem;
            lsqit[i] = qntditem;
            cout << "Deseja continuar o programa: s/n?" << endl;


            if (arquivo.is_open()) {
                arquivo << lsnit[i];
                arquivo << endl;
                arquivo << lsqit[i];
                arquivo << endl;
                cout << "Arquivo criado com sucesso!";
            } else {
                cout << "Erro na abertura do arquivo.";
            }

            cin >> sorn;
            if (sorn == 'n') {
                cout << "Obrigado por usar o Controle de Estoques! Até a próxima.";
                break;
            }
        }
    }

    arquivo.close();


    return 0;
}
