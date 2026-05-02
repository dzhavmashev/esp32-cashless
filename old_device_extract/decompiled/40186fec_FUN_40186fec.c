// Function : FUN_40186fec
// Address  : 0x40186fec
// Size     : 44 bytes


int FUN_40186fec(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) == 0) {
    for (iVar2 = *(int *)(param_1 + 4); *(int *)(iVar2 + 0xc) == param_1;
        iVar2 = *(int *)(iVar2 + 4)) {
      param_1 = iVar2;
    }
    if (iVar2 != *(int *)(param_1 + 0xc)) {
      param_1 = iVar2;
    }
  }
  else {
    do {
      piVar1 = (int *)(iVar2 + 8);
      param_1 = iVar2;
      iVar2 = *piVar1;
    } while (*piVar1 != 0);
  }
  return param_1;
}

