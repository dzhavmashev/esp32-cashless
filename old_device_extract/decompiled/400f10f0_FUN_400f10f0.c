// Function : FUN_400f10f0
// Address  : 0x400f10f0
// Size     : 34 bytes


void FUN_400f10f0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != 0) {
    uVar1 = func_0x4008c024(param_2);
    iVar2 = FUN_400f0f40(param_1,param_2,uVar1);
    if (iVar2 != 0) {
      return;
    }
  }
  FUN_400f0a38(param_1);
  return;
}

