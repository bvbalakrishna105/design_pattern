# Design Principles

Single Responsibility Principle (SRP):
This principle states that a class should have only one reason to change, meaning it should have only one responsibility. In other words, a class should have only one job or function and should not be responsible for multiple unrelated tasks. This helps to keep classes focused, easier to understand, and more maintainable.

Open/Closed Principle (OCP):
This principle states that software entities (such as classes, modules, functions, etc.) should be open for extension but closed for modification. In other words, the behavior of a module should be extendable without modifying its source code. This is typically achieved through the use of abstractions, inheritance, and polymorphism, allowing new functionality to be added through subclassing or composition without altering existing code.

Liskov Substitution Principle (LSP):
This principle states that objects of a superclass should be replaceable with objects of its subclass without affecting the correctness of the program. In other words, derived classes should be substitutable for their base classes without changing the desirable properties of the program. This ensures that derived classes adhere to the contracts established by their base classes, promoting interoperability and code reuse.

Interface Segregation Principle (ISP):
This principle states that clients should not be forced to depend on interfaces they do not use. In other words, interfaces should be specific to the needs of the clients that use them, rather than being large and monolithic. This helps to prevent interface pollution and minimizes the impact of changes in one part of the system on other parts.

Dependency Inversion Principle (DIP):
This principle states that high-level modules should not depend on low-level modules; both should depend on abstractions. Additionally, abstractions should not depend on details; details should depend on abstractions. This promotes loose coupling between modules, making the system more flexible and easier to maintain, as changes in one module do not directly affect others.
