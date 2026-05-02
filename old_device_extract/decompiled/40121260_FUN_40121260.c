// Function : FUN_40121260
// Address  : 0x40121260
// Size     : 74 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40121260(int *param_1)

{
  int iVar1;
  
  while (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if (((param_1[3] & 0x100U) == 0) &&
       (((param_1[2] == 0 || (FUN_40121260(), (param_1[3] & 0x100U) == 0)) && (param_1[4] != 0)))) {
      (*_DAT_3ffbf678)();
    }
    if (((param_1[3] & 0x200U) == 0) && (param_1[8] != 0)) {
      (*_DAT_3ffbf678)();
    }
    (*_DAT_3ffbf678)(param_1);
    param_1 = (int *)iVar1;
  }
  return;
}

