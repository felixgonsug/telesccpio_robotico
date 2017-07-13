int reset1 = 0;
int reset2 = 0;
int ACN = 0;
int error_pc = 0;
int hola = 0;
int intento_resetPC = 0;
int mal_clima = 0;
int error_cerrando = 0
int error_abriendo = 0;

void setup(){
	CerrarTapa(); //despues de un reset cierro tapa por las dudas
	Serial.begin(9600);
	while (!Serial) {
    ;//espero a que se de la conecxion con la pc
	}
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
