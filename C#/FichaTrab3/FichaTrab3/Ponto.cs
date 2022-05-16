/*
* Autor: Daniel Pereira
* Data: 21/02/2022
*/
namespace FichaTrab3 {
    class Ponto
    {
        private double x;
        private double y;

        // Para ser possivel ver o X e Y fora da class
        public double X {
            get { return x; }
            set { x = value; }
        }

        public double Y {
            get { return y; }
            set { y = value; }
        }

        public Ponto(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
        public void Imprimir()
        {
            Console.WriteLine("(" + x + "," + y + ")");
        }

        public double Distancia(Ponto p)
        {
            //A distância entre dois pontos é dada pela fórmula:
            //d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
            return Math.Sqrt(Math.Pow(x - p.x, 2) + Math.Pow(y - p.y, 2));
        }
    
    }
}