#include <stdio.h> //biblioteca de comunicacão com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar o usuários no sistema.
{
	// Início criação de variáveis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final criação de variáveis/string.
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário.
	scanf("%s", cpf); //%s refere-se a string.
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string.
	
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
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	    printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
	    printf("\n\n");
	}
	system("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
      
      
  }


int main()
 {
	int opcao=0; //Definindo variáveis.
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	
	{
	
	for(laco=1;laco=1;)
	   {
	
	 system("cls");
	 
     setlocale(LC_ALL,"portuguese"); //Definindo a linguagem.

        	printf("### Cartório da EBAC ###\n\n"); // Início do menu.
    	    printf("Escolha a opção desejada do menu:\n\n");
        	printf("\t1 - Registrar Nomes\n");
        	printf("\t2 - Consultar Nomes\n");
        	printf("\t3 - Deletar Nomes\n"); 
        	printf("\t4 - Sair do Sistema\n\n");
    	
        	printf("opcao: "); //Fim do menu.
	
        	scanf("%d", &opcao); // Armazenando a escolha do usuario.
	
        	system("cls"); //Responsável por limpar a tela.
	 
         	switch(opcao) //Início da seleção dos menus.
	        {
		        case 1:
      		    registro(); //chamada de funções.
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
    	    	printf("essa opção não esta disponível!\n");
    		    system("pause");
    	    	break;
     	    	//Fim da seleção.    
			}
		}
    
    } 
    
    else
     printf("senha incorreta");
    
}

  

