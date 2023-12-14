// LecturaTextoVocalesConsonantes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // Incluye las funciones b�sicas de entrada y salida.
#include <fstream>  // Incluye las funciones para manejar archivos.
#include <map>      // Incluye la biblioteca para usar contenedores de tipo mapa.
#include <string>   // Incluye la biblioteca para usar el tipo de dato string.
#include <cctype>   // Incluye funciones para manejar caracteres.
#include <cwchar>   // Incluye funciones y tipos para manejar caracteres anchos.

// Funci�n que determina si un car�cter es una vocal.
bool esVocal(char c) {
    std::string vocales = "aeiou�����������"; // Define un string con todas las vocales, incluyendo acentuadas y di�resis.
    return vocales.find(c) != std::string::npos; // Busca el car�cter en el string de vocales y retorna verdadero si lo encuentra.
}

// Funci�n que determina si un car�cter es alfab�tico.
bool esAlfabetico(char c) {
    // Comprueba si el car�cter est� en el rango de letras may�sculas, min�sculas o acentuadas.
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= '�' && c <= '�') || (c >= '�' && c <= '�') ||
        std::wstring(L"������������").find(c) != std::string::npos;
}

int main() {
    std::ifstream archivo("texto.txt"); // Abre el archivo de texto.
    // Verifica si el archivo se abri� correctamente.
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    // Lee todo el contenido del archivo en un string.
    std::string texto((std::istreambuf_iterator<char>(archivo)), std::istreambuf_iterator<char>());
    archivo.close(); // Cierra el archivo.

    std::map<char, int> contadorVocales; // Mapa para contar la ocurrencia de cada vocal.
    int contadorConsonantes = 0; // Contador para las consonantes.
    int totalLetras = 0; // Contador para el total de letras alfab�ticas.

    // Recorre cada car�cter del texto.
    for (char c : texto) {
        char cMin = std::tolower(c); // Convierte el car�cter a min�scula.
        // Comprueba si el car�cter es alfab�tico.
        if (esAlfabetico(cMin)) {
            // Si es una vocal, incrementa el contador correspondiente en el mapa.
            if (esVocal(cMin)) {
                contadorVocales[cMin]++;
                totalLetras++;
            }
            // Si no es una vocal, es una consonante.
            else {
                contadorConsonantes++;
                totalLetras++;
            }
        }
    }

    // Calcula el porcentaje total de vocales.
    double porcentajeTotalVocales = totalLetras > 0 ? 100.0 * (totalLetras - contadorConsonantes) / totalLetras : 0;

    // Muestra los resultados.
    std::cout << "Consonantes: " << contadorConsonantes << std::endl;
    for (auto const par : contadorVocales) {
        std::cout << "Vocal " << par.first << ": " << par.second << " veces, ";
        std::cout << (100.0 * par.second / totalLetras) << "% del total" << std::endl;
    }
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
