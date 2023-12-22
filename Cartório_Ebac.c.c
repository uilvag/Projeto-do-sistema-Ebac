#include  <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel de cuidar das String

int registrar()
{
	char arquivo[40]; //inicio das variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	char continuar = '1';//fim das variaveis
	
	while(continuar == '1' ) {   //para entrar em loop
	
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
		system("cls");
		printf("\nDeseja continuar? Tecle: 1 \nDeseja parar? Tecle: 2\n--> ");
		scanf("%s", &continuar); //op��o para sair
		system("cls");
	}
		
}

int	consultar()
{
	setlocale(LC_ALL, "Portuguese");//obrigat�rio para mostrar acentos
	
	char cpf[40];
	char conteudo[200];
	char continuar = '1';
	
	while(continuar == '1') {//entrando em loop
	
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
		system("cls");
		printf("\nDeseja continuar? Tecle: 1 \nDeseja parar? Tecle: 2\n--> ");
		scanf("%s", &continuar); //op��o para sair do loop
		system("cls");
	}

}

int deletar()
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	char continuar = '1';
	
	while(continuar == '1') { //entrando em loop
	
		printf("\nDigite o CPF do usu�rio a ser apagado: ");
		scanf("%s", cpf);
		
		FILE *file; //FILE � a biblioteca e file � para abrir a func�o file
		file = fopen(cpf,"r");// "r" � para procurar nos arquivos se tem algum com esse nome(CPF)
	
		if(file == NULL) //casso n�o ache nenhum arquivo com esse nome(CPF)
		{
			printf("\nEste usu�rio do CPF: %s, N�O EXISTE\n\n",cpf);
			system("pause");
		}
		else //Quando achar um arquivo com esse nome(CPF)
		{
			printf("\nFoi apagado o usu�rio do CPF: %s\n\n", cpf);
			system("pause");
		}
		fclose(file); //fecha a fun��o file
		
		remove(cpf);// Deleta o arquivo com o nome do CPF
		
		system("cls");
		printf("\nDeseja continuar? Tecle: 1 \nDeseja parar? Tecle: 2\n--> ");
		scanf("%s", &continuar); //Op��o para sair do loop 
		system("cls");
	}
}



int main() {
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	int opcao=0, cont=0; 	//definindo variaveis 
		int x, y;
	char nomeUsuario[10];//nome de usu�rio = admin
	char senha[10];//senha = 123456
	
	printf("\nDigite seu nome de usu�rio: ");
	scanf("%s", nomeUsuario);
	printf("\nDigite sua senha: ");
	scanf("%s", senha);
	
	x = strcmp (nomeUsuario, "admin");//compara a string nomeUsu�rio com "admin", se correto (x = 0) 
	y = strcmp (senha, "123456");//compara a string senha com "123456", se correto (y = 0)
		
	if(x==0 && y==0) //se x for igual a "0" e y for igual a "0", fa�a 

	{
	
		for (cont = 1 ; cont = 1;)
		{
			system("cls");
			printf("   ## CART�RIO DA EBAC ##\n\n"); //inicio do menu principal
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n");
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
					
				case 4:
					printf("\nObrigado por utilizar nosso sistema!\n");
					return 0;
					break;
				
				default:
					printf("\nOp��o indispon�vel!!\nEscolha uma op��o de 1 a 3\n");
					system("pause");
					break;				
			}	//Final da impress�o da escolha do usu�rio
		}
	}else{ 	//se "x" ou "y" for diferente de "0"
		printf("\nNome de usu�rio ou senha incorreta");
	}
}
