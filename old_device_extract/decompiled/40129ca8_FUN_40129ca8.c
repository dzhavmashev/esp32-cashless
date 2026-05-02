// Function : FUN_40129ca8
// Address  : 0x40129ca8
// Size     : 55 bytes


void FUN_40129ca8(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x19];
  if (*(char *)(*param_1 + 5) == '\x01') {
    param_1[0x30] = param_1[0x2e];
  }
  else {
    param_1[0x30] = param_1[0x2e] + 8;
    iVar1 = iVar1 + 8;
    memw();
  }
  param_1[0x1b] = iVar1;
  memw();
  FUN_40185840(param_1,0);
  FUN_40185894(param_1);
  return;
}

