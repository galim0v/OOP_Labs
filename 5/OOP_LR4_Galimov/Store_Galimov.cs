using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
using System.Runtime.Serialization.Formatters.Binary;


namespace OOP_LR4_Galimov
{
    public class Store
    {
        private List<Product> products = new List<Product>();

        public void AddProduct(Product product)
        {
            if (product != null)
            {
                products.Add(product);
            }
        }

        public void OutputProducts()
        {
            foreach (Product product in products)
            {
                product.OutputProduct();
            }
        }

        public void ToFileProducts()
        {
            Console.WriteLine("Type name of file: ");
            string fileName = Console.ReadLine() + ".dat";
            using (FileStream fout = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                formatter.Serialize(fout, products); // перевод данных в байты
            }
            products.Clear();
        }

        public void FromFileProducts()
        {
            Console.WriteLine("Type name of file: ");
            string fileName = Console.ReadLine() + ".dat";
            using (FileStream fin = new FileStream(fileName, FileMode.Open))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                products = formatter.Deserialize(fin) as List<Product>;
            }
        }



        public void ClearProducts()
        {
            products.Clear();
        }
    }

}