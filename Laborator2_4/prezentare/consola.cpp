//
// Created by lupse on 3/11/2025.
//
#include "../domain/lista.h"
#include "../service/service_medicamente.h"
#include <stdio.h>
#include <string.h>
#include "consola.h"
#include "../teste/test.h"
void printComenzi() {
    printf("Comenzi acceptate:\n");
    printf("1 - Adaugare medicament\n");
    printf("2 - Actualizeaza medicament\n");
    printf("3 - Sterge medicament\n");
    printf("4 - Vizualizare medicamente\n");
    printf("5 - Filtrare medicamente dupa cantitate\n");
    printf("6 - Filtrare medicamente dupa litera initiala a numelui\n");
    printf("7 - Sortare medicamente dupa nume\n");
    printf("8 - Sortare medicamente crescator dupa cantitate\n");
    printf("9 - Sortare medicamente descrescator dupa cantitate\n");
    printf("0 - Iesire\n");
}

void printMedicamente(VectorDynamic* v) {
    if (v->size == 0) {
        printf("Nu exista medicamente in stoc.\n");
        return;
    }

    printf("Lista de medicamente:\n");
    for (int i = 0; i < v->size; i++) {
        printf("Cod: %d\n", getCod(*getElement(v, i)));
        printf("Nume: %s\n", getNume(*getElement(v, i)));
        printf("Concentratie: %.2f\n", getConcentratie(*getElement(v, i)));
        printf("Cantitate: %d\n", getCantitate(*getElement(v, i)));
        printf("-------------------------\n");
    }
}

int citesteInt(int* valoare, const char* prompt) {
    printf("%s", prompt);
    if (scanf("%d", valoare) != 1) {
        while (getchar() != '\n');
        printf("Valoare invalida! Introduceti un numar intreg.\n");
        return 0;
    }
    return 1;
}


int citesteFloat(float* valoare, const char* prompt) {
    printf("%s", prompt);
    if (scanf("%f", valoare) != 1) {
        while (getchar() != '\n');
        printf("Valoare invalida! Introduceti un numar real.\n");
        return 0;
    }
    return 1;
}


int citesteString(char* valoare, const char* prompt) {
    printf("%s", prompt);
    if (scanf("%s", valoare) != 1 || strlen(valoare) == 0) {
        while (getchar() != '\n');
        printf("Nume invalid! Introduceti un sir de caractere valid.\n");
        return 0;
    }
    return 1;
}


int citesteChar(char* valoare, const char* prompt) {
    printf("%s", prompt);
    if (scanf(" %c", valoare) != 1) {
        while (getchar() != '\n');
        printf("Litera invalida! Introduceti o litera.\n");
        return 0;
    }
    return 1;
}

void run() {
    runTests();
    VectorDynamic stoc;
    initVector(&stoc, 2);

    while (true) {
        printComenzi();
        int userInput;

        do {
            printf("> ");
            if (scanf("%d", &userInput) != 1) {
                while (getchar() != '\n'); // Clear input buffer
                printf("Comanda invalida! Introduceti o comanda valida.\n");
                userInput = -1;
            }
        } while (userInput < 0 || userInput > NUMAR_COMENZI);

        switch (userInput) {
            case 1: {
                int cod, cantitate;
                char nume[50];
                float concentratie;

                if (!citesteInt(&cod, "Introduceti codul(int>0) medicamentului: ")) break;
                if (!citesteString(nume, "Introduceti numele(nevid) medicamentului: ")) break;
                if (!citesteFloat(&concentratie, "Introduceti concentratia(float>0) medicamentului: ")) break;
                if (!citesteInt(&cantitate, "Introduceti cantitatea(int>0) medicamentului: ")) break;
                int response = adaugaMedicamentService(&stoc, cod, nume, concentratie, cantitate);
                if (response == 1) {
                    printf("Medicament adaugat cu succes\n");
                }
                else if (response == 0) {
                    printf("Medicamentul exista deja in stoc, iar la cantitatea exsitenta \n a fost adaugata cea introdusa\n");
                }
                else if (response == 2) {
                    printf("Validation Error: Valorile introduse nu sunt valide");
                }
                break;
            }
            case 2: {
                int cod;
                char numeNou[50];
                float concentratieNoua;

                if (!citesteInt(&cod, "Introduceti codul(int>0) medicamentului de actualizat: ")) break;
                if (!citesteString(numeNou, "Introduceti numele(nevid) nou al medicamentului: ")) break;
                if (!citesteFloat(&concentratieNoua, "Introduceti noua concentratie(float>0) a medicamentului: ")) break;
                int response = actualizeazaMedicamentService(&stoc, cod, numeNou, concentratieNoua);
                if (response == 1) {
                    printf("Medicament actualizat cu succes\n");
                }
                else if (response == 0) {
                    printf("Repo Error: Nu exista medicament cu codul precizat");
                }
                else if (response == 2) {
                    printf("Validation Error: Valorile introduse nu sunt valide");
                }
                break;
            }
            case 3: {
                int cod;
                if (!citesteInt(&cod, "Introduceti codul(int>0) medicamentului de sters: ")) break;
                int response = stergeMedicamentService(&stoc, cod);
                if (response == 1) {
                    printf("Medicament sters cu succes");
                }
                else if (response == 0) {
                    printf("Repo Error: Nu exista medicament cu codul precizat");
                }
                else if (response == 2) {
                    printf("Validation Error: Valorile introduse nu sunt valide");
                }
                break;
            }
            case 4:
                printMedicamente(&stoc);
                break;
            case 5: {
                int cantitate;
                if (!citesteInt(&cantitate, "Introduceti cantitatea(int>0) limita: ") || cantitate < 0) break;
                VectorDynamic filtered = filtrareCantitate(&stoc, cantitate);
                printMedicamente(&filtered);
                freeVector(&filtered);
                break;
            }
            case 6: {
                char litera;
                if (!citesteChar(&litera, "Introduceti litera de inceput a numelui medicamentului: ")) break;
                VectorDynamic filtered = filtrareLitera(&stoc, litera);
                printMedicamente(&filtered);
                freeVector(&filtered);
                break;
            }
            case 7: {
                VectorDynamic sorted = sortMedicamenteDupaNume(&stoc);
                printMedicamente(&sorted);
                freeVector(&sorted);
                break;
            }
            case 8: {
                VectorDynamic sorted = sortMedicamenteCrescatorCantitate(&stoc);
                printMedicamente(&sorted);
                freeVector(&sorted);
                break;
            }
            case 9: {
                VectorDynamic sorted = sortMedicamenteDescrescatorCantitate(&stoc);
                printMedicamente(&sorted);
                freeVector(&sorted);
                break;
            }
            case 0:
                freeVector(&stoc);
                return;
            default:
                printf("Comanda invalida!\n");
                break;
        }
    }
}

