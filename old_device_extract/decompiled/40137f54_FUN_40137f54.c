// Function : FUN_40137f54
// Address  : 0x40137f54
// Size     : 89 bytes


void FUN_40137f54(undefined4 *param_1)

{
  int iVar1;
  
  param_1[0x38] = 0;
  memw();
  (*(code *)&SUB_4008b530)(param_1 + 0x39,0,400);
  *param_1 = 0;
  memw();
  FUN_4014098c(param_1 + 2);
  iVar1 = param_1[0x38];
  if (iVar1 < 0x14) {
    param_1[iVar1 * 5 + 0x39] = 0x4013cc34;
    param_1[iVar1 * 5 + 0x3a] = 0;
    param_1[iVar1 * 5 + 0x3c] = 0x20;
    param_1[iVar1 * 5 + 0x3d] = 1;
    param_1[0x38] = iVar1 + 1;
  }
  memw();
  return;
}

