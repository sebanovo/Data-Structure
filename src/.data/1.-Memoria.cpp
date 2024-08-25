#include <limits>
void mostrarMemoria() {
    CSMemoria* mem = nullptr;
    int opcion;
    do {
        cout << "1. Crear Memoria" << endl;
        cout << "2. Pedir espacio" << endl;
        cout << "3. Liberar espacio" << endl;
        cout << "4. Poner dato" << endl;
        cout << "5. Mostrar Memoria" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Entrada no válida. Inténtalo de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                if (mem != nullptr) {
                    delete mem;
                }
                mem = new CSMemoria();
                cout << "Memoria Creada\n";
            } break;

            case 2: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                string ids;
                cout << "Ids: ";
                cin.ignore();
                getline(cin, ids);
                mem->new_espacio(ids);
            } break;

            case 3: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                int dir_delete;
                cout << "Direccion a liberar: ";
                cin >> dir_delete;
                mem->delete_espacio(dir_delete);
            } break;

            case 4: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                int dir;
                cout << "Direccion: ";
                cin >> dir;
                string id;
                cout << "Id: ";
                cin.ignore();
                getline(cin, id);
                int valor;
                cout << "Valor: ";
                cin >> valor;
                mem->poner_dato(dir, id, valor);
            } break;

            case 5: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                mem->mostrar();
            } break;

            case 6: {
                delete mem;
                mem = nullptr;
                cout << "Saliendo...\n"
                     << endl;
            } break;

            default:
                cout << "Opción no válida. Inténtalo de nuevo.\n";
                break;
        }
    } while (opcion != 6);

    delete mem;
}