Java
====
Compile
-------
To compile a java program using the `javac` command, run:
```
javac -cp path/to/src -d path/to/bin path/to/src/**/*.java
```

e.g. if the command is being run from the project root directory, run:
```
javac -cp ./src -d ./bin ./src/**/*.java
```
> Note: using `src/**/*.java` will maintain the package structure in the output directory specified by the `-d` option. 

Run
---
To run a compiled java program using the `java` command, run:
```
java -cp path/to/bin mainpackage.MainClass
```
e.g. if the command is being run from the project root directory where the entry point is located in `./bin/mainpackage/HelloWorld.class`, run:
```
java -cp ./bin mainpackage.HelloWorld
```

Useful Links
------------
- `javac` command documentation (for java version 11):
https://docs.oracle.com/en/java/javase/11/tools/javac.html#GUID-AEEC9F07-CB49-4E96-8BC7-BCC2C7F725C9

- `java` command documentation (for java verion 11):
https://docs.oracle.com/en/java/javase/11/tools/java.html#GUID-3B1CE181-CD30-4178-9602-230B800D4FAE