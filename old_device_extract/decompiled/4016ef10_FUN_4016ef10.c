// Function : FUN_4016ef10
// Address  : 0x4016ef10
// Size     : 148 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016ef10(void)

{
  undefined4 in_a7;
  uint uVar1;
  byte in_stack_00000004;
  int in_stack_00000008;
  
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x62,1,0,7,7,1,in_a7);
  (**(code **)(_DAT_3ffc7e64 + 0x98))(0x62,1,0);
  uVar1 = 0;
  if (in_stack_00000004 == 0) {
    return;
  }
  do {
    *(undefined1 *)(in_stack_00000008 + uVar1) = 0;
    memw();
    if (uVar1 < 0xd) {
                    /* WARNING: Could not emulate address calculation at 0x4016ef90 */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(uVar1 * 4 + 0x3ffc3b08))();
      return;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < in_stack_00000004);
  return;
}

