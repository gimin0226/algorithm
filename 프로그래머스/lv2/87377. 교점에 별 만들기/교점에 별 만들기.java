import java.util.Vector;
import java.util.Arrays;

class Solution {
    public String[] solution(int[][] line) {
        Vector<Pair> vec= new Vector<Pair>();
        for(int i=0;i<line.length;i++){
            for(int j=i+1;j<line.length;j++){
                if(line[i][0]*line[j][1]-line[i][1]*line[j][0]!=0)
                {   
                    Pair pair=compare(line[i],line[j]);
                    if(pair!=null)
                        vec.add(pair);
                }
                
            }
        }
        long maxX=vec.get(0).getX();
        long maxY=vec.get(0).getY();
        long minX=vec.get(0).getX();
        long minY=vec.get(0).getY();
        for(int i=0;i<vec.size();i++){
            if(vec.get(i).getX()>maxX){
                maxX=vec.get(i).getX();
            }
             if(vec.get(i).getY()>maxY){
                maxY=vec.get(i).getY();
            }
             if(vec.get(i).getX()<minX){
                minX=vec.get(i).getX();
            }
             if(vec.get(i).getY()<minY){
                minY=vec.get(i).getY();
            }
        }
        int sizeX=(int)(maxX-minX+1);
        int sizeY=(int)(maxY-minY+1);
        char[][] ch=new char[sizeY][sizeX];
        
       for(int i = 0; i < ch.length; i++)
			Arrays.fill(ch[i], '.');
        
        for(int i=0;i<vec.size();i++){
           int x=(int)(vec.get(i).getX()-minX);
           int y=(int)(maxY-vec.get(i).getY());
           ch[y][x]='*';
        }
        
        String[] answer=new String[ch.length];
        for(int i=0;i<answer.length;i++){
            answer[i]=new String(ch[i]);
        } 
        
        return answer;
    }
    
    public Pair compare(int line1[],int line2[]){
        
            double x=(double)((long)line1[1]*line2[2]-(long)line1[2]*line2[1])/((long)line1[0]*line2[1]-(long)line1[1]*line2[0]);
            double y=(double)((long)line1[2]*line2[0]-(long)line1[0]*line2[2])/((long)line1[0]*line2[1]-(long)line1[1]*line2[0]);
        if(x%1!=0||y%1!=0)return null;
        
            Pair pair=new Pair((long)x,(long)y);
            return pair;
        
    }
}


class Pair{
    private long x,y;
    Pair(long x,long y){
        this.x=x;
        this.y=y;
    }
    public long getX(){
        return x;
    }
    public long getY(){
        return y;
    }
}