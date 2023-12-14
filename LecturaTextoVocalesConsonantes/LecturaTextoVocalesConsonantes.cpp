// LecturaTextoVocalesConsonantes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <codecvt>   // Para std::codecvt_utf8
#include <locale>    // Para std::locale
#include <string>
#include <cctype>

// Convierte vocales acentuadas o con di�resis a su forma b�sica
char normalizarVocal(char c) {
    if (std::string("��������������������").find(c) != std::string::npos) {
        switch (c) {
        case '�': case '�': case '�': case '�': return 'a';
        case '�': case '�': case '�': case '�': return 'e';
        case '�': case '�': case '�': case '�': return 'i';
        case '�': case '�': case '�': case '�': return 'o';
        case '�': case '�': case '�': case '�': return 'u';
        default: return c;
        }
    }
    return c;
}

// Funci�n que determina si un car�cter es una vocal
bool esVocal(char c) {
    std::string vocales = "aeiou"; // Solo vocales b�sicas
    return vocales.find(c) != std::string::npos;
}

// Funci�n que determina si un car�cter es alfab�tico
bool esAlfabetico(char c) {
    // Comprueba si el car�cter est� en el rango de letras alfab�ticas
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '�' && c <= '�') || (c >= '�' && c <= '�') || (c == '�')
        || (c == '�');
        
}

int main() {
    std::wifstream archivo("texto.txt");
    archivo.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>)); // Establece el locale para UTF-8

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    std::wstring texto((std::istreambuf_iterator<wchar_t>(archivo)), std::istreambuf_iterator<wchar_t>());
    archivo.close();

    int contadorConsonantes = 0, totalVocales = 0, totalLetras = 0;
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (char c : texto) {
        if (esAlfabetico(c)) {
            totalLetras++;
            char cMin = normalizarVocal(std::tolower(c));
            if (esVocal(cMin)) {
                totalVocales++;
                switch (cMin) {
                case 'a': a++; break;
                case 'e': e++; break;
                case 'i': i++; break;
                case 'o': o++; break;
                case 'u': u++; break;
                }
            }
            else {
                contadorConsonantes++;
            }
        }
    }

    double porcentajeTotalVocales = totalLetras > 0 ? 100.0 * totalVocales / totalLetras : 0;

    std::cout << "Consonantes: " << contadorConsonantes << std::endl;
    std::cout << "Vocales A: " << a << ", " << (100.0 * a / totalLetras) << "% del total" << std::endl;
    std::cout << "Vocales E: " << e << ", " << (100.0 * e / totalLetras) << "% del total" << std::endl;
    std::cout << "Vocales I: " << i << ", " << (100.0 * i / totalLetras) << "% del total" << std::endl;
    std::cout << "Vocales O: " << o << ", " << (100.0 * o / totalLetras) << "% del total" << std::endl;
    std::cout << "Vocales U: " << u << ", " << (100.0 * u / totalLetras) << "% del total" << std::endl;
    std::cout << "Porcentaje total de vocales: " << porcentajeTotalVocales << "%" << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
