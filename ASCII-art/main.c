#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int     get_pos(char c)
{
    int pos;
    if (c >= 'a' && c <= 'z')
        pos = c - 'a';
    else if (c >= 'A'  && c <= 'Z')
        pos = c - 'A';
    else
        pos = 26;
    return pos;
}

void    add_line(char **soluce, int hauteur, char *ASCII, char *line, int largeur)
{
    int k = 0;
    for (int i = 0; line[i] ; i++)
    {
        int pos = get_pos(line[i]);
        // printf("Position in the ASCII banner : %d\n", pos);
        for (int j = pos * largeur;  j < (pos + 1) * largeur ; j++)
            soluce[hauteur][k++] = ASCII[j];
    }
}

int main()
{
    int L;
    scanf("%d", &L); // Largeur de lettres
    int H;
    scanf("%d", &H); fgetc(stdin); // Hauteur des lettres
    char T[257];
    scanf("%[^\n]", T); fgetc(stdin); // Ligne a translate
    char ROW[H][1025];
    for (int i = 0; i < H; i++) {
        scanf("%[^\n]", ROW[i]); fgetc(stdin); // Lettres en ASCII
    }
    char **soluce = malloc(sizeof(char *) * (H+1));
    if (!soluce)
        return (1);
    for (int i = 0; i < H ; i++)
        soluce[i] = malloc(sizeof(char) * (L * strlen(T) + 1));
    for (int i = 0; i < H ; i++)
        add_line(soluce, i, ROW[i], T, L);
    // printf("\n\n");
    for(int i = 0; i < H; i++)
        printf("%s\n", soluce[i]);
    free (soluce);
    return 0;
}