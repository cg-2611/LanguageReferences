# Maven

## Contents
- [Project Management](#project-management)
    - [Creating Projects](#creating-projects)
    - [Compiling Projects](#compiling-projects)
    - [Packaging Projects](#packaging-projects)
    - [Executing Projects](#executing-projects)
        - [Using `java` Command](#using-java-command)
        - [Using `exec` Plugin](#using-exec-plugin)
        - [Arguments](#arguments)
- [Plugins](#plugins)
- [Dependencies](#dependencies)
- [Useful Links](#useful-links)
    - [Documentation Links](#documentation-links)
    - [Repository Links](#repository-links)
    - [Plugin Links](#plugin-links)
    - [General Information Links](#general-information-links)

## Project Management
### Creating Projects
---
To create a maven project from the terminal, navigate to the directory where the project will be
created and run:
```
mvn archetype:generate
```
This will launch an interactive project generator. To generate a project using the quick start archetype, use the default value for the first prompt. The maven archetype version must then be specified, followed by the groupId, the artifactId (project name), the project version, a main package name, and finally a confirmation.

To create a project without using the interactive generator, the values for the project properties can be provided as command line arguments, run:
```
mvn archetype:generate -DgroupId=groupId -DartifactId=project-name -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
```
Any properties that are not specified will be given their default values.
### Compiling Projects
---
To compile a maven project, from the root directory of the project, run:
```
mvn clean compile
```
This will compile all source code into the `./target/classes/` directory.
> Note: using `clean` is optional and when used, it will clean the project output before compilation, by removing the `./target` directory completely and then generating a new one.
### Packaging Projects
---
To package a maven project, from the root directory of the project, run:
```
mvn clean package
```
This will create a jar file of the project in the `.target` directory.
> Note: using `clean` is optional and when used, it will clean the project output before compilation, by removing the `./target` directory completely and then generating a new one.
### Executing Projects
---
#### Using `java` Command:
To run a compiled maven project, from the root directory of the project, run:
```
java -cp ./target/classes mainpackage.MainClass
```

To run a packaged maven project, from the root directory of the project, run:
```
java -jar ./target/artifactId-specifiedVersion.jar
```
e.g. for a maven project with an artifactId of maven-project and a version of 1.0, run:
```
java -jar ./target/maven-project-1.0.jar
```
> Note: the maven-jar-plugin must be configured to put the main class in the manifest file to execute a jar this way:
> ```xml
> <plugin>
>     <groupId>org.apache.maven.plugins</groupId>
>     <artifactId>maven-jar-plugin</artifactId>
>     <version>3.2.0</version>
>     <configuration>
>         <archive>
>             <manifest>
>                 <mainClass>${project.groupId}.App</mainClass>
>             </manifest>
>         </archive>
>     </configuration>
> </plugin>
> ```

#### Using `exec` Plugin:
To run a compiled maven project using the `mvn exec` plugin, either run:
```
mvn exec:java -Dexec.mainClass="mainpackage.MainClass"
```
or if the main class of the project is specified in the plugin configuration in the `pom.xml` file, run:
```
mvn exec:java
```
The `pom.xml` file plugin configuration:
```xml
<plugin>
    <groupId>org.codehaus.mojo</groupId>
    <artifactId>exec-maven-plugin</artifactId>
    <version>3.0.0</version>
    <executions>
        <execution>
        <goals>
            <goal>java</goal>
        </goals>
        </execution>
    </executions>
    <configuration>
        <mainClass>${project.groupId}.MainClass</mainClass>
    </configuration>
</plugin>
```
#### Arguments:
When running a maven project using the `java` command, command line and VM arguments can be passed as normal to the program.

When running a maven project using the `exec` plugin, for the `java` goal there are 2 options, either run:
```
mvn exec:java -Dexec.mainClass="mainpackage.MainClass" -Dexec.args="argument1 argument2"
```
or the arguments can be supplied in the plugin configuration in the `pom.xml` file:
```xml
<plugin>
    <groupId>org.codehaus.mojo</groupId>
    <artifactId>exec-maven-plugin</artifactId>
    <version>3.0.0</version>
    <executions>
        <execution>
        <goals>
            <goal>java</goal>
        </goals>
        </execution>
    </executions>
    <configuration>
        <mainClass>${project.groupId}.MainClass</mainClass>
        <arguments>
            <argument>argument1</argument>
            <argument>argument2</argument>
          </arguments>
    </configuration>
</plugin>
```
Using this method, when executing the project, run:
```
mvn exec:java
```
> Note: VM arguments cannot be passed using the `java` goal of the `exec` plugin.

Using the `exec` goal of the `exec` command, both VM and command line arguments can be passed.
Again there are 2 options for doing this, either run:
```
    mvn exec:exec -Dexec.executable="java" -Dexec.args="-XvmArg1 -XvmArg2 -jar ./target/artifactId-version.jar arg1 arg2"
```
or the arguments can be supplied in the plugin configuration in the `pom.xml` file:
```xml
 <plugin>
    <groupId>org.codehaus.mojo</groupId>
    <artifactId>exec-maven-plugin</artifactId>
    <version>3.0.0</version>
    <executions>
        <execution>
        <goals>
            <goal>exec</goal>
        </goals>
        </execution>
    </executions>
    <configuration>
        <executable>java</executable>
        <arguments>
        <argument>-XvmArg1</argument>
        <argument>-XvmArg2</argument>
        <argument>-jar</argument>
        <argument>./target/${project.artifactId}-${project.version}.jar</argument>
        <argument>arg1</argument>
        <argument>arg2</argument>
        </arguments>
    </configuration>
</plugin>
```
Using this method, when executing the project, run:
```
mvn exec:exec
```
> Note: the project must be packaged into a `jar` (or UBER-jar where applicable) before running using this method.

## Plugins
Plugins allow for different tasks to be run during the development and build lifecycle of a maven project.
Two useful plugins include:
- The `shade` plugin, which can be used to package the current project UBER-jar files including its dependencies.
- The `exec` plugin, which can be used to execute system and java programs.

Plugins can be added to the project and configured in the `pom.xml` file.

All plugins must be specified with a groupId, an artifactId and a version at least.

An example of what to add to the `pom.xml` file for using the `shade` plugin:
```xml
<plugins>
    <plugin>
        <groupId>org.apache.maven.plugins</groupId>
        <artifactId>maven-shade-plugin</artifactId>
        <version>3.2.4</version>
        <configuration>
            <transformers>
                <transformer implementation="org.apache.maven.plugins.shade.resource.ManifestResourceTransformer">
                <Main-Class>${project.groupId}.MainClass</Main-Class>
                </transformer>
            </transformers>
        </configuration>
        <executions>
            <execution>
            <phase>package</phase>
            <goals>
                <goal>shade</goal>
            </goals>
            </execution>
        </executions>
    </plugin>
</plugins>
```
> Note: all plugins must pe placed between the `<plugins>...</plugins>` tags.

## Dependencies
Dependencies can be added to a project in the `pom.xml` file.
All dependencies are resolved from any specified [repositories](https://maven.apache.org/guides/introduction/introduction-to-repositories.html).

All dependencies must be specified with a groupId, an artifactId and a version at least.

An example of what to add to the `pom.xml` file for using the `junit` dependency:
```xml
<dependencies>
    <dependency>
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.11</version>
      <scope>test</scope>
    </dependency>
</dependencies>
```
> Note: the `<scope>...</scope>` tags can be used to specify the portion of development in which the dependency can bee used.

> Note: all dependencies must pe placed between the `<dependencies>...</dependencies>` tags.

## Useful Links
- #### Documentation Links:
    - <http://maven.apache.org/>
- #### Plugin Links:
    - <https://maven.apache.org/plugins/>
    - <https://repo.maven.apache.org/maven2/org/apache/maven/plugins/>
    - MojoHaus: <https://www.mojohaus.org/plugins.html>
- #### Repository Links:
    - <https://maven.apache.org/guides/introduction/introduction-to-repositories.html>
    - Maven Central: <https://mvnrepository.com/repos/central>
    - Google: <https://maven.google.com/web/index.html>
- #### General Information Links:
    - <https://www.baeldung.com/maven>
    - <https://www.tutorialspoint.com/maven/index.htm>
