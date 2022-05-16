using System;

namespace FichaTrab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Ponto p1 = new Ponto(0, 0);
            Ponto p2 = new Ponto(1, 0);
            Ponto p3 = new Ponto(1, 1);
            Ponto p4 = new Ponto(0, 1);

            Console.WriteLine("------------------------");
            Console.WriteLine("Poligono (neste exemplo um retangulo)");
            Poligono poligono = new Poligono(new Ponto[] { p1, p2, p3, p4 });
            poligono.Imprimir();
            Console.WriteLine("Perimetro: " + poligono.Perimetro());
            Console.WriteLine("Area: " + poligono.Area());

            Console.WriteLine("------------------------");
            Console.WriteLine("Triangulo");
            Triangulo triangulo = new Triangulo(p1, p2, p3);
            Console.WriteLine("Perimetro: " + triangulo.Perimetro());
            Console.WriteLine("Area: " + triangulo.Area());
        }
    }


}
