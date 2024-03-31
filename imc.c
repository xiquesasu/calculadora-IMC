#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 

#define VERMELHO "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[36m"
#define AMARELO "\x1b[33m"
#define RESET   "\x1b[0m"



// Variáveis globais para facilitar a visualização dos dados que serão utilizados abaixo no código.
int height;
char name[20];
float weight;

void separar(){ // Void somente pra deixar bonitinho o código.
	printf("------------------------------------------------------------------");
}

void introduction(){

	int nameVer; // Name verification.
	
	separar();
	
	printf("\nBem-vindo(a) à calculadora de IMC! Para fins comunicativos, peço que digite seu "VERDE"nome"RESET" abaixo:\n\n"); // Espaço estético kkkkkkk
	scanf("%s",&name);
	separar();
	
	do{
        printf("\nSeu nome é "AMARELO"%s"RESET" correto?\n"AZUL"\n[1]Sim\n[2]Não\n\n"RESET"",name);
        scanf("%d",&nameVer); 

        if(nameVer==2) { // Enquanto o nome do usuário não for correto, irá ficar em loop.
        	separar();
            printf(VERMELHO"\nPor favor, digite seu nome novamente:\n\n"RESET);
            scanf("%s",name);
        }
    } while(nameVer==2);
    system("cls");
}

void userdata(){
	
	int weightVer,heightVer; // Weight verification e height verification.
	
	do{
		separar();
		
		printf("\n%s, qual seu "VERDE"PESO"RESET" em quilogramas?\n\n", name);
		scanf("%f",&weight);
		
		separar();
		
		printf("\nAqui consta que seu PESO é "AMARELO"%.1f"RESET". Este peso está correto?\n\n"AZUL"[1]Sim\n[2]Não"RESET"\n\n",weight);
		scanf("%d",&weightVer);
		
		if(weightVer!=1){ // Loop enquanto o peso estiver incorreto segundo o usuário.
			printf(VERMELHO"\nPeso não confirmado, tente novamente.\n"RESET);
		}
	}while(weightVer!=1);
	
	separar();
	
	do{
	
	printf("\nOk %s! Já tenho seu peso, agora me informa sua "VERDE"ALTURA"RESET" em centímetros (EX:154):\n\n",name);
	scanf("%d",&height);
	
	separar();
	
	printf("\nAqui consta que sua ALTURA é "AMARELO"%d cm"RESET". Esta altura está correta?\n\n"AZUL"[1]Sim\n[2]Não"RESET"\n\n",height);
	scanf("%d",&heightVer); 
	
	if(heightVer!=1){ // Loop enquanto o peso estiver incorreto segundo o usuário.
			printf(VERMELHO"\nAltura não confirmada, tente novamente.\n"RESET);
		}
	}while(heightVer!=1);
	
	separar();
	system("cls");
}

void imc(){
	
	float heightm = height / 100.0; // Fiz isso pra poder transformar a altura do usuário de centimetros em metros e calcular o IMC corretamente.
    float heightImc = heightm * heightm; // O imc é feito pela altura ao quadrado.
    float imc = weight / heightImc; // E posteriormente dividindo o resultante do quadrado pelo peso.
	
	printf("Ok "AMARELO"%s"RESET", você tem um PESO de "AMARELO"%.1fkg"RESET" e altura de "AMARELO"%dcm"RESET", estarei fazendo o cálculo do seu IMC agora...\n",name,weight,height);
	Sleep(3800);
	system("cls");
	
	separar();
	
	if(imc<18.5){ // Imprime na tela uma mensagem conforme o IMC resultante da pessoa(usuário).
        printf("\n%s você está "AMARELO"ABAIXO DO PESO.\n"RESET"",name);
    } else if (imc<24.9) {
        printf("\n%s você está com "AMARELO"UM PESO NORMAL.\n"RESET"",name);
    } else if (imc<29.9){
        printf("\n%s você está com "AMARELO"SOBREPESO.\n"RESET"",name);
    } else{
        printf("\n%s você está com "AMARELO"OBESIDADE.\n"RESET"",name);
    }
}
	
	
int main(){
	
	setlocale(LC_ALL,"portuguese");
	
	introduction(); // Introdução, coletando o nome do usuário;
	userdata(); // Pega os dados do usuário para utilizar posteriormente;
	imc(); // Faz o cálculo do IMC.
	
	
	//Esse programa foi feito por mim, João Vítor Almeida, utilizei a internet apenas pra pegar os parâmetros do IMC.
	//Espero que seja útil! Abraços.
	
}
