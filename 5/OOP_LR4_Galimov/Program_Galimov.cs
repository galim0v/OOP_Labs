using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_LR4_Galimov
{
    class Program
    {
        static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Store store = new Store();
            int s = 0;

            do
            {
                PrintMenu();
                s = int.Parse(Console.ReadLine());
                switch (s)
                {
                    case 0:
                        Environment.Exit(0);
                        break;
                    case 1:
                        Product product = new Product();
                        product.InputProduct();
                        store.AddProduct(product);
                        break;
                    case 2:
                        store.OutputProducts();
                        break;
                    case 3:
                        store.FromFileProducts();
                        break;
                    case 4:
                        store.ToFileProducts();
                        break;
                    case 5:
                        DiscountProduct discountProduct = new DiscountProduct();
                        discountProduct.InputProduct();
                        store.AddProduct(discountProduct);
                        break;
                    case 6:
                        store.ClearProducts();
                        break;
                    default:
                        Console.WriteLine("Invalid value. Try again");
                        break;
                }
            } while (s != 0);
        }

        static void PrintMenu()
        {
            Console.WriteLine("--------------------");
            Console.WriteLine("Выберите пункт меню");
            Console.WriteLine("1. Добавить продукт с консоли");
            Console.WriteLine("2. Вывести все продукты на консоль");
            Console.WriteLine("3. Загрузить продукты с файла");
            Console.WriteLine("4. Сохранить продукты в файл");
            Console.WriteLine("5. Добавить дисконтный продукт с консоли");
            Console.WriteLine("6. Очистить");
            Console.WriteLine("0. Выход");
            Console.WriteLine("--------------------");
        }
    }
}