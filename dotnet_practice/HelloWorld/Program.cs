using System;

class Student
{
  public string Name;
  public int Age;
  public int Roll;
  public List<int> Marks;

  public Student(string Name, int Age, int Roll, List<int> Marks)
  {
    this.Name = Name;
    this.Age = Age;
    this.Roll = Roll;
    this.Marks = Marks;
  }

  public float CalculateAverage()
  {
    int total = 0;
    foreach (int m in Marks)
    {
      total += m;
    }
    return total / Marks.Count;
  }

  public string PrintGrade()
  {
    float avg = CalculateAverage();
    if (avg >= 90)
    {
      return "A";
    }
    else if (avg >= 75 && avg < 90)
    {
      return "B";
    }
    else if (avg >= 50 && avg < 74)
    {
      return "C";
    }
    return "F";
  }

  public void DisplayStudentInfo()
  {
    Console.WriteLine($"Name: {Name}");
    Console.WriteLine($"Age: {Age}");
    Console.WriteLine($"Roll Number: {Roll}");
    Console.WriteLine($"Average Marks: {CalculateAverage():F2}");
    Console.WriteLine($"Grade: {PrintGrade()}");
  }
}

class BankAccount
{
  public int AccountNumber;
  public string HolderName;
  public double Balance;

  public BankAccount(int AccNum, string HolderName, double Balance)
  {
    AccountNumber = AccNum;
    this.HolderName = HolderName;
    this.Balance = Balance;
  }

  public void Deposit(double Amount)
  {
    if (Amount < 1)
    {
      Console.WriteLine("Amount cannot be less than 1");
      return;
    }

    Balance += Amount;
    Console.WriteLine("{0} deposited successfully.", Amount);
  }

  public void Withdraw(double Amount)
  {
    if (Amount < 1)
    {
      Console.WriteLine("Amount cannot be less than 1");
      return;
    }
    else if (Amount > Balance)
    {
      Console.WriteLine("insufficient Balance.");
      return;
    }

    Balance -= Amount;
    Console.WriteLine("{0} withdrawn successfully.", Amount);
  }

  public double CheckBalance()
  {
    return Balance;
  }
}

class Product
{
  public int Id;
  public string Name;
  public double Price;
  public int StockQuantity;

  public Product(int Id, string Name, double Price, int Quantity)
  {
    this.Id = Id;
    this.Name = Name;
    this.Price = Price;
    StockQuantity = Quantity;
  }

  public void DispalyInfo()
  {
    Console.WriteLine("-------------Product Information-------------");
    Console.WriteLine($"Name {Name}");
    Console.WriteLine($"Price {Price}");
    Console.WriteLine($"Stock {StockQuantity}");
  }

  public void Purchase(int Qty)
  {
    if (Qty < 1)
    {
      Console.WriteLine("Quantity cannot be less than 1");
      return;
    }
    else if (Qty > StockQuantity)
    {
      Console.WriteLine("Insufficient Stock");
      return;
    }

    StockQuantity -= Qty;
  }

  public void Restock(int Qty)
  {
    if (Qty < 1)
    {
      Console.WriteLine("Quantity cannot be less than 1");
      return;
    }

    StockQuantity += Qty;
  }
}

class Calculator
{
  public static double Add()
  {
    Console.WriteLine("Enter first operand");
    double a = Convert.ToDouble(Console.ReadLine());
    Console.WriteLine("Enter second operand");
    double b = Convert.ToDouble(Console.ReadLine());
    return a + b;
  }
  public static double Subtract()
  {
    Console.WriteLine("Enter first operand");
    double a = Convert.ToDouble(Console.ReadLine());
    Console.WriteLine("Enter second operand");
    double b = Convert.ToDouble(Console.ReadLine());
    return a - b;
  }
  public static double Multiply()
  {
    Console.WriteLine("Enter first operand");
    double a = Convert.ToDouble(Console.ReadLine());
    Console.WriteLine("Enter second operand");
    double b = Convert.ToDouble(Console.ReadLine());
    return a * b;
  }
  public static double Devide()
  {
    Console.WriteLine("Enter first operand");
    double a = Convert.ToDouble(Console.ReadLine());
    Console.WriteLine("Enter second operand");
    double b = Convert.ToDouble(Console.ReadLine());
    return a / b;
  }
}

class Program
{
  static void Main(string[] args)
  {
    // TakeName();
    // OddEvenNegativeCheck();
    // ArrayLoop();
    // FrequencyCounter();
    // GradeCalculator();
    // ReverseString();
    // CheckPrime();
    // CheckPalindrome();
    // MostFrequentChar();
    // CustomSort();
    // SimulateATM();
    // FindDuplicate();
    // WordCount();
  }


  static void TakeName()
  {
    Console.WriteLine("Enter your name : ");
    string name = Console.ReadLine() ?? "Unknown";

    Console.WriteLine("Enter yor age : ");
    int age = Convert.ToInt32(Console.ReadLine());

    Console.WriteLine("Hello, {0}! You are {1} years old.", name, age);
  }

  static void OddEvenNegativeCheck()
  {
    Console.WriteLine("Enter a number");
    int num = Convert.ToInt32(Console.ReadLine());
    if (num % 2 == 0)
    {
      Console.WriteLine("Even Number");
    }
    else
    {
      Console.WriteLine("Odd Number");
    }

    if (num < 0)
    {
      Console.WriteLine("Negative Number");
    }
    else if (num > 0)
    {
      Console.WriteLine("Positive Number");
    }
    else
    {
      Console.WriteLine("Zero");
    }
  }

  static void ArrayLoop()
  {
    Console.WriteLine("How many number you want to store : ");
    int num = Convert.ToInt32(Console.ReadLine());
    List<int> arr = new(num);

    Console.WriteLine("Now enter all {0} numbers.", num);
    for (int i = 0; i < num; i++)
    {
      arr.Add(Convert.ToInt32(Console.ReadLine()));
    }
    int ans = 0;
    for (int i = num - 1; i >= 0; i--)
    {
      Console.Write(arr[i] + " ");
      ans += arr[i];
    }
    Console.WriteLine();
    Console.WriteLine("The sum is : {0}", ans);
  }

  static void FrequencyCounter()
  {
    Console.WriteLine("Enter size : ");
    int size = Convert.ToInt32(Console.ReadLine());
    Dictionary<int, int> map = [];

    Console.WriteLine("Now enter all numbers");
    for (int i = 0; i < size; i++)
    {
      int num = Convert.ToInt32(Console.ReadLine());
      if (map.ContainsKey(num))
      {
        map[num]++;
      }
      else
      {
        map[num] = 1;
      }
    }

    foreach (var kv in map)
    {
      Console.WriteLine($"{kv.Key} => {kv.Value}");
    }
  }

  static void GradeCalculator()
  {
    string[] subjects = ["Math", "Science", "English", "Physics", "Chemistry"];
    int markSum = 0;
    Console.WriteLine("Enter marks.");
    for (int i = 0; i < 5; i++)
    {
      Console.Write($"{subjects[i]} marks : ");
      markSum += Convert.ToInt32(Console.ReadLine());
    }
    float avg = markSum / 5;
    Console.WriteLine($"Total: {markSum}");
    Console.WriteLine($"Average: {avg}");
    if (avg >= 90)
    {
      Console.WriteLine("Grade : A");
    }
    else if (avg >= 75 && avg < 90)
    {
      Console.WriteLine("Grade : B");
    }
    else if (avg >= 50 && avg < 74)
    {
      Console.WriteLine("Grade : C");
    }
    else
    {
      Console.WriteLine("Grade : F");
    }
  }

  static void ReverseString()
  {
    Console.WriteLine("Enter a string : ");
    string str = Console.ReadLine() ?? "Unknown";

    char[] arr = str.ToCharArray();

    int i = 0, j = str.Length - 1;
    while (i < j)
    {
      (arr[j], arr[i]) = (arr[i], arr[j]);
      i++; j--;
    }

    str = new string(arr);

    Console.WriteLine("Reversed string is : {0}", str);
  }

  static void CheckPrime()
  {
    Console.WriteLine("Enter a number : ");
    int num = Convert.ToInt32(Console.ReadLine());
    if (num < 2)
    {
      Console.WriteLine("Not Prime");
      return;
    }
    for (int i = 2; i * i <= num; i++)
    {
      if (num % i == 0)
      {
        Console.WriteLine("Not Prime");
        return;
      }
    }
    Console.WriteLine("Prime");
  }

  static void CheckPalindrome()
  {
    Console.WriteLine("Enter a word or number : ");
    string str = Console.ReadLine() ?? "Unknown";

    int i = 0, j = str.Length - 1;

    while (i < j)
    {
      if (str[i] != str[j])
      {
        Console.WriteLine("Not Palindrome");
        return;
      }
      i++; j--;
    }

    Console.WriteLine("Palindrome");
  }

  static void MostFrequentChar()
  {
    Console.WriteLine("Enter a string");
    string str = Console.ReadLine() ?? "unknown";
    Dictionary<char, int> map = [];

    var HighFreqTup = ('0', 0);
    foreach (char ch in str)
    {
      if (!map.ContainsKey(ch))
      {
        map[ch] = 1;
      }
      else
      {
        map[ch]++;
      }

      if (HighFreqTup.Item2 < map[ch])
      {
        HighFreqTup = (ch, map[ch]);
      }
    }
    Console.WriteLine($"'{HighFreqTup.Item1}' => {HighFreqTup.Item2}");
  }

  static void CustomSort()
  {
    Console.WriteLine("Enter size : ");
    int size = Convert.ToInt32(Console.ReadLine());

    List<int> odd = [];
    List<int> even = [];

    Console.WriteLine("Now enter all elements.");
    for (int i = 0; i < size; i++)
    {
      int num = Convert.ToInt32(Console.ReadLine());
      if (num % 2 == 0)
      {
        even.Add(num);
      }
      else
      {
        odd.Add(num);
      }
    }

    odd.Sort((a, b) => b.CompareTo(a));
    even.Sort();

    Console.Write("Even : ");
    foreach (int num in even)
    {
      Console.Write($"{num} ");
    }
    Console.WriteLine();

    Console.Write("Odd : ");
    foreach (int num in odd)
    {
      Console.Write($"{num} ");
    }
    Console.WriteLine();
  }

  static void SimulateATM()
  {
    Console.WriteLine("Enter starting balance");
    double Balance = Convert.ToDouble(Console.ReadLine());
    int choice;

    bool flag = true;
    while (flag)
    {
      Console.WriteLine("1. Check Balance");
      Console.WriteLine("2. Deposit");
      Console.WriteLine("3. Withdraw");
      Console.WriteLine("4. Exit");
      Console.Write(">>>> ");
      choice = Convert.ToInt32(Console.ReadLine());

      switch (choice)
      {
        case 1:
          Console.WriteLine("Your current balance is {0}", Balance);
          break;
        case 2:
          Console.WriteLine("How much amount you want to deposit");
          double DepositAmount = Convert.ToDouble(Console.ReadLine());
          if (DepositAmount < 1)
          {
            Console.WriteLine("Amount cannot be less than 1");
            break;
          }
          Balance += DepositAmount;
          Console.WriteLine("Amount {0} deposited successfully.", DepositAmount);
          break;
        case 3:
          Console.WriteLine("How much amount you want to withdraw");
          double WithdrawAmount = Convert.ToDouble(Console.ReadLine());
          if (WithdrawAmount < 1)
          {
            Console.WriteLine("Amount cannot be less than 1");
            break;
          }
          else if (WithdrawAmount > Balance)
          {
            Console.WriteLine("Insufficient Balance!!");
            break;
          }
          Balance -= WithdrawAmount;
          Console.WriteLine("Amount {0} withdrawn successfully.", WithdrawAmount);
          break;
        case 4:
          flag = false;
          break;
        default:
          Console.WriteLine("Invalid choice.");
          break;
      }
    }
  }

  static void FindDuplicate()
  {
    Console.WriteLine("Enter size : ");
    int size = Convert.ToInt32(Console.ReadLine());
    Dictionary<int, int> map = [];
    Console.WriteLine("Now enter all elements.");
    for (int i = 0; i < size; i++)
    {
      int num = Convert.ToInt32(Console.ReadLine());
      if (map.ContainsKey(num))
      {
        map[num]++;
      }
      else
      {
        map[num] = 1;
      }
    }

    foreach (var kv in map)
    {
      if (kv.Value > 1)
      {
        Console.Write($"{kv.Key} ");
      }
    }
    Console.WriteLine();
  }

  static void WordCount()
  {
    Console.WriteLine("Enter a long sentence");
    string str = Console.ReadLine() ?? "Unknown";
    HashSet<string> hs = [];
    string[] arr = str.Split(" ");

    foreach (string s in arr)
    {
      hs.Add(s);
    }

    Console.WriteLine($"Words = {arr.Length}, Unique = {hs.Count}");
  }
}