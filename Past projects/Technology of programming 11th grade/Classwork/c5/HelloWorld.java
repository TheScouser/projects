public class HelloWorld{
	public static void main(String[] args){
		int i,x=0,count=0;
		int arr[] = new int[10];
		
		
		for(i=0;i<100;i++){
			if(count<10){
			if(i%2 != 0){
				arr[x]=i;
				x++;
				count++;
			}
			}
			else break;
		}
		for(i=0;i<10;i++){
			System.out.println(arr[i]);
		}
	}
}