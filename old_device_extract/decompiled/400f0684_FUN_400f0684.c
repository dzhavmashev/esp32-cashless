// Function : FUN_400f0684
// Address  : 0x400f0684
// Size     : 30 bytes


undefined4 FUN_400f0684(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = func_0x4008c024();
    uVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_2,uVar1);
  }
  return uVar1;
}

