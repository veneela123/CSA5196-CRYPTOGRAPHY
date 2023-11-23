#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareKey(char key[], char keyTable[SIZE][SIZE]) 
{
    int i, j, k, flag = 0;
    int visited[26] = {0};

    for (i = 0; i < strlen(key); ++i) 
	{
        if (key[i] != 'j') 
		{
            if (!visited[key[i] - 'a']) 
			{
                keyTable[flag / SIZE][flag % SIZE] = key[i];
                visited[key[i] - 'a'] = 1;
                flag++;
            }
        }
    }
    for (i = 0; i < 26; ++i) 
	{
        if (i != ('j' - 'a')) 
		{
            if (!visited[i]) 
			{
                keyTable[flag / SIZE][flag % SIZE] = 'a' + i;
                visited[i] = 1;
                flag++;
            }
        }
    }
}
void getPosition(char keyTable[SIZE][SIZE], char letter, int *row, int *col) 
{
    int i, j;
    for (i = 0; i < SIZE; ++i) 
	{
        for (j = 0; j < SIZE; ++j) 
		{
            if (keyTable[i][j] == letter) 
			{
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encrypt(char keyTable[SIZE][SIZE], char message[]) 
{
    int i, len = strlen(message);
    for (i = 0; i < len; i += 2) 
	{
        char a = message[i];
        char b = (i + 1 < len) ? message[i + 1] : 'x'; 
        if (a == b) 
		{
            b = 'x';
            i--;
        }
        int row1, col1, row2, col2;
        getPosition(keyTable, a, &row1, &col1);
        getPosition(keyTable, b, &row2, &col2);

        if (row1 == row2) 
		{
            printf("%c%c ", keyTable[row1][(col1 + 1) % SIZE], keyTable[row2][(col2 + 1) % SIZE]);
        } 
		else if (col1 == col2) {
            printf("%c%c ", keyTable[(row1 + 1) % SIZE][col1], keyTable[(row2 + 1) % SIZE][col2]);
        } 
		else 
		{
            printf("%c%c ", keyTable[row1][col2], keyTable[row2][col1]);
        }
    }
}
int main() 
{
    char key[50], message[100];
    char keyTable[SIZE][SIZE];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message to encrypt (in lowercase): ");
    scanf("%s", message);

    prepareKey(key, keyTable);
    printf("Encrypted message: ");
    encrypt(keyTable, message);

    return 0;
}
