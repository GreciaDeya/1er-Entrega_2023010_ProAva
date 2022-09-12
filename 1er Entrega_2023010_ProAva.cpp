// 1er Entrega_2023010_ProAva.cpp//
// NOMBRE: Grecia Deyanira Martinez Lopez //
// MATRICULA: 2023010                        
// GRUPO: 007//

#include <iostream> //Rescate 
#include <string> //Rescate
#include <cstdlib> //Rescate
#include <conio.h> //Rescate
#include <string.h> //Rescate
#include <fstream> //Rescate 

#define user "grecia"
#define password "martinez"
using namespace std;

struct admin
{
	char nom[50];
	char pass[50];
	admin* sig;
};

struct cajero
{
	char nom[50];
	char pass[50];
	cajero* sig;
};

struct cliente
{
	char nom[50];
	char alias[15];
	char email[25];
	cliente* sig;
};

admin* inicio, * aux = nullptr;
cajero* inicio, * x = nullptr;
cliente* inicio, * y = nullptr;

void RegistroAdmin(admin* nuevo);
void RegistroCajero(cajero* nuevo);
void RegistroCliente(cliente* nuevo);

void Lista();

void ActualizarAdmin(char nomAd[50]);
void ActualizarCajero(char nomCj[50]);
void ActualizarCliente(char nomClt[50]);

void EliminarAdmin(char eliAd[50]);
void EliminarCajero(char eliCj[50]);
void EliminarCliente(char eliClt[50]);

void GuardarBinario();
void LeerBinario();

void Salir();

int main()
{
	string usuario, contraseña;
	int contador = 0;
	bool ingresa = false;

	do
	{
		system("cls");
		cout << "\t\t\tINICIA SESION:" << endl;
		cout << "\n\tUsuario:";
		getline(cin, usuario);
		cout << "\tContraseña:";
		// getline(cin, contraseña);
		char caracter;
		caracter = getch();

		contraseña = "";
		while (caracter != 13)
		{
			if (caracter != 8)
			{
				contraseña.push_back(caracter);
				cout << "*";
			}

			else
			{
				if (contraseña.length() > 0)
				{
					cout << "\b \b";
					contraseña = contraseña.substr(0, contraseña.length() - 1);
				}
			}
			caracter = getch();
		}

		if (usuario == user && contraseña == password)
		{
			ingresa = true;
		}
		else
		{
			cout << "\n\tUsuario/Contraseña INCORRECTOS" << endl;
			cin.get();
			contador++;
		}
	}

	while (ingresa == false && contador < 3);
	{
		if (ingresa == false)
		{
			cout << "\n\tNo se ha podido INGRESAR al sistema, intente mas tarde." << endl;
		}
		else
		{
			cout << "\n\t¡Bienvenido a Market Station!" << endl;
		}
		cin.get();
	}

	do
	{
	si:
		char nomAdmin[50] = { 0 };
		char nomCaja[50] = { 0 };
		char nomCliente[50] = { 0 };

		admin* NodoAd = new admin;
		cajero* NodoCj = new cajero;
		cliente* NodoClt = new cliente;
		int op = 0;

		system("cls");
		cout << "MENU DE OPCIONES:" << endl;
		cout << "1. Alta de USUARIO" << endl;
		cout << "2. Lista de USUARIOS" << endl;
		cout << "3. Actualizar USUARIO" << endl;
		cout << "4. Eliminar USUARIO" << endl;
		cout << "5. Salir" << endl;
		cin >> op;
		cin.ignore();

		switch (op)
		{
		case 1:
			int u;
			cout << "Tipo de USUARIO que quiera dar de ALTA" << endl;
			cout << "1. ADMINISTRADOR" << endl;
			cout << "2. CAJERO" << endl;
			cout << "3. CLIENTE" << endl;
			cin >> u;

			switch (u)
			{
			case 1:
				cout << "Ingrese el Nombre del ADMINISTRADOR:" << endl;
				cin.getline(NodoAd->nom, 50);
				cout << "Ingrese la Contraseña:" << endl;
				cin.getline(NodoAd->pass, 10);
				RegistroAdmin(NodoAd);
				goto si;
				break;

			case 2:
				cout << "Ingrese el Nombre del CAJERO:" << endl;
				cin.getline(NodoCj->nom, 50);
				cout << "Ingrese la Contraseña:" << endl;
				cin.getline(NodoCj->pass, 10);
				RegistroCajero(NodoCj);
				goto si;
				break;

			case 3:
				cout << "Ingrese el Nombre del CLIENTE:" << endl;
				cin.getline(NodoClt->nom, 50);
				cout << "Ingrese el Alias del CLIENTE:" << endl;
				cin.getline(NodoClt->alias, 15);
				cout << "Ingrese el Correo del CLIENTE:" << endl;
				cin.getline(NodoClt->email, 25);
				RegistroCliente(NodoClt);
				goto si;
				break;
			}

		case 2:
			Lista();
			goto si;
			break;

		case 3:
			int j;
			cout << "Tipo de USUARIO que quiera MODIFICAR" << endl;
			cout << "1. ADMINISTRADOR" << endl;
			cout << "2. CAJERO" << endl;
			cout << "3. CLIENTE" << endl;
			cin >> j;

			switch (j)
			{
			case 1:
			{
				cout << "Nombre del Administrador a MODIFICAR:" << endl;
				cin.getline(nomAdmin, 50);
				ActualizarAdmin(nomAdmin);
				cin.ignore();
				goto si;
				break;
			}

			case 2:
			{
				cout << "Nombre del Cajero a MODIFICAR:" << endl;
				cin.getline(nomCaja, 50);
				ActualizarCajero(nomCaja);
				cin.ignore();
				goto si;
				break;
			}

			case 3:
			{
				cout << "Nombre del Cliente a MODIFICAR:" << endl;
				cin.getline(nomCliente, 50);
				ActualizarCliente(nomCliente);
				cin.ignore();
				goto si;
				break;
			}

			}
			goto si;
			break;

		case 4:
			int q;
			cout << "Tipo de USUARIO que quiera ELIMINAR" << endl;
			cout << "1. ADMINISTRADOR" << endl;
			cout << "2. CAJERO" << endl;
			cout << "3. CLIENTE" << endl;
			cin >> q;

			switch (q)
			{
			case 1: cout << "Nombre del Administrador a ELIMINAR:" << endl;
				cin.getline(nomAdmin, 50);
				EliminarAdmin(nomAdmin);
				cin.ignore();
				goto si;
				break;

			case 2: cout << "Nombre del Cajero a ELIMINAR:" << endl;
				cin.getline(nomCaja, 50);
				EliminarCajero(nomCaja);
				cin.ignore();
				goto si;
				break;

			case 3: cout << "Nombre del Cliente a ELIMINAR:" << endl;
				cin.getline(nomCliente, 50);
				EliminarCliente(nomCliente);
				cin.ignore();
				goto si;
				break;
			}
			goto si;
			break;

		case 5:
			Salir();
			goto si;
			break;
		}
	}
}

void RegistroAdmin(admin* nuevo)
{
	if (inicio == nullptr)
	{
		inicio = new admin;
		aux = inicio;

		strcpy_s(aux->nom, nuevo->nom);
		strcpy_s(aux->pass, nuevo->pass);
		aux->sig = nullptr;
	}
	else {
		aux = inicio;
		while (aux->sig != nullptr)
		{
			aux = aux->sig;
		}

		aux->sig = new admin;
		aux = aux->sig;

		strcpy_s(aux->nom, nuevo->nom);
		strcpy_s(aux->pass, nuevo->pass);

		aux->sig = nullptr;
	}
}

void RegistroCajero(cajero* nuevo)
{
	if (inicio == nullptr)
	{
		inicio = new cajero;
		x = inicio;

		strcpy_s(x->nom, nuevo->nom);
		strcpy_s(x->pass, nuevo->pass);
		x->sig = nullptr;
	}
	else
	{
		x = inicio;

		while (x->sig != nullptr)
		{
			x = x->sig;
		}

		x->sig = new cajero;
		x = x->sig;

		strcpy_s(x->nom, nuevo->nom);
		strcpy_s(x->pass, nuevo->pass);

		x->sig = nullptr;
	}
}

void RegistrarCliente(cliente* nuevo)
{
	if (inicio == nullptr) {
		inicio = new cliente;
		y = inicio;

		strcpy_s(y->nom, nuevo->nom);
		strcpy_s(y->alias, nuevo->alias);
		strcpy_s(y->email, nuevo->email);
		y->sig = nullptr;
	}
	else {
		y = inicio;
		while (y->sig != nullptr)
		{
			y = y->sig;
		}

		y->sig = new cliente;
		y = y->sig;

		strcpy_s(y->nom, nuevo->nom);
		strcpy_s(y->alias, nuevo->alias);
		strcpy_s(y->email, nuevo->email);
		y->sig = nullptr;
	}
}

void ActualizarAdmin(char nomAd[50])
{
	aux = inicio;

	if (aux == nullptr)
	{
		cout << "Lista VACIA, Ingrese ADMINISTRADORES" << endl;
	}
	else
	{
		while (aux != nullptr && strcmp(aux->nom, nomAd) != 0)
		{
			aux = aux->sig;
		}
		if (aux == nullptr)
		{
			cout << "Administrador NO encontrado" << endl;
		}
		else
		{
			cout << "Se ah ENCONTRADO el Administrador" << endl;
			cout << "Nombre del ADMINISTRADOR: " << aux->nom << endl;
			cout << "\n";

			cout << "Nuevo NOMBRE" << endl;
			cin.getline(aux->nom, 50);
			cout << "\n";

			cout << "Se ah MODIFICADO el Administrador" << endl;
		}
	}
	system("PAUSE");
}

void ActualizarCajero(char nomCj[50])
{
	x = inicio;

	if (x == nullptr)
	{
		cout << "Lista VACIA, Ingrese CAJEROS" << endl;
	}
	else
	{
		while (x != nullptr && strcmp(x->nom, nomCj) != 0)
		{
			x = x->sig;
		}
		if (x == nullptr)
		{
			cout << "Cajero NO encontrado" << endl;
		}
		else
		{
			cout << "Se ah ENCONTRADO el Cajero" << endl;
			cout << "Nombre del CAJERO: " << x->nom << endl;
			cout << "\n";

			cout << "Nuevo NOMBRE" << endl;
			cin.getline(x->nom, 50);
			cout << "\n";

			cout << "Se ah MODIFICADO el Cajero" << endl;

		}
	}
	system("PAUSE");
}

void ActualizarCliente(char nomClt[50])
{

	y = inicio;

	if (y == nullptr)
	{
		cout << "Lista VACIA, Ingrese CLIENTE" << endl;
	}
	else {
		while (y != nullptr && strcmp(y->nom, nomClt) != 0)
		{
			y = y->sig;
		}
		if (y == nullptr)
		{
			cout << "Cliente NO encontrado" << endl;
		}
		else
		{
			cout << "Se ah ENCONTRADO el Cliente" << endl;
			cout << "Nombre del CLIENTE: " << y->nom << endl;
			cout << "\n";

			cout << "Nuevo NOMBRE" << endl;
			cin.getline(y->nom, 50);
			cout << "\n";

			cout << "Se ah MODIFICADO el Cliente" << endl;
		}
	}
	system("PAUSE");
}

void Lista() {
	system("cls");
	if (inicio == nullptr)
	{

		cout << "\n";
		cout << "La Lista esta VACIA. Agregue USUARIOS";

	}
	else if (aux == inicio)
	{
		aux = inicio;

		while (aux != nullptr)
		{
			cout << "ADMINISTRADORES:" << aux->nom << endl;
			aux = aux->sig;
		}
	}
	else if (x == inicio)
	{
		x = inicio;

		while (x != nullptr)
		{
			cout << "CAJERO:: " << x->nom << endl;
			x = x->sig;
		}
	}
	else if (y == inicio)
	{
		y = inicio;

		while (y != nullptr)
		{
			cout << "CLIENTE: " << y->nom << endl;
			y = y->sig;
		}
	}
}

void EliminarAdmin(char eliAd[50])
{
	aux = inicio;
	admin* anterior = nullptr;

	if (aux == nullptr)
	{
		cout << "Lista VACIA, Ingrese ADMINISTRADORES" << endl;
	}
	else
	{
		while (aux != nullptr && strcmp(aux->nom, eliAd) != 0)
		{
			aux = aux->sig;
			anterior = aux;
		}
		if (aux == nullptr)
		{
			cout << "Administrador NO encontrado" << endl;
		}
		else if (aux == inicio);
		{
			cout << "Se ah ENCONTRADO el Administrador" << endl;
			cout << "Nombre del ADMINISTRADOR: " << aux->nom << endl;
			cout << "\n";

			inicio = aux->sig;

			delete aux;
			aux = inicio;
			cout << "Se ah ELIMINADO el Administrador" << endl;
		}
		else
		{
			cout << "Se ah ENCONTRADO el Administrador" << endl;
			cout << "Nombre del ADMINISTRADOR: " << aux->nom << endl;
			cout << "\n";
			anterior->sig = aux->sig;

			delete aux;
			aux = inicio;

			cout << "Se ah ELIMINADO el Administrador" << endl;
		}
	}
	system("PAUSE");
}

void EliminarCajero(char eliCj[50])
{
	x = inicio;
	cajero* anterior = nullptr;

	if (x == nullptr)
	{
		cout << "Lista VACIA, Ingrese CAJEROS" << endl;
	}
	else
	{
		while (x != nullptr && strcmp(x->nom, eliCj) != 0)
		{
			x = x->sig;
			anterior = x;
		}
		if (x == nullptr)
		{
			cout << "Cajero NO encontrado" << endl;
		}
		else if (x == inicio)
		{
			cout << "Se ah ENCONTRADO el Cajero" << endl;
			cout << "Nombre del CAJERO:" << x->nom << endl;
			cout << "\n";

			inicio = x->sig;


			delete x;
			x = inicio;
			cout << "Se ah ELIMINADO el Cajero" << endl;
		}
		else
		{
			cout << "Se ah ENCONTRADO el Cajero" << endl;
			cout << "Nombre del CAJERO:" << x->nom << endl;
			cout << "\n";
			anterior->sig = x->sig;

			delete x;
			x = inicio;

			cout << "Se ah ELIMINADO el Cajero" << endl;
		}
	}
	system("PAUSE");
}

void EliminarCliente(char eliClt[50])
{
	y = inicio;
	cliente* anterior = nullptr;

	if (y == nullptr)
	{
		cout << "Lista VACIA, Ingrese USUARIOS" << endl;
	}
	else {
		while (y != nullptr && strcmp(y->nom, eliClt) != 0)
		{
			y = y->sig;
			anterior = y;
		}
		if (y == nullptr)
		{
			cout << "Cliente NO encontrado" << endl;
		}
		else if (y == inicio)
		{
			cout << "Se ah ENCONTRADO el Cliente" << endl;
			cout << "Nombre del CLIENTE:" << y->nom << endl;
			cout << "\n";

			inicio = y->sig;

			delete y;
			y = inicio;
			cout << "Se ah ELIMINADO el Usuario" << endl;
		}
		else
		{
			cout << "Se ah ENCONTRADO el Cliente" << endl;
			cout << "Nombre del CLIENTE: " << y->nom << endl;
			cout << "\n";
			anterior->sig = y->sig;

			delete y;
			y = inicio;

			cout << "Se ah ELIMINADO el Usuario" << endl;
		}
	}
	system("PAUSE");
}

void GuardarBinario()
{
	Archivo.open("Archivo.bin", ios::out | ios::binary);
	if (Archivo.is_open())
	{
		Archivo.write(reinterpret_cast<char*>(actual), sizeof(Nodo));
	}
	else
		cout << "Unable to open file" << endl;
	Archivo.close();
}

void LeerBinario()
{
	Archivo.open("Archivo.bin", ios::out | ios::binary);
	if (Archivo.is_open())
	{
		int size = Archivo.tellg();

		int i = 0;
		nodo* Temp = new nodo;
		Archivo.seekg(i * sizeof(nodo));
		Archivo.read(reinterpret_cast<char*>(Temp), sizeof(nodo));

		nodo lista;
		lista.a = Temp->a;
		strcpy_s(lista.b, 12, Temp->b);
		cout << lista.a << "," << lista.b << endl;
		delete Temp;
	}
	else
		cout << "Unable to open file" << endl;
	Archivo.close();
}

void Salir()
{

}