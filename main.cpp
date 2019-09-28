#include <iostream>
#include "Nombre.h"
#include "Alumno.h"
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
inline void Nombre::print(){
	std::cout<<nombre<<std::endl;
	std::cout<<a_p<<std::endl;
	std::cout<<a_m<<std::endl;
}

inline void Nombre::set(std::string nombre, std::string a_p, std::string a_m){
	this ->nombre = nombre;
	this ->a_p = a_p;
	this ->a_m = a_m;	
}

inline void Alumno::print(){
	Nombre::print();
	std::cout<<promedio<<std::endl;
	std::cout<<codigo<<std::endl;
}
inline void Alumno::set(std::string nombre, std::string a_p, std::string a_m, float promedio, int codigo){
Nombre::set(nombre,a_p,a_m);
this ->promedio=promedio;
this ->codigo=codigo;
}

inline int Alumno::getCodigo(){
	return codigo;
}

inline bool Lista::vacia(){
	return ultimo==-1;
}

inline bool Lista::llena(){
	return ultimo==50-1;
}

inline void Lista::agregar(Alumno aux,int pos){
	if(llena())
		return;
		
	ultimo++;
	for(int i=ultimo;i>pos;i--)
		Grupo[i]=Grupo[i-1];
	Grupo[pos]=aux;
}

inline void Lista::eliminar(int pos){
	if(vacia())
		return;
		
	for(int i=pos;i<ultimo;i++)
		Grupo[i]=Grupo[i+1];
	ultimo--;
}

inline void Lista::print(){
	if(vacia())
		return;
	for(int i=0; i<=ultimo; i++)
		Grupo[i].print();	
}

int Lista::busqueda_lineal(int x){
	if(vacia())
	return -1;
	for(int i=0; i<=ultimo;i++)
		if(x==Grupo[i].getCodigo())
			return i;
	return -1;
}

int Lista::busqueda_binaria(int x){
	if(vacia())
		return -1;
	int i=0, j=ultimo,m=(i+j)/2;
	while(i<=j){
		if(x==Grupo[m].getCodigo())
			return m;
		if(x>Grupo[m].getCodigo())
			i=m+1;
		if(x<Grupo[m].getCodigo())
			j=m-1;
		m=(i+j)/2;
	}
	return -1;
}

inline void Lista::intercambio(int i, int j){
	Alumno aux=Grupo[i];
	Grupo[i]=Grupo[j];
	Grupo[j]=aux;
}

inline void Lista::burbuja(){
	for(int i=ultimo;i>0;i--)
		for(int j=0;j<i;j++)
			if(Grupo[j].getCodigo()>Grupo[j+1].getCodigo())
			intercambio(j,j+1);
}

void Lista::shell() {
    float f;
    f = 0.5;
    for (int dist = ultimo*f; dist > 0 ; dist*=f) {
        for (int i = 0; i < ultimo-dist; ++i) {
            if (Grupo[i].getCodigo()>Grupo[i - dist].getCodigo())continue;
            intercambio(i,i+dist);
        }
    }
}

/*void Lista::insercion() {
    Alumno aux;
    int j;
    for (int i = 1; i <=ultimo ; ++i) {
        aux=Grupo[i];
    }
}*/

void Lista::seleccion() {

}

int main(){
	Lista L;
	Alumno aux;
	aux.set("juan","perez","lopez",9.8,3033);
	L.agregar(aux,0);
    aux.set("juan","perez","lopez",9.8,3034);
    L.agregar(aux,0);
    aux.set("juan","perez","lopez",9.8,3035);
    L.agregar(aux,0);
    aux.set("juan","perez","lopez",9.8,3036);
    L.agregar(aux,0);
    aux.set("juan","perez","lopez",9.8,3037);
    L.agregar(aux,0);
    L.shell();
	//std::cout<<L.busqueda_binaria(3033);
	L.print();
		
	return 0;
}
