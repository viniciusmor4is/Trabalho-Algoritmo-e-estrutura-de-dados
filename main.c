#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pdfgen.h"
#include "calccalendario.h"



int main()
{
    int aux1, dia[1], mes[1], ano, op1, op2 = 4, c, hh;
    char ANO[6];
    Arvore *raiz = cria_arvore();
    int idioma = language();
    if (idioma == 0)
    {
        printf("0- Buscar eventos especificos\t\t1- Imprimir Calendario\n");
        scanf("%d", &op2);
        if(op2 == 0)
        {
            busca(raiz, idioma);
        }
    }
    else if (idioma == 1)
    {
        printf("0- Search by date or type of events\t\t1- Print Calendar\n");
        scanf("%d", &op2);
        if (op2 == 0)
        {
            search(raiz, idioma);
        }
    }
    if(op2 == 1)
    {
        raiz = ler_evento(1);
        struct pdf_info info =
        {
            .creator = "My software",
            .producer = "My software",
            .title = "My document",
            .author = "My name",
            .subject = "My subject",
            .date = "Today"
        };
        struct pdf_doc *pdf = pdf_create(PDF_A4_HEIGHT, PDF_A4_WIDTH, &info);
        if (idioma == 0)
        {
            printf("Qual tipo de evento imprimir\n0-Aniversario\t\t1-Feriados\n2-Outros\t\t3-Viagens\n4-Todos\n");
            scanf("%d", &op2);
            printf("(0) - Lista\t\t(1) - Pdf\n");
            scanf("%d", &op1);
        }
        else if (idioma == 1)
        {
            printf("What kind of event to print\n0-Anniversary\t\t1-Holidays\n2-Others\t\t3-Travel\n4-All\n");
            scanf("%d", &op2);
            printf("(0) - List\t\t(1) - PDF\n");
            scanf("%d", &op1);
        }
        if(op1 == 0)
        {
            if (idioma == 1)
            {
                *mes = choose_month();
                ano = choose_year();
            }
            else if(idioma == 0)
            {
                *mes = escolher_mes();
                ano = escolher_ano();
            }
            hh = *mes;
            system("cls");
            aux1 = calcula_calendario(dia, mes, ano, hh);
            imprime_lista(aux1, dia, mes, ano, raiz, op1, pdf, op2);
        }
        else if(op1 == 1)
        {
            pdf_set_font(pdf, "Times-Roman");
            pdf_append_page(pdf);
            pdf_add_jpeg(pdf, NULL, 30, 0, 780, 500, "./calendario.jpg");
            if (idioma == 1)
            {
                *mes = choose_month();
                ano = choose_year();
                hh = *mes;
                c = choose_mini_calendar();
                if (c == 1)
                {
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_calendario(aux1, dia, mes, ano, pdf, raiz, op1, op2);
                    pdf_add_text(pdf, NULL, calcmesING(mes), 60, 42, 510, PDF_BLACK);
                    sprintf(ANO, "%d", ano);
                    pdf_add_text(pdf, NULL, ANO, 60, 308, 510, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SUNDAY", 15, 55, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "MONDAY", 15, 165, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "TUESDAY", 15, 275, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "WEDNESDAY", 15, 375, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "THURSDAY", 15, 495, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "FRIDAY", 15, 605, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SATURDAY", 15, 712, 480, PDF_BLACK);
                    pdf_add_jpeg(pdf, NULL, 680, 500, 110, 85, "./calendario_menor.jpg");
                    *mes = *mes + 1;
                    if(*mes == 13)
                        sprintf(ANO, "%d", ano + 1);
                    else
                        sprintf(ANO, "%d", ano);
                    pdf_add_text(pdf, NULL, ANO, 10, 730, 585, PDF_BLACK);
                    pdf_add_text(pdf, NULL, calcmesING(mes), 10, 680, 585, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_minidir(aux1, dia, mes, ano, pdf);
                }
                else
                {
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_calendario(aux1, dia, mes, ano, pdf, raiz, op1, op2);
                    pdf_add_text(pdf, NULL, calcmesING(mes), 60, 209, 510, PDF_BLACK);
                    sprintf(ANO, "%d", ano);
                    pdf_add_text(pdf, NULL, ANO, 60, 473, 510, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SUNDAY", 15, 55, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "MONDAY", 15, 165, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "TUESDAY", 15, 275, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "WEDNESDAY", 15, 375, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "THURSDAY", 15, 495, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "FRIDAY", 15, 605, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SATURDAY", 15, 712, 480, PDF_BLACK);
                    pdf_add_jpeg(pdf, NULL, 680, 500, 110, 85, "./calendario_menor.jpg");
                    pdf_add_jpeg(pdf, NULL, 30, 500, 110, 85, "./calendario_menor2.jpg");
                    *mes = *mes + 1;
                    if(*mes == 13)
                        sprintf(ANO, "%d", ano + 1);
                    pdf_add_text(pdf, NULL, ANO, 10, 730, 585, PDF_BLACK);
                    pdf_add_text(pdf, NULL, calcmesING(mes), 10, 680, 585, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_minidir(aux1, dia, mes, ano, pdf);
                    *mes = *mes - 2;
                    if(*mes == 0)
                        sprintf(ANO, "%d", ano - 1);
                    else
                        sprintf(ANO, "%d", ano);
                    pdf_add_text(pdf, NULL, ANO, 10, 80, 585, PDF_BLACK);
                    pdf_add_text(pdf, NULL, calcmesING(mes), 10, 30, 585, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_miniesq(aux1, dia, mes, ano, pdf);
                }
            }
            else if(idioma == 0)
            {
                *mes = escolher_mes();
                ano = escolher_ano();
                hh = *mes;
                c =escolhe_mini_calendario();
                if (c==1)
                {
                    pdf_add_text(pdf, NULL, calcmes(mes), 60, 45, 510, PDF_BLACK);
                    sprintf(ANO, "%d", ano);
                    pdf_add_text(pdf, NULL, ANO, 60, 280, 510, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "DOMINGO", 15, 55, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SEGUNDA", 15, 165, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, " TERCA", 15, 275, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, " QUARTA", 15, 385, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "QUINTA", 15, 495, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SEXTA", 15, 605, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SABADO", 15, 715, 480, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_calendario(aux1, dia, mes, ano, pdf, raiz, op1, op2);
                    pdf_add_jpeg(pdf, NULL, 680, 500, 110, 85, "./calendario_menor.jpg");
                    *mes = *mes + 1;
                    if(*mes == 13)
                        sprintf(ANO, "%d", ano + 1);
                    pdf_add_text(pdf, NULL, ANO, 10, 730, 585, PDF_BLACK);
                    pdf_add_text(pdf, NULL, calcmes(mes), 10, 680, 585, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_minidir(aux1, dia, mes, ano, pdf);
                }
                else
                {
                    pdf_add_text(pdf, NULL, calcmes(mes), 60, 215, 510, PDF_BLACK);
                    sprintf(ANO, "%d", ano);
                    pdf_add_text(pdf, NULL, ANO, 60, 460, 510, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "DOMINGO", 15, 55, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SEGUNDA", 15, 165, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, " TERCA", 15, 275, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, " QUARTA", 15, 385, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "QUINTA", 15, 495, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SEXTA", 15, 605, 480, PDF_BLACK);
                    pdf_add_text(pdf, NULL, "SABADO", 15, 715, 480, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_calendario(aux1, dia, mes, ano, pdf, raiz, op1, op2);
                    pdf_add_jpeg(pdf, NULL, 680, 500, 110, 85, "./calendario_menor.jpg");
                    pdf_add_jpeg(pdf, NULL, 30, 500, 110, 85, "./calendario_menor2.jpg");
                    *mes = *mes + 1;
                    if(*mes == 13)
                        sprintf(ANO, "%d", ano + 1);
                    pdf_add_text(pdf, NULL, ANO, 10, 730, 585, PDF_BLACK);
                    pdf_add_text(pdf, NULL, calcmes(mes), 10, 680, 585, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_minidir(aux1, dia, mes, ano, pdf);
                    *mes = *mes - 2;
                    if(*mes == 0)
                        sprintf(ANO, "%d", ano - 1);
                    pdf_add_text(pdf, NULL, ANO, 10, 80, 585, PDF_BLACK);
                    pdf_add_text(pdf, NULL, calcmes(mes), 10, 30, 585, PDF_BLACK);
                    aux1 = calcula_calendario(dia, mes, ano, hh);
                    imprime_miniesq(aux1, dia, mes, ano, pdf);
                }
            }
            pdf_save(pdf, "output.pdf");
            pdf_destroy(pdf);
        }
    }
    return 0;
}
