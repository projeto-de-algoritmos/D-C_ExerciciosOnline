#include <stdio.h>
#include <limits.h>

char string[131073];

int substituicoes(int inicio, int fim, char caractereDesejado);
int minimoSubstituicoes(int inicio, int fim, char caractereDesejado);

int main(){
    int quantidadeTestes, tamanhoString;

    scanf("%d", &quantidadeTestes);

    for(int i = 0; i < quantidadeTestes; i++){
        scanf("%d", &tamanhoString);

        for(int j = 1; j <= tamanhoString; j++){
            scanf(" %c", &string[j]);
        }
        printf("%d\n", minimoSubstituicoes(1, tamanhoString, 'a'));
    }

    return 0;
}

int substituicoes(int inicio, int fim, char caractereDesejado){
    int contador = 0;

    for(int i = inicio; i <= fim; i++){
        if(string[i] != caractereDesejado){
            contador++;
        }
    }
    return contador;
}

int minimoSubstituicoes(int inicio, int fim, char caractereDesejado){
	if(inicio == fim)
	{
		if(string[inicio] == caractereDesejado){
            return 0;
        } 
        else{
            return 1;
        }			
	}
	
	int meio = (inicio + fim) / 2;

    int primeiraMetadeDesejada = substituicoes(inicio, meio, caractereDesejado) +
           minimoSubstituicoes(meio + 1, fim, caractereDesejado + 1);

    int segundaMetadeDesejada = substituicoes(meio + 1, fim, caractereDesejado) +
                   minimoSubstituicoes(inicio, meio, caractereDesejado + 1);

    if(primeiraMetadeDesejada < segundaMetadeDesejada){
        return primeiraMetadeDesejada;
    }

    else{
        return segundaMetadeDesejada;
    }
}
