using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace OOP_LR4_Galimov
{
    public class Store_Galimov
    {
        private List<Product_Galimov> products = new List<Product_Galimov>();

        public void AddProduct(Product_Galimov product)
        {
            if (product != null)
            {
                products.Add(product);
            }
        }

        public void OutputProducts()
        {
            foreach (Product_Galimov product in products)
            {
                product.OutputProduct();
            }
        }

        public void ToFileProducts()
        {
            Console.WriteLine("Type name of file: ");
            string fileName = Console.ReadLine() + ".dat";

            try
            {
                using (FileStream fout = new FileStream(fileName, FileMode.OpenOrCreate))
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    formatter.Serialize(fout, products);
                }
                Console.WriteLine("File saved successfully.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving file: {ex.Message}");
            }
            finally
            {
                products.Clear();
            }
        }

        public void FromFileProducts()
        {
            Console.WriteLine("Type name of file: ");
            string fileName = Console.ReadLine() + ".dat";

            if (File.Exists(fileName))
            {
                using (FileStream fin = new FileStream(fileName, FileMode.Open))
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    products = formatter.Deserialize(fin) as List<Product_Galimov>;
                }
                Console.WriteLine("File loaded successfully.");
            }
            else
            {
                Console.WriteLine("File does not exist.");
            }
        }

        public void ClearProducts()
        {
            products.Clear();
        }
    }
}
