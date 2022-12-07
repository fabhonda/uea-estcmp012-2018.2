//Algoritmo e Estrutura de Dados II - Algoritmos de Ordenação
	
	//Insertion Sort
	for(j=1;j<tam;j++){
		chave = numeros[j];
		i=j-1;
		while(i>=0 && numeros[i] > chave){
			numeros[i+1] = numeros[i];
			i--;
		}
		numeros[i+1] = chave;
	}
	
	//Selection Sort
	for(i=0;i<tam-1;i++){
		min = i;
		for(j=i+1;j<tam;j++){
			if(numeros[min] > numeros[j]) {
				min = j;
			}
		}
		temp  = numeros[min];
		numeros[min] = numeros[i];
		numeros[i] = temp;
	}
	
	//Bubble Sort
	for(i=0;i<tam-1;i++){
		for(j=0;j<tam-i-1;j++){
			if(numeros[j] > numeros[j+1]){
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}
