// exercicio para listar nomes//
List<string> listaNomes = new List<string>();
string opcao;
string nome;

do
{
    Console.WriteLine("Digite seu nome completo: ");
    nome = Console.ReadLine();
    nome = nome.ToUpper(); // Garantir que o nome seja maiúsculo

    // Verificar se o nome já existe na lista
    if (listaNomes.Contains(nome))
    {
        Console.WriteLine("Nome já cadastrado!"); // Exibir mensagem de erro
    }
    else
    {
        listaNomes.Add(nome); // Adicionar nome à lista
    }

    Console.Write("1 - Continua; 2 - Finaliza: ");
    opcao = Console.ReadLine();
} while (opcao != "2");

listaNomes.Sort(); // Ordenar a lista

Console.WriteLine("A lista contém " + listaNomes.Count + " nomes:");
foreach (var i in listaNomes)
{
    Console.WriteLine(i); // Exibir todos os nomes cadastrados
}
