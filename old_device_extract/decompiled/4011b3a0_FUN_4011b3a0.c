// Function : FUN_4011b3a0
// Address  : 0x4011b3a0
// Size     : 52 bytes


undefined4 FUN_4011b3a0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_5 + 4;
  if ((0x18 < iVar2) && (param_4 = param_3, param_5 < 0x19)) {
    iVar2 = 0x24;
  }
  memw();
  uVar1 = FUN_40109af0(param_1,param_2,*(undefined4 *)(param_4 + iVar2 + -4));
  return uVar1;
}

