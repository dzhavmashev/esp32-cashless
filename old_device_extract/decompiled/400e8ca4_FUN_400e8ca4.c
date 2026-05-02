// Function : FUN_400e8ca4
// Address  : 0x400e8ca4
// Size     : 31 bytes


void FUN_400e8ca4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  FUN_400e8c70(param_1 + 2,param_2 + 2);
  uVar1 = param_2[7];
  param_1[6] = param_2[6];
  param_1[7] = uVar1;
  return;
}

