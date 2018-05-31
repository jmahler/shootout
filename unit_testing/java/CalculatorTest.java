
import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class CalculatorTest {
  @Test
  public void sumThree() {
    Calculator calculator = new Calculator();
    int sum = calculator.evaluate("1+2+3");
    assertEquals(6, sum);
  }

  @Test
  public void sumThree2() {
    Calculator calculator = new Calculator();
    int sum = calculator.evaluate("8+10+12");
    assertEquals(30, sum);
  }
}
