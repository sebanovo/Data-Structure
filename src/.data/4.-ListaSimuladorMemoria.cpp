void mostrarListaSM() {
    ListaSM* lista = new ListaSM();
    lista->inserta_primero(100);
    lista->inserta_primero(200);
    lista->inserta_primero(300);
    cout << lista->mostrar() << endl;
    lista->elimina_dato(200);
    cout << lista->mostrar() << endl;

    delete lista;
}