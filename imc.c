#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 

#define VERMELHO "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[36m"
#define AMARELO "\x1b[33m"
#define RESET   "\x1b[0m"



// Vari�veis globais para facilitar a visualiza��o dos dados que ser�o utilizados abaixo no c�digo.
int height;
char name[20];
float weight;

void separar(){ // Void somente pra deixar bonitinho o c�digo.
	printf("------------------------------------------------------------------");
}

void introduction(){

	int nameVer; // Name verification.
	
	separar();
	
	printf("\nBem-vindo(a) � calculadora de IMC! Para fins comunicativos, pe�o que digite seu "VERDE"nome"RESET" abaixo:\n\n"); // Espa�o est�tico kkkkkkk
	scanf("%s",&name);
	separar();
	
	do{
        printf("\nSeu nome � "AMARELO"%s"RESET" correto?\n"AZUL"\n[1]Sim\n[2]N�o\n\n"RESET"",name);
        scanf("%d",&nameVer); 

        if(nameVer==2) { // Enquanto o nome do usu�rio n�o for correto, ir� ficar em loop.
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
		
		printf("\nAqui consta que seu PESO � "AMARELO"%.1f"RESET". Este peso est� correto?\n\n"AZUL"[1]Sim\n[2]N�o"RESET"\n\n",weight);
		scanf("%d",&weightVer);
		
		if(weightVer!=1){ // Loop enquanto o peso estiver incorreto segundo o usu�rio.
			printf(VERMELHO"\nPeso n�o confirmado, tente novamente.\n"RESET);
		}
	}while(weightVer!=1);
	
	separar();
	
	do{
	
	printf("\nOk %s! J� tenho seu peso, agora me informa sua "VERDE"ALTURA"RESET" em cent�metros (EX:154):\n\n",name);
	scanf("%d",&height);
	
	separar();
	
	printf("\nAqui consta que sua ALTURA � "AMARELO"%d cm"RESET". Esta altura est� correta?\n\n"AZUL"[1]Sim\n[2]N�o"RESET"\n\n",height);
	scanf("%d",&heightVer); 
	
	if(heightVer!=1){ // Loop enquanto o peso estiver incorreto segundo o usu�rio.
			printf(VERMELHO"\nAltura n�o confirmada, tente novamente.\n"RESET);
		}
	}while(heightVer!=1);
	
	separar();
	system("cls");
}

void imc(){
	
	float heightm = height / 100.0; // Fiz isso pra poder transformar a altura do usu�rio de centimetros em metros e calcular o IMC corretamente.
    float heightImc = heightm * heightm; // O imc � feito pela altura ao quadrado.
    float imc = weight / heightImc; // E posteriormente dividindo o resultante do quadrado pelo peso.
	
	printf("Ok "AMARELO"%s"RESET", voc� tem um PESO de "AMARELO"%.1fkg"RESET" e altura de "AMARELO"%dcm"RESET", estarei fazendo o c�lculo do seu IMC agora...\n",name,weight,height);
	Sleep(3800);
	system("cls");
	
	separar();
	
	if(imc<18.5){ // Imprime na tela uma mensagem conforme o IMC resultante da pessoa(usu�rio).
        printf("\n%s voc� est� "AMARELO"ABAIXO DO PESO.\n"RESET"",name);
    } else if (imc<24.9) {
        printf("\n%s voc� est� com "AMARELO"UM PESO NORMAL.\n"RESET"",name);
    } else if (imc<29.9){
        printf("\n%s voc� est� com "AMARELO"SOBREPESO.\n"RESET"",name);
    } else{
        printf("\n%s voc� est� com "AMARELO"OBESIDADE.\n"RESET"",name);
    }
}
	
	
int main(){
	
	setlocale(LC_ALL,"portuguese");
	
	introduction(); // Introdu��o, coletando o nome do usu�rio;
	userdata(); // Pega os dados do usu�rio para utilizar posteriormente;
	imc(); // Faz o c�lculo do IMC.
	
	
	//Esse programa foi feito por mim, Jo�o V�tor Almeida, utilizei a internet apenas pra pegar os par�metros do IMC.
	//Espero que seja �til! Abra�os.
	
}
