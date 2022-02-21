namespace FichaTrab3 {
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
                area += (pontos[i].X * pontos[(i + 1) % pontos.Length].Y) - (pontos[i].Y * pontos[(i + 1) % pontos.Length].X);
            }
            return area / 2;
        }
    }
}