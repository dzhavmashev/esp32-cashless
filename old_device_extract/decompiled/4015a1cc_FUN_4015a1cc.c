// Function : FUN_4015a1cc
// Address  : 0x4015a1cc
// Size     : 41 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015a1cc(uint param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(_DAT_3ffc8800 + 0xe4);
  *(undefined1 *)(iVar1 + 0x135) = param_2;
  *(undefined1 *)(iVar1 + (param_1 & 0xff) + 0x137) = param_2;
  memw();
  memw();
  return;
}

