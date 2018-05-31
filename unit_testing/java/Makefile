
all: test

CLASSPATHS=".:/usr/share/maven-repo/junit/junit/4.x/junit-4.x.jar:/usr/share/maven-repo/org/hamcrest/hamcrest-core/1.3/hamcrest-core-1.3.jar"

%.class: %.java
	javac $<

%Test.class: %Test.java
	javac -cp ${CLASSPATHS} $<

test: CalculatorTest.class
	java -cp ${CLASSPATHS} org.junit.runner.JUnitCore CalculatorTest

clean:
	-rm -f *.class
