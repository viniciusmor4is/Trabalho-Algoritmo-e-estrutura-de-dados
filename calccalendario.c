#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pdfgen.h"
#include "calccalendario.h"

int x = 0, y = 0;


int language()
{
    int l;
    printf("Escolha o idioma\t---\tChoose the language\n -> 0 para portugues\t---\t0 for portuguese\n -> 1 para ingles\t---\t1 for english\n");
    scanf("%d", &l);
    if (l==1)
    {
        printf("Voce selecionou ingles   ---   You selected english\n");
        return 1;
    }
    else
    {
        printf("Voce selecionou portugues   ---   You selected portuguese\n");
        return 0;
    }
}
int escolher_ano(int a)
{
    printf("Agora, escolha o ano:\n");
    scanf("%d", &a);
    return a;
}
int escolher_mes(int m)
{
    printf("Escolha o mes para a sua consulta:\n1 - Janeiro\t 2 - Fevereiro\t 3 - Marco\t 4 - Abril\n5 - Maio\t 6 - Junho\t 7 - Julho\t 8 - Agosto\n9 - Setembro\t 10 - Outubro\t 11 - Novembro\t 12 - Dezembro\n");
    scanf("%d", &m);
    return m;
}
int choose_year(int a)
{
    printf("Now, choose the year:\n");
    scanf("%d", &a);
    return a;
}
int choose_month(int m)
{
    printf("Choose the month that you want to see:\n1 - January\t 2 - February\t 3 - March\t 4 - April\n5 - May \t 6 - June\t 7 - July\t 8 - August\n9 - September\t 10 - October\t 11 - November\t 12 - December\n");
    scanf("%d", &m);
    return m;
}
char* calcmes(int *mes)
{
    if(*mes == 13)
        return "Janeiro";
    else if(*mes == 0)
        return "Dezembro";
    else if(*mes == 1)
        return "Janeiro";
    else if(*mes == 2)
        return "Fevereiro";
    else if(*mes == 3)
        return "Marco";
    else if(*mes == 4)
        return "Abril";
    else if(*mes == 5)
        return "Maio";
    else if(*mes == 6)
        return "Junho";
    else if(*mes == 7)
        return "Julho";
    else if(*mes == 8)
        return "Agosto";
    else if(*mes == 9)
        return "Setembro";
    else if(*mes == 10)
        return "Outubro";
    else if(*mes == 11)
        return "Novembro";
    else if(*mes == 12)
        return "Dezembro";
    else
        return "NULL";
}
char* calcmesING(int *mes)
{
    if(*mes == 13)
        return "January";
    else if(*mes == 0)
        return "December";
    else if(*mes == 1)
        return "January";
    else if(*mes == 2)
        return "February";
    else if(*mes == 3)
        return "March";
    else if(*mes == 4)
        return "April";
    else if(*mes == 5)
        return "May";
    else if(*mes == 6)
        return "June";
    else if(*mes == 7)
        return "July";
    else if(*mes == 8)
        return "August";
    else if(*mes == 9)
        return "September";
    else if(*mes == 10)
        return "October";
    else if(*mes == 11)
        return "November";
    else if(*mes == 12)
        return "December";
    else
        return "NULL";
}
int calcula_calendario(int *dia, int *Mes, int ano, int hh)
{
    int aux1, aux2, aux3;
    if(*Mes == 3)
        aux3 = 3, *dia = 31;

    else if(*Mes == 4)
        aux3 = 6, *dia = 30;

    else if(*Mes == 5)
        aux3 = 1, *dia = 31;

    else if(*Mes == 6)
        aux3 = 4, *dia = 30;

    else if(*Mes == 7)
        aux3 = 6, *dia = 31;


    else if(*Mes == 8)
        aux3 = 2, *dia = 31;

    else if(*Mes == 9)
        aux3 = 5, *dia = 30;

    else if(*Mes == 10)
        aux3 = 0, *dia = 31;

    else if(*Mes == 11)
        aux3 = 3, *dia = 30;

    else if(*Mes == 12)
        aux3 = 5, *dia = 31;


    aux1 = ano - 1900;
    aux2 = aux1 / 4;

    int b;

    if(*Mes == 2)
    {
        aux3 = 3, *dia = 28;
        if (ano%400 == 0)
            b = 1;
        else         if ((ano%4 == 0) && (ano%100 != 0))
            b = 1;
        if (b==1)
        {
            *dia = 29;
            if (!(*Mes == 3 || *Mes == 1))
                aux2--;

        }
        if (ano%100 == 0)
            aux2 = aux2 - (ano/100 - 20);
    }
    else if(*Mes == 0)
    {
        aux3 = 5, *dia = 31;
        ano--;
        if(!(aux1%4))
        {

            if (*Mes == 1)
                aux1 = ano - 1900;
            aux2 = aux1 / 4;
            aux2++;

        }
        else
        {
            aux1 = ano - 1900;
            aux2 = aux1 / 4;
        }

    }
    else if(*Mes == 13)
    {
        aux3 = 0, *dia = 31;
        ano++;
        aux1 = ano - 1900;
        aux2 = aux1 / 4;
        if(!((aux1)%4))
            aux2--;
    }
    else if(*Mes == 1)
    {
        aux3 = 0, *dia = 31;
        if(!((aux1)%4))
        {
            if (*Mes == 2)
            {
                aux1 = ano - 1900;
                aux2 = aux1 / 4;
            }
            else
            {
                aux1 = ano - 1900;
                aux2 = aux1 / 4;
                aux2--;
            }
        }
        else
        {
            aux1 = ano - 1900;
            aux2 = aux1 / 4;
            aux2--;

        }

    }
    aux1 = aux1 + aux2 + aux3;
    aux1 = aux1 % 7;
    return aux1;
}
void imprime_calendario(int aux1, int *dia, int *mes, int ano, struct pdf_doc *pdf, Arvore *raiz, int op1, int op2)
{
    char aux2[4], aux3 = 0;
    y = 460;
    for(int i = 1; i<=*dia; i++)
    {
        if(aux3 == 0)
            y = 460;
        else if(aux3 == 1)
            y = 380;
        else if(aux3 == 2)
            y = 300;
        else if(aux3 == 3)
            y = 220;
        else if(aux3 == 4)
            y = 140;
        else
            y = 60;
        if(aux1 == 0)
        {
            x = 150;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 20, x, y, PDF_BLACK);
        }
        if(aux1 == 1)
        {
            x = 260;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 20, x, y, PDF_BLACK);
        }
        if(aux1 == 2)
        {
            x = 370;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 20, x, y, PDF_BLACK);
        }
        if(aux1 == 3)
        {
            x = 480;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 20, x, y, PDF_BLACK);
        }
        if(aux1 == 4)
        {
            x = 590;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 20, x, y, PDF_BLACK);
        }

        if(aux1 == 5)
        {
            x = 700;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 20, x, y, PDF_BLACK);
            aux3++;
        }
        if(aux1 == 6)
        {
            x = 40;

            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 20, x, y, PDF_BLACK);

        }
        aux1++;
        if(aux1 > 6)
        {
            aux1 = 0;
        }



        compara_dia(i, mes, ano, raiz, pdf, op1, op2);


    }
    return;
}
Arvore* ler_evento(int bus)
{
    FILE *eventos;
    int Dia,Mes,Ano;
    char Tipo;
    char frase[50];
    printf("Digite o nome do arquivo .txt a ser lido --- Type the name of .txt archive that you used to write the events\n");
    fflush(stdin);
    scanf("%s", frase);
    strcat(frase,".txt");
    eventos = fopen(frase, "r");
    if(eventos == NULL)
    {
        printf("Arquivo nao encontrado\n");
         exit(-1);
    }

    Arvore *raiz = cria_arvore();
    while(fscanf(eventos, "%c %d %d %d", &Tipo, &Dia, &Mes, &Ano) != EOF)
    {
        fgets(frase, 20, eventos);
        frase[strlen(frase)-1] = '\0';
        if(bus == 1)
            encadear_evento(Tipo, Dia, Mes, Ano, frase, raiz);
        else if(bus == 0)
            encadear_dia(Tipo, Dia, Mes, Ano, frase, raiz);
    }
    fclose(eventos);
    return raiz;
}
int encadear_evento(char Tipo, int Dia, int Mes, int Ano, char frase[], Arvore *raiz)
{
    if(raiz == NULL)
        return 0;
    struct No *folha;
    folha = (struct No*) malloc(sizeof(struct No));
    if(folha == NULL)
        return 0;
    folha->dia = Dia;
    folha->tipo = Tipo;
    folha->ano = Ano;
    folha->mes = Mes;
    strcpy(folha->evento,frase);
    folha->dir = NULL;
    folha->esq = NULL;
    if(*raiz == NULL)
    {
        *raiz = folha;
    }
    else
    {
        struct No *atual = *raiz;
        struct No *anterior = NULL;
        while(atual != NULL)
        {
            anterior = atual;
            if(Tipo == atual->tipo)
            {
                if(Ano == atual->ano)
                {
                    if(Mes == atual->mes)
                    {
                        if(Dia == atual->dia)
                        {
                            if(frase[0] > atual->evento[0])
                            {
                                atual = atual->dir;
                            }
                            else
                                atual = atual->esq;
                        }
                        else if(Dia > atual->dia)
                            atual = atual->dir;
                        else
                            atual = atual->esq;

                    }
                    else if (Mes > atual->mes)
                        atual = atual->dir;
                    else
                        atual = atual->esq;

                }
                else if(Ano > atual->ano)
                    atual = atual->dir;
                else
                    atual = atual->esq;

            }
            else if(Tipo > atual->tipo)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(Tipo > anterior->tipo)
            anterior->dir = folha;
        else if(Ano == anterior->ano)
        {
            if(Ano > anterior->ano)
                anterior->dir = folha;
            else if(Tipo == anterior->tipo)
            {
                if(Mes > anterior->mes)
                    anterior->dir = folha;
                else if(Mes == anterior->mes)
                {
                    if(Dia > anterior->dia)
                        anterior->dir = folha;
                    else if(Dia == anterior->dia)
                    {

                        if(frase[0] > anterior->evento[0])
                        {
                            anterior->dir = folha;
                        }
                        else
                            anterior->esq = folha;
                    }
                    else
                        anterior->esq = folha;
                }
                else
                    anterior->esq = folha;
            }
            else
                anterior->esq = folha;
        }
        else
            anterior->esq = folha;
    }
    return 1;
}
Arvore* cria_arvore()
{
    Arvore *raiz = (Arvore*)malloc(sizeof(Arvore));
    if(raiz != NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}
void compara_dia(int i, int *mes, int ano, Arvore *raiz, struct pdf_doc *pdf, int op1, int op2)
{
    if(*raiz != NULL)
    {
        compara_dia(i, mes, ano, &((*raiz)->esq), pdf, op1, op2);
        if((*raiz)->ano == 0)
            (*raiz)->ano = ano;
        if((*raiz)->mes == 0)
            (*raiz)->mes = *mes;
        if(ano == (*raiz)->ano)
            if(*mes == (*raiz)->mes)
                if(i == ((*raiz)->dia)||((*raiz)->dia == 0))
                {
                    if(op1 == 1)
                    {
                        y = y - 12;
                        if(op2 == 0 || op2 == 4)
                        {
                            if ((*raiz)->tipo == 'A')
                            {
                                pdf_add_jpeg(pdf, NULL, (x+5), y, 10, 10, "./bolo.jpg");
                                pdf_add_text(pdf, NULL, (*raiz)->evento, 10, (x+15), y, PDF_BLACK);
                            }
                        }
                        if(op2 == 1 || op2 == 4)
                        {
                            if ((*raiz)->tipo == 'F')
                                pdf_add_text(pdf, NULL, (*raiz)->evento, 10, (x+15), y, PDF_BLACK);
                        }
                        if(op2 == 2 || op2 == 4)
                        {
                            if ((*raiz)->tipo == 'O')
                                pdf_add_text(pdf, NULL, (*raiz)->evento, 10, (x+15), y, PDF_BLACK);
                        }
                        if(op2 == 3 || op2 == 4)
                        {
                            if ((*raiz)->tipo == 'V')
                            {
                                pdf_add_jpeg(pdf, NULL, (x+5), y, 10, 10, "./aviao1.jpg");
                                pdf_add_text(pdf, NULL, (*raiz)->evento, 10, (x+15), y, PDF_BLACK);
                            }

                        }



                    }
                    else if(op1 == 0)
                    {
                            if((op2 == 0 || op2 == 4) && ((*raiz)->tipo == 'A'))
                                printf("%c ---- %s\n", (*raiz)->tipo, (*raiz)->evento);
                            if((op2 == 1 || op2 == 4) && ((*raiz)->tipo == 'F'))
                                printf("%c ---- %s\n", (*raiz)->tipo, (*raiz)->evento);
                            if((op2 == 2 || op2 == 4) && ((*raiz)->tipo == 'O'))
                                printf("   ---- %s\n",(*raiz)->evento);
                            if((op2 == 3 || op2 == 4) && ((*raiz)->tipo == 'V'))
                                printf("%c ---- %s\n", (*raiz)->tipo, (*raiz)->evento);
                    }

                }


        compara_dia(i, mes, ano, &((*raiz)->dir), pdf, op1, op2);
    }
}
void imprime_minidir(int aux1m, int *dia, int *proxMes, int proxAno, struct pdf_doc *pdf)
{
    char aux2[4], aux3 = 0;
    y = 570;
    int aux4 = proxAno - 1900;
    if(aux4%4)   //conserta erro do ano bissexto
        aux1m++;
    else
    {
        if (*proxMes > 2)
            aux1m++;
    }
    for(int i = 1; i<=*dia; i++)
    {
        if(aux3 == 0)
            y = 570;
        else if(aux3 == 1)
            y = 557;
        else if(aux3 == 2)
            y = 544;
        else if(aux3 == 3)
            y = 531;
        else if(aux3 == 4)
            y = 518;
        else
            y = 505;

        if(aux1m > 6)
        {
            aux1m = 0;
        }
        if(aux1m == 0)
        {
            x = 684;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 10, x, y, PDF_BLACK);
        }
        if(aux1m == 1)
        {
            x = 700;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 10, x, y, PDF_BLACK);
        }
        if(aux1m == 2)
        {
            x = 716;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 10, x, y, PDF_BLACK);
        }
        if(aux1m == 3)
        {
            x = 732;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 10, x, y, PDF_BLACK);
        }
        if(aux1m == 4)
        {
            x = 748;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 10, x, y, PDF_BLACK);
        }
        if(aux1m == 5)
        {
            x = 764;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 10, x, y, PDF_BLACK);

        }
        if(aux1m == 6)
        {
            x = 780;
            sprintf(aux2, "%d", i);
            pdf_add_text(pdf, NULL, aux2, 10, x, y, PDF_BLACK);
            aux3++;
        }
        aux1m++;
    }
    return;
}
void imprime_miniesq(int aux1mm, int *dia, int *MesAnt, int AnoAnt, struct pdf_doc *pdf)
{
    char aux2m[4], aux3m = 0;
    y = 570;
    int aux4m = AnoAnt - 1900;
    if(aux4m%4)   //conserta erro do ano bissexto
        aux1mm++;
    else
    {
        if (*MesAnt > 2)
            aux1mm++;
    }
    for(int i = 1; i<=*dia; i++)
    {
        if(aux3m == 0)
            y = 570;
        else if(aux3m == 1)
            y = 557;
        else if(aux3m == 2)
            y = 544;
        else if(aux3m == 3)
            y = 531;
        else if(aux3m == 4)
            y = 518;
        else
            y = 505;

        if(aux1mm > 6)
        {
            aux1mm = 0;
        }

        if(aux1mm == 0)
        {
            x = 36;
            sprintf(aux2m, "%d", i);
            pdf_add_text(pdf, NULL, aux2m, 10, x, y, PDF_BLACK);
        }
        if(aux1mm == 1)
        {
            x = 50;
            sprintf(aux2m, "%d", i);
            pdf_add_text(pdf, NULL, aux2m, 10,  x, y, PDF_BLACK);
        }
        if(aux1mm == 2)
        {
            x = 66;
            sprintf(aux2m, "%d", i);
            pdf_add_text(pdf, NULL, aux2m, 10,  x, y, PDF_BLACK);
        }
        if(aux1mm == 3)
        {
            x = 82;
            sprintf(aux2m, "%d", i);
            pdf_add_text(pdf, NULL, aux2m, 10,  x, y, PDF_BLACK);
        }
        if(aux1mm == 4)
        {
            x = 98;
            sprintf(aux2m, "%d", i);
            pdf_add_text(pdf, NULL, aux2m, 10,  x, y, PDF_BLACK);
        }

        if(aux1mm == 5)
        {
            x = 114;
            sprintf(aux2m, "%d", i);
            pdf_add_text(pdf, NULL, aux2m, 10,  x, y, PDF_BLACK);

        }
        if(aux1mm == 6)
        {
            x = 130;

            sprintf(aux2m, "%d", i);
            pdf_add_text(pdf, NULL, aux2m, 10,  x, y, PDF_BLACK);
            aux3m++;
        }
        aux1mm++;


    }
    return;
}
void imprime_arvore(Arvore *raiz, char Tipo, int bus, int ano, int mes, int idioma)
{
    if(*raiz != NULL)
    {
        imprime_arvore(&((*raiz)->esq), Tipo, bus, ano, mes, idioma);
        if(bus == 0)
        {
            if((*raiz)->ano == 0)
                (*raiz)->ano = ano;
            if((*raiz)->mes == 0)
                (*raiz)->mes = mes;
            if(ano == (*raiz)->ano)
            {
                if(mes == (*raiz)->mes)
                {
                    if((*raiz)->tipo == 'O')
                        (*raiz)->tipo = '\0';
                    printf("%c ---- %s\t", (*raiz)->tipo, (*raiz)->evento);
                    if((*raiz)->dia == 0)
                    {
                        if (idioma == 0)
                        printf("Todos os dias");
                        else printf("Everyday");
                    }
                    else
                    {
                        if (idioma == 0)
                        printf("Dia %d",(*raiz)->dia);
                        else printf("Day %d", (*raiz)->dia);
                    }
                    printf("\n");
                }
            }

        }
        else if(bus == 1)
        {
            if((*raiz)->tipo == Tipo)
            {
                printf("%s\t%d/%d/%d\n",(*raiz)->evento, (*raiz)->dia,(*raiz)->mes,(*raiz)->ano);
            }

        }
        imprime_arvore(&((*raiz)->dir), Tipo, bus, ano, mes, idioma);
    }
}
void busca(Arvore *raiz, int idioma)
{
    char Tipo;
    int bus, ano, mes;
    printf("Digite a Forma de Busca por eventos\n0- Data\t\t1- Evento\n");
    scanf("%d", &bus);
    raiz = ler_evento(bus);
    if(bus == 0)
    {
        printf("Digite o Ano\n");
        scanf("%d", &ano);
        printf("Digite o Mes\n");
        scanf("%d", &mes);
    }
    else if(bus == 1)
    {
        printf("Digite o Tipo do evento\n");
        fflush(stdin);
        scanf("%c", &Tipo);
    }
    imprime_arvore(raiz, Tipo, bus, ano, mes, idioma);
}
void search(Arvore *raiz, int idioma)
{
    char Tipo;
    int bus, ano, mes;
    printf("Type how do you want to do this search s\n0- By date\t\t1- By event\n");
    scanf("%d", &bus);
    raiz = ler_evento(bus);
    if(bus == 0)
    {
        printf("Type the year\n");
        scanf("%d", &ano);
        printf("Type the month\n");
        scanf("%d", &mes);
    }
    else if(bus == 1)
    {
        printf("Type the event's type\n");
        fflush(stdin);
        scanf("%c", &Tipo);
    }
    imprime_arvore(raiz, Tipo, bus, ano, mes, idioma);
}
void imprime_lista(int aux1, int *dia, int *mes, int ano, Arvore *raiz, int op1, struct pdf_doc *pdf, int op2)
{
    for(int i = 1; i<=*dia; i++)
    {
        printf("%.2d\t", i);
        if(aux1 == 0)
        {
            printf("Segunda");
        }
        if(aux1 == 1)
        {
            printf("Terca");
        }
        if(aux1 == 2)
        {
            printf("Quarta");
        }
        if(aux1 == 3)
        {
            printf("Quinta");
        }
        if(aux1 == 4)
        {
            printf("Sexta");
        }
        if(aux1 == 5)
        {
            printf("Sabado");
        }
        if(aux1 == 6)
        {
            printf("Domingo");
        }
        aux1++;
        if(aux1 == 7)
            aux1 = 0;
        printf("\n");
        compara_dia(i, mes, ano, raiz, pdf, op1, op2);
    }
}
int escolhe_mini_calendario(int c)
{
    printf("Qual modo de exibicao do calendario voce deseja? Digite seu respectivo numero:\n (1) Calendario principal e calendario do mes seguinte.\n (2) Calendario principal e dos meses seguinte e anterior.\n");
    scanf("%d", &c);
    return c;
}
int choose_mini_calendar(int c)
{
    printf("Which type of exhibition do you want? Text the following number\n (1) Main calendar with next month's calendar.\n (2) Main calendar with next and previous month's calendars.\n");
    scanf ("%d", &c);
    return c;
}
int encadear_dia(char Tipo, int Dia, int Mes, int Ano, char frase[], Arvore *raiz)
{
    if(raiz == NULL)
        return 0;
    struct No *folha;
    folha = (struct No*) malloc(sizeof(struct No));
    if(folha == NULL)
        return 0;
    folha->dia = Dia;
    folha->tipo = Tipo;
    folha->ano = Ano;
    folha->mes = Mes;
    strcpy(folha->evento,frase);
    folha->dir = NULL;
    folha->esq = NULL;
    if(*raiz == NULL)
    {
        *raiz = folha;
    }
    else
    {
        struct No *atual = *raiz;
        struct No *anterior = NULL;
        while(atual != NULL)
        {
            anterior = atual;
            if(Dia == atual->dia)
            {
                if(Tipo == atual->tipo)
                {
                    if(Ano == atual->ano)
                    {
                        if(Mes == atual->mes)
                        {
                            if(frase[0] > atual->evento[0])
                            {
                                atual = atual->dir;
                            }
                            else
                                atual = atual->esq;
                        }
                        else if (Mes > atual->mes)
                            atual = atual->dir;
                        else
                            atual = atual->esq;
                    }
                    else if(Ano > atual->ano)
                        atual = atual->dir;
                    else
                        atual = atual->esq;
                }
                else if(Tipo > atual->tipo)
                    atual = atual->dir;
                else
                    atual = atual->esq;
            }
            else if(Dia > atual->dia)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(Dia > anterior->dia)
            anterior->dir = folha;
        else if(Dia == anterior->dia)
        {
            if(Tipo == anterior->tipo)
                anterior->dir = folha;
            else if(Tipo > anterior->tipo)
            {
                if(Ano > anterior->ano)
                    anterior->dir = folha;
                else if(Ano == anterior->ano)
                {
                    if(Mes > anterior->mes)
                    {
                        if(frase[0] > anterior->evento[0])
                        {
                            anterior->dir = folha;
                        }
                        else
                            anterior->esq = folha;
                    }
                    else if(Mes == anterior->mes)
                        anterior->dir = folha;
                    else
                        anterior->esq = folha;
                }
                else
                    anterior->esq = folha;
            }
            else
                anterior->esq = folha;
        }
        else
            anterior->esq = folha;
    }
    return 1;
}
