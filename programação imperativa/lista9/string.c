#include <stdio.h>
#include <string.h>

int main() {
    char string1[1000], string2[1000];
    int freq1[26] = {0}, freq2[26] = {0}, diff = 0;
    
    scanf("%s", string1);
    scanf("%s", string2);
    
    for (char *ptr = string1; *ptr; ptr++) freq1[*ptr - 'a']++;
    for (char *ptr = string2; *ptr; ptr++) freq2[*ptr - 'a']++;
    
    for (int i = 0; i < 26; i++) {
        if (freq1[i] > freq2[i]) diff += (freq1[i] - freq2[i]);
        else diff += (freq2[i] - freq1[i]);
    }
    
    if (diff == 0) printf("String A is almost equal to string B\n");
    else printf("They differ by %d characters\n", diff);
    
    return 0;
}
