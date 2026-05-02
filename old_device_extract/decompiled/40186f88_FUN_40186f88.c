// Function : FUN_40186f88
// Address  : 0x40186f88
// Size     : 45 bytes


void FUN_40186f88(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar1 + 0xc);
  *(int *)(param_1 + 8) = iVar2;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 4) = param_1;
  }
  iVar2 = *(int *)(param_1 + 4);
  *(int *)(iVar1 + 4) = iVar2;
  if (*param_2 == param_1) {
    *param_2 = iVar1;
  }
  else if (*(int *)(iVar2 + 0xc) == param_1) {
    *(int *)(iVar2 + 0xc) = iVar1;
  }
  else {
    *(int *)(iVar2 + 8) = iVar1;
  }
  *(int *)(iVar1 + 0xc) = param_1;
  *(int *)(param_1 + 4) = iVar1;
  return;
}

