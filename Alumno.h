#ifndef Alumno_H
#define Alumno_H
class Alumno:public Nombre{
	private:
		float promedio;
		int codigo;
	public:
		Alumno(float a=0,int b=0): promedio(a),codigo(b){}//constructor
		void print();
		void set(std::string,std::string,std::string,float,int);
		int getCodigo();

};


#endif
