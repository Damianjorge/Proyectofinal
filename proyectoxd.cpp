#include <iostream>
#include <string>
#include <ctime> 

using namespace std;

int main() {
    setlocale(LC_ALL, ""); 
    
    string nombre;
    int opcion = 0;
    int puntaje = 0;
    int respuestaUsuario;
    int respuestaCorrecta;
    
    time_t tiempoInicio;
    time_t tiempoFin;
    double duracion; 
    int respuestasCorrectas[5] = {10, 6, 9, 4, 5}; 

    cout<< " Hola! Por favor ingresa tu nombre: "<<endl;
    cin>> nombre;

    // EL BUCLE EXTERNO: REINICIA EL MENÚ DESPUÉS DE CADA ACCIÓN (excepto Salir)
    do {
        // --- 1. MOSTRAR MENÚ Y PEDIR OPCIÓN ---
        cout<< "\nBIENVENIDO, querido usuario "<< nombre<< ", a la Mision de Estrellas!"<<endl;
        cout<< "Elige una opcion para continuar:"<<endl;
        cout<< "1. Ver la Mision" <<endl;
        cout<< "2. Iniciar Desafio (5 preguntas)"<<endl;
        cout<< "3. Salir " <<endl<<endl;
        cout<< "Opcion: ";
        cin>> opcion;

        // --- 2. EVALUAR Y EJECUTAR ACCIÓN ---
        switch (opcion) {
            case 1: 
                // CASE 1: Misión / Instrucciones (Vuelve al inicio del DO-WHILE)
                cout<< "------------ EL GRAN DESAFIO MENTAL ------------"<<endl;
                cout<< "Bienvenido, "<< nombre << "!"<<endl;
                cout<< "Tu mision es simple: Un antiguo pergamino contiene 5 acertijos matematicos."<<endl;
                cout<< "* Tu objetivo es: Escribir el numero exacto que falta en el acertijo (la respuesta)."<<endl;
                cout<< "* Cada acierto te da 1 estrella."<<endl;
                cout<< "Mucha suerte! "<<endl<<endl; 
                break;

            case 2: { 
                // CASE 2: Iniciar Juego (NO vuelve al menú, fuerza la salida)
                cout<< "------------ COMIENZA EL DESAFIO ------------"<<endl<<endl;
                
                puntaje = 0;
                time(&tiempoInicio);

                // CICLO FOR para las 5 preguntas
                for (int i = 0; i < 5; i++) {
                    cout<< "Pregunta "<< (i + 1) << " de 5:"<<endl;

                    switch (i) {
                        case 0:
                            cout<< "¿Cuanto es 5 + 5?"<<endl; 
                            cout<< "Opciones: [ 8 ] [ 10 ] [ 12 ]"<<endl;
                            break;
                        case 1:
                            cout<< "¿Cuanto es 10 - 4?"<<endl;
                            cout<< "Opciones: [ 7 ] [ 4 ] [ 6 ]"<<endl;
                            break;
                        case 2:
                            cout<< "¿Cuanto es 3 x 3?"<<endl;
                            cout<< "Opciones: [ 6 ] [ 9 ] [ 10 ]"<<endl;
                            break;
                        case 3:
                            cout<< "¿Cuanto es 8 ÷ 2?"<<endl;
                            cout<< "Opciones: [ 2 ] [ 4 ] [ 16 ]"<<endl;
                            break;
                        case 4:
                            cout<< "Si 2(x) = 10. ¿Cuanto vale x?"<<endl;
                            cout<< "Opciones: [ 12 ] [ 5 ] [ 8 ]"<<endl;
                            break;
                    }
                    
                    respuestaCorrecta = respuestasCorrectas[i]; 

                    cout<< "Tu respuesta: ";
                    cin>> respuestaUsuario;
                    
                    
                    if (respuestaUsuario == respuestaCorrecta) {
                        cout<< "Correcto! Ganaste una estrella."<<endl<<endl;
                        puntaje++;
                    } else {
                        cout<< "Incorrecto. La respuesta era "<< respuestaCorrecta <<endl<<endl;
                    }
                }

                time(&tiempoFin);
                duracion = difftime(tiempoFin, tiempoInicio); 

                cout<< "------------ MISION CUMPLIDA! ------------"<<endl<<endl;
                cout<< "Jugador: "<< nombre <<endl;
                cout<< "Total de Estrellas Ganadas: "<< puntaje << " de 5."<<endl;
                cout<< "Tiempo total de respuesta: "<< duracion << " segundos."<<endl;
                
                if (puntaje >= 4) {
                     cout<< "Eres un Super-Heroe Matematico!"<<endl;
                } else {
                     cout<< "Sigue practicando para coleccionarlas todas."<<endl;
                }
                
                opcion = 3; 
                break;
            } 
            case 3:
                cout<< "Hasta pronto, "<< nombre << "!"<<endl;
                break;
                
            default:
                cout << "Opcion invalida. Intentalo de nuevo."<<endl;
                break;
        }

    } while (opcion != 3); 

    return 0;
}
