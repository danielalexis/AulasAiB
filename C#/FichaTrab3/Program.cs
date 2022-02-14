using System;

namespace FichaTrab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }

    class Ponto
    {
        public int x;
        public int y;

        public Ponto(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public void Imprimir()
        {
            Console.WriteLine("(" + x + "," + y + ")");
        }
    }
}
