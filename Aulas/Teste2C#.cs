//Criar uma Lista com N Numeros Aleatorios ( DE 0 A 100) tamanho N  e sem repetição 



using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Defina o tamanho da lista N
        int N;
        Console.Write("Digite o tamanho da lista (N): ");
        N = int.Parse(Console.ReadLine());

        // Lista para armazenar os números aleatórios
        List<int> listaNumeros = new List<int>();
        Random random = new Random();

        // Gerar números aleatórios sem repetição
        while (listaNumeros.Count < N)
        {
            int numeroAleatorio = random.Next(0, 101); // Gera um número entre 0 e 100

            // Verifica se o número já está na lista
            if (!listaNumeros.Contains(numeroAleatorio))
            {
                listaNumeros.Add(numeroAleatorio); // Adiciona à lista se não houver repetição
            }
        }

        // Exibe a lista gerada
        Console.WriteLine($"Lista com {N} números aleatórios (sem repetição):");
        foreach (var numero in listaNumeros)
        {
            Console.WriteLine(numero);
        }
    }
}
