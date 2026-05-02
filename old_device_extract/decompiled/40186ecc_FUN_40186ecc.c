// Function : FUN_40186ecc
// Address  : 0x40186ecc
// Size     : 52 bytes


int FUN_40186ecc(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *local_30 [12];
  
  local_30[0] = (undefined4 *)*param_3;
  iVar1 = (**(code **)(*param_2 + 8))(param_2);
  if (iVar1 != 0) {
    local_30[0] = (undefined4 *)*local_30[0];
  }
  iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2,local_30,1);
  if (iVar1 != 0) {
    *param_3 = local_30[0];
  }
  return iVar1;
}

