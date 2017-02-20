THE FINER POINTS OF C :|: OBJECT-ORIENTED PROGRAMMING
Corresponding C source: c-oop.c

There's a simple cheat using pointers to functions that allows us to emulate OOP in C.

Here's an example of an "object":

    struct someObject {
        int member1, member2;
        int (*someMethod)(struct someObject);
    };

    int addTwoNumbers(struct someObject x)
    {
        return x.member1 + x.member2;
    }

Of course, the function pointer would need to be assigned like so:

    struct someObject FooBar;
    FooBar.someMethod = addTwoNumbers;

The "methods" would then be called like so:

    // call "method" someMethod from "object" someObject FooBar
    int i = FooBar.someMethod(FooBar);

It isn't anywhere near as simple or efficient as other languages.
In Java, for example, this would be written as:

    class someClass {
        int member1, member2;

        public int someMethod()
        {
            return this.member1 + this.member2;
        }
    }

And be called/initialized as...

    someClass FooBar = new FooBar(1, 2);
    int i = FooBar.someMethod();

As you can see, OOP in C isn't perfect. For example, there's no (simple) way to use the `this` keyword in C.

For those who aren't experienced in Object-Oriented languages, the `thi`' keyword (if it were available in C) would basically refer to the calling structure.

The `this` keyword in C++ is explicitly passed at the ABI level. So there's no real way to use it in C.

That being said, there's still quite a bit of fun to be had with C "Objects".

Check out the C source example, "c-oop.c". For some advanced (cheating) techniques, check out [polymorphism.c](https://github.com/aaronryank/c-prohackr112/blob/master/polymorphism.c). 
