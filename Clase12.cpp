#include <iostream>

using namespace std;
//CRUD con archivos
const char *nombre_archivo="archivo.dat"; //flujo de datos binarios = nombre.dat

struct Estudiante{
    int codigo;
    char nombre[50];
    char apellidos[50];
    int telefono;

    
};

void Leer(){
    system("cls"); //funcion para borrar los datos y todo lo que esta dentro de la pantalla de la consola.
    FILE* archivo = fopen(nombre_archivo,"rb"); 
    if (!archivo){
    archivo = fopen(nombre_archivo,"w+b"); 
    }
    Estudiante estudiante; //el tamaño
    int id=0; // indice o posicion del registro (fila) dentro del archivo
    fread(&estudiante,sizeof(Estudiante),1,archivo);
    cout<<"____________________________________________________________"<<endl;
    cout<<"ID"<<"|"<<"Codigo"<<"|"<<"   Nombres "<<"|"<<"   Apellidos   "<<"|"<<"   Telefono    "<<endl;

    do
    {
        cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
        fread(&estudiante,sizeof(Estudiante),1,archivo);
        id+=1;
    } while (feof(archivo)==0); //hasta que ya no encuentre elementos no se va a ejecutar
    fclose(archivo);

}

void Crear(){
    FILE* archivo = fopen(nombre_archivo,"a+b");
    char res;
    Estudiante estudiante;
    do
    {
        fflush(stdin); //limpia el flujo de entrada de la memoria del archivo 
        cout<<"Ingrese codigo: ";
        cin>>estudiante.codigo;
        cin.ignore();

        cout<<"Ingrese nombres: ";
        cin.getline(estudiante.nombre,50);

        cout<<"Ingrese apellidos: ";
        cin.getline(estudiante.apellidos,50);
        
        cout<<"Ingrese telefono: ";
        cin>>estudiante.telefono;

        fwrite(&estudiante,sizeof(Estudiante),1,archivo); // dfwrite(direccion de los datos, tamaño, bandera, nombre del archivo)
        cout<<"Desea ingresar otro estudiante(s/n)";
        cin>>res;
    } while (res=='s'||res=='S');
    fclose(archivo);
    Leer();
}

int main()
{
//Archivos Binarios
// informacion volatil -> se pierde cuando se cierra el programa
  Leer();
//  Crear();
    system("pause");
}
