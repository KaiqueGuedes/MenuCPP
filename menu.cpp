#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

char lerNomes(char candidatos[5][100]){
	
	cout<< "\n\t----------------------" << "\n\tCadastro de Candidatos" << "\n\t----------------------\n\n";
	
	for (int i=0; i<5; i++){
		cout<<"\nInsira o nome do " << i+1 << "o " << "candidato: \n";       
		cin>>candidatos[i];
  	}
  		cout<<"\n\t------------------------------------" << "\n\tCandidatos cadastrados com sucesso!\n" << "\t\tRetornando ao Menu\n" << "\t------------------------------------\n\n";  	   	 	   	
  	   	return candidatos[5][100];
}

int realizarVotacao(char candidatos[5][100], int vetorVotos[6]){
	int voto;
		
	cout<< "\n\t------------------------------" << "\n\tVote nos seguintes candidatos:" << "\n\t------------------------------\n";
	
	cout<<"\n1 - " << candidatos[0] << "\n";
	cout<<"\n2 - " << candidatos[1] << "\n";
	cout<<"\n3 - " << candidatos[2] << "\n";
	cout<<"\n4 - " << candidatos[3] << "\n";
	cout<<"\n5 - " << candidatos[4] << "\n";
	
	cout<< "\n\t--------------------------------" << "\n\tPressione '0' quando quiser sair" << "\n\t--------------------------------\n\n";
	do{
		cout<<"\nEm qual candidato voce vota?\n";
		cin>>voto;
	
		if(voto == 1){
			vetorVotos[0]++;
		}
		else if(voto == 2){
			vetorVotos[1]++;
		}
		else if(voto == 3){
			vetorVotos[2]++;
		}
		else if(voto == 4){
			vetorVotos[3]++;
		}
		else if(voto == 5){
			vetorVotos[4]++;
		}
		else if(voto != 0 and voto < 1 or voto > 5){
			vetorVotos[5]++;
		}
		else{
			cout<<"\n\t----------------------" << "\n\tVotacao Encerrada!" << "\n\t------------------\n\n\n";
		}
	}while(voto != 0);
	
	return vetorVotos[6];
}

void totalVotos(char candidatos[5][100], int totalVotos[6]){
	cout<< "\n\t----------------------" << "\n\t   Contagem de Votos" << "\n\t----------------------\n";

	cout<<"\n\nO Candidato 1 - " << candidatos[0] << " recebeu: "  << totalVotos[0] << " votos!\n";
	cout<<"\n\nO Candidato 2 - " << candidatos[1] << " recebeu: "  << totalVotos[1] << " votos!\n";
  	cout<<"\n\nO Candidato 3 - " << candidatos[2] << " recebeu: "  << totalVotos[2] << " votos!\n";
  	cout<<"\n\nO Candidato 4 - " << candidatos[3] << " recebeu: "  << totalVotos[3] << " votos!\n";
  	cout<<"\n\nO Candidato 5 - " << candidatos[4] << " recebeu: "  << totalVotos[4] << " votos!\n";
  	cout<<"\nVotos nulos: " << totalVotos[5] << "\n";
  	
	cout<< "\n\t----------------------" << "\n\t   Fim da Contagem" << "\n\t----------------------\n\n\n";
}

void mostrarVencedor(char candidatos[5][100], int totalVotos[6]){
	int qtdVotos = totalVotos[0];
	char *vencedor = candidatos[0];
	
	for (int i=1; i<5; i++){		
		if(totalVotos[i] > qtdVotos){
			qtdVotos = totalVotos[i];
			vencedor = candidatos[i];
		}
	}
	cout<<"\nVencedor(a) da eleicao: " << vencedor << ", com um total de: " << qtdVotos << " votos!!\n\n\n";
}

void sair(){
    cout<< "\n\t----------------------" << "\n\t   FIM DA EXECUCAO!" << "\n\t----------------------\n\n";
}


int main(){
    int continuar = 1, vetorVotos[6] = {0, 0, 0, 0, 0, 0};;
    char nomes[5][100] = {};
    bool checaLeitura, checaVotacao = false;

    do{
        cout<< "----------------------------------------------------------------------------" << "\n\t\t\tELEICOES - MENU\n\n";
        
        printf("1 - Ler Nome dos Candidatos\n");
        printf("2 - Realizar Votacao\n");
        printf("3 - Mostrar Total de Votos\n");
        printf("4 - Mostrar Vencedor\n");
        printf("5 - Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                lerNomes(nomes);
                checaLeitura = true;
                break;
                
            case 2:
            	if(checaLeitura != false){
            		realizarVotacao(nomes, vetorVotos);
            		checaVotacao = true;
				}
				else{
					cout<<"\n----- ERRO - Favor ler os nomes dos candidatos na opcao 1 antes de realizar a votacao!!! -----\n\n";
				}
				break;
                        
	        	case 3:
	        		if(checaVotacao != false){
		                totalVotos(nomes, vetorVotos);
					}
					else{
						cout<<"\n----- ERRO - A votacao ainda nao foi realizada!!! -----\n\n";
					}
					break;
					
	            case 4:
	            	if(checaVotacao != false){
		                mostrarVencedor(nomes, vetorVotos);
	                }
					else{
						cout<<"\n----- ERRO - A votacao ainda nao foi realizada!!! -----\n\n";
					}
					break;
					
	            case 5:
	                sair();
	                continuar=0;
	                break;
	
	            default:
	                printf("Opcao Invalida...\n");
        }
    } while(continuar);
}
