    import java.util.Scanner;
     
    class Myclass{
    	public static void main(String[] args){
    		Scanner sc = new Scanner(System.in);
    		int t = sc.nextInt();
    		long[] aarr = new long[100005];
    		long[] barr = new long[100005];
    		while(t!=0){
    			t-=1;
    			int n = sc.nextInt();
    			for(int i=0;i<n;i++){
    				aarr[i] = sc.nextLong();
    			}
    			for(int i=0;i<n;i++){
    				barr[i] = sc.nextLong();
    			}
    			long prev = -1, flag = 0;
    			for(int i=0;i<n;i++){
    				if(prev<=aarr[i] && prev<=barr[i]){
    					if(aarr[i]<=barr[i]){
    						prev=aarr[i];
    					}
    					else{
    						prev=barr[i];
    					}
    				}
    				else if(prev<=aarr[i]){
    					prev=aarr[i];
    				}
    				else if(prev<=barr[i]){
    					prev=barr[i];
    				}
    				else{
    					flag=1;
    					System.out.println("NO");
    					break;
    				}
    			}
    			if(flag==0){
    				System.out.println("YES");	
    			}
    		}
    	}	
    } 
