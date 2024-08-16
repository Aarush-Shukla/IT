        
        int pylons(int k, int arr_count, int* arr) {
        int index = 0;
        int range = 0;
        int changes = 0;
        
        while(index < arr_count){
            
            if(index < range){
                // city is already in range                
            }
            else{
                // find a tower to switch on
                
                int towerEnd = index+k;
                int towerStart = index-k+1;
                if(towerStart < 0){
                    towerStart = 0;
                }
                int tower = -1;
                
                for(int j=towerStart; j<towerEnd && j<arr_count; j++){
                    if(arr[j] == 1){
                        tower = j;
                    }
                }
                
                // no way to handle current city
                if(tower == -1){
                    return -1;
                }
                else{
                    changes++;
                    index = tower;
                    range = index + k;
                }
            }
            
            index++;
        }
        
        return changes;
}