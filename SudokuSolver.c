#include <stdio.h>
#include <stdbool.h>

bool VerifLigne(int grille[9][9], int ligne, int chiffre) {
    for (int i = 0; i < 9; i++) {
        if (grille[ligne][i] == chiffre)
            return false;
    }
    return true;
}

bool VerifColonne(int grille[9][9], int colonne, int chiffre) {
    for (int i = 0; i < 9; i++) {
        if (grille[i][colonne] == chiffre)
            return false;
    }
    return true;
}

bool VerifZone(int grille[9][9], int ligne, int colonne, int chiffre) {
    int departLigne = (ligne / 3) * 3;
    int departColonne = (colonne / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grille[departLigne + i][departColonne + j] == chiffre)
                return false;
        }
    }
    return true;
}

bool Validation(int grille[9][9], int position) {
    if (position > 80)
        return true;

    int colonne = position / 9;
    int ligne = position % 9;

    if (grille[ligne][colonne] != 0)
        return Validation(grille, position + 1);

    for (int chiffre = 1; chiffre <= 9; chiffre++) {
        if (VerifLigne(grille, ligne, chiffre) && VerifColonne(grille, colonne, chiffre) && VerifZone(grille, ligne, colonne, chiffre)) {
            grille[ligne][colonne] = chiffre;
            if (Validation(grille, position + 1))
                return true;
        }
    }
    grille[ligne][colonne] = 0;
    return false;
}

void AfficherGrille(int grille[9][9]) {
    printf("\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            printf("------+-------+------\n");
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0)
                printf("| ");
            if (j == 8)
                printf("%d\n", grille[i][j]);
            else
                printf("%d ", grille[i][j]);
        }
    }
    printf("\n");
}

int main(void) {
    int grille[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Grille initiale :\n");
    AfficherGrille(grille);

    if (Validation(grille, 0)) {
        printf("\nGrille resolue :\n");
        AfficherGrille(grille);
    } else {
        printf("\nPas de solution.\n");
    }

    return 0;
}