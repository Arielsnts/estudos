#include <stdio.h>
#include <string.h>

int main() {
    char str1[1001], str2[1001];
    int count = 0;
    int len1, len2, i;

    scanf("%s", str1);
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    for(i = 0; i <= len1 - len2; i++) {
        if(strncmp(&str1[i], str2, len2) == 0) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

