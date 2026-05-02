// Function : FUN_40184394
// Address  : 0x40184394
// Size     : 24 bytes


undefined4 FUN_40184394(int *param_1,undefined4 param_2,undefined2 param_3,int param_4)

{
  undefined4 uVar1;
  
  param_1[0xe] = param_4;
  uVar1 = (**(code **)(*param_1 + 0x34))(param_1,param_2,param_3);
  return uVar1;
}

