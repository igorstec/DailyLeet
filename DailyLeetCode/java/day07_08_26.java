class Solution {
    private class MyMap {
        HashMap<Integer, Integer> factors;
        int sum_of_values = 0;

        public MyMap(long t) {
            HashMap<Integer, Integer> factors = new HashMap<>();
            int sums = 0;
            while (t != 0 && t % 2 == 0) {
                t /= 2;
                factors[2]++;
                sums++;
            }
            while (t != 0 && t % 3 == 0) {
                t /= 3;
                factors[3]++;
                sums++;
            }
            while (t != 0 && t % 5 == 0) {
                t /= 5;
                factors[5]++;
                sums++;
            }
            while (t != 0 && t % 7 == 0) {
                t /= 7;
                factors[7]++;
                sums++;
            }
            factors[4] = factors[2] / 2;
            factors[6] = Math.min(factors[2], factors[3]);
            factors[8] = factors[2] / 3;
            factors[9] = factors[3] / 2;
            if (t != 0) {
                factors[-1] = 1;
            }
            self.sum_of_values = sums;
            self.factors = factors;
        }
            int check_val(int key){
                return factors[key];
            }
            void take(int key){
                if(key == 2){
                    if(factors[2]%8==0){
                        factors[8]--;
                        if(factors[2]%4==0){
                            factors[4]--;
                        }
                    }
                    factors[2]--;
                }
                else if(key ==3){}
                else if(key ==4){}
                else if(key ==5){}
                else if(key ==6){}
                else if(key ==7){}
                else if(key ==8){}
                else if(key ==9){}
                
            }
    }

    public String smallestNumber(String num, long t) {
        //spraw zeby nie ialo zera
        //chcemy zeby product byl podzielny przez t
        //ale rozbicie na pierwsze jest najlepsze pewnie i pozniej iteracja po dlugpsci slowa
        MyMap factors = MyMap(t);

        int len = num.size();

        if(factors.chcek_val(-1)==1){
            return "-1";
        }
        // 1, 2, 3, 2 * 2 , 5, 2* 3, 7, 2 * 2 *2 , 3 * 3
        // must haves : 5 , 7
        // searching for the smallest combination
        if(factors.sum_of_values <= len){
            //utnij przedrostek co mamy chyba ze zaraz po nim jest 9 to sie wroc do pierwszego
            
            MyMap copy_h = factors;
            
            int check = 0;
            while(check<len ){
                if(num[check]=='1'){
                check++;}else if(copy_h.checkk_val(num[checkk].toInt))>0){
                    copy_h.take(num[check].toInt);
                    check++;
                }
            }
            while(check>=0 && (check == len || num[check=='9'])){
                check--;
            }
            //mamy wyznaczone miejsce gdzie ma byc zmiana
            
        }else{
            
        

        StringBuilder to_return;
        while(HashMap[3]>0 && HashMap[3]%2==0){
            HashMap[3]-=2;
            to_return.append('9');
        }
        while(HashMap[2]>0 && HashMap[2]%3==0){
            HashMap[2]-=3;
            to_return.append('8');
        }
        while(HashMap[7]>0){
            HashMap[7]--;
            to_return.append('7');
        }
        while(HashMap[3]>0 && HashMap[2]>0){
            HashMap[3]--;
            HashMap[2]--;
            to_return.append('6');
        }
        while(HashMap[5]>0){
            HashMap[5]--;
            to_return.append('5');
        }
        while(HashMap[2]>0 && HashMap[2]%2==0){
            HashMap[2]-=2;
            to_return.append('4');
        }
        while(HashMap[3]>0){
            HashMap[3]--;
            to_return.append('3');
        }
        while(HashMap[2]>0){
            HashMap[2]--;
            to_return.append('2');
        }

        

        }

        }
}}