#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//feito
int numVariaveisTabela(char arquivo[])
{
	FILE *in;
	char c;
	int count;
	bool x =  false;
	in = fopen(arquivo,"r");
	do
	{
		c = fgetc(in);
		if (c == '*')
		{
			count++;
		}
	}while(c != EOF);
	fclose(in);
	return count;
}
void criarTabela()
{
	int op,pkop;
	bool pk = false;
	char tmp[50];
	FILE *f,*list;
	printf("\nDigite o nome da sua tabela: ");
	scanf("%s",&tmp);
	f = fopen(tmp,"w");
	list = fopen("listadetabelas.txt","a");
	fprintf(list,"%s\n",tmp);
	fclose(list);
	while(1)
	{
		printf("\nDigite o tipo de variavel que deseja adicionar\n1- char\n2- float\n3- double\n4- int\n5- string\n6- Finalizar\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				fprintf(f,"*CHAR %s",tmp);	
			break;
			case 2:
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				fprintf(f,"*FLOAT %s",tmp);	
			break;
			case 3:	
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				fprintf(f,"*DOUBLE %s",tmp);	
			break;
			case 4:
				printf("\nDigite o nome da sua variavel: ");
				scanf("%s",&tmp);
				if(pk == false)
				{
					printf("\nA variavel eh chave primaria?\n1- sim\n2- nao\n");
					scanf("%d",&pkop);
					if(pkop == 1){
						fprintf(f,"*PK UNASSIGNED INT %s",tmp);
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
				fprintf(f,"*STRING %s",tmp);	
			break;
			case 6:
			if (pk == true)
			{
				fclose(f);
				return 1;
			}else
			{
				printf("Tabela não apresenta chave primaria.\n");
			}
			default:
				printf("Opcao invalida\n");
		}
	}
}
//precisa fix (excluir na lista de tabelas)
void deletarTabela()
{
	char tmp[50];
	FILE *in;
	printf("Digite o nome da tabela a ser excluida: \n");
	scanf("%s",&tmp);
	remove(tmp);
}
//feito
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
//feito
void listarDadosTabela()
{
	char tmp[50];
	FILE *f;
	char linha[200];
	printf("\nDigite o nome da tabela: ");
	scanf("%s",&tmp);
	f = fopen(tmp,"r");
	if(f == NULL)
	{
		printf("\n Tabela nao existe.");
	}else
	{
		printf("TABELA: %s\n",tmp);
		while(!feof(f))
		{
			fgets(linha,200,f);
			printf("%s\n",linha);
		}
		printf("Fim de tabela.\n");
		fclose(f);
	}
}
void addLinhaTabela()
{

}
void pesquisarTabela()
{
}
void apagaLinhaTabela(char arquivo[],char id[])
{
	FILE *in;
	int count = 0,count2,i = 0,j = 1,op;
	char linha[1000], *compare;
	bool x = false;
	const char div[2] = "*";
	in = fopen(arquivo,"r");
	if (in == NULL)
	{
		printf("Tabela nao existe\n");
		return 1;
	}else
	{
		while(!feof(in))
		{
			linha[i] = fgetc(in);
			if (linha[i] == '\n')
			{
				count++;
				x = true;
			}
			else if (linha[i] == '*' && x == false)
			{
				count2++;
			}
			i++;
		}
		compare = strtok(linha,div);
		while( compare != NULL ) 
		{
      		compare = strtok(NULL, div);
      		j++;
      		if (strcmp(id,compare) == 0)
			{
				printf("Deletar linha %d ?\n",j/5);
				break;
			}
   		}
   		while(1)
   		{
   		printf("1-sim\n2-nao");
   		scanf("%d",&op);
   			if (op == 1)
   			{
   				//codigo para excluir linha aqui
   			}else if (op == 2)
   			{
   				break;
   			}else
   			{
   				printf("Opcao invalida\n");
   			}
   		}
	}

}
int main(int argc, char const *argv[])
{	
	printf("%d",numVariaveisTabela("tabelinha"));
	//apagaLinhaTabela("tabelinha","55");
	
	return 0;
}