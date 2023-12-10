#include  <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável de cuidar dass String

int registrar()
{
	char arquivo[40]; //inicio das variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	//fim das variaveis
	
	printf("\nDigite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s para receber string
	
	strcpy(arquivo, cpf); //"STRCPY" é responsável por copiar os valores da string
	
	FILE *file; //execute o comando FILE e crie um "file(arquivo)"
	file = fopen(arquivo, "w"); //edite o arquivo (obs:"arquivo" é o que vai ser editado/criado ou consultado e "W" quer dizer que o arquivo é do tipo write)
		fprintf(file, "CPF: "); //Diferença pro teste 5 <- <- <-----
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo,"a"); //abra o arquivo e edite
		fprintf(file,cpf);
	fclose(file); //já estou fechando o arquivo
	
	file = fopen(arquivo,"a"); //tenho que abrir o arquivo de novo
		fprintf(file,"\nNome: ");
	fclose(file); //já estou fechando de novo o arquivo
	
	printf("\nDigite o nome a ser cadastrado: ");
	scanf("%s",nome); //scanf para receber o nome
	
	file = fopen(arquivo, "a");//abro novamente o arquivo para colocar a string nome dentro do arquivo
		fprintf(file, nome);
	fclose(file);// Tenho que fechar novamente
	
	file = fopen(arquivo,"a");
		fprintf(file,"\nSobrenome: ");//segue o mesmo procedimento acima
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
		fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo,"a");
		fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
		fprintf(file,cargo);
	fclose(file);
	
	printf("\n\n");
	
	system("pause");//pausa o programa, assim mostrando todas as informações acima.
	
}

int	consultar()
{
	setlocale(LC_ALL, "Portuguese");//obrigatório para mostrar acentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//obrigatório saber o CPF do usuário
	
	FILE *file; 
	file = fopen(cpf, "r"); //abre a pasta onde está o arquivo e procure pelo arquivo com o nome do "CPF"
	
		if (file == NULL) //Se não encontrar nada ou seja "Arquivo = NULO", faça
		{
			printf("Não foi possivel abrir o arquivo, arquivo não localizado.");
		}
		else//senao faça
		{
			printf("\nEssas são as informações do usuário: ");
			printf("\n\n\t");	
		}
		
		while(fgets(conteudo, 200, file) != NULL) /*enquanto tiver (conteudo == a nova string ou seja o texto total, 
												 200 ==tamanho selecionado da string conteúdo, file == Arquivo CPF */
		{
			printf("%s",conteudo);//vai escrever todas as strings até dá 200 ou até ser nulo ou seja acabar
			printf("\n\t");
		}
		printf("\n\n");
		system("pause");
	
	fclose(file); //fecha o arquivo

}

int deletar()
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	
	printf("\nDigite o CPF do usuário a ser apagado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("\nEste usuário do CPF: %s, NÃO EXISTE\n\n",cpf);
		system("pause");
	}
	else
	{
		printf("\nFoi apagado o usuário do CPF: %s\n\n", cpf);
		system("pause");
	}
	fclose(file);
	
	remove(cpf);
	
}



int main() {
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	int opcao=0, cont=0; 	//definindo variaveis 
	
	
	for (cont = 1 ; cont = 1;)
	{
		system("cls");
		printf("   ## CARTÓRIO DA EBAC ##\n\n"); //inicio do menu principal
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\n\tOpção: "); //fim do menu principal
		scanf("%d", &opcao); //armazenamento da escolha do usuário
		system("cls"); //limpar a tela
		
		switch (opcao) //inicio da impressão da escolha do usuário
		{
			case 1:
				registrar();
				break;
			
			case 2:
				consultar();
				break;
				
			case 3:
				deletar();
				break;
			
			default:
				printf("\nOpção indisponível!!\nEscolha uma opção de 1 a 3\n");
				system("pause");
				break;				
		}	//Final da impressão da escolha do usuário
	}
}
