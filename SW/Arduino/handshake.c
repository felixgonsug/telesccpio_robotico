void handshake() {
	// Si intente resetear la pc MaxResetsPC me quedo en error esperando reset 
	if (intento_resetPC > MaxResetsPC){
		error_pc = 1;
		Serial.write(error_pc);
	} else {
		leido = 0;
		//intento comunicarme 15 veces
		for (intento_com = 0; intento_com < MaxIntento_com ; intento_om++ ) {
			//envío el saludo a ser respondido, niego el saludo para la proxima recepción de datos
			Serial.write(hola);
			hola = !hola;
			//envio datos del clima y los ultimos datos recibidos para mitigar errores de lectura y envío errores en cerrado o abierto si los hubo
			Serial.write(datos_clima);
			Serial.write(reset1);
			Serial.write(reset2);
			Serial.write(ACN);
			Serial.write(informe_errores);
			//doy tiempo a generar respuesta
			delay(tiempo_com);
			// si no obtengo respuesta vuelvo a intentar
			if (serial.available() > 0) {
				//leo la respuesta del saludo y verifico que sea coherente
				respuesta = serial.read()
				if (respuesta = hola) {
					//si la respuesta es coherente leo las palabras de reset de camara y montura y Abrir/Cerrar/Nada
					reset1 = serial.read();
					reset2 = serial.read();
					ACN = serial.read();
					leido = 1;
					//salgo del for
					intento_com = MaxIntento_com;
				} else{ //si la respuesta no es coherente, agrego un delay y realizo un nuevo saludo
					delay(t_nueva_consulta);
				}
			}
		}
		//si no pude comunicarme con la pc:
		if (!leido &&  intento_com >= MaxIntento_com) {
			//cierro tapa, reseteo la pc y espero el tiempo necesario de arranque de la pc
			CerrarTapa();
			digitalWrite(resetPC,  1);
			delay(t_reset);
			digitalWrite(resetPC,  0);
			delay(treset_pc);
			//aumento el conteo de intentos de reset de la pc
			intento_resetPC++;
		//si pude comunicarme:
		} else {
			//Realizo los reset si son necesarios
			if (reset1 OR reset2) {
				digitalWrite(resetMontura,  reset1);
				digitalWrite(resetCamara,  reset2);
				delay(tmin_reset);
				digitalWrite(resetMontura,  0);
				digitalWrite(resetMontura,  0);
			}
		}
	}
}
