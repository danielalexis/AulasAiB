namespace FichaTrab3 {
    class Ponto
    {
        public double x;
        public double y;
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

    class Poligono {
        public Ponto[] pontos;
        public Poligono(Ponto[] pontos)
        {
            this.pontos = pontos;
        }
        public void Imprimir()
        {
            for (int i = 0; i < pontos.Length; i++)
            {
                pontos[i].Imprimir();
            }
        }
        public double Perimetro()
        {
            double perimetro = 0;
            for (int i = 0; i < pontos.Length; i++)
            {
                perimetro += pontos[i].Distancia(pontos[(i + 1) % pontos.Length]);
            }
            return perimetro;
        }
        public double Area()
        {
            double area = 0;
            for (int i = 0; i < pontos.Length; i++)
            {
                area += (pontos[i].x * pontos[(i + 1) % pontos.Length].y) - (pontos[i].y * pontos[(i + 1) % pontos.Length].x);
            }
            return area / 2;
        }
    }

}