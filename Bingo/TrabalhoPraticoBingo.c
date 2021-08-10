//		Bacharelado em Ciência da Computação - IFSULDEMINAS
//		Algoritmos I - Prof. Hiran
//		Trabalho Pratico I

//Relizado pelos seguintes estudantes:

//	Ryan Henrique Silva Alves
//	Geovanna Costa Santos
//	Milnner Kauan Torres Andrade

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int cartela[10][25], //Cartelas do bingo
        numeros_sorteados[99], //Array utilizado para saber qual o numero que ja foi sorteado
        count = 0, //tem uso em varias partes do programa, o principal e contar quantas vezes ouve sorteio
        op = 1,//vai ser usado para definir se a execução sera numero a numero ou completa
        i,j,k,l, index, tmp, achou = 1; //variaveis de controle

    char enter; // utilizado para esperar a tecla enter

    srand(time(NULL));//Gera uma semente nova para RAND_MAX em stdlib.h
    //carrga as cartelas com seus numeros, sem repetir numeros dentro delas ou repitirem-se entre si
    for( i = 0;i<10;i++)
    {
        cartela[i][24]=0;
        for( j = 0;j<24;j++)
        {
            cartela[i][j] = (rand()%98)+1; //gera numeros aleatorios
            if(j == 23)
            {
                for( k = 0;k < 24; k++)
                    for( l = 0;l<24; l++)
                        if(k!=l)                                    //quando os index for diferente ele faz a checagem para saber se algum numero repete
                            if(cartela[i][k]==cartela[i][l])
                                cartela[i][k--] = (rand()%99)+1;       //caso repita ele gera um numero novo para a posicao, e fara isso ate que nenhum repita

                for( k = 0;k < 24; k++)                          // coloca todos os numeros em ordem
                    for( l = 0;l<24; l++)
                        if(cartela[i][k] < cartela[i][l])
                        {
                            tmp = cartela[i][k];
                            cartela[i][k] = cartela[i][l];
                            cartela[i][l] = tmp;
                        }
                for( index = 0; index < i; index++) //faz a checagem se a cartela atual e identica a alguma outra
                {
                    for( k = 0;k < 24; k++)
                        for( l = 0;l<24; l++)
                            if(k!=l)
                                if (cartela[i][k] == cartela[index][l])
                                    count++;

                    if (count == 24)                    //caso uma cartela seja identica i repete a iteracao
                        i--;

                    count = 0;                          //zerar o count
                }
            }
        }
    }
    printf("As tabelas são");
	for(i = 0; i < 10; i++)//Mostra as cartelas
	{
		printf("\nTabela %d:\n", i+1);
		for(j=0, count = 1;j < 24;j++, count++)
		{
			printf(count%5 != 0?"%02d  -  ":"%02d\n",cartela[i][j]);
			if(j==11)
			{
				printf("XX  -  ");
				count++;
			}
		}
	}
	count = 0;
   	printf("\n\n");

    do{		//define qual deve ser a execucao do programa
    printf("Caso queira sorteio completo tecle [0][ENTER]\nSe quiser sorteio numero a numero tecle [1] e [ENTER]\n");
    scanf("%d", &op);
    printf("\n");

	}while(!(op == 1 || op == 0));     //Tem que se atingir que enter deve ser igual a 1 ou 0

    //Sorteio dos numeros definitivos
    for(i = 0; i < 99 && achou; i++)
    {

            do//gera numeros aleatorios
            {
                tmp = (rand()%99)+1;
                achou = 0;
                for(j = 0; j < 99 ; j++)
                    if(tmp == numeros_sorteados[j]) // compara se tmp existe no vetor
                        achou = 1;
            } while (achou);                        //se achou verdadeiro repete e gera um novo numero

            achou = 1;

            for(j = 0; j < 10 ;j++)
            {
            	for(k = 0;k < 24;k++)
            		if(tmp == cartela[j][k])
            		{
            			cartela[j][24]++;
            			break;
            		}
            }
            for(j = 0; j < 10; j++)
           			if( cartela[j][24] == 24)
           				achou = 0;


        if(op == 1) //quando o programa deve ser executado numero a numero ele executa esta condicao
        {
        	printf("\n");
		    scanf("%c", &enter);
		    printf("O numero sorteado foi %d\n\n", tmp); 
		    printf("Contagem das cartelas:\n///");
			for(j = 0; j < 10; j++)//Mostra quanto cada cartela acertou
				printf(j != 4 ? "Tabela %2d: %2d /// " : "Tabela %2d: %2d ///\n///", j+1,cartela[j][24]);
			printf("\n------------------------------------------------------------------------------------------------\n\n");
		}

        count++;
        numeros_sorteados[i] = tmp;                 //caso tmp nao exista no vetor adicione e prossegue para a proxima iteracao
    }

	int copia_numeros_sorteados[count];

	for(k = 0;k < count; k++) //preenche o vetor com os numeros sorteados
	{
		copia_numeros_sorteados[k] = numeros_sorteados[k];
	}

    for( k = 0;k < count; k++)                          // coloca todos os numeros em ordem
        for( l = 0;l < count; l++)
            if(copia_numeros_sorteados[k] < copia_numeros_sorteados[l])
            {
                int tmp = copia_numeros_sorteados[k];
                copia_numeros_sorteados[k] = copia_numeros_sorteados[l];
                copia_numeros_sorteados[l] = tmp;
            }
    printf("\n\nQuantos numeros foram sorteados: %d\n\n",count);

    for( i = 0; i < count;i++)//mostra os numeros sorteados
    {
        printf("%02d   ",copia_numeros_sorteados[i]);
  		if((i+1) % 10 == 0)
        {
        	printf("\n");
        }
    }
    printf("\n\n");

    printf("///");
    for(i = 0; i < 10; i++)//Mostra quanto cada cartela acertou
		printf(i != 4 ? "Tabela %2d: %2d /// " : "Tabela %2d: %2d ///\n///", i+1,cartela[i][24]);

    printf("\n\n");

    for(i = 0; i < 10; i++)//Mostra as cartelas
    	if(cartela[i][24] == 24)
    	{
    		printf("\nTabela %d: %d\n", i+1,cartela[i][24]);
    		for(j=0, count = 1;j < 24;j++, count++)
    		{
				printf(count%5 != 0?"%02d  -  ":"%02d\n",cartela[i][j]);
				if(j==11)
				{
					printf("XX  -  ");
					count++;
				}
    		}
    	}
    		printf("\n\n");
    return 0;
}
