// Function : FUN_400e04f0
// Address  : 0x400e04f0
// Size     : 56 bytes


void FUN_400e04f0(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 1;
  param_1[3] = 0;
  param_1[4] = 0;
  if (param_3 != 0) {
    cVar1 = *(char *)(param_3 + 8);
    iVar2 = *(int *)(param_3 + 0xc);
    if (iVar2 != 0) {
      iVar3 = func_0x4008c024(iVar2);
    }
    *param_1 = iVar2;
    param_1[1] = iVar3;
    param_1[2] = ((int)cVar1 ^ 0xffffffffU) >> 0x1f;
    param_1[3] = param_3;
    param_1[4] = param_2;
  }
  return;
}

