    import java.util.Scanner;
     
    class Myclass{
    	public static void main(String[]args){
    		Scanner sc = new Scanner(System.in);
    		while(sc.hasNextLine()){
    			String a = sc.nextLine();
    			String b = sc.nextLine();
    			int[] aarr = new int[26];
    			int[] barr = new int[26];
    			for(int i=0;i<26;i++){
    				aarr[i]=0;
    				barr[i]=0;
    			}
     
    			for(int i=0;i<a.length();i++){
    				aarr[(int)(a.charAt(i)-'a')]++;
    			}
    			for(int i=0;i<b.length();i++){
    				barr[(int)(b.charAt(i)-'a')]++;
    			}
     
    			for(int i=0;i<26;i++){
    				if(aarr[i]<barr[i]){
    					for(int j=0;j<aarr[i];j++){
    						System.out.print((char)('a'+i));
    					}
    				}
    				else{
    					for(int j=0;j<barr[i];j++){
    						System.out.print((char)('a'+i));
    					}
    				}
    			}
    			System.out.println();
     
    		}
    	}
    } 
