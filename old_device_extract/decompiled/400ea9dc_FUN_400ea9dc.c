// Function : FUN_400ea9dc
// Address  : 0x400ea9dc
// Size     : 116 bytes


void FUN_400ea9dc(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (-1 < *param_1) {
    FUN_401090b4();
    *param_1 = -1;
  }
  if (param_1[0xb3] != 0) {
    FUN_40144730(param_1 + 0x176);
  }
  if (param_1[0xb2] != 0) {
    FUN_40144730(param_1 + 0x1cc);
    FUN_40139b44(param_1 + 0x222);
  }
  FUN_4012cf14(param_1 + 2);
  FUN_4012d108(param_1 + 0x8a);
  FUN_40133da8(param_1 + 0xc4);
  FUN_40137fb0(param_1 + 0xd8);
  iVar2 = param_1[0x225];
  iVar1 = param_1[0x224];
  func_0x4008b538(param_1,0,0x898);
  param_1[0x225] = iVar2;
  param_1[0x224] = iVar1;
  return;
}

