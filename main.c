#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 100

// Estrutura para representar um registro simples
typedef struct {
    int id;
    char nome[50];
    int ativo; // 1 para ativo, 0 para deletado
} Registro;

Registro tabela[MAX_REGISTROS];
int registroAtual = 0;

// Função para executar o comando USE (abre uma tabela fictícia)
void comandoUSE() {
    printf("Tabela aberta.\n");
    registroAtual = 0;
}

// Função para executar o comando LIST (exibe todos os registros ativos)
void comandoLIST() {
    printf("Listando registros:\n");
    for (int i = 0; i < registroAtual; i++) {
        if (tabela[i].ativo) {
            printf("ID: %d, Nome: %s\n", tabela[i].id, tabela[i].nome);
        }
    }
}

// Função para executar o comando APPEND (adiciona um novo registro)
void comandoAPPEND(char nome[]) {
    if (registroAtual < MAX_REGISTROS) {
        tabela[registroAtual].id = registroAtual + 1;
        strcpy(tabela[registroAtual].nome, nome);
        tabela[registroAtual].ativo = 1;
        registroAtual++;
        printf("Registro adicionado: %s\n", nome);
    } else {
        printf("Tabela cheia.\n");
    }
}

// Função para executar o comando REPLACE (atualiza o nome de um registro)
void comandoREPLACE(int id, char nome[]) {
    if (id > 0 && id <= registroAtual && tabela[id - 1].ativo) {
        strcpy(tabela[id - 1].nome, nome);
        printf("Registro atualizado: ID %d, Nome %s\n", id, nome);
    } else {
        printf("Registro não encontrado.\n");
    }
}

// Função para executar o comando DELETE (marca um registro como excluído)
void comandoDELETE(int id) {
    if (id > 0 && id <= registroAtual) {
        tabela[id - 1].ativo = 0;
        printf("Registro ID %d deletado.\n", id);
    } else {
        printf("Registro não encontrado.\n");
    }
}

// Função para interpretar e executar comandos
void interpretarComando(char comando[]) {
    char comandoPrincipal[10];
    sscanf(comando, "%s", comandoPrincipal);

    if (strcmp(comandoPrincipal, "USE") == 0) {
        comandoUSE();
    } else if (strcmp(comandoPrincipal, "LIST") == 0) {
        comandoLIST();
    } else if (strcmp(comandoPrincipal, "APPEND") == 0) {
        char nome[50];
        sscanf(comando, "%*s %s", nome);
        comandoAPPEND(nome);
    } else if (strcmp(comandoPrincipal, "REPLACE") == 0) {
        int id;
        char nome[50];
        sscanf(comando, "%*s %d %s", &id, nome);
        comandoREPLACE(id, nome);
    } else if (strcmp(comandoPrincipal, "DELETE") == 0) {
        int id;
        sscanf(comando, "%*s %d", &id);
        comandoDELETE(id);
    } else {
        printf("Comando não reconhecido.\n");
    }
}

int main() {
    char comando[100];
    printf("Digite um comando DBASE: ");
    while (fgets(comando, sizeof(comando), stdin)) {
        interpretarComando(comando);
        printf("Digite um comando DBASE: ");
    }
    return 0;
}
