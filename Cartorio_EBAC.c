#include <stdio.h> //biblioteca de comunicac�o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar o usu�rios no sistema.
{
	// In�cio cria��o de vari�veis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final cria��o de vari�veis/string.
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio.
	scanf("%s", cpf); //%s refere-se a string.
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string.
	
	FILE *file; //Cria o Arquivo.
	file = fopen(arquivo, "w"); //"W" = Cria uma nova e escreve.
	fprintf(file,cpf); //Salvo o valor da variavel.
	fclose(file); //Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // "A" = Atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s,",sobrenome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza ele.
	fprintf(file,sobrenome); // depois de aberto, atualize com o sobrenome.
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	}

int consulta()
{
	
   setlocale(LC_ALL,"portuguese");
   
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	    printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
	    printf("\n\n");
	}
	system("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
      
      
  }


int main()
 {
	int opcao=0; //Definindo vari�veis.
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	
	{
	
	for(laco=1;laco=1;)
	   {
	
	 system("cls");
	 
     setlocale(LC_ALL,"portuguese"); //Definindo a linguagem.

        	printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu.
    	    printf("Escolha a op��o desejada do menu:\n\n");
        	printf("\t1 - Registrar Nomes\n");
        	printf("\t2 - Consultar Nomes\n");
        	printf("\t3 - Deletar Nomes\n"); 
        	printf("\t4 - Sair do Sistema\n\n");
    	
        	printf("opcao: "); //Fim do menu.
	
        	scanf("%d", &opcao); // Armazenando a escolha do usuario.
	
        	system("cls"); //Respons�vel por limpar a tela.
	 
         	switch(opcao) //In�cio da sele��o dos menus.
	        {
		        case 1:
      		    registro(); //chamada de fun��es.
    		    break;
		    
     	    	case 2:
    	    	consulta();
    	    	break;
		    	
    		    case 3:
    		    deletar();
    			break;
			
    			case 4:
    			printf("Obrigado por ultilizar o sistema!\n");
    			return 0;
    			break;
	
    		    default:
    	    	printf("essa op��o n�o esta dispon�vel!\n");
    		    system("pause");
    	    	break;
     	    	//Fim da sele��o.    
			}
		}
    
    } 
    
    else
     printf("senha incorreta");
    
}

  

