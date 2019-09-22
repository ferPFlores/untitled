//#include <iostream>
#ifndef Nombre_H
#define Nombre_H
class Nombre{
	private:
		std::string nombre;
		std::string a_p;
		std::string a_m;	
	public:
		Nombre(){ nombre="sin nombre"; a_p="sin apellido"; a_m="sin apellido";}
		Nombre(std::string nombre, std::string a_p, std::string a_m ){
			this ->nombre=nombre;
			this ->a_p=a_p;
			this ->a_m=a_m;
		}
		void print();
		void set(std::string,std::string,std::string);
		
};		
#endif
