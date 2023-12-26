using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace OOP_LR4_Galimov
{
   
    [Serializable]
    public class DiscountProduct : Product
    {
        private int discount;
        private int quantity;

        public DiscountProduct() { }

        public override void InputProduct()
        {
            base.InputProduct();
            Console.Write("Input discount: ");
            discount = int.Parse(Console.ReadLine());
            Console.Write("Input quantity: ");
            quantity = int.Parse(Console.ReadLine());
        }

        public override void OutputProduct()
        {
            base.OutputProduct();
            Console.WriteLine($"{discount}\n{quantity}");
        }
    }
}