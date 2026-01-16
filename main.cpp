#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <string>

#include "BitWriter.h"
#include "huffman_engine.h"

using namespace std;

string lerArquivo(string caminho) {
    ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        return "";
    }

    string conteudo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
    return conteudo;
}

int main() {
    string text;
    string nomeSaida = "saida_padrao.huff";
    int opcao;

    cout << "=== COMPRESSOR DE HUFFMAN ===\n";
    cout << "1. Digitar mensagem manualmente\n";
    cout << "2. Ler arquivo de texto (.txt)\n";
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    cin.ignore();
    if (opcao == 1) {
        cout << "\nDigite a mensagem: ";
        getline(cin, text);
    }
    else if (opcao == 2) {
        string caminho;
        cout << "\nDigite o nome do arquivo (ex: livro.txt), o arquivo deve estar na mesma pasta do projeto: ";
        getline(cin, caminho);

        text = lerArquivo(caminho);

        if (text.empty()) {
            cerr << "ERRO: Arquivo nao encontrado ou vazio!" << endl;
            cerr << "Dica: Verifique se o arquivo esta na mesma pasta do executavel." << endl;
            return 1;
        }

        size_t ponto = caminho.find_last_of(".");
        if (ponto != string::npos) {
            nomeSaida = caminho.substr(0, ponto) + ".huff";
        } else {
            nomeSaida = caminho + ".huff";
        }

        cout << "Lido com sucesso! Tamanho original: " << text.size() << " bytes." << endl;
    }
    else {
        cout << "Opcao invalida!" << endl;
        return 1;
    }

    map<char, int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    ofstream arquivo(nomeSaida, ios::binary);
    if (!arquivo) {
        cerr << "Erro ao criar arquivo de saida!" << endl;
        return 1;
    }

    BitWriter writer(arquivo);

    cout << "\nComprimindo para '" << nomeSaida << "'..." << endl;
    for (char c : text) {
        string code = huffmanCode[c];
        writer.writeSequence(code);
    }

    writer.flush();
    arquivo.close();

    ifstream arqCheck(nomeSaida, ios::binary | ios::ate);
    long tamanhoComprimido = arqCheck.tellg();
    long tamanhoOriginal = text.length();

    cout << "\n--- Relatorio Final ---" << endl;
    cout << "Arquivo Original: " << tamanhoOriginal << " bytes" << endl;
    cout << "Arquivo Comprimido (.huff): " << tamanhoComprimido << " bytes" << endl;

    if (tamanhoOriginal > 0) {
        float economia = 100.0 - ((float)tamanhoComprimido / tamanhoOriginal * 100.0);
        cout << "Economia de espaco: " << economia << "%" << endl;
    }

    if(tamanhoComprimido < tamanhoOriginal) {
        cout << "SUCESSO: Compressao realizada!" << endl;
    } else {
        cout << "NOTA: Arquivo aumentou ou ficou igual (comum em textos muito pequenos)." << endl;
    }

    deleteTree(root);
    return 0;
}
