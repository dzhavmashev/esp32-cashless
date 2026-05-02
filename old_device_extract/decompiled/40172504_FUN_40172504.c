// Function : FUN_40172504
// Address  : 0x40172504
// Size     : 82 bytes


undefined4 FUN_40172504(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_28 [10];
  
  FUN_40184768(param_1,param_2 * 1000);
  param_1[9] = param_2 * 1000;
  iVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  uVar2 = 0;
  if (-1 < iVar1) {
    aiStack_28[1] = 0;
    aiStack_28[0] = param_2;
    iVar1 = FUN_401724ec(param_1,0x1006,aiStack_28);
    uVar2 = 0xffffffff;
    if (-1 < iVar1) {
      uVar2 = FUN_401724ec(param_1,0x1005,aiStack_28);
    }
  }
  return uVar2;
}

