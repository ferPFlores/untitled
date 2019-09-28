#ifndef Lista_H
#define Lista_H

class Lista{
	private:
		Alumno Grupo[50];
		int ultimo;
		
	public:
		Lista(){
			ultimo=-1;
		}
		bool vacia();
		bool llena();
		void agregar(Alumno,int);
		void eliminar(int);
		void print();
		int busqueda_lineal(int);
		int busqueda_binaria(int);
		void intercambio(int,int);
		void burbuja();
		void shell();
		void insercion();
		void seleccion();
};



#endif
