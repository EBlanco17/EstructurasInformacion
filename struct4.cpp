//Editor Dev C++ 511
//Por si no ejecuta ir:
//Herramientas>opciones del compilador
//configuracion>generacion de codigo
//ir a la opcion de lenguage estandar(-std)->ISO c++11


#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<string>
#define p 15
using namespace std;

struct date {
	int yearI, monthI, dayI;
	int yearR, monthR, dayR;
	short int dateR;
	char dateFR[10];
};

struct company {
	struct date d;
	char name[20];
	char lastName[20];
	char position [20];
} employee[p];

void readData();
void sortPosition();
void sortDate();
void print();
void printPosition();
void printDate();
void searchPosition();

int main() {
	system("color f0");
	short int opc;
	readData();
	do {
		cout<<"----------Menu---------"<<endl;
		cout<<"1. Listar empleados"<<endl;
		cout<<"2. Listar cargos "<<endl;
		cout<<"3. Listar fecha de evaluacion"<<endl;
		cout<<"4. Busqueda por cargo"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Ingrese opcion: ";
		cin>>opc;

		switch(opc) {
			case 1:
				print();
				break;
			case 2:
				sortPosition();
				printPosition();
				break;
			case 3:
				sortDate();
				printDate();
				break;
			case 4:
				searchPosition();
				break;
			default:
				cout<<"Error"<<endl;
				break;
		}

	} while(opc!=5);
}
void readData() {
	short int day=0,dayF=0, month=0,dateF=0;
	char bis;
	for(int i=0; i<p; i++) {
		cout<<"---------------Datos del empleado "<<i+1<<"---------------"<<endl;
		cout<<"Ingrese el Nombre del empleado: ";
		cin>>employee[i].name;
		cout<<"Ingrese el Apellido del empleado: ";
		cin>>employee[i].lastName;
		cout<<"Ingrese el Cargo del empleado: ";
		cin>>employee[i].position;
		cout<<"Ingrese el anio de ingreso del empleado: ";
		cin>>employee[i].d.yearI;
		cout<<"Ingrese el mes de ingreso del empleado: ";
		cin>>month;
		if(month>0 && month<=12) {
			employee[i].d.monthI=month;
		} else {
			cout<<"Error- Mes mayor a 12"<<endl;
			cout<<"Ingrese el mes de ingreso del empleado: ";
			cin>>employee[i].d.monthI;
		}
		cout<<"Ingrese el dia de ingreso del empleado: ";
		cin>>day;
		switch(employee[i].d.monthI) {
				//Enero, Marzo, Mayo, Julio, Agosto, Octubre y Diciembre 31
			case 1:
				if(day>0 && day<=31) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Enero solo tiene 31 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 2:
				cout<<"Fue o es anio bisiesto s/n: ";
				cin>>bis;
				if(bis == 's') {
					if(day>0 && day<=29) {
						employee[i].d.dayI=day;
					} else {
						cout<<"Error- Febrero solo tiene 29 dias"<<endl;
						cout<<"Ingrese el dia de ingreso del empleado: ";
						cin>>employee[i].d.dayI;
					}
				} else {
					if(day>0 && day<=28) {
						employee[i].d.dayI=day;
					} else {
						cout<<"Error- Febrero solo tiene 28 dias"<<endl;
						cout<<"Ingrese el dia de ingreso del empleado: ";
						cin>>employee[i].d.dayI;
					}
				}

				break;
			case 3:
				if(day>0 && day<=31) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Marzo solo tiene 31 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 4:
				if(day>0 && day<=30) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Abril solo tiene 30 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;

			case 5:
				if(day>0 && day<=31) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Mayo solo tiene 31 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 6:
				if(day>0 && day<=30) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Junio solo tiene 30 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 7:
				if(day>0 && day<=31) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Julio solo tiene 31 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;

			case 8:
				if(day>0 && day<=31) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Agosto solo tiene 31 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 9:
				if(day>0 && day<=30) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Septiembre solo tiene 30 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 10:
				if(day>0 && day<=31) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Octubre solo tiene 31 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 11:
				if(day>0 && day<=30) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Noviembre solo tiene 30 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;
			case 12:
				if(day>0 && day<=31) {
					employee[i].d.dayI=day;
				} else {
					cout<<"Error- Diciembre solo tiene 31 dias"<<endl;
					cout<<"Ingrese el dia de ingreso del empleado: ";
					cin>>employee[i].d.dayI;
				}
				break;

		}

		cout<<"Ingrese numero de dias en los que se realizara la evaluacion(0-62): ";
		cin>>employee[i].d.dateR;
		if(employee[i].d.dateR>=0 && employee[i].d.dateR<=62) {
			dateF=employee[i].d.dateR+employee[i].d.dayI;
			switch(employee[i].d.monthI) {
				case 1:
					if(dateF<=31) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>31 && dateF<=62) {
							dayF=dateF-31;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-62;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 2:
					if(bis == 'n') {
						//no bisiesto
						if(dateF<=28) {
							employee[i].d.dayR=dateF;
							employee[i].d.monthR=employee[i].d.monthI;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							if(dateF>28 && dateF<=56) {
								dayF=dateF-28;
								employee[i].d.dayR=abs(dayF);
								employee[i].d.monthR=employee[i].d.monthI+1;
								employee[i].d.yearR=employee[i].d.yearI;
							} else {
								dayF=dateF-56;
								employee[i].d.dayR=abs(dayF);
								employee[i].d.monthR=employee[i].d.monthI+2;
								employee[i].d.yearR=employee[i].d.yearI;
							}
						}
					} else {
						//bisiesto
						if(dateF<=29) {
							employee[i].d.dayR=dateF;
							employee[i].d.monthR=employee[i].d.monthI;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							if(dateF>29 && dateF<=58) {
								dayF=dateF-29;
								employee[i].d.dayR=abs(dayF);
								employee[i].d.monthR=employee[i].d.monthI+1;
								employee[i].d.yearR=employee[i].d.yearI;
							} else {
								dayF=dateF-58;
								employee[i].d.dayR=abs(dayF);
								employee[i].d.monthR=employee[i].d.monthI+2;
								employee[i].d.yearR=employee[i].d.yearI;
							}
						}
					}
					break;

				case 3:
					if(dateF<=31) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>31 && dateF<=62) {
							dayF=dateF-31;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-62;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 4:
					if(dateF<=30) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>30 && dateF<=61) {
							dayF=dateF-30;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-61;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 5:
					if(dateF<=31) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>31 && dateF<=62) {
							dayF=dateF-31;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-62;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 6:
					if(dateF<=30) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>30 && dateF<=61) {
							dayF=dateF-30;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-61;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 7:
					if(dateF<=31) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>31 && dateF<=62) {
							dayF=dateF-31;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-62;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 8:
					if(dateF<=31) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>31 && dateF<=62) {
							dayF=dateF-31;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-62;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 9:
					if(dateF<=30) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>30 && dateF<=61) {
							dayF=dateF-30;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-61;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 10:
					if(dateF<=31) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>31 && dateF<=62) {
							dayF=dateF-31;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-62;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI;
						}
					}
					break;
				case 11:
					if(dateF<=30) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>30 && dateF<=61) {
							dayF=dateF-30;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+1;
							employee[i].d.yearR=employee[i].d.yearI;
						} else {
							dayF=dateF-61;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=employee[i].d.monthI+2;
							employee[i].d.yearR=employee[i].d.yearI+1;
						}
					}
					break;

				case 12:
					if(dateF<=31) {
						employee[i].d.dayR=dateF;
						employee[i].d.monthR=employee[i].d.monthI;
						employee[i].d.yearR=employee[i].d.yearI;
					} else {
						if(dateF>31 && dateF<=62) {
							dayF=dateF-31;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=1;
							employee[i].d.yearR=employee[i].d.yearI+1;
						} else {
							dayF=dateF-62;
							employee[i].d.dayR=abs(dayF);
							employee[i].d.monthR=2;
							employee[i].d.yearR=employee[i].d.yearI+1;
						}
					}
					break;
			}

		}


		int d=0,m=0,y=0;
		d=employee[i].d.dayR;
		m=employee[i].d.monthR;
		y=employee[i].d.yearR;
		string a=std::to_string(d);
		string b=std::to_string(m);
		string c=std::to_string(y);
		string dF=c+"/"+b+"/"+a;

		char dateF[dF.length()];
		for (int k = 0; k < sizeof(dateF); k++) {
			dateF[k] = dF[k];
			employee[i].d.dateFR[k]= dateF[k];
			//cout<<employee[i].d.dateFR[k];
		}

	}

}
void sortPosition() {
	struct company aux;
	int change;
	int temp;
	for(int i=1; i<p; i++) {
		change=0;
		for(int j=p-1; j>=i; j--) {
			temp=strcmp(employee[j-1].position,employee[j].position);
			if(temp>0) {
				aux=employee[j];
				employee[j]=employee[j-1];
				employee[j-1]=aux;
				change=1;
			}
		}
		if (change==0)
			break;
	}
}
void sortDate() {
	struct company aux;
	int change=0;
	int temp;
	for(int i=1; i<p; i++) {
		for(int j=p-1; j>=i; j--) {
			temp=strcmp(employee[j-1].d.dateFR, employee[j].d.dateFR);
			if(temp>0) {
				aux=employee[j];
				employee[j]=employee[j-1];
				employee[j-1]=aux;
				change=1;
			}
		}
		if (change==0) break;
	}
}
void print() {
	for(int i=0; i<p; i++) {
		cout<<"---------------------------"<<endl;
		cout<<"Nombre: "<<employee[i].name<<" "<<employee[i].lastName<<endl;
		cout<<"Cargo: "<<employee[i].position<<endl;

	}
}
void printPosition() {
	for(int i=0; i<p; i++) {
		cout<<"---------------------------"<<endl;
		cout<<"Cargo: "<<employee[i].position<<endl;
		cout<<"Nombre: "<<employee[i].name<<" "<<employee[i].lastName<<endl;
		cout<<endl;
	}
}
void printDate() {
	for(int i=0; i<p; i++) {
		cout<<"---------------------------"<<endl;
		cout<<"Nombre: "<<employee[i].name<<" "<<employee[i].lastName<<endl;
		cout<<"Cargo: "<<employee[i].position<<endl;
		cout<<"Fecha de Ingreso (aa/mm/dd): "<<employee[i].d.yearI<<"/"<<employee[i].d.monthI<<"/"<<employee[i].d.dayI<<endl;
		cout<<"Dias en que se evaluara: "<<employee[i].d.dateR<<endl;
		cout<<"Fecha de Revision (aa/mm/dd): "<<employee[i].d.yearR<<"/"<<employee[i].d.monthR<<"/"<<employee[i].d.dayR<<endl;

	}
}
void searchPosition() {
	string position[20];
	cout<<"Ingrese el cargo que desea buscar: ";
	cin>>position[1];
	cout<<endl;
	cout<<"Los empleados encontrados de  "<<position[1]<<" son:"<<endl;
	for(int i=0; i<p; i++) {
		if(position[1]==employee[i].position) {
			cout<<"Nombre: "<<employee[i].name<<" "<<employee[i].lastName<<endl;
		}
	}
	cout<<endl;
}

