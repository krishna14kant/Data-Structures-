def insertion_sort(vet):
    for i in range (1, len (vet)):
        var = vet[i]
        j = i - 1
        while (j >= 0 and var < vet[j]):
            vet[j + 1] = vet[j]
            j = j - 1
        vet[j + 1] = var
