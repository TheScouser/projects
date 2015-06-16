package iEvaluator.code;

public class DirectIEvaluatorFactory implements IEvaluatorFactory{
	int choice;
	@Override
	public IEvaluator createSumEvaluator() {
		IEvaluation IE = new IEvaluation(1,choice);
		return IE;
	}

	@Override
	public IEvaluator createPowerOnEvaluator() {
		IEvaluation IE = new IEvaluation(2,choice);
		return IE;
	}

	@Override
	public IEvaluator createPowerOnEvaluator(double power) {
		IEvaluation IE = new IEvaluation(power,choice);
		return IE;
	}

	@Override
	public IEvaluator createFibonaciEvaluator() {
		IEvaluationFib IE = new IEvaluationFib(1,choice);
		return IE;
	}
}
