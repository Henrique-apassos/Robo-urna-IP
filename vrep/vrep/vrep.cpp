#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}
void CodigoTeste();

/*____Membros do Grupo____
    HENRIQUE ALVES PASSOS
    TIAGO RENAN DA SILVA
    VICTOR SILVA E OLIVEIRA
*/

int main(int argc, char* argv[])
{

    //variavei para handler das juntas
    int handler = 0;

    //conecta com o coppelia
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);

    extApi_sleepMs(500);

    //verifica conexao com simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }

    //configura o handler da primeira junta
    simxChar handlerName[200] = "/base_link_respondable[0]/joint_1";
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);


    // Colocando a mao proximo ao painel



    // junta 1 (base)
    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 12), (simxInt)simx_opmode_oneshot_wait);
    printf("Junta 1\n");
    extApi_sleepMs(2000);


    // junta 2 (braco)
    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    printf("Junta 2\n");
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 6), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);

    // junta 3 (cotovelo)
    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    printf("Junta 3\n");
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 10), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);

    // juta 4 (antebraco)
    strcpy(handlerName, "/base_link_respondable[0]/joint_4");
    simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    printf("Junta 4\n");
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);

    // junta 5 (punho)
    strcpy(handlerName, "/base_link_respondable[0]/joint_5");
    simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    printf("Junta 5\n");
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);

    // junta 6 (mao)
    strcpy(handlerName, "/base_link_respondable[0]/joint_6");
    simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    printf("Junta 6\n");
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);



    FILE *arq;
    arq = fopen("C:\\Users\\Henrique\\Documents\\Projeto Robo\\voto.txt", "r"); // Le o arquivo (precisa alterar o camnho)
    if (arq == NULL) {
        printf("Problema no arquivo\n");
        exit(1);
    }


    while (!feof(arq)) {
        // le a opcao do arquivo
        char opcao[12];
        fscanf(arq, "%s", opcao);

        for (int i = 0; i < 12 && opcao[i] != '\0'; i++){
            if ((opcao[i] - '0') == 0){
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 5), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 11), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 19.31), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.85), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 20.3), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.77), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                
            }
            if (opcao[i] - '0' == 1) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 15), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 25), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 45), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.76), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 2) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 12), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 20), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.77), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 45), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.65), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 3) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 9), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 24), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.7), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 30), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_4");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 4\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 6), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 30), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.53), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 4) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 15), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 54), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(4000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 21), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.8), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 5) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 12), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2500);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 57), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.75), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 6) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 9), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 45), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.77), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 55), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.58), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 7) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 15), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 62), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(4000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 75), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.8), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 8) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 19.31), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 12), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 10), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 18.95), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.75), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] - '0' == 9) {
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 9), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 63), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(4000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 20), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.6), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] == 'b') { //Caso o voto seja em branco
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.175, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.20, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.830, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }
            if (opcao[i] == 'x') { // caso precise corrigir

                double degreesToRadians = (PI / 180);

                //movimento da junta 5 para baixo
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(-15.0 * degreesToRadians), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);

                //movimento para a direita até o botão 7  na junta 1
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(-15.0 * degreesToRadians), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);

                /*Movimento de decida suave*/
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4.5), (simxInt)simx_opmode_oneshot_wait);
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);


                //movimento da junta 3 para baixo
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(-3.0 * degreesToRadians), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);

                //movimento da junta 2 para baixo
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(-52.0 * degreesToRadians), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);

            }
            if (opcao[i] == 'c') { // Confirma
                strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 8), (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 1\n");
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 3\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 25), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2500);
                strcpy(handlerName, "/base_link_respondable[0]/joint_5");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 5\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)(PI / 25), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                printf("Junta 2\n");
                simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 3.5), (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(3000);
            }


            strcpy(handlerName, "/base_link_respondable[0]/joint_2");
            simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            printf("Junta 2\n");
            simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 6), (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(1000);
            strcpy(handlerName, "/base_link_respondable[0]/joint_1");
            simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 12), (simxInt)simx_opmode_oneshot_wait);
            printf("Junta 1\n");
            extApi_sleepMs(2000);
            strcpy(handlerName, "/base_link_respondable[0]/joint_3");
            simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            printf("Junta 3\n");
            simxSetJointTargetPosition(clientID, handler, (simxFloat)-(PI / 10), (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(1000);
            strcpy(handlerName, "/base_link_respondable[0]/joint_4");
            simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            printf("Junta 4\n");
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(1000);
            strcpy(handlerName, "/base_link_respondable[0]/joint_5");
            simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            printf("Junta 5\n");
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(1000);
            strcpy(handlerName, "/base_link_respondable[0]/joint_6");
            simxGetObjectHandle(clientID, (simxChar*)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            printf("Junta 6\n");
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(1000);
        }
     } 
    
    // Fecha a conexao 
    simxFinish(clientID);

    fclose(arq);

    return(0);
}

void CodigoTeste() {
/*
    int handler = 0;

    // conecta com o coppelia
    int clientID = simxStart((simxChar *)"127.0.0.1", 19999, true, true, 2000, 5);

    extApi_sleepMs(500);

    // verifica conexao com simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");

        simxChar handlerName[150] = "/NiryoOne/Joint";

        for (int i = 1; i <= 6; i++) {

            printf("Testando junta %d\n", i);

            // move a junta ate seu ponto maximo
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);
            simxSetJointTargetPosition(clientID, handler, (simxFloat)2 * PI, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);

            // passa para a proxima junta
            strcat(handlerName, "/Link/Joint");
            simxGetObjectHandle(clientID, (simxChar *)handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            simxFinish(clientID);
        }
    }*/
}