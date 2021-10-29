typedef struct {
    //Campos a ser preenchidos
    char nome[50];
    char cpf[11];
    int poltrona;
} Cliente;

typedef struct{
    int cpfCliente;
    int status;
}Poltronas;

void opcaoSelect(int opcao,  Cliente *vetor); //

void cadastrarCliente( Cliente *vetor); //

void reservarAcento(Cliente *vetor);

void venderAcento();

void alterar();

void retirarPoltronaDaReserva();

int pesquisar();

void imprimir();

void criarOnibus(); //

void excluirCadastro();

void carregarArquivo(char *nomeArquivo, Cliente *vetor, int tam);

int verificarCliente(char cpf[], char nome[]);
