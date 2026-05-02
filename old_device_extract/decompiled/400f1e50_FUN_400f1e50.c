// Function : FUN_400f1e50
// Address  : 0x400f1e50
// Size     : 77 bytes


uint FUN_400f1e50(uint param_1)

{
  uint in_a7;
  int iVar1;
  uint uVar2;
  uint in_stack_00000000;
  char in_stack_00000004;
  char in_stack_00000008;
  
  param_1 = param_1 & 0xff;
  uVar2 = 0;
  if (param_1 < 3) {
    uVar2 = FUN_400f7cd0(param_1);
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = param_1 * 0x20;
      if (((*(ushort *)(iVar1 + 0x3ffbdbe8) == in_a7) &&
          (*(ushort *)(iVar1 + 0x3ffbdbea) == in_stack_00000000)) &&
         (*(char *)(iVar1 + 0x3ffbdbec) == in_stack_00000004)) {
        uVar2 = (uint)(*(char *)(iVar1 + 0x3ffbdbed) != in_stack_00000008);
      }
    }
  }
  return uVar2;
}

