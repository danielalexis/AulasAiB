/*
* Autor: Daniel Pereira
* Data: 21/02/2022
*/
namespace FichaTrab3 {    
    class Triangulo {
        private Ponto p1;
        private Ponto p2;
        private Ponto p3;

        public Triangulo(Ponto p1, Ponto p2, Ponto p3)
        {
            this.p1 = p1;
            this.p2 = p2;
            this.p3 = p3;
        }

        public void Imprimir() {
            Console.WriteLine("(" + p1.X + "," + p1.Y + ")");
            Console.WriteLine("(" + p2.X + "," + p2.Y + ")");
            Console.WriteLine("(" + p3.X + "," + p3.Y + ")");
        }

        public double Perimetro() {
            // A area do triangulo é dada pela distância entre os 3 pontos
            return p1.Distancia(p2) + p2.Distancia(p3) + p3.Distancia(p1);
        }

        public double Area() {
            // Formula de Heron
            double area = 0;
            area = (p1.X * p2.Y) - (p1.Y * p2.X) + (p2.X * p3.Y) - (p2.Y * p3.X) + (p3.X * p1.Y) - (p3.Y * p1.X);
            return area / 2;
        }
    }
}