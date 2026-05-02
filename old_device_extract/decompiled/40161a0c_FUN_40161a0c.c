// Function : FUN_40161a0c
// Address  : 0x40161a0c
// Size     : 45 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161a0c(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = (*(code *)&SUB_4000d280)(*param_1,param_1[1],_DAT_3ffca204,0);
    _DAT_3ffc7c34 = (iVar1 - _DAT_3ffc7c34) / _DAT_3ffc7c14 + _DAT_3ffc7c34;
  }
  memw();
  return;
}

