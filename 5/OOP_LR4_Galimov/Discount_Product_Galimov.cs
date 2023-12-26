using System;

namespace OOP_LR4_Galimov
{
    [Serializable]
    public class DiscountProduct_Galimov : Product_Galimov
    {
        private int discount;
        private int quantity;

        public DiscountProduct_Galimov() { }

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
