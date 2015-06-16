package iEvaluator.code;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DirectIEvaluatorFactory fact1=new DirectIEvaluatorFactory();
		AbsoluteIEvaluatorFactory fact2=new AbsoluteIEvaluatorFactory();
		
		IEvaluation list=(IEvaluation) fact1.createSumEvaluator();
		list.add(-10);
		list.add(20);
		System.out.println(list.evaluate());
		list=(IEvaluation) fact2.createFibonaciEvaluator();
		list.add(8);
		list.add(1);
		
		System.out.println(list.evaluate());
	}

}
