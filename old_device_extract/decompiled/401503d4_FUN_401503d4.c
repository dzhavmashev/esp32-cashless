// Function : FUN_401503d4
// Address  : 0x401503d4
// Size     : 37 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401503d4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (((_DAT_3ffc8864 != 0) && (_DAT_3ffc7a40 != (code *)0x0)) && (uVar1 = 0x102, param_1 != 0)) {
    uVar1 = (*_DAT_3ffc7a40)(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x14));
  }
  return uVar1;
}

