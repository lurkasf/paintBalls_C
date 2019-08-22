 /*gcc pinturaBolihasMouse.c console_v1.5.4.c graphics_v1.1.c -o pinturaBolinhasMouse.exe -lgdi32 -Wall -pedantic -Wextra*/

 /* Descrição: Ler uma tecla específica do teclado */
 /* 14/03/2015 */
 /* Declaração dos arquivos cabeçalhos */
 #include <stdio.h>            /* função printf() */
 #include "console_v1.5.4.h"  /* função Evento() */
 #include "graphics_v1.1.h"  /*funções graficas */

 /* Inicio do programa */
int main(int argc, char **argv)
{
	/* Variável que armazenará o evento do teclado */
	EVENTO mouseEvent;
	EVENTO keyEvent;
	
	/* Silenciar o warning relativo aos parämetros não usados da função main() */

	COLORREF colorLine;
	COORD resol=getResolucaoMonitor();
	COORD tamletra=getTamanhoFonteConsole();
	printf("Resolucao: %i X %i\n", resol.X, resol.Y);
	printf("Tamanho da fonte: %i x %i",tamletra.X,tamletra.Y);
	colorLine=RGB(rand()%255,rand()%255,rand()%255);
	int ponto1,ponto2;
	int ativo = 1;
	argc = argc;
	argv = argv;
	setCursorStatus(DESLIGAR);
	do{
		mouseEvent = Evento();
		keyEvent = Evento();

		/*
			ISSO ERA PRA LIGAR E DESLIGAR A PINTURA KK
		if(keyEvent.teclado.codigo_tecla == ENTER)
		{
			if(ativo == 1)
			{
				ativo = 0;
			}
			else
			{
				if(ativo == 0)
				{
					ativo = 1;
				}
			}
		}*/
		if(ativo == 1)
		{
	        if(mouseEvent.tipo_evento & MOUSE_EVENT)
			{
				//printf("X:%i Y:%i",mouseEvent.mouse.posicao.X, mouseEvent.mouse.posicao.Y);
				circulo(mouseEvent.mouse.posicao.X*tamletra.X, mouseEvent.mouse.posicao.Y*tamletra.Y,1,colorLine);//multiplica por 7.2(de 720) e por 13.6(de1366)
				colorLine=RGB(rand()%255,rand()%255,rand()%255);
				circulo(mouseEvent.mouse.posicao.X*tamletra.X, mouseEvent.mouse.posicao.Y*tamletra.Y,2,colorLine);
				colorLine=RGB(rand()%255,rand()%255,rand()%255);
				circulo(mouseEvent.mouse.posicao.X*tamletra.X, mouseEvent.mouse.posicao.Y*tamletra.Y,3,colorLine);
				colorLine=RGB(rand()%255,rand()%255,rand()%255);
				circulo(mouseEvent.mouse.posicao.X*tamletra.X, mouseEvent.mouse.posicao.Y*tamletra.Y,4,colorLine);
				colorLine=RGB(rand()%255,rand()%255,rand()%255);
				circulo(mouseEvent.mouse.posicao.X*tamletra.X, mouseEvent.mouse.posicao.Y*tamletra.Y,5,colorLine);
			}
		}
		if(keyEvent.teclado.codigo_tecla == ESC)
		{
			setCursorStatus(LIGAR);
			printf("\nJOGO TERMINADO!\n");
			break;
		}
	}while(1); 
	/* Retornar que o programa encerrou com sucesso */
	return 0;
} /* Fim do programa */