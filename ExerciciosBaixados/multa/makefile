all: geraos geralib geraexecutavel limpadir

geraos: 
	gcc -c circulo.c retangulo.c triangulo.c multa.c

geralib:
	ar rcs libmulta.a circulo.o retangulo.o triangulo.o multa.o

geraexecutavel:
	gcc main.c -o main -L. -lmulta

limpadir:
	rm -rf *.o