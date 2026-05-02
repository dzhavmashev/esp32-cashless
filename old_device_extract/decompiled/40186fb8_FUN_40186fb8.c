// Function : FUN_40186fb8
// Address  : 0x40186fb8
// Size     : 43 bytes


int * FUN_40186fb8(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  if ((*param_1 == 0) && (*(int **)(param_1[1] + 4) == param_1)) {
    piVar1 = (int *)FUN_40186fe8();
    return piVar1;
  }
  piVar1 = (int *)param_1[2];
  if ((int *)param_1[2] == (int *)0x0) {
    for (piVar2 = (int *)param_1[1]; (int *)piVar2[2] == param_1; piVar2 = (int *)piVar2[1]) {
      param_1 = piVar2;
    }
  }
  else {
    do {
      piVar2 = piVar1;
      piVar1 = (int *)piVar2[3];
    } while ((int *)piVar2[3] != (int *)0x0);
  }
  return piVar2;
}

