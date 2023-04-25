Algoritmo sin_titulo
	Escribir "Hola ,bienvenido , cual es el usuario para la tienda?"
	leer usuario
	Escribir  "Cual sera la contraseña?"
	leer contraseña
	Limpiar Pantalla
	Escribir "Usuario:"
	leer chequeo
	Mientras chequeo<>usuario Hacer
		Escribir "Usuario incorrecto,try again"
		leer chequeo
	Fin Mientras
	Escribir "Contraseña:"
	leer chequeocontraseña
	Mientras chequeocontraseña<>contraseña Hacer
		Escribir "Contraseña incorrecto,try again"
		leer chequeocontraseña
	Fin Mientras
	escribir "Entraste "
FinAlgoritmo
