package iEvaluator.code;

public class IEvaluationFib extends IEvaluation {

	IEvaluationFib(double power, int choice) {
		super(power, choice);
		// TODO Auto-generated constructor stub
	}
	 public Double evaluate(){
		
		
		double sum = 0;
		for(Double d:list){
			sum+=d;
		}
		
		int c=0;
		int a=0;
		int b=1;
		
		while(c<=sum){
		      c=a+b; 
		      a=b; 
		      b=c;
		}
		if((sum-a) > (c-sum) ){
			return (double) c;
		}
		else 
		{
			return (double) a;
		}
	 }

}

