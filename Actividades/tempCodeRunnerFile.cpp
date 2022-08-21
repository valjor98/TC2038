
    for(int i = mejoresDias.size() - 1; -1 < i; i--){
        if(mejoresDias[i-1] - mejoresDias[i] == maxprofit){
            mejorComprar = mejoresDias[i-1];
            mejorVender = mejoresDias[i];
        }