using System;

namespace FichaTrab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Ponto p1 = new Ponto(3, 2);
            Ponto p2 = new Ponto(4, 2);
            Console.WriteLine(p1.x);
            p1.Imprimir();
            p2.Imprimir();

            Console.WriteLine("Distância entre os pontos: " + p1.Distancia(p2));
        }
    }


}
