#include <stdio.h>

#include <strings.h>

#include <stdlib.h>

#include <ctype.h>

// get iniverse of a

int

inv_a(int a)

{

        int i = 0;

        for (i = 0; i < 26; i++)

                if (((a*i)%26) == 1)

                        return i;

        return -1;

}

int

encrypt(int a, int m, int b)

{

        return ((a*m+b)%26);

}

int

decrypt(int inv_a, int c, int b)

{

        return ((inv_a*(c-b))%26+26)%26;

}

int

test(void)

{

        printf("%d\n", encrypt(7, 18, 21));

        printf("%d\n", decrypt(inv_a(7), 21, 21));

        return 0;

}

int

solve1()

{

        char* plaintext = "THE NATIONAL SECURITY AGENCY";

        int count = 0;

        char *ciphertext = malloc(strlen(plaintext)+1);

        char *plaintext1 = malloc(strlen(plaintext)+1);

        while (plaintext[count] != '\0') {

                if (isspace(plaintext[count])) {

                        ciphertext[count] = ' ';

                        count++;

                        continue;

                }

                else {

                        ciphertext[count] = encrypt(11, plaintext[count]-'A', 23);

                        ciphertext[count] += 'A';

                        count++;

                }

        }

        ciphertext[count] = '\0';

        printf("%s\n", ciphertext);

        count = 0;

        while (ciphertext[count] != '\0') {

                if (isspace(ciphertext[count])) {

                        plaintext1[count] = ' ';

                        count++;

                        continue;

                }

                else {

                //      printf("%c\n", ciphertext[count]);

                        plaintext1[count] = decrypt(inv_a(11), ciphertext[count]-'A', 23);

                        plaintext1[count] += 'A';

                        count++;

                }

        }

//      printf("%d\n", decrypt(inv_a(11), 'W'-'A', 23));

        plaintext1[count] = '\0';

        printf("%s\n", plaintext1);

        return 0;

}

int

solve2()

{

        int i, j;

        int a, b;

        for (i = 0; i <= 26; i++)

                for (j = 0; j <= 26; j++)

                        if (((8*i+j)%26 == 4) && ((5*i+j)%26 == 3)) {

                                printf("i is %d, j is %d\n", i, j);

                                a = i; b = j;

                        }

        char* ciphertext = "edsgickxhuklzveqzvkxwkzukvcuh";

        int count = 0;

        char *plaintext1 = malloc(strlen(ciphertext)+1);

        printf("i is %d, j is %d\n", i, j);

        while (ciphertext[count] != '\0') {

                if (isspace(ciphertext[count])) {

                        plaintext1[count] = ' ';

                        count++;

                        continue;

                }

                else {

                //      printf("%c\n", ciphertext[count]);

                        plaintext1[count] = decrypt(inv_a(a), ciphertext[count]-'a', b);

                        plaintext1[count] += 'a';

                        count++;

                }

        }

//      printf("%d\n", decrypt(inv_a(11), 'W'-'A', 23));

        plaintext1[count] = '\0';

        printf("%s\n", plaintext1);

        //printf("%d\n", inv_a(11));

        return 0;

}

int

main()

{

        int i, j;

        int a, b;

        for (i = 0; i <= 26; i++)

                for (j = 0; j <= 26; j++)

                        if (((3*i+14*j)%26 == 4) && ((13*i+19*j)%26 == 13)) {

                                printf("i is %d, j is %d\n", i, j);

                                a = i; b = j;

                        }

        for (i = 0; i <= 26; i++)

                for (j = 0; j <= 26; j++)

                        if (((3*i+14*j)%26 == 11) && ((13*i+19*j)%26 == 8)) {

                                printf("i is %d, j is %d\n", i, j);

                                a = i; b = j;

                        }

        return 0;

}
