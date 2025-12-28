#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2)
{
    int length1 = strlen(word1), length2 = strlen(word2), i=0, j=0, m=0;
    char *merge = malloc(length1 + length2 + 1);
    if (!merge) return NULL;
    while(word1[i] != '\0' && word2[j] != '\0'){
        merge[m] = word1[i];
        merge[m+1] = word2[j];
        i++;
        j++;
        m++;
    }
    while(word1[i] != '\0'){
        merge[m] = word1[i];
        i++;
        m++;
    }
    while(word2[j] != '\0'){
        merge[m] = word2[j];
        j++;
        m++;
    }
    merge[m]='\0';
    return merge;
}

int main()
{
    char word1[] = "abc";
    char word2[] = "pqr";
    char *result = mergeAlternately(word1, word2);
    if (result) {
        printf("Merged string: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed\n");
    }
    return 0;
}