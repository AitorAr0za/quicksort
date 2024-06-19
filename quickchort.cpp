#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

void imprimirArrai(int arr[], int largo) {

    for (int i = 0; i < largo; i++) cout << arr[i] << " ";

}

void interkambio(int& a, int& b) {

    int temporal = a;
    a = b;
    b = temporal;

}

void qs(int arr[], int cotaInf, int cotaSup) {

    int izq = cotaInf;
    int der = cotaSup;
    int medio = cotaInf + (cotaSup - cotaInf) / 2;
    int pivote = arr[medio];

    do {

        while (arr[izq] < pivote && izq < cotaSup) izq++;

        while (arr[der] > pivote && der > cotaInf) der--;

        if (izq <= der) {

            interkambio(arr[izq], arr[der]);
            izq++;
            der--;

        }


    } while (izq <= der);

    if (cotaInf < der) qs(arr, cotaInf, der);

    if (cotaSup > izq) qs(arr, izq, cotaSup);


}



int main() {

    int length;

    cout << "Ingrese el largo del array: ";
    cin >> length;

    srand(time(0));
    int arrai[length];
    int inicio = 0;

    for (int i = 0; i < length; i++) arrai[i] = rand() % 100;

    cout << "El array ahora mismo se ve asi: " << endl;
    imprimirArrai(arrai, length);

    cout << endl << endl << "Tras aplicar el metodo de ordenamiento Quicksort, el array queda asi: " << endl;
    qs(arrai, inicio, length);
    imprimirArrai(arrai, length);

    return 0;
}
