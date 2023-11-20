#include <stdio.h>
#include <limits.h>

char string[131073];

int main(){
    int quantidadeTestes, tamanhoString;

    scanf("%d", &quantidadeTestes);

    for(int i = 0; i < quantidadeTestes; i++){
        scanf("%d", &tamanhoString);

        for(int i = 1; i <= tamanhoString; i++){
            scanf(" %c", &string[i]);
        }
    }

    return 0;
}