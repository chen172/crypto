#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this is the secret key
char Cipher_alphabet[26];

// mapping from plain alphabet to cipher alphabet
void 
init_alphabet(char *A)
{
	int i;
	for (i = 0; i < 26; i++)
		A[i] = (('D' + i - 'A') % 26) + 'A';
} 

char*
monoalphabet_encrypto(char* plain)
{
	char *ciper;
	int i;

	int len =strlen(plain);
	ciper = (char*)malloc(len*sizeof(char));


	for (i = 0; i < len; i++) {
		//ciper[i] = ((plain[i] - 97 + key) % 26) + 65;
		ciper[i] = Cipher_alphabet[plain[i] - 'a'];		
	}
	ciper[i] = '\0';
	return ciper;
}



int main()
{
	init_alphabet(Cipher_alphabet);
	for (int i = 0; i < 26; i++)
		printf("%c\n", Cipher_alphabet[i]);

	char *ciper;
	char *plain = "meetmeafterthetogaparty";
	ciper = monoalphabet_encrypto(plain);
	printf("%s\n", ciper);
	return 0;
}
