#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//variaveis globais
char *error;
//funções do programa
//cria tabela
void criarTabela()
{
	int ctrl = 0,op,pkop;
	bool pk = false;
	char tmp[50];
	FILE *f,*list;
	printf("\nDigite o nome da sua tabela: ");
	scanf("%s",&tmp);
	f = fopen(tmp,"w");
	list = fopen("listadetabelas.txt","a");
	fprintf(list,"%s\n",tmp);
	while(ctrl != -1)
	{
		printf("\nDigite o tipo de variavel que deseja adicionar\n1- char\n2- float\n3- double\n4- int\n5- string\n6- Finalizar\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				if(pk == false)
				{
					printf("\nA variavel eh chave primaria?\n1- sim\n2- nao");
					scanf("%d",&pkop);
					if(pkop == 1){
						fprintf(f,"*PK CHAR %s",tmp);
						pk = true;
					}else if(pkop == 2)
					{
						fprintf(f,"*CHAR %s",tmp);
					}
				}else
				{
					fprintf(f,"*CHAR %s",tmp);	
				}
			break;
			case 2:
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				if(pk == false)
				{
					printf("\nA variavel eh chave primaria?\n1- sim\n2- nao\n");
					scanf("%d",&pkop);
					if(pkop == 1){
						fprintf(f,"*PK FLOAT %s",tmp);
						pk = true;
					}else if(pkop == 2)
					{
						fprintf(f,"*FLOAT %s",tmp);
					}
				}else
				{
					fprintf(f,"*FLOAT %s",tmp);	
				}
			break;
			case 3:	
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				if(pk == false)
				{
					printf("\nA variavel eh chave primaria?\n1- sim\n2- nao\n");
					scanf("%d",&pkop);
					if(pkop == 1){
						fprintf(f,"*PK DOUBLE %s",tmp);
						pk = true;
					}else if(pkop == 2)
					{
						fprintf(f,"*DOUBLE %s",tmp);
					}
				}else
				{
					fprintf(f,"*DOUBLE %s",tmp);	
				}
			break;
			case 4:
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				if(pk == false)
				{
					printf("\nA variavel eh chave primaria?\n1- sim\n2- nao\n");
					scanf("%d",&pkop);
					if(pkop == 1){
						fprintf(f,"*PK INT %s",tmp);
						pk = true;
					}else if(pkop == 2)
					{
						fprintf(f,"*INT %s",tmp);
					}
				}else
				{
					fprintf(f,"*INT %s",tmp);	
				}
			break;
			case 5:
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				if(pk == false)
				{
					printf("\nA variavel eh chave primaria?\n1- sim\n2- nao\n");
					scanf("%d",&pkop);
					if(pkop == 1){
						fprintf(f,"*PK STRING %s",tmp);
						pk = true;
					}else if(pkop == 2)
					{
						fprintf(f,"*STRING %s",tmp);
					}
				}else
				{
					fprintf(f,"*STRING %s",tmp);	
				}
			break;
			case 6:
				fclose(f);
				ctrl = -1;
		}
		system("cls");
	}
}
//adiciona linha na tabela
void addlinhaTabela()
{
	char tmp[50];
	int count = 1;
	FILE *f;
	int ctrl = 0,i;
	while(ctrl != -1)
	{
		printf("\nDigite o nome da tabela: ");
		scanf("%s",&tmp);
		f = fopen(tmp,"a");
		if(f == NULL){
			printf("\n Tabela nao existe.");
		}else
		{
			while()
			{
				if (count == 1)
				{
					printf("Digite o valor para a variavel %d: ",count);
					scanf("%s",&tmp);
					fprintf(f, "*%s",tmp);
				}else
				{
					printf("Deseja adicionar outro valor?\n1- sim\n2- nao");
					scanf("%d",&i)
					if (i == 1)
					{
						printf("Digite o valor para a variavel %d: ",count);
						scanf("%s",&tmp);
						fprintf(f, "*%s",tmp);
					}else if (i == 2)
					{
						ctrl = -1;
					}
				}				
			}
		}
	}
	fclose(f);	
}
//lista todas as tabelas no sistema
void listarTabelas()
{
	FILE *f;
	char linha[200];
	f = fopen("listadetabelas.txt","r");
	while(!feof(f))
	{
		fgets(linha,200,f);
		printf("%s\n",linha);
	}

}
//lista os dados de uma certa tabela
void listarDadosTabela()
{
	char tmp[50];
	FILE *f;
	int ctrl = 0,i,j;
	char linha[200];
	while(ctrl != -1)
	{
		printf("\nDigite o nome da tabela: ");
		scanf("%s",&tmp);
		f = fopen(tmp,"r");
		if(f == NULL){
			printf("\n Tabela nao existe.");
		}else
		{
			while(!feof(f))
			{
				fgets(linha,200,f);
				printf("%s\n",linha);
			}
			ctrl = -1;
			fclose(f);
		}
	}
}
//pesquisa valor em uma tabela
void pesquisarTabela()
{
	
}
//apaga tabela
void apagarValorTabela()
{
	char tmp[50];
	FILE *f;
	int ctrl = 0,i,j;
	while(ctrl != -1)
	{
		printf("\nDigite o nome da tabela: ");
		scanf("%s",&tmp);
		f = fopen(tmp,"r+");
		if(f == NULL){
			printf("\n Tabela nao existe.");
		}else
		{
			remove(tmp);
			ctrl = -1;
		}
	}
}
int main(int argc, char const *argv[])
{
	int op,ctrl = 0;
	while(ctrl != -1)
	{
		printf("SGBD\n1- Criar tabela\n2- Listar tabelas\n3- Criar uma nova linha na tabela\n4- Listar todos os dados de uma tabela\n5- Pesquisar valor em uma tabela\n6- Apagar valor de uma tabela\n7- Sair do sistema\n");
		if(error != NULL)
		{
			printf("ERRO: %s",error);
		}
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				criarTabela();
			break;
			case 2:
				listarTabelas();
			break;
			case 3:
				addlinhaTabela();
			break;
			case 4:
				listarDadosTabela();
			break;
			case 5:
			break;
			case 6:
				apagarValorTabela();
			break;
			case 7:
				ctrl = -1;
			break;
			default:
				error = "opcao invalida";
		}
		system("cls");
	}
	return 0;
}
