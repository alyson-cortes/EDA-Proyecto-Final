void menuRegisPac()
{
    //Declaración de variables 
    int opcion; 
    //Algoritmo 
    do 
    {
       
        printf("\n----- Menu de registro de paquetes-----\n");
        printf("Opcion 1: Registrar paquetes desde un archivo\n");
        printf("Opcion 2: Agregar  paquete manualmente\n");
        printf("Opcion 3: Salir del menu\n");
        if(scanf("%d", &opcion)==1)
        {
            switch(opcion)
            {
                case 1:
                if(contAr<6)
                {
                    regisPacAr();
                }
                else
                {
                    puts("No hay más artículos por insertar"); 
                }

                break; 

                case 2: 
                regisPacMan(); 
                break; 

                case 3:
                puts("Ha salido del menu de registro de paquetes");
                break; 

                default: 
                puts("Inserte un digito valido");
            }
        }
        else 
        {
            clean(); 
        }
       
    }while(opcion!=3);
}