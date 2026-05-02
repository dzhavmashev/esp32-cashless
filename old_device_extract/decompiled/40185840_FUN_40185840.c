// Function : FUN_40185840
// Address  : 0x40185840
// Size     : 79 bytes


void FUN_40185840(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x30];
  if (*(char *)(*param_1 + 5) == '\x01') {
    param_1[0x2f] = iVar1 + 3;
    iVar2 = iVar1 + 0xd;
    param_1[0x31] = iVar1 + 0xb;
  }
  else {
    param_1[0x2f] = iVar1 + -8;
    iVar2 = iVar1 + 5;
    param_1[0x31] = iVar1 + 3;
    memw();
  }
  param_1[0x32] = iVar2;
  param_1[0x33] = param_1[0x32];
  if (param_2 != 0) {
    iVar1 = 0;
    if (1 < *(int *)(param_2 + 0xd0)) {
      iVar1 = *(int *)(param_2 + 4) - *(int *)(param_2 + 8);
    }
    param_1[0x33] = param_1[0x32] + iVar1;
  }
  memw();
  return;
}

