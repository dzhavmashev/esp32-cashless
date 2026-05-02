// Function : FUN_400f8eb4
// Address  : 0x400f8eb4
// Size     : 36 bytes


undefined4 FUN_400f8eb4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400f8e3c(param_1,param_2,param_3);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_400f8e98();
    (*(code *)&SUB_40094d80)(iVar1);
  }
  return uVar2;
}

