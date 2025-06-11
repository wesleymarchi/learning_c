#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CPF 12
#define MAX_NOME 50
#define MAX_TIPO 30
#define MAX_MARCA 30
#define MAX_COR 20
#define MAX_TAMANHO 10
#define MAX_PROVADORES 3

// Estruturas de dados
typedef struct Item {
    int codigo;
    char tipo[MAX_TIPO];
    char marca[MAX_MARCA];
    char cor[MAX_COR];
    char tamanho[MAX_TAMANHO];
    int setor;
    int arara;
    struct Item* prox;
} Item;

typedef struct Arara {
    int numero;
    Item* itens;
    struct Arara* prox;
} Arara;

typedef struct Setor {
    int numero;
    Arara* araras;
    struct Setor* prox;
} Setor;

typedef struct Cliente {
    char cpf[MAX_CPF];
    Item* itensProvando;
    struct Cliente* prox;
} Cliente;

typedef struct Provador {
    int ocupado;
    char tipo; // 'M' para masculino, 'F' para feminino
    Cliente* cliente;
} Provador;

typedef struct FilaEspera {
    Cliente* inicio;
    Cliente* fim;
} FilaEspera;

typedef struct Loja {
    Setor* setores;
    Provador provadoresM[MAX_PROVADORES];
    Provador provadoresF[MAX_PROVADORES];
    FilaEspera filaM;
    FilaEspera filaF;
} Loja;

// Funções auxiliares
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char* str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = 0; // Remove \n
}

void inicializarLoja(Loja* loja) {
    loja->setores = NULL;
    for (int i = 0; i < MAX_PROVADORES; i++) {
        loja->provadoresM[i].ocupado = 0;
        loja->provadoresM[i].tipo = 'M';
        loja->provadoresM[i].cliente = NULL;
        loja->provadoresF[i].ocupado = 0;
        loja->provadoresF[i].tipo = 'F';
        loja->provadoresF[i].cliente = NULL;
    }
    loja->filaM.inicio = loja->filaM.fim = NULL;
    loja->filaF.inicio = loja->filaF.fim = NULL;
}

void salvarBinario(Loja* loja, const char* arquivo) {
    FILE* fp = fopen(arquivo, "wb");
    if (!fp) {
        printf("Erro ao salvar arquivo binário\n");
        return;
    }

    Setor* setor = loja->setores;
    while (setor) {
        fwrite(&setor->numero, sizeof(int), 1, fp);
        Arara* arara = setor->araras;
        while (arara) {
            fwrite(&arara->numero, sizeof(int), 1, fp);
            Item* item = arara->itens;
            while (item) {
                fwrite(item, sizeof(Item), 1, fp);
                item = item->prox;
            }
            int fim = -1;
            fwrite(&fim, sizeof(int), 1, fp); // Marcador de fim de arara
            arara = arara->prox;
        }
        int fim = -1;
        fwrite(&fim, sizeof(int), 1, fp); // Marcador de fim de setor
        setor = setor->prox;
    }
    fclose(fp);
}

// 1. Carregar arquivo de inicialização
void carregarArquivo(Loja* loja, const char* arquivo) {
    FILE* fp = fopen(arquivo, "r");
    if (!fp) {
        printf("Erro ao abrir arquivo %s\n", arquivo);
        return;
    }

    inicializarLoja(loja);

    char linha[256];
    Setor* setorAtual = NULL;
    Arara* araraAtual = NULL;

    while (fgets(linha, sizeof(linha), fp)) {
        linha[strcspn(linha, "\n")] = 0;
        if (linha[0] == 'S') {
            Setor* novoSetor = (Setor*)malloc(sizeof(Setor));
            sscanf(linha, "S%d", &novoSetor->numero);
            novoSetor->araras = NULL;
            novoSetor->prox = loja->setores;
            loja->setores = novoSetor;
            setorAtual = novoSetor;
        }
        else if (linha[0] == 'A') {
            if (!setorAtual) continue;
            Arara* novaArara = (Arara*)malloc(sizeof(Arara));
            sscanf(linha, "A%d", &novaArara->numero);
            novaArara->itens = NULL;
            novaArara->prox = setorAtual->araras;
            setorAtual->araras = novaArara;
            araraAtual = novaArara;
        }
        else {
            if (!araraAtual) continue;
            Item* novoItem = (Item*)malloc(sizeof(Item));
            sscanf(linha, "%d, %[^,], %[^,], %[^,], %s",
                   &novoItem->codigo, novoItem->tipo, novoItem->marca,
                   novoItem->cor, novoItem->tamanho);
            novoItem->setor = setorAtual->numero;
            novoItem->arara = araraAtual->numero;
            novoItem->prox = araraAtual->itens;
            araraAtual->itens = novoItem;
        }
    }
    fclose(fp);
    salvarBinario(loja, "estoque.bin");
}

// 2. Inserir item de vestuário
void inserirItem(Loja* loja, int codigo, char* tipo, char* marca, char* cor, char* tamanho, int setorNum, int araraNum) {
    Setor* setor = loja->setores;
    while (setor && setor->numero != setorNum) setor = setor->prox;
    if (!setor) {
        setor = (Setor*)malloc(sizeof(Setor));
        setor->numero = setorNum;
        setor->araras = NULL;
        setor->prox = loja->setores;
        loja->setores = setor;
    }

    Arara* arara = setor->araras;
    while (arara && arara->numero != araraNum) arara = arara->prox;
    if (!arara) {
        arara = (Arara*)malloc(sizeof(Arara));
        arara->numero = araraNum;
        arara->itens = NULL;
        arara->prox = setor->araras;
        setor->araras = arara;
    }

    Item* novoItem = (Item*)malloc(sizeof(Item));
    novoItem->codigo = codigo;
    strcpy(novoItem->tipo, tipo);
    strcpy(novoItem->marca, marca);
    strcpy(novoItem->cor, cor);
    strcpy(novoItem->tamanho, tamanho);
    novoItem->setor = setorNum;
    novoItem->arara = araraNum;
    novoItem->prox = arara->itens;
    arara->itens = novoItem;

    salvarBinario(loja, "estoque.bin");
}

// 3. Retirar item
void retirarItem(Loja* loja, int codigo) {
    Setor* setor = loja->setores;
    while (setor) {
        Arara* arara = setor->araras;
        while (arara) {
            Item* item = arara->itens;
            Item* anterior = NULL;
            while (item) {
                if (item->codigo == codigo) {
                    if (anterior) anterior->prox = item->prox;
                    else arara->itens = item->prox;
                    free(item);
                    salvarBinario(loja, "estoque.bin");
                    printf("Item %d retirado com sucesso\n", codigo);
                    return;
                }
                anterior = item;
                item = item->prox;
            }
            arara = arara->prox;
        }
        setor = setor->prox;
    }
    printf("Item %d nao encontrado\n", codigo);
}

// 4. Busca endereço de um item
void buscarEndereco(Loja* loja, int codigo) {
    Setor* setor = loja->setores;
    while (setor) {
        Arara* arara = setor->araras;
        while (arara) {
            Item* item = arara->itens;
            while (item) {
                if (item->codigo == codigo) {
                    printf("Item encontrado - Setor: %d, Arara: %d\n", item->setor, item->arara);
                    return;
                }
                item = item->prox;
            }
            arara = arara->prox;
        }
        setor = setor->prox;
    }
    printf("Item %d nao encontrado ou está sendo provado\n", codigo);
}

// 5. Locar provador
void locarProvador(Loja* loja, char* cpf, char tipo) {
    Provador* provadores = (tipo == 'M') ? loja->provadoresM : loja->provadoresF;
    int i;
    for (i = 0; i < MAX_PROVADORES; i++) {
        if (!provadores[i].ocupado) {
            provadores[i].ocupado = 1;
            provadores[i].cliente = (Cliente*)malloc(sizeof(Cliente));
            strcpy(provadores[i].cliente->cpf, cpf);
            provadores[i].cliente->itensProvando = NULL;
            printf("Provador %d (%c) alocado para CPF %s\n", i, tipo, cpf);
            return;
        }
    }

    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    strcpy(novoCliente->cpf, cpf);
    novoCliente->itensProvando = NULL;
    novoCliente->prox = NULL;

    FilaEspera* fila = (tipo == 'M') ? &loja->filaM : &loja->filaF;
    if (!fila->inicio) {
        fila->inicio = fila->fim = novoCliente;
    } else {
        fila->fim->prox = novoCliente;
        fila->fim = novoCliente;
    }
    printf("Provadores ocupados. Cliente %s adicionado à fila %c\n", cpf, tipo);
}

// 6. Liberar provador
void liberarProvador(Loja* loja, char tipo, int provadorNum, Item* itensDevolver, Item* itensComprar) {
    Provador* provadores = (tipo == 'M') ? loja->provadoresM : loja->provadoresF;
    if (provadorNum < 0 || provadorNum >= MAX_PROVADORES) {
        printf("Número de provador inválido\n");
        return;
    }
    if (provadores[provadorNum].ocupado) {
        // Devolver itens
        Item* item = itensDevolver;
        while (item) {
            inserirItem(loja, item->codigo, item->tipo, item->marca, item->cor, item->tamanho,
                       item->setor, item->arara);
            Item* temp = item;
            item = item->prox;
            free(temp);
        }

        // Retirar itens comprados
        item = itensComprar;
        while (item) {
            retirarItem(loja, item->codigo);
            Item* temp = item;
            item = item->prox;
            free(temp);
        }

        // Liberar provador
        free(provadores[provadorNum].cliente->itensProvando);
        free(provadores[provadorNum].cliente);
        provadores[provadorNum].cliente = NULL;
        provadores[provadorNum].ocupado = 0;

        // Alocar próximo cliente da fila
        FilaEspera* fila = (tipo == 'M') ? &loja->filaM : &loja->filaF;
        if (fila->inicio) {
            Cliente* cliente = fila->inicio;
            fila->inicio = cliente->prox;
            if (!fila->inicio) fila->fim = NULL;

            provadores[provadorNum].ocupado = 1;
            provadores[provadorNum].cliente = cliente;
            printf("Provador %d (%c) alocado para próximo cliente da fila (CPF: %s)\n",
                   provadorNum, tipo, cliente->cpf);
        }
    } else {
        printf("Provador %d (%c) nao está ocupado\n", provadorNum, tipo);
    }
}

// 7. Provar item
void provarItem(Loja* loja, char* cpf, int codigo) {
    Provador* provador = NULL;
    char tipo;
    for (int i = 0; i < MAX_PROVADORES; i++) {
        if (loja->provadoresM[i].ocupado && strcmp(loja->provadoresM[i].cliente->cpf, cpf) == 0) {
            provador = &loja->provadoresM[i];
            tipo = 'M';
            break;
        }
        if (loja->provadoresF[i].ocupado && strcmp(loja->provadoresF[i].cliente->cpf, cpf) == 0) {
            provador = &loja->provadoresF[i];
            tipo = 'F';
            break;
        }
    }

    if (!provador) {
        printf("Cliente %s nao está em nenhum provador\n", cpf);
        return;
    }

    Setor* setor = loja->setores;
    while (setor) {
        Arara* arara = setor->araras;
        while (arara) {
            Item* item = arara->itens;
            Item* anterior = NULL;
            while (item) {
                if (item->codigo == codigo) {
                    Item* novoItem = (Item*)malloc(sizeof(Item));
                    *novoItem = *item;
                    novoItem->prox = provador->cliente->itensProvando;
                    provador->cliente->itensProvando = novoItem;

                    if (anterior) anterior->prox = item->prox;
                    else arara->itens = item->prox;
                    free(item);
                    salvarBinario(loja, "estoque.bin");
                    printf("Item %d adicionado ao provador\n", codigo);
                    return;
                }
                anterior = item;
                item = item->prox;
            }
            arara = arara->prox;
        }
        setor = setor->prox;
    }
    printf("Item %d nao encontrado\n", codigo);
}

// 8. Imprimir Mapa de Provadores
void imprimirProvadores(Loja* loja) {
    printf("\nProvadores Masculinos:\n");
    for (int i = 0; i < MAX_PROVADORES; i++) {
        if (loja->provadoresM[i].ocupado) {
            printf("Provador %d - CPF: %s\n", i, loja->provadoresM[i].cliente->cpf);
            Item* item = loja->provadoresM[i].cliente->itensProvando;
            while (item) {
                printf("  Item: %d, %s, %s, %s, %s\n", item->codigo, item->tipo,
                       item->marca, item->cor, item->tamanho);
                item = item->prox;
            }
        } else {
            printf("Provador %d - Vazio\n", i);
        }
    }

    printf("\nProvadores Femininos:\n");
    for (int i = 0; i < MAX_PROVADORES; i++) {
        if (loja->provadoresF[i].ocupado) {
            printf("Provador %d - CPF: %s\n", i, loja->provadoresF[i].cliente->cpf);
            Item* item = loja->provadoresF[i].cliente->itensProvando;
            while (item) {
                printf("  Item: %d, %s, %s, %s, %s\n", item->codigo, item->tipo,
                       item->marca, item->cor, item->tamanho);
                item = item->prox;
            }
        } else {
            printf("Provador %d - Vazio\n", i);
        }
    }
}

// 9. Imprimir Fila de Espera
void imprimirFilaEspera(Loja* loja) {
    printf("\nFila de Espera Masculina:\n");
    Cliente* cliente = loja->filaM.inicio;
    if (!cliente) printf("Vazia\n");
    while (cliente) {
        printf("CPF: %s\n", cliente->cpf);
        cliente = cliente->prox;
    }

    printf("\nFila de Espera Feminina:\n");
    cliente = loja->filaF.inicio;
    if (!cliente) printf("Vazia\n");
    while (cliente) {
        printf("CPF: %s\n", cliente->cpf);
        cliente = cliente->prox;
    }
}

// Função auxiliar para coletar itens para devolução ou compra
Item* coletarItens(char* tipoLista) {
    Item* lista = NULL;
    char continuar;
    do {
        Item* novoItem = (Item*)malloc(sizeof(Item));
        printf("Digite o código do item %s: ", tipoLista);
        scanf("%d", &novoItem->codigo);
        limparBuffer();
        printf("Digite o tipo do item: ");
        lerString(novoItem->tipo, MAX_TIPO);
        printf("Digite a marca do item: ");
        lerString(novoItem->marca, MAX_MARCA);
        printf("Digite a cor do item: ");
        lerString(novoItem->cor, MAX_COR);
        printf("Digite o tamanho do item: ");
        lerString(novoItem->tamanho, MAX_TAMANHO);
        printf("Digite o setor do item: ");
        scanf("%d", &novoItem->setor);
        printf("Digite a arara do item: ");
        scanf("%d", &novoItem->arara);
        limparBuffer();
        novoItem->prox = lista;
        lista = novoItem;
        printf("Adicionar outro item %s? (s/n): ", tipoLista);
        scanf("%c", &continuar);
        limparBuffer();
    } while (tolower(continuar) == 's');
    return lista;
}

int main() {
    Loja loja;
    inicializarLoja(&loja);
    int opcao;

    do {
        printf("\n=== Stresser Modas - Menu ===\n");
        printf("1. Carregar arquivo de inicializacao\n");
        printf("2. Inserir item de vestuario\n");
        printf("3. Retirar item\n");
        printf("4. Buscar endereco de um item\n");
        printf("5. Locar provador\n");
        printf("6. Liberar provador\n");
        printf("7. Provar item\n");
        printf("8. Imprimir mapa de provadores\n");
        printf("9. Imprimir fila de espera\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: {
                char arquivo[100];
                printf("Digite o nome do arquivo de inicializacao: ");
                lerString(arquivo, 100);
                carregarArquivo(&loja, arquivo);
                printf("Arquivo carregado com sucesso!\n");
                break;
            }
            case 2: {
                int codigo, setor, arara;
                char tipo[MAX_TIPO], marca[MAX_MARCA], cor[MAX_COR], tamanho[MAX_TAMANHO];
                printf("Digite o codigo do item: ");
                scanf("%d", &codigo);
                limparBuffer();
                printf("Digite o tipo do item: ");
                lerString(tipo, MAX_TIPO);
                printf("Digite a marca do item: ");
                lerString(marca, MAX_MARCA);
                printf("Digite a cor do item: ");
                lerString(cor, MAX_COR);
                printf("Digite o tamanho do item: ");
                lerString(tamanho, MAX_TAMANHO);
                printf("Digite o setor: ");
                scanf("%d", &setor);
                printf("Digite a arara: ");
                scanf("%d", &arara);
                limparBuffer();
                inserirItem(&loja, codigo, tipo, marca, cor, tamanho, setor, arara);
                printf("Item inserido com sucesso!\n");
                break;
            }
            case 3: {
                int codigo;
                printf("Digite o código do item a ser retirado: ");
                scanf("%d", &codigo);
                limparBuffer();
                retirarItem(&loja, codigo);
                break;
            }
            case 4: {
                int codigo;
                printf("Digite o codigo do item para buscar endereco: ");
                scanf("%d", &codigo);
                limparBuffer();
                buscarEndereco(&loja, codigo);
                break;
            }
            case 5: {
                char cpf[MAX_CPF], tipo;
                printf("Digite o CPF do cliente: ");
                lerString(cpf, MAX_CPF);
                printf("Digite o tipo de provador (M/F): ");
                scanf("%c", &tipo);
                limparBuffer();
                locarProvador(&loja, cpf, toupper(tipo));
                break;
            }
            case 6: {
                char tipo;
                int provadorNum;
                printf("Digite o tipo de provador (M/F): ");
                scanf("%c", &tipo);
                printf("Digite o número do provador (0-%d): ", MAX_PROVADORES - 1);
                scanf("%d", &provadorNum);
                limparBuffer();
                printf("Coletando itens para devolucao...\n");
                Item* itensDevolver = coletarItens("para devolucao");
                printf("Coletando itens para compra...\n");
                Item* itensComprar = coletarItens("para compra");
                liberarProvador(&loja, toupper(tipo), provadorNum, itensDevolver, itensComprar);
                printf("Provador liberado!\n");
                break;
            }
            case 7: {
                char cpf[MAX_CPF];
                int codigo;
                printf("Digite o CPF do cliente: ");
                lerString(cpf, MAX_CPF);
                printf("Digite o codigo do item a ser provado: ");
                scanf("%d", &codigo);
                limparBuffer();
                provarItem(&loja, cpf, codigo);
                break;
            }
            case 8: {
                imprimirProvadores(&loja);
                break;
            }
            case 9: {
                imprimirFilaEspera(&loja);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Liberar memória (simplificado, pode ser expandido para liberar todas as listas)
    Setor* setor = loja.setores;
    while (setor) {
        Arara* arara = setor->araras;
        while (arara) {
            Item* item = arara->itens;
            while (item) {
                Item* temp = item;
                item = item->prox;
                free(temp);
            }
            Arara* tempArara = arara;
            arara = arara->prox;
            free(tempArara);
        }
        Setor* tempSetor = setor;
        setor = setor->prox;
        free(tempSetor);
    }

    for (int i = 0; i < MAX_PROVADORES; i++) {
        if (loja.provadoresM[i].ocupado) {
            free(loja.provadoresM[i].cliente->itensProvando);
            free(loja.provadoresM[i].cliente);
        }
        if (loja.provadoresF[i].ocupado) {
            free(loja.provadoresF[i].cliente->itensProvando);
            free(loja.provadoresF[i].cliente);
        }
    }

    Cliente* cliente = loja.filaM.inicio;
    while (cliente) {
        Cliente* temp = cliente;
        cliente = cliente->prox;
        free(temp);
    }
    cliente = loja.filaF.inicio;
    while (cliente) {
        Cliente* temp = cliente;
        cliente = cliente->prox;
        free(temp);
    }

    return 0;
}