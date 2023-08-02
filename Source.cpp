#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

//�������
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

    std::cout << " ������� ����� ������.\n";
    std::cout << "-------------------------------------------------------------\n";
    std::cout << " 1) ������� 1. ����� ���� ������� ����� �� ����������� X.\n";
    std::cout << " 2) ������� 2. �� ��� ������������ ��������.\n";
    std::cout << " 3) ������� 3. ������ �� �����.\n";
    std::cout << " 4) �����.\n";
    std::cout << "--------------------------------------------------------------\n";

    while (true)
    {
        std::cin >> num;
        if ((num.find_first_not_of("0123456789") == std::string::npos))
            break;
        std::cout << " ������� �����.\n";
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
        std::cout << "�����";
        exit;
        break;
    default:
        std::cout << "�������� ����!";
        menu();
        break;
    }

}


void task_1()
{
    std::cout << "������� 1. ����� ���� ������� ����� �� ����������� X.\n";

    std::string x;

    while (true)
    {
        std::cout << "������� ����� �����:\n";
        std::cin >> x;
        if ((x.find_first_not_of("0123456789") == std::string::npos)) // �������� �� ���������� ����
            break;

    }

    int X = stoi(x);
    int sum = 0;

    for (int i = 2; i <= X; i++)
    {
        if (isPrime(i)) // ���� ����� �������, ���������
        {
            sum += + i;
            std::cout << i << " ";
        }

    }

    std::cout << "\n����� ���� ������� �����, �� ����������� " << X << ": " << sum << std::endl;
    std::cout << "---------------------------------------------------------------\n\n";

}

std::vector<bool> sieve(int n) // ��������  - ������ ����������:
{
    std::vector<bool> primes(n + 1, true); //���������� �������, ��� ��� ����� ������� - true
    primes[0] = primes[1] = false; //��������� �������� ��� 0 � 1, ��� ��� �� �������� �������� �������

    for (int i = 2; i * i <= n; i++) //���������� ������� �� ����� ���������
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false; // ���� ����� ��������� - false
            }
        }
    }

    return primes;
}

bool isPrime(int n)
{
    // �������� ��� ������� ����� �� n
    std::vector<bool> primes = sieve(n);
    // ���������� �������� �� ������� n
    return primes[n];
}

void task_2()
{
    std::cout << "������� 2. �� ��� ������������ ��������.\n";
    std::string sum_z, sum_c;

    while (true)
    {
        std::cout << "������� ����� ������ � �����, ��������� ��������:\n";
        std::cin >> sum_z >> sum_c;
        if ((sum_z.find_first_not_of("0123456789") == std::string::npos) && //�������� �� ���������� ����
            (sum_c.find_first_not_of("0123456789") == std::string::npos)
            && (stoi(sum_z) <= stoi(sum_c))) // �������� �� ��, ��� �����, ���������� ��������, >= ���� ������
            break;
    }

    int z = stoi(sum_z), c = stoi(sum_c);
    std::vector<int> denominations = { 5000, 2000, 1000, 500, 200, 100, 50, 10, 5, 2, 1 };
    std::vector<int> result(denominations.size(), 0);
    int amount = c - z;
    
    if (amount == 0)
    {
        std::cout << "��� �����.\n";
    }
    else
    {
        for (int i = 0; i < denominations.size(); i++) 
        {
            if (amount >= denominations[i]) // ���� ����� ������ ������/������
            {
                result[i] = amount / denominations[i]; //������������ ���-�� �����, ������ �������� � ��������
                amount = amount % denominations[i];
            }
        }

        std::cout << "���������� ����� � ����� ������� ��������:\n";
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
    std::cout << "������� 3. ������ �� �����.\n";
    std::string n;

    while (true)
    {
        std::cout << "������� ���������� ��������:\n";
        std::cin >> n;
        if (n.find_first_not_of("0123456789") == std::string::npos) //�������� �����
            break;
    }

    int N = stoi(n);
    std::string* arr = new std::string[N]; //������� ������ 
    int* arr_ = new int[N];
 
    std::cout << "������� �������� �������: \n";
    for (int i = 0; i < N; i++)
    {
        while (true)
        {
            std::cin >> arr[i];

            if ((arr[i].find_first_not_of("-0123456789") == std::string::npos) && (arr[i].find("--") != 0))//�������� �����
                break;
            std::cout << "������� �����: \n";

        }

    }

    for (int i = 0; i < N; i++)
    {
        arr_[i] = stoi(arr[i]);
    }

    mergeSort(arr_, 0, N - 1); // ��������� ������ ����������� ��������

    int count = 0, i = 0;

    while (i < N) 
    {
        if (i == N - 1) // ���� �������� ���� ��������, ��������� +1 � ���-�� �����
        {
            count++;
            break;
        }

        if (arr_[i + 1] - arr_[i] <= 2) // ��������� ������������� �� ������� ��������, 
            //���� ������� �����������, ��� �������� ����� 1 ����
            i += 2; 
        else
            i += 1;

        count++;
    }


    std::cout << "����������� ���������� ��� ����: " << count << std::endl;
    std::cout << "---------------------------------------------------------------\n\n";

    delete[] arr;
    delete[] arr_;
}

void mergeSort(int* list, int start, int end) //���������� ��������
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

