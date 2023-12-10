#include  <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel de cuidar dass String

int registrar()
{
	char arquivo[40]; //inicio das variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	//fim das variaveis
	
	printf("\nDigite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s para receber string
	
	strcpy(arquivo, cpf); //"STRCPY" � respons�vel por copiar os valores da string
	
	FILE *file; //execute o comando FILE e crie um "file(arquivo)"
	file = fopen(arquivo, "w"); //edite o arquivo (obs:"arquivo" � o que vai ser editado/criado ou consultado e "W" quer dizer que o arquivo � do tipo write)
		fprintf(file, "CPF: "); //Diferen�a pro teste 5 <- <- <-----
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo,"a"); //abra o arquivo e edite
		fprintf(file,cpf);
	fclose(file); //j� estou fechando o arquivo
	
	file = fopen(arquivo,"a"); //tenho que abrir o arquivo de novo
		fprintf(file,"\nNome: ");
	fclose(file); //j� estou fechando de novo o arquivo
	
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
	
	system("pause");//pausa o programa, assim mostrando todas as informa��es acima.
	
}

int	consultar()
{
	setlocale(LC_ALL, "Portuguese");//obrigat�rio para mostrar acentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//obrigat�rio saber o CPF do usu�rio
	
	FILE *file; 
	file = fopen(cpf, "r"); //abre a pasta onde est� o arquivo e procure pelo arquivo com o nome do "CPF"
	
		if (file == NULL) //Se n�o encontrar nada ou seja "Arquivo = NULO", fa�a
		{
			printf("N�o foi possivel abrir o arquivo, arquivo n�o localizado.");
		}
		else//senao fa�a
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("\n\n\t");	
		}
		
		while(fgets(conteudo, 200, file) != NULL) /*enquanto tiver (conteudo == a nova string ou seja o texto total, 
												 200 ==tamanho selecionado da string conte�do, file == Arquivo CPF */
		{
			printf("%s",conteudo);//vai escrever todas as strings at� d� 200 ou at� ser nulo ou seja acabar
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
	
	printf("\nDigite o CPF do usu�rio a ser apagado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("\nEste usu�rio do CPF: %s, N�O EXISTE\n\n",cpf);
		system("pause");
	}
	else
	{
		printf("\nFoi apagado o usu�rio do CPF: %s\n\n", cpf);
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
		printf("   ## CART�RIO DA EBAC ##\n\n"); //inicio do menu principal
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\n\tOp��o: "); //fim do menu principal
		scanf("%d", &opcao); //armazenamento da escolha do usu�rio
		system("cls"); //limpar a tela
		
		switch (opcao) //inicio da impress�o da escolha do usu�rio
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
				printf("\nOp��o indispon�vel!!\nEscolha uma op��o de 1 a 3\n");
				system("pause");
				break;				
		}	//Final da impress�o da escolha do usu�rio
	}
}
