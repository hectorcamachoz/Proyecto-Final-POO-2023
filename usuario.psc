Algoritmo sin_titulo
	Escribir "Hola ,bienvenido , cual es el usuario para la tienda?"
	leer usuario
	Escribir  "Cual sera la contrase�a?"
	leer contrase�a
	Limpiar Pantalla
	Escribir "Usuario:"
	leer chequeo
	Mientras chequeo<>usuario Hacer
		Escribir "Usuario incorrecto,try again"
		leer chequeo
	Fin Mientras
	Escribir "Contrase�a:"
	leer chequeocontrase�a
	Mientras chequeocontrase�a<>contrase�a Hacer
		Escribir "Contrase�a incorrecto,try again"
		leer chequeocontrase�a
	Fin Mientras
	escribir "Entraste "
FinAlgoritmo
