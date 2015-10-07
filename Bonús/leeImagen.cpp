#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\opencv.hpp>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;
using namespace cv;

/*Estructuras auxiliares usadas*/

/*Struct pixel. Guarda las coordenadas x e y del pixel de una imagen*/
struct pixel{
	int x;
	int y;
};
/*Struct color. Guarda los valores [0,255] para cada uno de los canales R,G,B */
struct color{
	int R;
	int B;
	int G;
};

/**
* @brief Lectura de una imagen a color o escala de grises
* @param imagen, dirección en disco de la imagen a leer
* @param flagColor, numero que indica si la imagen pasada es a color o no
* @return Asigna la imagen leida a una variable
*/
Mat leeImagen(String imagen, int flagColor){
	Mat im;
	im = imread(imagen,1);

	if(flagColor == 1){
		cvtColor(im, im, CV_RGB2GRAY);	
	}
	return im;
};

/**
* @brief Imprime una imagen por pantalla 
* @param img, imagen que mostramos por pantalla
* @return Muestra por pontalla una ventana con la imagen y luego la borra
*/
void pintaImagen(Mat img){
	namedWindow("ventana",1);
	waitKey(1000);

	cout << "Ventana creada " << endl;
	imshow("ventana",img);
	waitKey(0);
	cout << "imagen mostrada " << endl;
	destroyWindow("ventana");

};

/**
* @brief Muestra por pantalla varias imagenes
* @param imagenes, lista de imagenes que queremos mostrar
* @return Muestra varias imagenes en una ventana
*/
void pintaMI(vector <Mat> imagenes){
	/*
		Obtengo el tamaño de la ventana.
		- Ancho: suma de los anchos
		- Alto: máximo de las alturas
	*/

	int ancho = 0;
	int largo = 0;
	for(int i=0; i < imagenes.size();i++){
		ancho = ancho + imagenes[i].cols;
	};

	for(int i=0; i < imagenes.size();i++){
		int aux = imagenes[i].rows;
		if(aux > largo){largo = aux;};
	};

	//Creo un objeto Mat para incorporar todas las imagenes
	Mat ventana_mixta(largo, ancho, imagenes[0].type());

	int pivote = 0;

	for(int i=0; i < imagenes.size();i++){
		imagenes[i].copyTo(ventana_mixta(Rect(pivote,0,imagenes[i].cols,imagenes[i].rows)));
		pivote = pivote + imagenes[i].cols;
	};

	pintaImagen(ventana_mixta);
};


/**
* @brief Modifica el valor de unos píxeles de una zona de la imagen determinada
* @param imagen, es el objeto al que queremos modificar parcial o totalmente sus píxeles
* @param mascara, zona establecida para poder modificar
* @param valor, valor a establecer a los píxeles
* @return Asigna a la imagen una zona establecida por mascara un valor
*/
void modificaImagen(Mat imagen, vector <pixel> mascara, color valor){
	int coord_x, coord_y;
	for(int i=0;i < mascara.size(); i++){
		coord_x = mascara[i].x;
		coord_y = mascara[i].y;
		Point3_<uchar>* p = imagen.ptr<Point3_<uchar> >(coord_x,coord_y);
		p->x = valor.B; //B
		p->y = valor.G; //G
		p->z = valor.R; //R
	}

};

void main(){
	cout << "OpenCV detectada " << endl;
	vector <Mat> imagen_prueba;

	/*	Inserto en el vector de imagenes la imagen dada de prueba "lena.jpg". Esta imagen la leo con la función
		creada para dicho proposito, leeImagen("",)
	*/
	imagen_prueba.push_back(leeImagen("lena.jpg",0));
	imagen_prueba.push_back(leeImagen("lena.jpg",0));
	cout << "Imagen detectada " << endl;

	/*
		Pruebo la función para mostrar varias imagenes a la vez
	*/
	pintaMI(imagen_prueba);
	/*
		Creo una imagen con fondo negro para posteriormente modificar algunos de sus pixeles
	*/

	Mat img(imagen_prueba[0].cols, imagen_prueba[0].rows, imagen_prueba[0].type(), Scalar::all(0));
	vector <pixel> lista;
	/*Tomo la diagonal principal de la imagen como conjunto de pixeles a modificar*/
	for(int i=0;i< img.rows;i++){
		lista.push_back(pixel());
		lista[i].x = i;
		lista[i].y = i;
	};
	/*Asigno el color que quiero para esos píxeles*/
	color valor;
	valor.B=0; valor.G=255; valor.R=255;
	cout << "Lista de pixeles captada " << endl;
	/*Invoco a la función para modificar píxeles, creando así una línea amarilla en la diagonal principal*/
	modificaImagen(img,lista,valor);
	/*La imprimo por pantalla para observar su modificación */
	pintaImagen(img);
	/*Esta nueva imagen la inserto en mi vector de imagenes y vuelvo a imprimir las 3*/
	imagen_prueba.push_back(img);

	pintaMI(imagen_prueba);



}

