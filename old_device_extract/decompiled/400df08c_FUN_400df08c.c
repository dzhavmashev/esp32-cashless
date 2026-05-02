// Function : FUN_400df08c
// Address  : 0x400df08c
// Size     : 51 bytes


void FUN_400df08c(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80;
    }
    else {
      iVar1 = func_0x4008c024(param_1);
      *param_2 = param_1;
      *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80 | 4;
      param_2[1] = iVar1;
    }
  }
  return;
}

