// Function : FUN_400f0948
// Address  : 0x400f0948
// Size     : 40 bytes


undefined4 FUN_400f0948(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1 = param_1 + 0x10;
  iVar1 = (*(code *)&LAB_40183a7b_1)(param_1);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = FUN_400f13ac(param_1,0);
    FUN_400f1760(param_1,0,1);
  }
  return uVar2;
}

