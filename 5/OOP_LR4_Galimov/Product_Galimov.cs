using System;
using System.Xml;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace OOP_LR4_Galimov
{
    [Serializable]
    public class Product
    {
        protected string name { get; set; }
        protected float price { get; set; }
        protected float weight { get; set; }
        protected float code { get; set; }

        public virtual void InputProduct()
        {
            Console.Write("Input Product-Name: ");
            name = Console.ReadLine();
            Console.Write("Input Product-Price: ");
            price = float.Parse(Console.ReadLine());
            Console.Write("Input Product-Weight: ");
            weight = float.Parse(Console.ReadLine());
            Console.Write("Input Product-Code: ");
            code = float.Parse(Console.ReadLine());
        }

        public virtual void OutputProduct()
        {
            Console.WriteLine($"{name}\n{price}\n{weight}\n{code}");
        }
    }
}