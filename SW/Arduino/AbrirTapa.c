void AbrirTapa() {
	if (digitalRead(FinCarreraAbierto) { //si ya esta abierto no hago nada
		error_abriendo = 0;
	} else { //en el caso de que no este abierto
		DigitalWrite(iman, 1); //libero el iman
		pasos = 0; 
		while (pasos <= MaxPAsos && !digitalRead(FinCarreraAbierto)) { //activo motores hasta abrir o hasta que complete los pasos
			RetrocederPaso();
			pasos++;
		}
		DigitalWrite(iman, 0); //cierro el iman
		if (pasos > MaxPAsos) { //si no llego a fin de carrera cierro tapa e mprimo error
			CerrarTapa();
			error_abriendo = 1;
		} else { //si abrio normalmente no imprimo error
			error_abriendondo = 0;
		}
	}
}
