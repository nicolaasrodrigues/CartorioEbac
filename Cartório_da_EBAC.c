#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das Strings




int Registro() //Função Responsável pelo cadastro de usuário no sistema
{
	//Inicio da criação de variáveis/strings
	 char arquivo[40];
     char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40] ;
	 //Final da criação de variáveis/strings
	 
	 printf("Digite o CPF a ser cadastrado: \n"); //Coletando informação do usuário
	 scanf("%s", cpf); //%s refere-se e salva string
	 
	 strcpy(arquivo, cpf); //Responsável por copiar os arquivos das Strings
	 
	 FILE *file; //cria o arquivo
	 file = fopen(arquivo, "w"); //cria o arquivo e abre o arquivo
	 fprintf(file, cpf); //salva o arquivo
	 fclose(file); //fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // Cria e abre o arquivo
	 fprintf(file, ","); // Põe uma , no arquivo
	 fclose(file);
	 
	 printf("Digite o nome a ser cadastrado: \n"); // Coletando informação do usuário
	 scanf("%s", nome); //%s refere-se e salva string
	 
	 file = fopen(arquivo, "a"); // Cria e abre o arquivo
	 fprintf(file, nome); // Adiciona o texto(Nome) ao arquivo
	 fclose(file); // Fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // Cria e abre o arquivo
	 fprintf(file, "_"); // Adiciona espaço ao texto (nome_sobrenome) do arquivo
	 fclose(file); // Fecha o arquivo
	 
	 printf("Digite o sobrenome a ser cadastrado: \n"); // Coletando informação do usuário
	 scanf("%s", sobrenome); //%s refere-se e salva string
	 
	 file = fopen(arquivo, "a"); // Cria, abre o arquivo e adiciona o conteúdo ao final
	 fprintf(file, sobrenome); // Adiciona o texto(sobrenome) ao arquivo
	 fclose(file); //Fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // Crie, abre o arquivo e adiciona o conteúdo ao final
	 fprintf(file, ","); // Adiciona uma virgula ao texto do arquivo
	 fclose(file);
	 
	 printf("Digite o Cargo a ser cadastrado: \n"); // Coletando informação do usuário
	 scanf("%s", cargo); //%s refere-se e salva string
	 
	 file = fopen(arquivo, "a"); // Cria, abre o arquivo e adicio o arquivo ao final
	 fprintf(file, cargo); // Adicione o texto(cargo) ao arquivo
	 fclose(file); // fceha o arquivo
	 
	 system("pause");
	 
}

int Consultar() // Função responsável por Consultar os usuários
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	// Inicio da criação de Var./strings
	char cpf[40];
	char conteudo[200];
	// Final da criação de Var./strings
	
	printf("Digite o CPF que você quer consultar:"); // Escolha do CPF a ser Consultado
	scanf("%s",cpf); // Refere-se a e salva strings
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf, "r"); // Abre o arquivo
	
	if(file == NULL) // se não ouver o CPF cadastrado
	{
		printf(" CPF não localizado!"); // Aviso caso o CPF não esteja cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Encontra e lê  as informações do usuário e se não tiver usuário volta NULL
	{
		printf("\nEssas são as informações do usuário: "); // Mostra as info. do usuário
		printf("%s", conteudo); // Refere-se e salva string
		printf("\n\n"); // Espaçamento de linhas
	}
	system("pause");
        
}

int Deletar() // Função de Deletar usuários do Banco de dados.
{
	// Inicio da criação de Var./strings
	char cpf[40];
	// Final da criação de Var./strings
	
	printf("Digite o CPF que você quer Deletar: "); // Escolha do CPF a ser deletado
	scanf("%s", cpf); // Refere-se e salva string
	
	remove(cpf); 
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf, "r"); // Abre e lê as informações
	
	if(file == NULL); // Usuário não foi encontrado
	{
		printf("O usuário foi Deletado!\n"); // Delete feito com sucesso
		system("pause");
	}
}





int main()
{
	int opcao=0; //Definindo Variaveis]
	int laco=1;
	
		for(laco=1; laco=1;)
	{
		
		system("cls"); //  responsável por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
        printf("### Cartório da EBAC ### \n\n"); //inicio do menu
	    printf("Escolha a opção que tu deseja:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao);  
		//Armazenando a escolha do usuário
	
	    system("cls"); // Responsável por limpar a tela
	
	    switch(opcao)
	    {
		   case 1:
		   	 Registro(); // Inicio da chamada de funções
	         break;
		   
		   case 2:
		   	 Consultar(); 
	         break;
	         
	       case 3:
	       	Deletar(); 
	       	break;
	       	
	       	case 4:
	       		printf("Agradecemos pelo uso do nosso sistema! \n");
	       		return 0;
	       		break;
	       	
	       	default:
	       		printf("Desculpe, mas esta opção não está disponível\n"); // Outra opção que seja as acima volta que não está disponivel
	       		system("pause"); //Fim da seleção}
	       		
	    }
		   
		   

	    
	 }
	 
	 
}


