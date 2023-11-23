#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCK_SIZE 16
void cbc_encrypt(char *plaintext, char *key, char *ciphertext) 
{
    int i, j;
    int len = strlen(plaintext);

    for (i = 0; i < len; i += BLOCK_SIZE) 
	{
        for (j = 0; j < BLOCK_SIZE; j++) 
		{
            ciphertext[i + j] = plaintext[i + j] ^ key[j];
        }
    }
    ciphertext[len] = '\0';
}
void cbc_decrypt(char *ciphertext, char *key, char *decryptedText) 
{
    int i, j;
    int len = strlen(ciphertext);

    for (i = 0; i < len; i += BLOCK_SIZE) 
	{
        for (j = 0; j < BLOCK_SIZE; j++) 
		{
            decryptedText[i + j] = ciphertext[i + j] ^ key[j];
        }
    }
    decryptedText[len] = '\0';
}
int main() 
{
    char key[BLOCK_SIZE + 1];
    char plaintext[1000];
    char ciphertext[1000];
    char decryptedText[1000];

    printf("Enter 128-bit key (16 characters): ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    cbc_encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    cbc_decrypt(ciphertext, key, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}
