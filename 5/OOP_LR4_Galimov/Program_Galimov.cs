using System;

namespace OOP_LR4_Galimov
{
    class Program_Galimov
    {
        static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Store_Galimov store = new Store_Galimov();
            int s = 0;

            do
            {
                PrintMenu();
                while (!int.TryParse(Console.ReadLine(), out s))
                {
                    Console.WriteLine("Введите корректное число. Попробуйте еще раз.");
                }
                switch (s)
                {
                    case 0:
                        Environment.Exit(0);
                        break;
                    case 1:
                        Product_Galimov product = new Product_Galimov();
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
                        DiscountProduct_Galimov discountProduct = new DiscountProduct_Galimov();
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
