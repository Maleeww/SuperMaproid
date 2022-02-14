#include "Pantalla.h"
#include "Personaje.h"
#include "Enemigo.h"

#include "Colision.h"
#include "Estrella.h"
#include "Galaxia.h"
#include "Disparo.h"
#include "Boton.h"
#include "Ejercito.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    srand(time(NULL));
    Pantalla_Crea("PantallaJuego", 1240,770); //1440, 970

    //Los comentarios al final de cada imagen son auxiliares para indicarme a mí mismo las imágenes que he liberado en el main, no les de importancia
    //IMÁGENES DE LA PRIMERA PANTALLA
    Imagen playi = Pantalla_ImagenLee("JUGAR51.bmp",255); //
    Imagen playi2 = Pantalla_ImagenLee("JUGAR52.bmp",255); //
    Imagen controli = Pantalla_ImagenLee("controles11.bmp",255);//
    Imagen controli2 = Pantalla_ImagenLee("controles12.bmp",255);//
    Imagen menunave1i = Pantalla_ImagenLee("botonnave11.bmp",255);//
    Imagen menunave2i = Pantalla_ImagenLee("botonnave12.bmp",255);//
    Imagen returni = Pantalla_ImagenLee("return1.bmp",255);//
    Imagen returni2 = Pantalla_ImagenLee("return2.bmp",255);//
    Imagen tituloimagen = Pantalla_ImagenLee("titulo.bmp",255);//
    Imagen fondomenu = Pantalla_ImagenLee("planeta2.bmp",0);//
    Imagen controles = Pantalla_ImagenLee("planeta2controles.bmp",0);//
    Imagen fondomenunave = Pantalla_ImagenLee("menunave.bmp",0); //
    Imagen nave1menu = Pantalla_ImagenLee("nave1.bmp",255);//
    Imagen nave1menu2 = Pantalla_ImagenLee("nave1.bmp",0);//
    Imagen nave2menu = Pantalla_ImagenLee("nave2.bmp",255);//
    Imagen nave2menu2 = Pantalla_ImagenLee("nave2.bmp",0);//


    //IMÁGENES DE LA SEGUNDA PANTALLA
    Imagen fondojuego= Pantalla_ImagenLee("planeta1.bmp",0);//
    Imagen EstI = Pantalla_ImagenLee("estrella.bmp",255); //
    Imagen imagend = Pantalla_ImagenLee("disp2.bmp",255); //
    Imagen hpi2 = Pantalla_ImagenLee("hp5.bmp",255);//
    Imagen hpi = Pantalla_ImagenLee("hp2.bmp",255);//
    Imagen eImagen = Pantalla_ImagenLee("enemigo.bmp",255);//
    Imagen eImagenFrame1 = Pantalla_ImagenLee("enemigoframe2.bmp",255);//
    Imagen eImagenFrame2 = Pantalla_ImagenLee("enemigoframe2.bmp",255);//
    Imagen eImagenFrame3 = Pantalla_ImagenLee("enemigoframe3.bmp",355);//
    Imagen eImagenFrame4 = Pantalla_ImagenLee("enemigoframe4.bmp",455);//
    Imagen eImagenFrame5 = Pantalla_ImagenLee("enemigoframe5.bmp",455);//
    Imagen eImagenFrame6 = Pantalla_ImagenLee("enemigoframe6.bmp",455);//
    Imagen eImagenFrame7 = Pantalla_ImagenLee("enemigoframe7.bmp",455);//
    Imagen eImagenFrame8 = Pantalla_ImagenLee("enemigoframe8.bmp",455);//
    Imagen eImagenFrame9 = Pantalla_ImagenLee("enemigoframe9.bmp",455);//
    Imagen eImagenFrame10 = Pantalla_ImagenLee("enemigoframe10.bmp",455);//
    Imagen eImagenFrame11 = Pantalla_ImagenLee("enemigoframe11.bmp",455);//
    Imagen cuadrado = Pantalla_ImagenLee("gris2.bmp",255);//
    Imagen fuego = Pantalla_ImagenLee("fuego.bmp",255); //
    Imagen misiles = Pantalla_ImagenLee("misiles3.bmp",255); //
    Imagen rayo = Pantalla_ImagenLee("rayaco.bmp",255); //
    Imagen cyan = Pantalla_ImagenLee("cyan.bmp",255); //

    //IMAGEN DE LA TERCERA PANTALLA
    Imagen fondofinal;//

    //IMÁGENES AUXILIARES (tanto de la segunda como la tercera)
    Imagen i1 = Pantalla_ImagenLee("1.bmp",255); //
    Imagen i2 = Pantalla_ImagenLee("2.bmp",255); //
    Imagen i3 = Pantalla_ImagenLee("3.bmp",255); //
    Imagen i4 = Pantalla_ImagenLee("4.bmp",255); //
    Imagen i5 = Pantalla_ImagenLee("5.bmp",255); //
    Imagen i6 = Pantalla_ImagenLee("6.bmp",255);//
    Imagen i7 = Pantalla_ImagenLee("7.bmp",255);//
    Imagen i8 = Pantalla_ImagenLee("8.bmp",255); //
    Imagen i9 = Pantalla_ImagenLee("9.bmp",255); //
    Imagen i0 = Pantalla_ImagenLee("0.bmp",255);//


    int terminado = 0;
    int mousex;
    int mousey;
    char * nombre=NULL; //Puntero a array donde se va a guardar el nombre
    int intnave = 1; //Entero que indica el tipo de nave que ha elegido en el menu, la 1 o la 2
    Boton play = BotonCrea(playi,playi2,Pantalla_Anchura()/2-(350/2),Pantalla_Altura()/8,350,200);
    Boton help = BotonCrea(controli,controli2,Pantalla_Anchura()/5-(350/2),Pantalla_Altura()/1.5,350,200);
    Boton menunaveboton = BotonCrea(menunave1i,menunave2i,4*Pantalla_Anchura()/5-(350/2),Pantalla_Altura()/1.5,350,200);
    Boton returnb = BotonCrea(returni,returni2,Pantalla_Anchura()/120,Pantalla_Altura()/120,350/4,200/2);
    Boton nave1 = BotonCrea(nave1menu,nave1menu2,Pantalla_Anchura()/7,Pantalla_Altura()/3,704/2,704/2);
    Boton nave2 = BotonCrea(nave2menu,nave2menu2,6*Pantalla_Anchura()/7-(704/2),Pantalla_Altura()/3,704/2,704/2);


    while (Pantalla_Activa() && terminado!=1) //cambio esto a !=1 para poder usar la variable con distintas imágenes en la misma pantalla
    {
        SDL_GetMouseState(&mousex, &mousey);


        switch(terminado)
        {
        case(0):
            Pantalla_DibujaImagen(fondomenu,0,0,Pantalla_Anchura(),Pantalla_Altura());
            Pantalla_DibujaImagen(tituloimagen,Pantalla_Anchura()/2-170,Pantalla_Altura()-300,362,128);
            Pantalla_ColorTrazo(157,91,136,255);
            Pantalla_DibujaTexto("Escribe tu nombre", Pantalla_Anchura()/2.45,Pantalla_Altura()/10+60);
            Pantalla_DibujaTexto("Presiona Enter para guardar", Pantalla_Anchura()/2.45,Pantalla_Altura()/10+80);
            Pantalla_DibujaTexto("Presiona Escape para no introducir ningun nombre", Pantalla_Anchura()/2.45,Pantalla_Altura()/10+100);
            Pantalla_DibujaTexto("(Diez caracteres max)", Pantalla_Anchura()/2.45,Pantalla_Altura()/10+120);
            nombre = Pantalla_LeeTexto(Pantalla_Anchura()/2.25,Pantalla_Altura()/10,10,"Nombre"); //guardo en nombre lo escrito (o NULL) si se cancela
            terminado = 2; //Solo se ejecuta una vez, luego paso a la segunda pantalla del menú
            break;

        case(2):
            Pantalla_DibujaImagen(fondomenu,0,0,Pantalla_Anchura(),Pantalla_Altura());
            Pantalla_DibujaImagen(tituloimagen,Pantalla_Anchura()/2-170,Pantalla_Altura()-300,362,128);
            Pantalla_ColorTrazo(255,0,0,255);
            if(BotonDibuja(play,mousex,mousey))
                terminado=1; //Dibuja el botón, y si devuelve 0 (al estar dibujado y hacer click) devuelve 1, haciendo que terminado sea 1 y pasando al juego
            if (BotonDibuja(help,mousex,mousey))  //estos dos botones ponen terminado a 3 o a 2 según el botón para entrar en el switch de más abajo, que incluyen menús
                terminado=3;
            if (BotonDibuja(menunaveboton,mousex,mousey))
                terminado=4;



            Pantalla_Actualiza();
            Pantalla_Espera(40);
            break;
        case(3):
            Pantalla_DibujaImagen(controles,0,0,Pantalla_Anchura(),Pantalla_Altura());
            if(BotonDibuja(returnb,mousex,mousey)) //botón de vuelta al menú del principio (case 2)
                terminado=2;
            Pantalla_Actualiza();
            Pantalla_Espera(40);
            break;
        case(4):
            Pantalla_DibujaImagen(fondomenunave,0,0,Pantalla_Anchura(),Pantalla_Altura());
            if(BotonDibuja(returnb,mousex,mousey))//botón de vuelta al menú del principio (case 2)
                terminado=2;
            if(BotonDibuja(nave1,mousex,mousey))  //2 botones para dos opciones de nave, que se mantienen presionados según el que se haya elegido
            {
                intnave=1;
                //terminado = 0;
            }
            if(BotonDibuja(nave2,mousex,mousey))
            {
                intnave=2;
                // terminado = 0; //vuelta al menú

            }

            switch(intnave) //Dibuja la imagen del botón presionado según la nave que esté elegida
            {
            case(1):
                Pantalla_DibujaImagen(nave1menu2,Pantalla_Anchura()/7,Pantalla_Altura()/3,704/2,704/2);
                break;
            case(2):
                Pantalla_DibujaImagen(nave2menu2,6*Pantalla_Anchura()/7-(704/2),Pantalla_Altura()/3,704/2,704/2);
                break;
            }
            Pantalla_Actualiza();
            Pantalla_Espera(40);
            break;
        }
    }



    Pantalla_ImagenLibera(tituloimagen);
    Pantalla_ImagenLibera(controles);
    Pantalla_ImagenLibera(fondomenunave);

    //libera el botón play y sus imagenes
    BotonLibera(play);
    Pantalla_ImagenLibera(playi);
    Pantalla_ImagenLibera(playi2);

    //libera el botón de controles y sus imagenes
    BotonLibera(help);
    Pantalla_ImagenLibera(controli);
    Pantalla_ImagenLibera(controli2);

    //libera el botón del menu de naves y sus imagenes
    BotonLibera(menunaveboton);
    Pantalla_ImagenLibera(menunave1i);
    Pantalla_ImagenLibera(menunave2i);

    //libera el botón de objetivo y sus imagenes
    BotonLibera(nave1);
    Pantalla_ImagenLibera(nave1menu);
    Pantalla_ImagenLibera(nave1menu2);

    //libera el botón de objetivo y sus imagenes
    BotonLibera(menunaveboton);
    Pantalla_ImagenLibera(nave2menu);
    Pantalla_ImagenLibera(nave2menu2);

    //libera el botón de volver y sus imagenes
    BotonLibera(returnb);
    Pantalla_ImagenLibera(returni);
    Pantalla_ImagenLibera(returni2);




    //Leo e inicializo las imágenes del personaje que se cargarán según la nave elegida
    Imagen pi;
    Imagen pizqi;
    Imagen pderi;
    Imagen pmovi;

    switch(intnave)
    {
    case(1):
        pi = Pantalla_ImagenLee("p1.bmp",255);
        pmovi = Pantalla_ImagenLee("p1mov1.bmp",255);
        pderi = Pantalla_ImagenLee("p1d.bmp",255);
        pizqi = Pantalla_ImagenLee("p1i.bmp",255);
        break;
    case(2):
        pi = Pantalla_ImagenLee("p2.bmp",255);
        pmovi = Pantalla_ImagenLee("p2mov1.bmp",255);
        pderi = Pantalla_ImagenLee("p2d.bmp",255);
        pizqi = Pantalla_ImagenLee("p2i.bmp",255);
        break;
    default:
        pi = Pantalla_ImagenLee("p1.bmp",255);
        pmovi = Pantalla_ImagenLee("p1mov1.bmp",255);
        pderi = Pantalla_ImagenLee("p1d.bmp",255);
        pizqi = Pantalla_ImagenLee("p1i.bmp",255);
        break;
    };
    terminado = 0;
    int t0=time(NULL),tiempoActual=0,t2,record;
    char texto[100000];
    char texto2[1000], texto3[1000],texto4[1000],texto5[1000],texto6[1000];;
    int contadorDanoRecibido=0,tsprint=0,tsprint2=0; //contadores
    int hp=4,hpe=12; //vida y vida enemigo
    int recibirDano=1; //booleano que indica si puedes recibir daño
    int nmisiles=4; //número de misiles actual (empieza con 4)
    int pmov=0; //indica dirección de movimiento del personaje
    int sprintDisponibilidad=1,sprintActivo=0; //disponibilidad de sprint y si está activo
    int misilmax = 50; //número máximo de misiles
    int HabilidadX = 0,HabilidadY = 80,HabilidadW = 90,HabilidadH = 100,HabilidadW2=90;
    int rayoDisponible=1,tr2=0,tr,rayoActivado=0; //booleano de disponibilidad de rayo, contadores para el enfriamiento de la habilidad y booleano de si está activo o no
    int ejercitot=0; //entero que se utiliza para insertar de forma aleatoria enemigos
    int ResXP1 = 110; //w de P
    int ResYP1 = 110; //h de P
    int hit = 36; //entero que nos indica hace cuántos bucles que nos han atacado, (se pone a 0 cuando te atacan), si es menor que 35 el personaje parpadea
    Disparo d1=NULL; //Creación de una variable disparo vacía para luego utilizarla
    //creación del personaje con sus imágenes de movimiento
    Personaje p = PersonajeCrea(pi,pmovi, pizqi, pderi,rand()%(Pantalla_Anchura()-ResXP1),Pantalla_Altura()-ResYP1-rand()%Pantalla_Altura()/4,ResXP1,ResYP1); //el y sale de coger un numero entre 0 y pantalla_altura/4 y restarselo al total
    Galaxia g = GalaxiaCrea(4); //Creación de galaxia g con un número máximo de 4 estrellas
    Ejercito ej = EjercitoCrea(); //creación ejercito ej
    Rayo r = RayoCrea(rayo,p,0,0,0,15,904); //creación del rayo utilizado luego por el personaje

    while (Pantalla_Activa() && !terminado)
    {

        tiempoActual = time(NULL)-t0; //cojo el tiempo desde que se ha entrado a esta pantalla y lo guardo en un array
        sprintf (texto,"%d",tiempoActual);

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)||hp==0||hpe==1) //si pulsas el espacio o alguna de las vidas (enemigo o personaje) está a 0, acaba la partida, la de enemigo está a 1 porque no funcionan igual
            terminado=1;


        //DISPAROS

        //La primera comprueba si coges alguna estrella, y si lo haces, la elimina y te da 4 misiles, pero solo si no tienes el máximo (50) o más

        if (nmisiles<misilmax)
            nmisiles+=4*GalaxiaColision(g, PersonajeGetX(p),PersonajeGetY(p),PersonajeGetW(p),PersonajeGetW(p)); //cada colisión con estrellas nos da un misil

        //Inserta un nuevo estrella
        GalaxiaInserta(g,EstI,rand()%(Pantalla_Anchura()-55),rand()%(Pantalla_Altura()-55),55,40);

        //Si no existe el misil lo crea y resta 1 al número de misiles
        if ((Pantalla_TeclaPulsada(SDL_SCANCODE_E))&&(d1==NULL)&&nmisiles>0) //crear proyectil 1
        {
            d1 = DisparoCrea(imagend, PersonajeGetX(p)+(PersonajeGetW(p)/2)-(25/2),PersonajeGetY(p),25,25,0,-100);
            nmisiles-=1;
        }



        //si existe el disparo, comprueba que de a un enemigo, y si lo hace, le quita 1 de vida
        if (d1!=NULL)
        {
            if (EjercitoColision(ej,DisparoGetX(d1),DisparoGetY(d1),DisparoGetW(d1),DisparoGetH(d1)))
                hpe-=1;
        };

        //Si existe el disparo, lo mueve
        if (d1!=NULL)
            DisparoMueve(d1);

        //Si existe el disparo y llega al borde de la pantalla, lo libera
        if ((d1!=NULL)&&(DisparoGetY(d1)<0))
        {
            DisparoLibera(d1);
            d1 = NULL;
        }



        //RAYO
        //Si no está activo y está disponible, se presiona, se pone activo y se coge el tiempo
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_T)&&!rayoActivado&&rayoDisponible)
        {
            rayoActivado=1;
            tr=tiempoActual;
        };

        //Después de estar activo y pasar dos segundos, se pone inactivo y se pone disponibilidad a 0, se coge tiempo otra vez
        if(rayoActivado&&(tr+1<tiempoActual))
        {
            rayoActivado=0;
            rayoDisponible=0;
            tr2=tiempoActual;
        };

        //Al pasar 3 segundos desde que se coge el tiempo por última vez, se pone disponible
        if(tr2+3<tiempoActual)
            rayoDisponible=1;


        //Si das a un enemigo con el rayo pierde vida el enemigo y procede a eliminar ese enemigo
        if (rayoActivado&&EjercitoColisionRayo(ej,r))
            hpe-=1;



        //EJERCITO
        //Cojo un número aleatorio, y cuando sea divisor de 35, inserto un enemigo nuevo
        ejercitot=rand();
        if (ejercitot%35==0)
        {
            // Para la velocidad vx cojonumero entre 0 y 10 + 10 para que esté entre 10 y 20
            EjercitoInserta(ej,eImagen,eImagenFrame1,eImagenFrame2,eImagenFrame3,eImagenFrame4,eImagenFrame5,eImagenFrame6,eImagenFrame7,eImagenFrame8,eImagenFrame9,eImagenFrame10,eImagenFrame11,rand()%(Pantalla_Anchura()-70),0,70,70,(rand()%10)+10,(rand()%10)+10);
        };

        //Si colisiona el personaje con ejercito pierdes 1 de vida pero solo 1 vez por segundo
        if (EjercitoColision(ej, PersonajeGetX(p),PersonajeGetY(p),PersonajeGetW(p),PersonajeGetH(p)))
        {
            if (recibirDano) //Si la variable que indica si puedes recibir daño está a 1, se resta vida, se coge el tiempo y se pone a 0 la variable
            {
                hp=hp-1;
                recibirDano=0;
                contadorDanoRecibido=tiempoActual;
                hit = 0;
            }

        }
        if (tiempoActual>contadorDanoRecibido+1)
            recibirDano=1; //Cuando pasa un segundo desde que se coge el tiempo, se pone la variable a 1 para poder volver a recibir daño

        hit++;



        //BLOQUE PERSONAJE
        //Disponibilidad del sprint del personaje
        if (!sprintActivo&&sprintDisponibilidad&&(Pantalla_TeclaPulsada(SDL_SCANCODE_LSHIFT))) //Si usas el sprint, se pone a cero la variable que indica disponibilidad de sprint y cojo el tiempo
        {
            sprintActivo=1;
            //sprintDisponibilidad=0;
            tsprint=tiempoActual;
        };
        if ((sprintActivo)&&(tsprint+2<tiempoActual)) //Cuando pasan tres segundos desde que se ha cogido el tiempo, se pone la disponibilidad a 0 y se vuelve a coger tiempo.
        {
            sprintActivo=0;
            sprintDisponibilidad=0;
            tsprint2=tiempoActual;
        };
        if ((!sprintActivo)&&(!sprintDisponibilidad)&&(tsprint2+3<tiempoActual)) //Cuando pasen 3 segundos desde que se ha cogido el tiempo, se pone disponibilidad a 1
        {
            sprintDisponibilidad=1;
        };

        //Mueve el personaje según tenga la habilidad sprint activada o no
        PersonajeMov(p,sprintActivo);

        //Cambia la variable que indica en qué direccion se mueve el personaje
        if(((Pantalla_TeclaPulsada(SDL_SCANCODE_W))||(Pantalla_TeclaPulsada(SDL_SCANCODE_S))))
            pmov=1;
        else
            pmov=0;
        if(((Pantalla_TeclaPulsada(SDL_SCANCODE_A))))
            pmov=2;
        if(((Pantalla_TeclaPulsada(SDL_SCANCODE_D))))
            pmov=3;

        //Dibujamos el fondo, luego el texto, luego las vidas de personaje y enemigos
        //Luego dibujamos la galaxia (estrellas), el ejercito(de enemigos), el personaje, el disparo, y el rayo
        Pantalla_DibujaImagen(fondojuego,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(224,255,255,255);
        Pantalla_DibujaTexto("Presiona Espacio para rendirte",Pantalla_Anchura()/2.5,Pantalla_Altura()-20);
        EjercitoDibujaVida(hpe,hpi2);

        PersonajeDibujaVida(hp,hpi);
        GalaxiaDibuja(g);
        EjercitoDibuja(ej);
        EjercitoMueve(ej);

        //Si el valor es menor que 35 y par o divisor entre 3 par, o bien si es mayor que 35.
        //Cuando se toma daño, se pone a 0 y, cada 2 frames, no se dibuja uno hasta que llegue a 35
        //Da sensación de parpadeo
        if ((hit>35)||((hit<35)&&((hit%2==0)||(hit%3==0))))
            PersonajeDibuja(p,pmov);

        if (nombre!=NULL) //Si el nombre no es NULL (puede serlo, ya que no es obligatorio) se dibuja debajo del personaje
            Pantalla_DibujaTexto(nombre, PersonajeGetX(p)+(PersonajeGetW(p)/2-4.5*strlen(nombre)), PersonajeGetY(p)+PersonajeGetH(p)); //La y se desplaza desde la mitad para la izquierda según como de largo sea el nombre para que esté centrado


        if (d1!=NULL)
            DisparoDibuja(d1);

        if (rayoActivado)
        {
            RayoDibuja(r);
        };

        //Dibujamos el cuadrado que indica la disponibilidad del sprint
        if(sprintActivo) //Si está activo se dibuja el cuadro cyan y se va restando anchura
        {
            HabilidadW-=1.0005;
            Pantalla_DibujaImagen(cyan,HabilidadX,HabilidadY,HabilidadW,HabilidadH);
        };
        if (!sprintDisponibilidad) //Si no está disponible se pone anchura estática al cuadro cyan
            HabilidadW=90;
        if (sprintActivo) //Si está activo se pone anchura estática al cuadro gris
            HabilidadW2=90;
        if (!sprintActivo) //Si no está activo se dibuja el cuadro gris y se resta anchura
        {
            Pantalla_DibujaImagen(cuadrado,HabilidadX,HabilidadY,HabilidadW2,HabilidadH);
            HabilidadW2-=1;
        };
        if (sprintDisponibilidad)
            Pantalla_DibujaImagen(cyan,HabilidadX,HabilidadY,HabilidadW,HabilidadH);
        Pantalla_DibujaImagen(fuego,HabilidadX+15,HabilidadY,60,90);

        //Dibujamos el cuadro en el que pondremos el número de misiles
        Pantalla_DibujaImagen(misiles,0,Pantalla_Altura()-78,168,94);
        //Escribimos el número de misiles
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,nmisiles,95,Pantalla_Altura()-70,50,70);
        //Escribimos el tiempo que llevamos en la pantalla con imagenes de los números gracias a la función NumAText
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,tiempoActual,Pantalla_Anchura()-130,Pantalla_Altura()-130,100,100);

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    //cojo un segundo tiempo para compararlo con el de antes del bucle
    t2=time(NULL);

    //Libero la imagen de fondo
    Pantalla_ImagenLibera(fondojuego);

    //Libero el personaje y sus imágenes asociadas
    Pantalla_ImagenLibera(pmovi);
    Pantalla_ImagenLibera(pizqi);
    Pantalla_ImagenLibera(pderi);
    Pantalla_ImagenLibera(pi);
    PersonajeLibera(p);

    //Libero la galaxia y el ejercito con sus imágenes asociadas (enemigo)
    GalaxiaLibera(g);
    Pantalla_ImagenLibera(EstI);

    EjercitoLibera(ej);
    Pantalla_ImagenLibera(eImagen);
    Pantalla_ImagenLibera(eImagenFrame1);
    Pantalla_ImagenLibera(eImagenFrame2);
    Pantalla_ImagenLibera(eImagenFrame3);
    Pantalla_ImagenLibera(eImagenFrame4);
    Pantalla_ImagenLibera(eImagenFrame5);
    Pantalla_ImagenLibera(eImagenFrame6);
    Pantalla_ImagenLibera(eImagenFrame7);
    Pantalla_ImagenLibera(eImagenFrame8);
    Pantalla_ImagenLibera(eImagenFrame9);
    Pantalla_ImagenLibera(eImagenFrame10);
    Pantalla_ImagenLibera(eImagenFrame11);

    //Liberamos la interfaz de usuario, o sea, el cuadrado que nos da la disponibilidad del sprint y sus elemntos, así como el cuadro del número de misiles y las barras de vida
    Pantalla_ImagenLibera(cuadrado);
    Pantalla_ImagenLibera(cyan);
    Pantalla_ImagenLibera(fuego);
    Pantalla_ImagenLibera(misiles);
    Pantalla_ImagenLibera(hpi);
    Pantalla_ImagenLibera(hpi2);

    //Liberamos el rayo y los disparos, así como sus imágenes
    RayoLibera(r);
    Pantalla_ImagenLibera(rayo);
    if (d1!=NULL)
        DisparoLibera(d1);
    Pantalla_ImagenLibera(imagend);

    //terminado a 0
    //Apuntador a tipo f que abre el archivo para lectura, se hace un fscan y se guarda número en record
    //se cierra el archivo y se compara con el record almacenado en el disco duro. Si es mayor se sobreescribe
    terminado=0;
    FILE * f = fopen("resultado.txt","r");
    fscanf(f,"%d",&record);
    fclose(f);
    if (t2-t0>record)
    {
        f = fopen("resultado.txt","w");
        fprintf(f,"%d",t2-t0);
        fclose(f);
    }

    //pasamos al array texto el tiempo que hemos estado en la anterior panatalla
    sprintf (texto,"%d",t2-t0);
    int nRecord=5; //5 records

    //records
    int rr[nRecord];

    //hacemos un bucle que vaya recibiendo los números y los guarde en posiciones de un array
    f = fopen("record.txt","r");
    for(int i=0; i<nRecord; i++)
        fscanf(f,"%d\n",&rr[i]);
    fclose(f);

    int i=nRecord;

    //bucle que busca un valor en el array menor que nuestro record para sustituirlo y desplazar hacia abajo el resto
    while((i>0)&&(tiempoActual>rr[i-1])) //mientras sea mayor que el anterior (empezamos en el último y vamos subiendo por los records hasta que no sea mayor)
    {
        if (i<nRecord) //si es mayor que el número de records es porque hay alguno menor que el resultado actual
        {
            rr[i] = rr[i-1]; //se guarda el resultado hacia abajo, desplazando todos los números de los records
        }
        i--;
    }
    if ((t2-t0>1)&&(i<nRecord)) //reemplaza en el archivo record si encuentra uno menor y si el tiempo es mayor de 1 para evitar errores si no se llega a la parte del juego
    {
        rr[i] = tiempoActual;
        FILE * f = fopen("record.txt","w");
        for(int i=0; i<nRecord; i++) //bucle que va guardando en el archivo txt los records nuevos
            fprintf(f,"%d\n",rr[i]);
        fclose(f);
    }

    //según si se ha acabado por quedarse sin vida el personaje o el enemigo, se carga una imagen final diferente en la variable fondofinal
    if (hpe<1)
        fondofinal = Pantalla_ImagenLee("win.bmp",0);
    else
        fondofinal=Pantalla_ImagenLee("lose.bmp",0);

    //TERCERA PANTALLA
    while (Pantalla_Activa() && !terminado)
    {
        //Si presionas escape se finaliza la pantalla
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))
            terminado=1;
        Pantalla_DibujaImagen(fondofinal,0,0,Pantalla_Anchura(),Pantalla_Altura());


        //Dibujamos el tiempo de la segunda pantalla (tiempo final - tiempo inicial
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,(t2-t0),Pantalla_Anchura()/28,5*Pantalla_Altura()/6,Pantalla_Anchura()/16,Pantalla_Altura()/7-7);


        //Se pasan los números de los records guardados
        sprintf(texto2,"%d\n",rr[0]);
        sprintf(texto3,"%d\n",rr[1]);
        sprintf(texto4,"%d\n",rr[2]);
        sprintf(texto5,"%d\n",rr[3]);
        sprintf(texto6,"%d\n",rr[4]);
        //están guardados en arrays, así que se guardan como enteros para poder ejecutar la función NumAText (hecha a mano por mí) que recibe enteros
        int texto2int = atoi(texto2);
        int texto3int = atoi(texto3);
        int texto4int = atoi(texto4);
        int texto5int = atoi(texto5);
        int texto6int = atoi(texto6);
        //Dibujamos los records, desplazandolos hacia abajo lo suficiente como para que estén separados
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,texto2int,Pantalla_Anchura()/1.35,Pantalla_Altura()/1.9+0*(Pantalla_Altura()/12),Pantalla_Anchura()/16,Pantalla_Altura()/13);
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,texto3int,Pantalla_Anchura()/1.35,Pantalla_Altura()/1.9+1*(Pantalla_Altura()/12),Pantalla_Anchura()/16,Pantalla_Altura()/13);
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,texto4int,Pantalla_Anchura()/1.35,Pantalla_Altura()/1.9+2*(Pantalla_Altura()/12),Pantalla_Anchura()/16,Pantalla_Altura()/13);
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,texto5int,Pantalla_Anchura()/1.35,Pantalla_Altura()/1.9+3*(Pantalla_Altura()/12),Pantalla_Anchura()/16,Pantalla_Altura()/13);
        NumAText(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,texto6int,Pantalla_Anchura()/1.35,Pantalla_Altura()/1.9+4*(Pantalla_Altura()/12),Pantalla_Anchura()/16,Pantalla_Altura()/13);



        Pantalla_Actualiza();
        Pantalla_Espera(40);

    }

    //Libero tanto la imagen de fondo como los números
    Pantalla_ImagenLibera(fondofinal);
    Pantalla_ImagenLibera(i0);
    Pantalla_ImagenLibera(i1);
    Pantalla_ImagenLibera(i2);
    Pantalla_ImagenLibera(i3);
    Pantalla_ImagenLibera(i4);
    Pantalla_ImagenLibera(i5);
    Pantalla_ImagenLibera(i6);
    Pantalla_ImagenLibera(i7);
    Pantalla_ImagenLibera(i8);
    Pantalla_ImagenLibera(i9);
    //Libero la pantalla creada para el juego
    Pantalla_Libera();
    return 0;
};
