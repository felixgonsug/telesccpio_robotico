void setup(){
	CerrarTapa();
	Serial.begin(9600);
	while (!Serial) {
    ;//espero a que se de la conecxion con la pc
}

void loop(){
	//realizo handshake con la pc
	handshake();
	//si no estoy en situacion de error de pc:
	if (!error_pc){
		//genero datos de clima nuevos
		leer_clima();
		// si el clima es adverso o recibo comando cerrar, cierro tapa
		if (accion = cerrar OR mal_clima){
			CerrarTapa();
		} else if (accion = abrir){	//si recibo comando de abrir, abro tapa
			AbrirPuerta();
		}
	}
}
