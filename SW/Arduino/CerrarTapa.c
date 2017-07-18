void CerrarTapa() {
	if (digitalRead(FinCarreraCerrado) { //si ya esta cerrada no hago nada
		error_cerrando = 0;
	} else { //si no esta cerrada
		pasos = 0;
		while (pasos <= MaxPAsos && !digitalRead(FinCarreraCerrado)) { //avanzo hasta completar pasos o sensor cerrado = 1
			AvanzarPaso();
			pasos++;
			delay(max_vel_motor)
		}
		if (pasos > MaxPAsos) { //si no hubo senal del sensor de cerrado imprimo error de cerrado
			error_cerrando = 1;
		} else { //todo OK
			error_cerrando = 0;
		}
	}
}
