// Function : FUN_40171c9c
// Address  : 0x40171c9c
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40171c9c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  param_2[3] = param_1;
  param_2[4] = 0x7fa;
  *param_2 = 0xffffffff;
  param_2[1] = param_3;
  param_2[2] = param_4;
  (*(code *)&SUB_40082de4)(0x3ffc0770);
  puVar1 = param_2;
  param_2[5] = _DAT_3ffc7ec4;
  _DAT_3ffc7ec4 = puVar1;
  (*(code *)&SUB_40082e0c)(0x3ffc0770);
  return;
}

