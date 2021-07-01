import java.util.HashMap;

public class bool_parenthesis {

    
    int boolParenRec(String str, int i, int j, boolean isTrue, HashMap<String, Integer> res){

        if(i>j){
            return 0;
        }

        if (i==j){
            if((isTrue && str.charAt(i)=='T')||(!isTrue && str.charAt(i)=='F'))
                return 1;
            return 0;
        }

        String a = Integer.toString(i) + ' '+Integer.toString(j) + ' '+ isTrue;
        
        if(res.containsKey(a)){
            return res.get(a);
        }

        int ans = 0;
        for(int k=i+1; k<j; k+=2){

            int lT = boolParenRec(str,i,k-1,true,res);
            int lF = boolParenRec(str,i,k-1,false,res);
            int rT = boolParenRec(str,k+1,j,true,res);
            int rF = boolParenRec(str,k+1,j,false,res);

            switch ((int)(str.charAt(k))){

            case 38:
                if(isTrue)
                    ans += (lT*rT)%1003;
                else
                    ans += (lT*rF)%1003+(lF*rT)%1003+(lF*rF)%1003;
            break;

            case 124:
                if(isTrue)
                    ans+=(lT*rF)%1003+(lF*rT)%1003+(lT*rT)%1003;
                else
                    ans+=(lF*rF)%1003;
            break;

            case 94:
                if(isTrue)
                    ans+=(lT*rF)%1003+(lF*rT)%1003;
                else
                    ans+=(lF*rF)%1003+(lT*rT)%1003;
            }
        }
        res.put(a,ans%1003);
        return ans%1003;
    }

    int boolParen(String str)
    {
        int N = str.length();
        HashMap<String,Integer> res = new HashMap<>();
        
        return boolParenRec(str,0,N-1,true,res);
    }
    
}
