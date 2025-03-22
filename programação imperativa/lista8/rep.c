#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int n;
	int* elements;
} t_vector;

t_vector repetidas(t_vector album, t_vector novas){
    t_vector reps;
    reps.elements = (int*)malloc(novas.n * sizeof(int));
    int j = 0;

    for (int i = 0; i < novas.n; i++) {
        for (int k = 0; k < album.n; k++) {
            if (novas.elements[i] == album.elements[k]) {
                reps.elements[j] = novas.elements[i];
                j++;        
            }
        }
    }
    
    reps.n = j;
    return reps;
} 

int main() {
	int i, j, k;
	t_vector album, novas, reps;
	scanf("%d", &album.n);
	album.elements = (int*)malloc((album.n+1)*sizeof(int));
	for(i = 0; i < album.n; i++){
		scanf("%d", &(album.elements[i]));
	}
	album.elements[i] = INT_MAX;
	
	scanf("%d", &novas.n);
	novas.elements = (int*)malloc((novas.n+1)*sizeof(int));
	for(i = 0; i < novas.n; i++){
		scanf("%d", &(novas.elements[i]));
	}
	novas.elements[i] = INT_MAX;
	
	reps = repetidas(album, novas);
	
	for(k = 0; k < reps.n-1; k++)
	  printf("%d ", reps.elements[k]);
	printf("%d\n", reps.elements[k]);
	
	free(reps.elements);
	free(album.elements);
	free(novas.elements);
	
	return 0;
}