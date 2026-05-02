// Function : FUN_400e472c
// Address  : 0x400e472c
// Size     : 56 bytes


bool FUN_400e472c(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = func_0x4008c024(param_1);
  }
  if (param_1 == 0) {
    *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80;
  }
  else {
    *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80 | 4;
    *param_2 = param_1;
    param_2[1] = iVar1;
  }
  return param_1 != 0;
}

