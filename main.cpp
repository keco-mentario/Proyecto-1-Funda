#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>

using namespace std;

string str1;
string str2;
char* cadena1;
char* cadena2;

string deciBin (int);
void menu();
string op_and ();
string op_or ();
string op_xor ();
string op_not (char*);
string op_add ();

int main (int argc, char *argv[]) {
	int deci;
	string resp;
	
	cout << "Favor digite el primer numero" << endl;
	cin >> deci;
	if(deci >= 0 && deci <= 255){
		str1 = deciBin(deci);
		cadena1 = (char *)str1.c_str();
		cout << "Su numero en binario es: " << cadena1 << endl << endl;
	}
	else{
		cout << "Favor ingrese un numero menor a 255" << endl;
		cin >> deci;
		str1 = deciBin(deci);
		cadena1 = (char *)str1.c_str();
		cout << "Su numero en binario es: " << cadena1 << endl << endl;
	}
	cout << "Favor digite el segundo numero" << endl;
	cin >> deci;
	if(deci >= 0 && deci <= 255){
		str2 = deciBin(deci);
		cadena2 = (char *)str2.c_str();
		cout << "Su numero en binario es: " << cadena2 << endl << endl;
	}
	else{
		cout << "Favor ingrese un numero menor a 255" << endl;
		cin >> deci;
		str2 = deciBin(deci);
		cadena2 = (char *)str2.c_str();
		cout << "Su numero en binario es: " << cadena2 << endl << endl;
	}
	
	cout << "Digite enter para continuar";
	cin.get();
	cin.get();
	
	menu ();
	
	do {
		cout<< char(168) << "Desea realizar mas operaciones?" << endl;
		cin>>resp;
		cout << endl;
		if (resp == "si"){
			menu();
		}
		else if(resp == "no"){
			cout<< "Gracias por usar el programa" <<endl;
		}
		else{
			cout<< "Por favor digite si o no"<<endl <<endl;
			resp = "si";
		}
	} while(resp == "si");
	
	return 0;
}

string deciBin (int x) {
	string bin;
	while (x != 0){
		if(x % 2 == 0){
			bin += "0";
		}
		else{
			bin += "1";
		}
		x = x / 2;
	}
	string bin_reversed (bin.rbegin(), bin.rend());
	return (bin_reversed);
}

void menu(){
	int menu_opc;
	
	system("cls");
	cout << "Numero 1: " << cadena1 << endl;
	cout << "Numero 2: " << cadena2 << endl << endl;
	
	cout << char(168) <<"Que operacion desea realizar con estos numeros?" << endl;
	cout << "(1) AND" << endl;
	cout << "(2) OR" << endl;
	cout << "(3) XOR" << endl;
	cout << "(4) NOT" << endl;
	cout << "(5) ADD" << endl << endl;
	cout << "Coloque el numero de la operacion que desea del 1 al 5" << endl;
	cin >> menu_opc;
	cout << endl;
	
	switch (menu_opc){
	case 1: cout<< "Operacion AND" <<endl;
			cout<< "El resultado es " << op_and() <<endl <<endl;
			break;
	case 2: cout<< "Operacion OR" <<endl;
			cout<< "El resultado es " << op_or() <<endl <<endl;
			break;
	case 3: cout<< "Operacion XOR" <<endl;
			cout<< "El resultado es " << op_xor() <<endl <<endl;
		break;
	case 4: cout<< "Operacion NOT" <<endl;
			cout<< "El resultado NOT del numero " << cadena1 << " es: " << op_not(cadena1) <<endl;
			cout<< "El resultado NOT del numero " << cadena2 << " es: " << op_not(cadena2) <<endl <<endl;
		break;
	case 5: cout<< "Operacion ADD" <<endl;
			cout<< "El resultado es " << op_add() <<endl <<endl;
		break;
	default: cout << "Debe digitar un numero del 1 al 5" <<endl <<endl;
	menu();
	break;
	}
}

string op_and (){
	string result = " ";
	int x = 0;
	
	while (x <= 7){
		if(cadena1[x] == '\0' or cadena2[x]== '\0'){
			return result;
		}
		else{
			
			if(cadena1[x] == '1' && cadena2[x] == '1'){
				result += "1";
			}
			else{
				result += "0";
			}
		}
		x++;
	}
	return result;
}

string op_or (){
	string result = " ";
	int x = 0;
	
	while (x <= 7){
		
		if(cadena1[x] == '\0' or cadena2[x]== '\0'){
			return result;
		}
		else{
			
			if(cadena1[x] == '0' && cadena2[x] == '0'){
				result += "0";
			}
			else{
				result += "1";
			}
		}
		x++;
	}
	return result;
}

string op_xor (){
	string result = " ";
	int x = 0;
	
	while (x <= 7){
		
		if(cadena1[x] == '\0' or cadena2[x]== '\0'){
			return result;
		}
		else{
			
			if(cadena1[x] == cadena2[x]){
				result += "0";
			}
			else{
				result += "1";
			}
		}
		x++;
	}
	return result;
}

string op_not (char* cadena){
	string result = " ";
	int x = 0;
	
	while (x <= 7){
		if(cadena[x] == '\0'){
				return result;
		}
		else{
			
			if(cadena[x] == '1'){
				result += "0";
			}
			else{
				result += "1";
			}
		}
		x++;
	}
	return result;
}

string op_add (){
	string result;
	bool save = 0;
	int x = 0;
	string acarreo ="0" ; 
	while (x <= 7){
		int elValor1 = strlen(cadena1)-(1+x);
		int elValor2 = strlen(cadena2)-(1+x);
		if(cadena1[elValor1] == '\0' or cadena2[elValor2]== '\0'){
			if(save == 1){
				save = 0;
				if (acarreo == "1"){
					result += "1";
					acarreo = "1";
				}
				else{
					result += "0";
					acarreo = "1";
				}
			}
			else{
				if (acarreo == "1"){
				result += "1";
					acarreo = "0";
				}
				break;
			}
		}
		else{
			if(save == 1){
				save = 0;
				if(cadena1[elValor1] == cadena2[elValor2]){
					if(cadena1[elValor1] == '1'){
						if (acarreo == "1"){
							result += "1";
							acarreo = "1";
						}
						else{
							result += "0";
							acarreo = "1";
						}
					}
					else{
						save = 0;
						result += "1";
					}
				}
				else{
					save = 1;
					if (acarreo == "1"){
						result += "0";
						acarreo = "1";
					}
					else{
						result += "1";
						acarreo = "0";
					}
				}
			}
			else{
				if(cadena1[elValor1] == cadena2[elValor2]){
					if(cadena1[elValor1] == '1'){
						save = 1;
						if (acarreo == "1"){
							result += acarreo + "0";
							acarreo = "0";
						}
						else{
							result += "0";
							acarreo = "1";
						}
					}
					else{
						result += "0";
					}
				}
				else{
					result += "1";
				}
			}
		}
		x++;
	}
	
	string resultr (result.rbegin(), result.rend());
	
	return resultr;
}
