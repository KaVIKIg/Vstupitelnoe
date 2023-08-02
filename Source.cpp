#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

//функции
void menu();
void task_1();
void task_2();
void task_3();
std::vector<bool> sieve(int n);
bool isPrime(int n);
void merge(int* list, int start, int end, int mid);
void mergeSort(int* list, int start, int end);


int main()
{
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");
    menu();

    return 0;
}

void menu()
{
    std::string num;

    std::cout << " Введите номер пункта.\n";
    std::cout << "-------------------------------------------------------------\n";
    std::cout << " 1) Задание 1. Сумма всех простых чисел не превышающих X.\n";
    std::cout << " 2) Задание 2. ПО для вендингового аппарата.\n";
    std::cout << " 3) Задание 3. Заказы на линзы.\n";
    std::cout << " 4) Выход.\n";
    std::cout << "--------------------------------------------------------------\n";

    while (true)
    {
        std::cin >> num;
        if ((num.find_first_not_of("0123456789") == std::string::npos))
            break;
        std::cout << " Введите число.\n";
    }

     system("cls");

    switch (stoi(num))
    {
    case 1:
        task_1();
        menu();
        break;
    case 2:
        task_2();
        menu();
        break;
    case 3:
        task_3();
        menu();
        break;
    case 4:
        std::cout << "Выход";
        exit;
        break;
    default:
        std::cout << "Неверный ввод!";
        menu();
        break;
    }

}


void task_1()
{
    std::cout << "Задание 1. Сумма всех простых чисел не превышающих X.\n";

    std::string x;

    while (true)
    {
        std::cout << "Введите целое число:\n";
        std::cin >> x;
        if ((x.find_first_not_of("0123456789") == std::string::npos)) // проверка на корректный ввод
            break;

    }

    int X = stoi(x);
    int sum = 0;

    for (int i = 2; i <= X; i++)
    {
        if (isPrime(i)) // если число простое, суммируем
        {
            sum += + i;
            std::cout << i << " ";
        }

    }

    std::cout << "\nСумма всех простых чисел, не превышающих " << X << ": " << sum << std::endl;
    std::cout << "---------------------------------------------------------------\n\n";

}

std::vector<bool> sieve(int n) // алгоритм  - Решето Эратосфена:
{
    std::vector<bool> primes(n + 1, true); //изначально говорим, что все числа простые - true
    primes[0] = primes[1] = false; //обновляем значения для 0 и 1, кто они не являются простыми числами

    for (int i = 2; i * i <= n; i++) //определяем явлется ли число составным
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false; // если число составное - false
            }
        }
    }

    return primes;
}

bool isPrime(int n)
{
    // Получаем все простые числа до n
    std::vector<bool> primes = sieve(n);
    // Возвращаем значение по индексу n
    return primes[n];
}

void task_2()
{
    std::cout << "Задание 2. ПО для вендингового аппарата.\n";
    std::string sum_z, sum_c;

    while (true)
    {
        std::cout << "Введите сумму заказа и сумму, внесенную клиентом:\n";
        std::cin >> sum_z >> sum_c;
        if ((sum_z.find_first_not_of("0123456789") == std::string::npos) && //проверка на корректный ввод
            (sum_c.find_first_not_of("0123456789") == std::string::npos)
            && (stoi(sum_z) <= stoi(sum_c))) // проверка на то, что сумма, внесеенная клиентом, >= сумы заказа
            break;
    }

    int z = stoi(sum_z), c = stoi(sum_c);
    std::vector<int> denominations = { 5000, 2000, 1000, 500, 200, 100, 50, 10, 5, 2, 1 };
    std::vector<int> result(denominations.size(), 0);
    int amount = c - z;
    
    if (amount == 0)
    {
        std::cout << "Без сдачи.\n";
    }
    else
    {
        for (int i = 0; i < denominations.size(); i++) 
        {
            if (amount >= denominations[i]) // если сумма больше купюры/монеты
            {
                result[i] = amount / denominations[i]; //рассчитываем кол-во купюр, дальше работаем с остатком
                amount = amount % denominations[i];
            }
        }

        std::cout << "Количество купюр и монет каждого номинала:\n";
        for (int i = 0; i < result.size(); i++) 
        {
            if (result[i] > 0) 
            {
                std::cout << result[i] << " x " << denominations[i] << std::endl;
            }
        }
    }

    std::cout << "---------------------------------------------------------------\n\n";

}


void task_3()
{
    std::cout << "Задание 3. Заказы на линзы.\n";
    std::string n;

    while (true)
    {
        std::cout << "Введите количество циклопов:\n";
        std::cin >> n;
        if (n.find_first_not_of("0123456789") == std::string::npos) //проверка ввода
            break;
    }

    int N = stoi(n);
    std::string* arr = new std::string[N]; //входной массив 
    int* arr_ = new int[N];
 
    std::cout << "Введите элементы массива: \n";
    for (int i = 0; i < N; i++)
    {
        while (true)
        {
            std::cin >> arr[i];

            if ((arr[i].find_first_not_of("-0123456789") == std::string::npos) && (arr[i].find("--") != 0))//проверка ввода
                break;
            std::cout << "Вводите числа: \n";

        }

    }

    for (int i = 0; i < N; i++)
    {
        arr_[i] = stoi(arr[i]);
    }

    mergeSort(arr_, 0, N - 1); // сортируем массив сортировкой слиянием

    int count = 0, i = 0;

    while (i < N) 
    {
        if (i == N - 1) // если осталось одно значение, добавляем +1 к кол-ву очков
        {
            count++;
            break;
        }

        if (arr_[i + 1] - arr_[i] <= 2) // проверяем удволетворяют ли условию соседние, 
            //если условие выполняется, для соседних берем 1 очки
            i += 2; 
        else
            i += 1;

        count++;
    }


    std::cout << "Минимальное количество пар линз: " << count << std::endl;
    std::cout << "---------------------------------------------------------------\n\n";

    delete[] arr;
    delete[] arr_;
}

void mergeSort(int* list, int start, int end) //сортировка слиянием
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(list, start, mid);
        mergeSort(list, mid + 1, end);
        merge(list, start, end, mid);
    }
}

void merge(int* list, int start, int end, int mid) 
{

    int* mergedList = new int[end + 1];
    int i, j, k;
    i = start;
    k = start;
    j = mid + 1;

    while (i <= mid && j <= end) 
    {
        if (list[i] < list[j]) 
        {
            mergedList[k] = list[i];
            k++;
            i++;
        }
        else 
        {
            mergedList[k] = list[j];
            k++;
            j++;
        }
    }

    while (i <= mid) 
    {
        mergedList[k] = list[i];
        k++;
        i++;
    }

    while (j <= end) 
    {
        mergedList[k] = list[j];
        k++;
        j++;
    }

    for (i = start; i < k; i++) 
    {
        list[i] = mergedList[i];
    }

}

