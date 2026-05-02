// Function : FUN_40185894
// Address  : 0x40185894
// Size     : 56 bytes


void FUN_40185894(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x1b];
  if (*(char *)(*param_1 + 5) == '\x01') {
    param_1[0x1a] = iVar1 + 3;
    iVar2 = iVar1 + 0xd;
    param_1[0x1c] = iVar1 + 0xb;
  }
  else {
    param_1[0x1a] = iVar1 + -8;
    iVar2 = iVar1 + 5;
    param_1[0x1c] = iVar1 + 3;
    memw();
  }
  param_1[0x1d] = iVar2;
  param_1[0x1e] = param_1[0x1d];
  memw();
  return;
}

