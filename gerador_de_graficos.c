#include <stdio.h>

/*void mostrarGrafico(int valores[], int qtdvalores)
{
      for(int i=0; i<(qtdvalores);i++)
      {
        if(valores[i]>=0)
        {
            printf("%d | ", i+1);
            for(int j=0; j<valores[i];j++)
            {
                  printf("#");
            }
            printf("\n");
        }
        else
        {
            for(int j=0;j<-valores[i];j++)
            {
                printf("#");
            }
            printf(" | %d\n", i+1);
        }
      }
}*/

int maiorValor(int valores[], int qtdvalores)
{
    int maior=valores[0];
    for(int i=0;i<qtdvalores;i++)
    {
        if(maior<valores[i])
        {
            maior=valores[i];
        }
    }
    return maior;
}

int menorValor(int valores[], int qtdvalores)
{
    int menor=valores[0];
    for(int i=0;i<qtdvalores;i++)
    {
        if(menor>valores[i])
        {
            menor=valores[i];
        }
    }
    return menor;
}

void mostrarGrafico(int valores[], int qtdvalores)
{
    int maior=maiorValor(valores, qtdvalores);
    int menor=menorValor(valores, qtdvalores);

    for(int i=maior;i>=menor;i--)
    {
        printf("%3d | ", i);
        for(int j=0;j<qtdvalores;j++)
        {
            if(i==0)
            {
                printf("-+-");
            }
            else
            {
                if(i>0 && valores[j]>0 && valores[j]>=i)
                {
                    printf(" # ");
                }
                else if(i<0 && valores[j]<0 && valores[j]<=i)
                {
                    printf(" # ");
                }
                else
                {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }
    printf("      ");
    for(int j=0; j<qtdvalores; j++)
    {
        if(j+1<10)
        {
            printf(" %d ", j+1);
        }
        else
        {
            printf("%d ",j+1);
        }
    }
    printf("\n");
}

int main()
{
    int QtdValores;
    printf("Quantos valores voce quer inserir?\n");
    scanf("%d", &QtdValores);
    while(QtdValores<=0)
    {
        printf("o numero de valores deve ser maior que 0, insira novamente\n");
        scanf("%d", &QtdValores);
    }
    int Valores[QtdValores];
    printf("Agora insira cada valor\n");
    for(int i=0;i<QtdValores;i++)
    {
        scanf("%d", &Valores[i]);
        while(Valores[i] > 99 || Valores[i] < -99)
        {
            printf("o valor deve estar entre -99 e 99, insira novamente:\n");
            scanf("%d", &Valores[i]);
        }
    }
    printf("Os valores inseridos sao:\n");
    for(int i=0;i<QtdValores;i++)
    {
        printf("%d ", Valores[i]);
    }
    printf("\n");
    mostrarGrafico(Valores, QtdValores);
    
    return 0;
}
