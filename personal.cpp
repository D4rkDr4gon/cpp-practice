#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nombre;
    string password;
    int a;

    cout << "bienvenida al regalo a mamor!!!!!" << endl
         << "preparate para un increible regalo echo por tu servidor(lucci)" << endl;
    cout << "nombre de mamor? ";
    cin >> nombre;
    cout << "password? (<3) ";
    cin >> password;

    while (true)
    {

        if (nombre == "agus" && password == "<3")
        {
            cout << "bienvenida amor de mi vida, que queres hacer?" << endl
                 << "1 = poema para mamor" << endl
                 << "2 = mensaje a mamor" << endl
                 << "3 = salir" << endl;
            cin >> a;

            switch (a)
            {
            case 1:
                cout << "Te amo como se aman ciertas cosas oscuras, secretamente, entre la sombra y el alma." << endl
                     << "Yo te quiero como el mar quiere al río, como la noche quiere al día, como el sol a la luna, como la luz al día" << endl
                     << "Porque cada día te quiero más, hoy más que ayer y menos que mañana" << endl
                     << "Por ti aprendí a amar la lluvia, los días grises, el frío en la piel, la tibieza del sol en la tarde, y el sabor del amor verdadero" << endl
                     << "Si te digo que te amo es porque realmente te amo, si te digo que te quiero es porque no puedo vivir sin ti" << endl
                     << "Tu risa me hace libre, me pone alas. Soledades me quita, cárcel me arranca" << endl
                     << "Eres mi complemento perfecto, mi media naranja, mi otra mitad, eres la persona que siempre he buscado, el amor que siempre he anhelado." << endl
                     << "Te amo como se aman las almas gemelas, como se aman los amantes verdaderos, con pasión, con entrega, con todo el corazón." << endl
                     << "Amarte es como vivir en un sueño, donde todo es posible y nada es imposible, donde el amor lo llena todo, y la felicidad es eterna." << endl;

                break;
            case 2:
                cout << "para este regalo queria poner mis habiliadades en codigo para crear un regalo q fuera perfecto para vos, tome todo lo q se y cree este sistemita. puede q no sea mucho pero lo hice con todo mi esfuerzo y dedicacion, se q hay dias y dias, se q hay miedos, dudas, problemas, verguenza, se q hay todo tipo de cosas q nublan tu sonrisa, q lastiman tu corazon y q te causan ansiedad vreeme q lo se xq te conozco completamente y se q esas cosas estan. con este archivo espero sacarte una sonrisa q a mis ojos siempre es mas brillante q el mismo sol. te amo con todo mi ser mi amor. pero no es un te amo cualquiera, un amarte es algo grande y amplio, abarca desde cosas mundanas como el dia a dia en el q solo pienso en vos, tu cuerpo¿, tu forma de ser, tu terquedad, incluso nuestros problemas, nuestras risas, hasta lo mas intimo, el futuro, los planes, la vida misma. y desde el dia en q te conoci adquiri esos sentimientos x vos y hoy a modo de carte electronica te los vengo a compartir y decirte q vos sos y siempre seras mi unico amor." << endl
                     << "gracias x todo lo q haces y me das, mejoras mi vida en todos los aspectos. tmb te pido perdon x a veces ser causante de disgustos o problemas. quiero ser tu compañero en esta y en todas mis vidas. te voy a amar siempre" << endl;

                break;
            }

            if (a == 3)
            {
                cout << "gracias mamor, te amo!!!!!" << endl;
                break;
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}