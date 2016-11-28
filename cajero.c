#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario{
    int ID;
    int NIP;
    char nombre[30];
    float saldo;
    struct Usuario *next;
}typedef Usuario;

void menu(Usuario *);
void consulta(Usuario *);
void retiro(Usuario *);
void pagoServicios(Usuario *);
void deposito(Usuario *);
int transferencia(Usuario *);
void cambiarNIP(Usuario *);
void salir(Usuario *);
void liberarMemoria(Usuario *);
Usuario* confirmarUsuario();

Usuario u1;
Usuario u2;
Usuario u3;
Usuario u4;
Usuario u5;

int main(){
    u1.ID = 1234;
    u1.NIP = 1234;
    strcpy(u1.nombre,"Humberto");
    u1.saldo = 3.27;
    u1.next = &u2;

    u2.ID = 2222;
    u2.NIP = 2222;
    strcpy(u2.nombre,"Prof. Cianca");
    u2.saldo = 200330.27;
    u2.next = &u3;

    u3.ID = 4545;
    u3.NIP = 4545;
    strcpy(u3.nombre,"Oscar");
    u3.saldo = 7000.27;
    u3.next = &u4;

    u4.ID = 9797;
    u4.NIP = 9797;
    strcpy(u4.nombre,"Alfredo");
    u4.saldo = 5330.27;
    u4.next = &u5;

    u5.ID = 1313;
    u5.NIP = 1313;
    strcpy(u5.nombre,"May");
    u5.saldo = 3330.27;
    u5.next = NULL;

    Usuario *usuario;
    int opc,a;
    label2:
    usuario = confirmarUsuario();
    do{
        system("cls");
        menu(usuario);
        scanf("%d",&opc);
        switch(opc){
        case 1:
            consulta(usuario);
        break;
        case 2:
            retiro(usuario);
        break;
        case 3:
            pagoServicios(usuario);
        break;
        case 4:
            deposito(usuario);
        break;
        case 5:
            a=transferencia(usuario);
            a+=1;
        break;
        case 6:
            cambiarNIP(usuario);
        break;
        case 7:
            salir(usuario);
            goto label2;
        break;
        default:
            system("cls");
            printf("\n\t Opcion ingresada incorrecta :(\n\n");
            system("pause");
        break;
        }
    }while(opc!=7);
    liberarMemoria(&u1);
    system("pause");
    return 0;
}

void menu(Usuario *aux){
   system("cls");
   printf("\t----------------- CAJERO AUTOMATICO -------------------\n\n");
   printf("\n\tBIENVENIDO %s !\n\n",aux->nombre);
   printf("\t1) Consulta de saldo\n");
   printf("\t2) Retiro de saldo\n");
   printf("\t3) Pago de servicios\n");
   printf("\t4) Deposito\n");
   printf("\t5) Transferencia\n");
   printf("\t6) Cambiar NIP\n");
   printf("\t7) Salir\n");
   printf("\n\tSelecciona el numero de la accion que deseas realizar: ");
}

void consulta(Usuario *aux){
    system("cls");
    printf("\n\t Consulta de saldo \n\n");
    printf(" Su saldo es de : $ %.2f \n",aux->saldo);
    system("pause");
}

void retiro(Usuario *aux){
    float retiroAux;
    system("cls");
    printf("\n\t Retiro de saldo\n\n");
    printf(" Ingrese la cantidad a retirar : ");
    scanf("%f",&retiroAux);
    if(retiroAux <= aux->saldo){
        aux->saldo -= retiroAux;
        printf("\n\n Su saldo ahora es de : $ %.2f ",aux->saldo);
    }
    else{
        printf("\n\n Saldo insuficiente ! :( \n\n");
    }
    system("pause");
}

void pagoServicios(Usuario *aux){
    int opc,tel,recarga;
    system("cls");
    printf("\n\t Pago de servicios\n\n");
    printf(" Selecciona el servicio que desea pagar \n");
    printf("\n\t1) Pago de telefono");
    printf("\n\t2) Compra de tiempo aire\n\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
            system("cls");
            printf("\n\t Pago de telefono \n\n");
            printf(" Ingresa tu numero telefonico: ");
            scanf("%d", &tel);
            aux->saldo -= 389;
            printf("\n La cantidad a pagar es de $389\n");
            printf("\n Su saldo ahora es de : $ %.2f\n",aux->saldo);
        break;
        case 2:
            system("cls");
            printf("\n\t Compra de tiempo aire \n\n");
            printf(" Ingresa tu numero telefonico: ");
            scanf("%d", &tel);
            printf(" Ingresa la cantidad que deseas recargar : ");
            scanf("%d", &recarga);
            aux->saldo -= recarga;
            printf("\n Se han recargado $%d al %d \n",recarga,tel);
            printf("\n Su saldo ahora es de : $ %.2f\n",aux->saldo);
        break;
        default:
            system("cls");
            printf("\n\t Opcion ingresada incorrecta :(\n\n");
        break;
    }
    system("pause");
}

void deposito(Usuario *aux){
    float saldoAux;
    system("cls");
    printf("\n\t Deposito\n\n");
    printf(" Ingrese el monto a depositar : ");
    scanf("%f",&saldoAux);
    aux->saldo += saldoAux;
    printf("\n Su saldo ahora es de : $ %.2f\n",aux->saldo);
    system("pause");
}

int transferencia(Usuario *aux){
    int idAux;
    float transferencia;
    Usuario *aux2;
    system("cls");
    printf("\n\t Transferencia\n\n");
    printf(" Ingrese el numero de cuenta para transferencia : ");
    scanf("%d",&idAux);
    aux2=&u1;
    while( aux2 != NULL){
        if( idAux == aux2->ID){
            printf(" Ingrese la cantidad a transferir : ");
            scanf("%f",&transferencia);
            if(transferencia <= aux->saldo){
                aux->saldo -= transferencia;
                aux2->saldo += transferencia;
                printf("\n\n Su saldo ahora es de : $ %.2f ",aux->saldo);
            }
            else{
                printf("\n\n Saldo insuficiente ! :( \n\n");
            }
            return 0;
        }
        else{
            aux2 = aux2->next;
        }
    }
    printf("\n\n Numero de cuenta no existente :( !\n\n");
    system("pause");
    return 1;
}

void cambiarNIP(Usuario *aux){
    int nipAux,contador=1,num;
    label3:
    system("cls");
    printf("\n\t Cambiar NIP\n\n");
    printf(" NIP actual : %d \n\n",aux->NIP);
    printf(" Ingrese su nuevo NIP : ");
    scanf("%d",&nipAux);
    num=nipAux;
    while(num/10>0){
        num=num/10;
        contador++;
    }
    if(contador == 4){
        aux->NIP = nipAux;
        printf("\n NIP nuevo : %d \n\n",aux->NIP);
    }
    else{
        printf("\n El NIP debe contener 4 caracteres !");
        goto label3;
    }
    system("pause");
}

void salir(Usuario *aux){
    system("cls");
    printf("\n\t Gracias %s , vuelve pronto ! :)\n\n",aux->nombre);
    system("pause");
}

void liberarMemoria(Usuario *aux){
    while(aux != NULL){
        free(aux);
        aux = aux->next;
    }

}

Usuario* confirmarUsuario(){
    Usuario *aux;
    int nipAux;
    int idAux;
    do{
        label1:
        aux = &u1;
        system("cls");
        printf("\n\t Bienvenido !\n\n");
        printf(" Ingrese su numero de cuenta : ");
        scanf("%d",&idAux);
        while( aux != NULL){
            if( idAux == aux->ID){
                printf(" Ingrese su NIP a 4 digitos : ");
                scanf("%d",&nipAux);
                if( nipAux == aux->NIP)
                    return aux;
                else{
                    printf("\n\n NIP incorrecto !\n\n");
                    system("pause");
                    goto label1;
                }
            }
            else{
                aux = aux->next;
            }
        }
        printf("\n\n Numero de cuenta no existente :( !\n\n");
        system("pause");
    }while(1<2);
}
