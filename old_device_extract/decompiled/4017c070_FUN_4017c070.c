// Function : FUN_4017c070
// Address  : 0x4017c070
// Size     : 52 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4017c070(undefined4 *param_1,undefined4 param_2,undefined *param_3,undefined4 param_4,
                undefined4 *param_5)

{
  int iVar1;
  
  if (param_3 == (undefined *)0x0) {
    param_4 = 1;
    param_3 = &DAT_3f42161d;
    param_2 = 0;
  }
  iVar1 = (**(code **)(_DAT_3ffc07c0 + 0xe4))(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == -1) {
    *param_5 = 0;
    *param_1 = 0x8a;
  }
  return iVar1;
}

