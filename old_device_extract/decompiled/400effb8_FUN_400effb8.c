// Function : FUN_400effb8
// Address  : 0x400effb8
// Size     : 30 bytes


undefined4 FUN_400effb8(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = FUN_400f2054(param_1[5]);
  }
  return uVar2;
}

