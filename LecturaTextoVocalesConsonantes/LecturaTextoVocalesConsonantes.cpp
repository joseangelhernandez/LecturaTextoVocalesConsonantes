// LecturaTextoVocalesConsonantes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // Incluye las funciones básicas de entrada y salida
#include <fstream>  // Incluye las funciones para manejar archivos
#include <string>   // Incluye la biblioteca para usar el tipo de dato string
#include <cctype>   // Incluye funciones para manejar el capCase caracteres

// Función que determina si un carácter es una vocal
bool esVocal(char c) {
    std::string vocales = "aeiouáéíóúàèìòùü"; // Define un string con todas las vocales, incluyendo acentuadas y diéresis
    return vocales.find(c) != std::string::npos; // Busca el carácter en el string de vocales y retorna verdadero si lo encuentra
}

// Función que determina si un carácter es alfabético
bool esAlfabetico(char c) {
    // Comprueba si el carácter está en el rango de letras mayúsculas, minúsculas o acentuadas
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= 'Á' && c <= 'Ú') || (c >= 'á' && c <= 'ú') ||
        std::wstring(L"ÀÈÌÒÙàèìòùÜü").find(c) != std::string::npos;
}

int main() {
    std::ifstream archivo("texto.txt"); // Abre el archivo de texto
    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    // Lee todo el contenido del archivo en un string
    std::string texto((std::istreambuf_iterator<char>(archivo)), std::istreambuf_iterator<char>());
    archivo.close(); // Cierra el archivo

    // Contadores para las vocales y consonantes
    int contadorConsonantes = 0, totalVocales = 0, totalLetras = 0;
    int a = 0, e = 0, i = 0, o = 0, u = 0; // Contadores para cada vocal

    // Recorre cada carácter del texto
    for (char c : texto) {
        char cMin = std::tolower(c);// Convierte el carácter a minúscula
        // Comprueba si el carácter es alfabético
        if (esAlfabetico(cMin)) {
            totalLetras++; // Incrementa el contador total de letras
            if (esVocal(cMin)) { // Si es una vocal...
                totalVocales++; // Incrementa el contador de vocales
                // Incrementa el contador de la vocal específica
                if (cMin == 'a') a++;
                else if (cMin == 'e') e++;
                else if (cMin == 'i') i++;
                else if (cMin == 'o') o++;
                else if (cMin == 'u') u++;
            }
            else { // Si no es una vocal, es una consonante
                contadorConsonantes++;
            }
        }
    }

    // Calcula el porcentaje total de vocales
    double porcentajeTotalVocales = totalLetras > 0 ? 100.0 * totalVocales / totalLetras : 0;

    // Muestra los resultados
    std::cout << "Consonantes: " << contadorConsonantes << std::endl;
    // Muestra el conteo y el porcentaje para cada vocal
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
