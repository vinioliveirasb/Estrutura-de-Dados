//gerar duas listas de números aleatórios com o mesmo sistema da primeira, e depois criar uma terceira lista com os números comuns entre as duas primeiras listas.


using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Defina o tamanho da lista N
        int N;
        Console.Write("Digite o tamanho das listas (N): ");
        N = int.Parse(Console.ReadLine());

        // Listas para armazenar os números aleatórios
        List<int> lista1 = GerarListaUnica(N);
        List<int> lista2 = GerarListaUnica(N);

        // Lista para armazenar os números em comum
        List<int> listaComum = new List<int>();

        // Encontrar os números comuns entre lista1 e lista2
        foreach (var numero in lista1)
        {
            if (lista2.Contains(numero))
            {
                listaComum.Add(numero);
            }
        }

        // Exibe as listas
        Console.WriteLine("Lista 1:");
        foreach (var numero in lista1)
        {
            Console.WriteLine(numero);
        }

        Console.WriteLine("\nLista 2:");
        foreach (var numero in lista2)
        {
            Console.WriteLine(numero);
        }

        Console.WriteLine("\nLista com números comuns:");
        foreach (var numero in listaComum)
        {
            Console.WriteLine(numero);
        }
    }

    // Função para gerar uma lista de números únicos
    static List<int> GerarListaUnica(int N)
    {
        List<int> lista = new List<int>();
        Random random = new Random();

        while (lista.Count < N)
        {
            int numeroAleatorio = random.Next(0, 101); // Gera número entre 0 e 100
            if (!lista.Contains(numeroAleatorio)) // Verifica se já existe na lista
            {
                lista.Add(numeroAleatorio); // Adiciona à lista se não houver repetição
            }
        }

        return lista;
    }
}
