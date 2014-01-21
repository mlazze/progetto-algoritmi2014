#include <stdio.h>
#include "prog.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *read_line(void);

int main(void) {
	int s = 0,t;
	while (s!=10) {
	printf("1 per creare un nuovo esperimento\n2 per inserire un nuovo frammento\n3 per inserire un nuovo enzima\n4 per eliminare un enzima\n5 per preparare un nuovo esperimento\n6 per eseguire l'esperimento\n7 per calcolare gli enzimi minimi necessari a passare da f a g\n8 per calcolare l'energia minima e gli enzimi necessari a passare da f a g\n9 per confrontare la similarità tra f e g\n10 per uscire\n\nInserire un valore: ");
	char c = getchar();
	if (isdigit(c)) {
		s = c - '0';
	} else s = 0;
	getchar();

	Esperimento *e = NULL;
	Benznode *alberoenzimi;
	char *a,*b,*enz;

	switch(s) {
		case 1: //nuovo_esp
			e=crea_nuovo();
			break;
		case 2: //nuovo_framm
			if(!e) {
				printf("Creare prima un nuovo esperimento\n");
				break;
			}
			printf("Inserire il nome del nuovo frammento:\n");
			a= read_line();
			nuovo_frammento(e->grafo,a);
			printf("Frammento %s inserito\n",a);
			break;
		case 3: //nuovo_enz
			if(!e) {
				printf("Creare prima un nuovo esperimento\n");
				break;
			}
			printf("Inserire il nome dell'enzima da inserire:\n");
			a= read_line();
			nuovo_enzima(e->alberoenzimi,a);
			printf("Enzima %s inserito\n",a);
			break;
		case 4: //el_enz
			if(!e) {
				printf("Creare prima un nuovo esperimento\n");
				break;
			}
			printf("Inserire il nome dell'enzima da eliminare:\n");
			a= read_line();
			elimina_enzima(e->alberoenzimi,a);
			printf("Frammento %s inserito\n",a);
			break;
		case 5: //prepare_esp
			printf("Inserire il nome del file dei frammenti:\n");
			a= read_line();
			printf("Inserire il nome del file degli enzimi:\n");
			b= read_line();
			prepara_esperimento(e,a,b);
			printf("Esperimento inserito\n");
			break;
		case 6: //esegui esp
			if(!e) {
				printf("Creare prima un nuovo esperimento\n");
				break;
			}
			printf("Inserire il tempo:\n");
			c = getchar();
			while (!isdigit(c)) {
			}
			t=c-'0';
			getchar();
			esp(e,t);
			printf("Esperimento eseguito\n");
			break;
		case 7: //enzimi
			if(!e) {
				printf("Creare prima un nuovo esperimento\n");
				break;
			}
			printf("Inserire il nome del primo frammento:\n");
			a= read_line();
			printf("Inserire il nome del secondo frammento:\n");
			b= read_line();
			printf("Inserire il tempo:\n");
			c = getchar();
			while (!isdigit(c)) {
			}
			t=c-'0';
			getchar();

			cancella_enz(alberoenzimi);
			//per ogni enzima enz nella libreria degli enzimi
				//alberoenzimi=inserisci(alberoenzimi, enz);
			Enzimi(e->grafo,alberoenzimi,a,b,t);
			break;
		case 8: //energia
			if(!e) {
				printf("Creare prima un nuovo esperimento\n");
				break;
			}
			printf("Inserire il nome del primo frammento:\n");
			a= read_line();
			printf("Inserire il nome del secondo frammento:\n");
			b= read_line();
			printf("Inserire il tempo:\n");
			c = getchar();
			while (!isdigit(c)) {
			}
			t=c-'0';
			getchar();

			cancella_enz(alberoenzimi);
			printf("\nInserire il nome di un enzima: ");
			while ((strcmp(enz=read_line(),""))!=0) {
				alberoenzimi=inserisci(alberoenzimi, enz);
				printf("\nInserire il nome di un enzima: ");
			}

			Enzimi(e->grafo,alberoenzimi,a,b,t);
			break;
		case 9: //simil
			printf("Inserire il primo frammento:\n");
			a= read_line();
			printf("Inserire il secondo frammento:\n");
			b= read_line();
			similarita(a,b);
			break;
		case 10:
			break;
		default:
			printf("Valore non ammissibile\n");
	}
	}
	return 0;
}

char *read_line(void) {
    int err = 0;
    char c;
    int n = 2;
    char *p;
    p = malloc(n);
    if (!p)
        err = 1;
    int i = 0;
    while ((c=getchar())!='\n' && err!=1) {
        if (i>=n) {
            n+=5;
            p = realloc(p,n);
            if (!p) { 
                err = 1; 
                break;
            }
        }
        *(p+i)=c;
        i++;
    }
    *(p+i)='\0';
    return p;
}

