// Function : FUN_40163070
// Address  : 0x40163070
// Size     : 42 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163070(uint param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,char param_5
                 )

{
  int iVar1;
  
  iVar1 = _DAT_3ffc0034 + (param_1 & 0xff) * 0x30;
  *(undefined2 *)(iVar1 + 0x2a) = param_2;
  *(undefined4 *)(iVar1 + 0x38) = param_4;
  *(undefined4 *)(iVar1 + 0x3c) = param_3;
  *(char *)(iVar1 + 0x28) = param_5 + *(char *)(iVar1 + 0x28);
  memw();
  memw();
  return;
}

