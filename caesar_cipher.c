#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char*
caesar_encrypto(char* plain, char key)
{
	char *ciper;
	int i;

	int len =strlen(plain);
	ciper = (char*)malloc(len*sizeof(char));


	for (i = 0; i < len; i++) {
		//ciper[i] = ((plain[i] - 97 + key) % 26) + 65;
		ciper[i] = ((plain[i] - 'a' + key) % 26) + 'A';		
	}
	ciper[i] = '\0';
	return ciper;
}

void 
caesar_brute_force(char* ciper)
{
	char *plain;
	int i, key;

	int len =strlen(ciper);
	plain = (char*)malloc(len*sizeof(char));


	for (key = 1; key < 26; key++) {
		for (i = 0; i < len; i++) {
			//ciper[i] = ((plain[i] - 97 + key) % 26) + 65;
			plain[i] = ((ciper[i] - 'A' - key) % 26) + 'a';		
		}
		plain[i] = '\0';
		printf("%d	%s\n", key, plain);
	}
}
int main()
{
	char *ciper;
	char *plain = "meetmeafterthetogaparty";
	ciper = caesar_encrypto(plain, 3);
	printf("%s\n", ciper);
	caesar_brute_force(ciper);
	return 0;
}
