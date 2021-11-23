#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void MakeEmptyArr (TabChar *T){
    (*T).Neff = 0;
}

int NbElmtArr (TabChar T){
    return T.Neff;
}

int MaxNbElArr (TabChar T){
    return IdxMax;
}

IdxType GetFirstIdx (TabChar T){
    return IdxMin;
}

IdxType GetLastIdx (TabChar T){
    return T.Neff;
}

ElType GetElmtArr (TabChar T, IdxType i){
    return T.TI[i];
}

void SetTab (TabChar Tin, TabChar *Tout){
    for (int i = IdxMin; i <= IdxMax; i++){
        (*Tout).TI[i] = Tin.TI[i];
    }
}
    
void SetEl (TabChar *T, IdxType i, ElType v){
    (*T).TI[i] = v;

}
void SetNeff (TabChar *T, IdxType N){
    (*T).Neff = N;
}

boolean IsIdxValid (TabChar T, IdxType i){
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabChar T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmptyArr (TabChar T){
    return (T.Neff == 0);
}

boolean IsFull (TabChar T){
    return (T.Neff == IdxMax);
}