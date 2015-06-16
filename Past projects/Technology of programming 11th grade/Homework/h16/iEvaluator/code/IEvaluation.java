package iEvaluator.code;
import java.util.ArrayList;
public class IEvaluation implements IEvaluator{
	ArrayList<Double> list = new ArrayList<Double>();
	double power;
	int choice;
	
	IEvaluation(double power,int choice){
		this.power = power;
		this.choice = choice;
	}
	
	double checkChoice(double d,int choice){
		if(choice == 1 && d < 0){
			return -d;
		}
		return d;
	}
	
	@Override
	public void add(double d) {
		for(int i = 1; i<power;i++){
			d=d*d;
		}
		list.add(checkChoice(d,choice));
	}

	@Override
	public Double evaluate() {
		double sum = 0;
		for(Double d:list){
			sum+=d;
		}
		return sum;
	}

}
