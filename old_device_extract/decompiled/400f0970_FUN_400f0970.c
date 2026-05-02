// Function : FUN_400f0970
// Address  : 0x400f0970
// Size     : 32 bytes


undefined4 FUN_400f0970(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&LAB_40183a7b_1)(param_1 + 0x10);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = FUN_400f13ac(param_1 + 0x10,0);
  }
  return uVar2;
}

