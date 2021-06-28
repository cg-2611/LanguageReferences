# JUnit5

## Contents
- [Adding Dependency](#adding-dependency)
	- [Gradle](#gradle)
	- [Maven](#maven)
- [Useful Links](#useful-links)
	- [JUnit5 Documentation](#junit5-documentation)
	- [Writing Tests Information](#writing-tests-information)
	- [General Information](#general-information)

## Adding Dependency
### Gradle
---
To use JUnit5 version `5.7.2` in a java gradle project, add to the 
`build.gradle` file:
```groovy
dependencies {
	testImplementation 'org.junit.jupiter:junit-jupiter:5.7.2'
}

test {
	useJUnitPlatform()
	testLogging.showStandardStreams = true
	testLogging {
		events "passed", "skipped", "failed"
	}
}
```
> Note: `testLogging.showStandardStreams` and `testLogging` are optional.
### Maven
---
To use JUnit5 version `5.7.2` in a maven project, add to the `pom.xml` file:
```xml
<dependencies>
	<dependency>
		<groupId>org.junit.jupiter</groupId>
		<artifactId>junit-jupiter</artifactId>
		<version>5.7.2</version>
		<scope>test</scope>
	</dependency>
</dependencies>

<plugins>
	<plugin>
		<artifactId>maven-surefire-plugin</artifactId>
		<version>2.22.2</version>
	</plugin>
</plugins>
```
> Note: maven-surefire-plugin is required for the tests to run.

## Useful Links
- #### JUnit5 Documentation:
	- Documentation <https://junit.org/junit5/docs/current/api/>
	- User Guide: <https://junit.org/junit5/docs/current/user-guide/>
- #### General Information
	- <https://www.vogella.com/tutorials/JUnit/article.html>
	- <https://www.tutorialspoint.com/junit/index.htm>
	- <https://www.baeldung.com/junit>