#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Proces {
    char naziv[51];
    int trajanje;

    struct Proces *sledeci;
} Proces;

Proces *glava = NULL;
Proces *rep = NULL;

Proces *init_procesa(char naziv[51], int trajanje) {
    Proces *novi = (Proces*)malloc(sizeof(Proces));

    strcpy(novi->naziv, naziv);
    novi->trajanje = trajanje;

    novi->sledeci = NULL;

    return novi;
}

void IspisListe() {
    Proces *temp = glava;
    while (temp!=NULL) {
        printf("%s: %dms\n", temp->naziv, temp->trajanje);
        temp = temp->sledeci;
    }

}

void Unos_Podataka() {
    while (1) {

        char nazivProcesa[51];
        printf("Unesi naziv procesa: ");
        scanf("%s",nazivProcesa);

        if (strcmp(nazivProcesa, "K") == 0 || strcmp(nazivProcesa, "k") == 0) {
            return;
        }

        int trajanjeProcesa;
        printf("Unesi trajanje procesa: ");
        scanf("%d",&trajanjeProcesa);

        Proces *novi = init_procesa(nazivProcesa, trajanjeProcesa);
        
        if (glava==NULL) {
            glava = novi;
            rep = novi;
        } else {
            rep->sledeci = novi;
            rep = rep->sledeci;
        }
    }
}

void UpisUDatoteku() {
    Proces *temp = glava;
    FILE *fp = fopen("C:\\Users\\dello\\Desktop\\C\\procesi.txt","a");
    if (fp==NULL) {
        printf("Greska");
        return;
    }
    while (temp != NULL) {


        fprintf(fp, "%s %d\n", temp->naziv, temp->trajanje);
        temp = temp->sledeci;
    }
    fclose(fp);
}

int main() {
    printf("Pocetak programa \n");
    Unos_Podataka();
    IspisListe();
    UpisUDatoteku();
    printf("Kraj programa \n");
    return 0;
}
