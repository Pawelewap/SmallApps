using System;
using System.Text;

namespace BazaPracownikow
{
    class Program
    {
        static int employeeCounter;
        class Employee
        {
            string fname;
            string lname;
            int age;
            decimal salary;
            static bool flag = false;

            public Employee(
                string fn = "",
                string ln = "",
                int a = 0,
                decimal s = 0)
            {
                this.fname = fn;
                this.lname = ln;
                this.age = a;
                this.salary = s;

                if (employeeCounter >= 5)
                {
                    SetEmployee(ref fn, ref ln, ref a, ref s);
                    this.fname = fn;
                    this.lname = ln;
                    this.age = a;
                    this.salary = s;
                }
                employeeCounter++;
            }

            public void SetEmployee(ref string fn, ref string ln, ref int a, ref decimal s)
            {
                // dodać zabezpieczenie przed nieprawidłowymi znakami
                Console.Clear();
                Console.WriteLine("Employee No. {0}\n", employeeCounter + 1);
                Console.WriteLine("Please give first name of employee: ");
                fn = Console.ReadLine();

                Console.Clear();
                Console.WriteLine("Employee No. {0}: {1}\n", employeeCounter + 1, fn);
                Console.WriteLine("Please give last name of employee: ");
                ln = Console.ReadLine();

                //dodac ograniczenia wieku (0-100) + ograniczenie znaków
                Console.Clear();
                Console.WriteLine("Employee No. {0}: {1} {2}\n", employeeCounter + 1, fn, ln);
                Console.WriteLine("Please give age of employee: ");
                a = Int32.Parse(Console.ReadLine());


                Console.Clear();
                Console.WriteLine("Employee No. {0}: {1} {2}, Age: {3}\n", employeeCounter + 1, fn, ln, a);
                Console.WriteLine("Please give salary of employee: ");

                string test = Console.ReadLine();
                StringBuilder dot = new StringBuilder(test);
                dot.Replace(".", ",");
                s = Decimal.Parse(dot.ToString());


                //dodac mozliwosc poprawienia danych
                Console.Clear();
                Console.WriteLine("Employee No. {0}: {1} {2}, Age: {3}, Salary: {4}$\n",
                    employeeCounter + 1, fn, ln, a, s);
                System.Threading.Thread.Sleep(500);
            }

            public static void ShowEmployees(Employee[] tab)
            {
                if (employeeCounter > 0)
                {
                    for (int i = 0; i < employeeCounter; i++)
                    {
                        Console.WriteLine("Employee No. {0}: {1} {2}, Age: {3}, Salary: {4}$\n",
                            i + 1, tab[i].fname, tab[i].lname, tab[i].age, tab[i].salary);
                    }
                }

                else
                    Console.WriteLine("\nNot found!");

                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();
                Console.Clear();
            }

            public static void ShowBy(string byLastName, Employee[] tab)
            {
                for (int i = 0; i < employeeCounter; i++)
                {
                    if (byLastName.Equals(tab[i].lname))
                    {
                        flag = true;
                        Console.WriteLine("Employee No. {0}: {1} {2}, Age: {3}, Salary: {4}$\n",
                            i + 1, tab[i].fname, tab[i].lname, tab[i].age, tab[i].salary);
                    }

                }

                if (!flag)
                    Console.WriteLine("\nNot found!");

                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();
                Console.Clear();
                flag = false;
            }

            public static void ShowBy(decimal bySalary, Employee[] tab)
            {
                for (int i = 0; i < employeeCounter; i++)
                {
                    if (tab[i].salary > bySalary)
                    {
                        flag = true;
                        Console.WriteLine("Employee No. {0}: {1} {2}, Age: {3}, Salary: {4}$\n",
                            i + 1, tab[i].fname, tab[i].lname, tab[i].age, tab[i].salary);
                    }

                }

                if (!flag)
                    Console.WriteLine("\nNot found!");

                flag = false;
                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();
                Console.Clear();
            }

            public static void ShowBy(int byAge, Employee[] tab)
            {
                for (int i = 0; i < employeeCounter; i++)
                {
                    if (tab[i].age < byAge)
                    {
                        flag = true;
                        Console.WriteLine("Employee No. {0}: {1} {2}, Age: {3}, Salary: {4}$\n",
                            i + 1, tab[i].fname, tab[i].lname, tab[i].age, tab[i].salary);
                    }

                }
                if (!flag)
                    Console.WriteLine("\nNot found!");

                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();
                Console.Clear();
                flag = false;
            }

            ~Employee()
            {
                ;
            }
        }

        static void Main(string[] args)
        {
            string choiceStr;
            int choice;
            bool resultTest;
            Employee[] tabOfEmpl = new Employee[15];
            tabOfEmpl[0] = new Employee("Adam", "Adamski", 22, 500);
            tabOfEmpl[1] = new Employee("Ania", "Luwiczak", 50, 1500);
            tabOfEmpl[2] = new Employee("Roman", "Polański", 31, 300);
            tabOfEmpl[3] = new Employee("Edmund", "Barański", 19, 250);
            tabOfEmpl[4] = new Employee("Hania", "Maleńczuk", 20, 1800);
            do
            {
                Console.WriteLine("\n====== Workers Database 0.9 beta ======\n\n" +

                                    "1. Add employee\n" +
                                    "2. Show all employees\n" +
                                    "3. Show employees with name...\n" +
                                    "4. Show employees earning above...\n" +
                                    "5. Show employees younger than...\n" +
                                    "6. Close program\n" +
                                    "\nSelect an option from the menu:"
                                    ); choiceStr = Console.ReadLine();

                resultTest = int.TryParse(choiceStr, out choice);

                switch (choice)
                {
                    case 1:
                        if (employeeCounter == 15)
                        {
                            Console.Clear();
                            Console.WriteLine("\n\nOut of memory! Insert coin for more employees");
                            System.Threading.Thread.Sleep(1000);
                        }

                        else
                        {
                            for (int i = 5; i < 15; i++)
                                tabOfEmpl[i] = new Employee();
                        }

                        Console.Clear();
                        break;

                    case 2:
                        Console.Clear();
                        Employee.ShowEmployees(tabOfEmpl);
                        break;

                    case 3:
                        string byName = "";
                        Console.Clear();
                        Console.WriteLine("Please give last name of employee to find: ");
                        byName = Console.ReadLine();
                        Employee.ShowBy(byName, tabOfEmpl);
                        break;

                    case 4:
                        decimal bySalary = 0;
                        Console.Clear();
                        Console.WriteLine("Please give amount of salary: ");
                        bySalary = decimal.Parse(Console.ReadLine());
                        Employee.ShowBy(bySalary, tabOfEmpl);
                        break;

                    case 5:
                        int byAge = 0;
                        Console.Clear();
                        Console.WriteLine("Please give age of employee: ");
                        byAge = int.Parse(Console.ReadLine());
                        Employee.ShowBy(byAge, tabOfEmpl);
                        break;

                    case 6:
                        Console.Clear();
                        Console.Write("\n\n!!!!!-Bye-!!!!! \n");
                        System.Threading.Thread.Sleep(500);
                        Console.Clear();
                        Environment.Exit(0);
                        break;

                    default:
                        Console.Clear();
                        Console.Write("\n\n!!!!!-Wrong choice-!!!!! \n");
                        System.Threading.Thread.Sleep(1500);
                        Console.Clear();
                        break;
                }
            } while (true);
        }
    }
}
