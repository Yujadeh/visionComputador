void main(){
	int rows = 600;
    int cols = 800;
    int rec = 150;
      
		/* Creamos un objeto Mat de 600x800 píxeles de 3 canales(imagen RGB) cuyo fondo es negro */
       Mat img(rows, cols, CV_8UC3, Scalar::all(0));

       /* Hacemos uso de funciones básicas para dibujar un circulo en el centro de la imagen de un radio de 200*/
       circle(img, Point(cols / 2, rows / 2), 200, Scalar(255,0,0), 3);

	   //Insertamos un texto
       putText(img, "Ejemplo Color", Point(90,320), FONT_HERSHEY_SCRIPT_COMPLEX, 3, CV_RGB(125,12,145), 2);

	   /* Creamos un objeto Mat de 600x800 píxeles de 3 canales(imagen RGB) cuyo fondo es negro */
       Mat imag(rows, cols, CV_8UC1, Scalar::all(0));

       /* Hacemos uso de funciones básicas para dibujar un circulo en el centro de la imagen de un radio de 200*/
       circle(imag, Point(cols / 2, rows / 2), 200, Scalar(255,0,0), 3);

	   //Insertamos un texto
       putText(imag, "Ejemplo de Grises", Point(75,320), FONT_HERSHEY_SCRIPT_COMPLEX, 3, CV_RGB(125,12,145), 2);

	   /*Operamos con ambas imagenes
	   Mat escala_color;
	   cvtColor(imag, escala_color, CV_GRAY2RGB);

	   //Dibujo de rectangulo a modo de ejemplo
	   rectangle(escala_color, Point(rec, rec), Point(cols - rec, rows - rec), CV_RGB(0,255,255));
	   */


	
       imshow("Ventana 1", img);
	   imshow("Ventana 2", imag);
       waitKey(0);
	   destroyWindow("Ventana 1");
	   destroyWindow("Ventana 2");
	   
}