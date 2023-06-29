#ifndef METODOSORGANIZACAO_H_INCLUDED
#define METODOSORGANIZACAO_H_INCLUDED

using namespace std;

template <typename T>
void shellsort(vector<T> &v,int &trocas, int &comp) {
    unsigned int h = 1;
    unsigned int i, j;

    while (h < v.size()) {
        comp++;
        h = h*3+1;
    }
    comp++;
    while (h > 1) {
        comp++;
        h /= 3;
        for (i = h; i < v.size(); i++) {
            comp++;
            T aux = v[i];
            j = i;
            while (j >= h && aux < v[j-h]) {
                comp+=2;
                v[j] = v[j-h];
                j -= h;
                trocas++;
            }
            comp+=2;
            v[j] = aux;
        }
        comp++;
    }
    comp++;
}



template<typename T>
void quicksort(vector<T> &v, int inicio, int fim,int &trocas, int &comp){
	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = v[(inicio + fim) / 2];
	while(i <= j)
	{
        comp++;
		while(v[i] < pivo && i < fim)
		{
            comp+=2;
			i++;
		}
        comp+=2;
		while(v[j] > pivo && j > inicio)
		{
            comp+=2;
			j--;
		}
        comp+=2;
		if(i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
            trocas++;
		}
        comp++;
	}
    comp++;
	if(j > inicio)
		quicksort(v, inicio, j+1, trocas, comp);
    comp++;
	if(i < fim)
		quicksort(v, i, fim, trocas, comp);
    comp++;
}

template<typename T>
void merge(vector<T> &v, int p, int q, int r, int &trocas, int &comp) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++){
    comp++;
    L[i] = v[p + i];
  }
  comp++;
  for (int j = 0; j < n2; j++){
    comp++;
    M[j] = v[q + 1 + j];
  }
  comp++;

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    comp+=2;
    if (L[i] <= M[j]) {
      v[k] = L[i];
      i++;
      trocas++;
    } else {
      v[k] = M[j];
      j++;
      trocas++;
    }
    comp++;
    k++;
  }
  comp+=2;


  while (i < n1) {
    comp++;
    v[k] = L[i];
    i++;
    k++;
    trocas++;
  }
  comp++;

  while (j < n2) {
    comp++;
    v[k] = M[j];
    j++;
    k++;
    trocas++;
  }
  comp++;
}

template<typename T>
void mergesort(vector<T> &v, int l, int r, int &trocas, int &comp) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergesort(v, l, m, trocas, comp);
    mergesort(v, m + 1, r, trocas, comp);

    merge(v, l, m, r, trocas, comp);
  }
}

template<typename T>
void heapify(vector<T> &v, int n, int i, int &trocas, int &comp) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && v[left] > v[largest])
    largest = left;
comp+=2;

  if (right < n && v[right] > v[largest])
    largest = right;
comp+=2;

  if (largest != i) {
    swap(v[i], v[largest]);
    trocas++;
    heapify(v, n, largest, trocas, comp);
  }
  comp++;
}

template<typename T>
void heapsort(vector<T> &v, int n, int &trocas, int &comp) {
  for (int i = n / 2 - 1; i >= 0; i--){
    comp++;
    heapify(v, n, i, trocas, comp);
  }
  comp++;
  for (int i = n - 1; i >= 0; i--) {
    comp++;
    swap(v[0], v[i]);
    trocas++;
    heapify(v, i, 0, trocas, comp);
  }
  comp++;
}

#endif // METODOSORGANIZACAO_H_INCLUDED
