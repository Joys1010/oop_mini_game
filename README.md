# OOP Mini Game

---

- **Object Oriented Programming project**

It’s an object-oriented-programming game that expresses episodes that might happen at Chung-And University in mini-game.

- **Development Methodology**

"easy to share roles" _ Agile Development Methodology

We divided project by each mini game, and each member implement each functions of a mini game. 

**Init Shared Infrastructure:**  

Screen size, game story (game flow, order), stage time,  Header file-"manager.h", game manager code

- **Project Title:** [ESCAPE SOFT] Chung-Ang University Escape Console Game Using Mini-Games

## Compile

---

**development environment:** Visual Studio 2019

To start the game, you can use these scripts on a command window. 

(change directory)

```tsx
C:\~~ oop_mini_game\final\Debug
```

(execute the game file)

```tsx
final.exe
```

There are codes of mini games in "oop_mini_game/final/final/" folder directory. 

## Object Oriented Concepts

---

- **Inheritance**

Inheritance is used when a class is derived from an existing class. Reusing the class is easy to read and can improve maintenance.

- **Polymorphism >> Overloading**

Overloading is the declaration of a member in a derived class of the same type as a member declared in a basic class. The above functions receive two Char types as factors, but below they receive Item and Char as factors.

- **Class**

A class is a collection of variables of different types and a function. It can be seen that the variables with various data types and the functions that have them as parameters are listed.

- **Constructor**

Constructors themselves initialize their own objects and can generate multiple constructors by taking different factors.

- **Private-public**

Private is not accessible from the external class and can only be accessed within the same class. Only methods within the class can be accessed. On the other hand, Public has external access.

## Game Flows

---

**Start Scene:** Input Player’s Information ( Name, ID, Department ) and start

**Game 1:** Finding the right Key and moving in limited time

**Game 2:** Cooking 4 Hamburgers in a given recipe

**Game 3:** Skipping over obstacles while running

**Game 4:** Finding the OOP classroom by solving the quiz

**Game 5:** Avoiding the boss mob and collecting items

**Game 6:** Arrow key matching game

**End Scene:** Show the score and ranking
