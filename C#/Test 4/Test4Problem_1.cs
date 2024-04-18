using System;

abstract class Person
{
    public virtual void sayIt()
    {
        Console.WriteLine("Generic output");
    }

    public void doIt()
    {
        Console.WriteLine("Doing it...");
    }
}

class PsychologyMajor : Person
{
    public override void sayIt()
    {
        Console.WriteLine("PsychologyMajor output");
    }
}

class ComputerScienceMajor : Person
{
    public override void sayIt()
    {
        Console.WriteLine("ComputerScienceMajor output");
    }
}

class Barista : Person
{
    public override void sayIt()
    {
        Console.WriteLine("Barista output");
    }
}

class Program
{
    static void Main(string[] args)
    {
        PsychologyMajor a = new PsychologyMajor();
        ComputerScienceMajor b = new ComputerScienceMajor();
        Barista c = new Barista();
        Person f;

        f = (Person)a;
        f.sayIt();
        f = (Person)b;
        f.sayIt();
        f = (Person)c;
        f.sayIt();
    }
}