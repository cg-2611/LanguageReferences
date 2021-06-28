# Gradle

## Contents
- [Project Management](#project-management)
	- [Creating Projects](#creating-projects)
	- [Compiling Projects](#compiling-projects)
	- [Building Projects](#building-projects)
	- [Executing Projects](#executing-projects)
		- [Using `java` Command](#using-java-command)
		- [Using `run` Task](#using-run-task)
		- [Arguments](#arguments)
- [Dependencies](#dependencies)
	- [Central Repository Dependencies](#central-repository-dependencies)
	- [Local Jar Dependencies](#local-jar-dependencies)
- [Useful Links](#useful-links)
	- [Gradle Documentation](#gradle-documentation)
	- [Dependency Information](#dependency-information)
	- [General Information](#general-information)

## Project Management
### Creating Projects
---
To create a gradle project, the project directory must first be created.
Once created, navigate to this directory and run:
```
gradle init
```
This will launch the gradle `init` task that is used to generate a project.
After completing the project initialization, a gradle project and all the
required files will be created in the project directory.
### Compiling Projects
---
To compile a java gradle project, from the project root directory, run:
```
gradle clean compileJava
```
This will compile all source code into the `./build/classes/` directory.
> Note: using `clean` is optional and when used, it will clean the project
output directory before compilation, by removing the `./build` directory
completely and then generating a new one.
### Building Projects
---
To build a gradle project, from the project root directory, run:
```
gradle clean build
```
Using the `build` task will run tests during its execution, however to not run
the tests and just package the project, run:
```
gradle clean assemble
```
> Note: using `clean` is optional and when used, it will clean the project
output directory before compilation, by removing the `./build` directory
completely and then generating a new one.
### Executing Projects:
#### Using `java` Command:
To run a compiled java gradle project, from the root directory of the project,
run:
```
java -cp ./build/classes MainClass
```
To run an assembled java gradle project, from the root directory if the
project, run:
```
java -jar ./build/libs/gradle-project.jar
```
> Note: the main class must be specified in the `build.gradle` file in order to
> execute the assembled jar this way:
> ```groovy
> jar {
>     manifest {
>         attributes(
>             'Main-Class': 'MainClass'
>         )
>     }
> }
> ```
#### Using `run` Task:
To run a gradle project using the `run` task, from the root directory of the
project, run:
```
gradle run
```
#### Arguments:
When running a java gradle project using the `java` command, command line and
VM arguments can be passed as normal to the program.

When running a java gradle project using the `run` task, run:
```
gradle run --args="argument1 argument2"
```
To pass VM arguments when running a java gradle project, in the `build.gradle`
file, add:
```groovy
application {
	mainClass = 'MainClass'
	applicationDefaultJvmArgs = ['-XvmArg1 -XvmArg2']
}
```

## Dependencies
### Central Repository Dependencies
---
Gradle is, by default, configured to resolve dependencies from the maven central
repository. Dependencies can be added to a project in the `build.gradle` file.

An example of what to add to the `build.gradle` file for using the `junit`
dependency:
```groovy
repositories {
	mavenCentral()
}

dependencies {
	testImplementation 'junit:junit:4.13.2'
}
```
> Note: `testImplementation` specifies that this dependency is used only for
> testing. To add a development dependency, use `implementation` instead. To
> add a runtime dependency, use `runtimeOnly`.
### Local Jar Dependencies
---
To use local `jar` files in a java gradle project, firstly, create a directory
in the project root where the local `jar` files will go, e.g. `./libs`.

Next, add to the `build.gradle` file:
```groovy
dependencies {
	implementation fileTree('libs') { include '*.jar' }
}
```
This will include any `.jar` files in the project as an implementation
dependency.

## Useful Links
- #### Gradle Documentation:
	- <https://docs.gradle.org/current/userguide/userguide.html>
	- <https://docs.gradle.org/current/javadoc/index.html?overview-summary.html>
- #### Dependency Information:
	- Maven Central: <https://mvnrepository.com/repos/central>
- #### General Information:
	- <https://www.tutorialspoint.com/gradle/index.htm>
	- <https://www.baeldung.com/gradle>
