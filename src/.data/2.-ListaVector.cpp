void mostrarListaV() {
    ListaV v;
    v.inserta_primero(10);
    v.inserta_primero(32);
    v.inserta_primero(43);
    v.inserta_primero(3829);
    v.inserta_primero(3289);
    v.mostrar();
    std::cout << v.fin() << std::endl;
    std::cout << v.primero() << std::endl;
    std::cout << v.siguiente(3) << std::endl;
    std::cout << v.anterior(3) << std::endl;
    std::cout << v.vacia() << std::endl;
    std::cout << v.recupera(4) << std::endl;
    std::cout << v._longitud() << std::endl;
    v.mostrar();
    v.inserta(4, 12);
    v.mostrar();
    v.inserta_primero(100);
    v.mostrar();
    v.inserta_ultimo(200);
    v.mostrar();
    v.suprime(1);
    v.mostrar();
    v.modifica(4, 1000000);
    v.mostrar();
}