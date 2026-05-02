// Function : FUN_4015a254
// Address  : 0x4015a254
// Size     : 41 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_4015a254(char param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == '\0') {
    if (_DAT_3ffc8800 == 0) {
      return 0;
    }
    iVar1 = *(int *)(_DAT_3ffc8800 + 0xe4);
  }
  else {
    iVar1 = FUN_40187c28(param_2);
  }
  if (iVar1 == 0) {
    return 0;
  }
  return *(undefined1 *)(iVar1 + 0x2f7);
}

