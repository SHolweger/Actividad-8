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

//No existe como tal, solo existen crear y borrar...
void Actualizar(){ //sobreescribe los datos. Borrar para despues crear. 
FILE* archivo = fopen(nombre_archivo,"r+b"); 
    Estudiante estudiante;
    int id=0;
    cout<<"Ingrese el ID que desea modificar: ";
    cin>>id;
    fseek(archivo,id * sizeof(Estudiante),SEEK_SET); //Sirve para ubicar mi puntero en una determinada posicion //SEEK_SET POSICIONARNOS PARA POSTERIORMENTE SOBREESCRIBIR
        cout<<"Ingrese codigo: ";
        cin>>estudiante.codigo;
        cin.ignore();

        cout<<"Ingrese nombres: ";
        cin.getline(estudiante.nombre,50);

        cout<<"Ingrese apellidos: ";
        cin.getline(estudiante.apellidos,50);
        
        cout<<"Ingrese telefono: ";
        cin>>estudiante.telefono;

        fwrite(&estudiante,sizeof(Estudiante),1,archivo);
        
    fclose(archivo);
    Leer();
}

void Borrar(){
const char *nombre_archivo_temp = "archivo.dat";
FILE* archivo = fopen(nombre_archivo,"rb"); 
FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b"); 
Estudiante estudiante;
int id=0,id_n=0;
cout<<"Ingrese el ID a eliminar: ";
cin>>id;
while (fread(&estudiante,sizeof(Estudiante),1,archivo)){
    if (id_n!=id){
       fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
    }
    id_n++;
}
fclose(archivo);
fclose(archivo_temp);

archivo_temp = fopen(nombre_archivo_temp,"rb"); 
archivo = fopen(nombre_archivo,"wb"); 

while (fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
fwrite(&estudiante,sizeof(Estudiante),1,archivo);
}

fclose(archivo);
fclose(archivo_temp);
Leer();

}

int main()
{
//Archivos Binarios
// informacion volatil -> se pierde cuando se cierra el programa
  Leer();
  Crear();
  Borrar();
  Actualizar();
  system("pause");
}
