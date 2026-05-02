// Function : FUN_401705a4
// Address  : 0x401705a4
// Size     : 81 bytes


/* WARNING: Instruction at (ram,0x401705e5) overlaps instruction at (ram,0x401705e3)
    */

void FUN_401705a4(uint *param_1)

{
  undefined1 uVar1;
  int unaff_retaddr;
  uint uVar2;
  uint uVar3;
  uint in_stack_00000080;
  
  if (param_1 != (uint *)0x0) {
    FUN_40170020(param_1);
    uVar3 = *param_1 + 0xbcd4d500;
    if (((uint)(uVar3 < *param_1) + param_1[1] + 0xb8b1aabc == 0) && (uVar3 < 2)) {
      FUN_401701a8(param_1[-9]);
    }
  }
  FUN_401701ec();
  cust0();
  uVar1 = *(undefined1 *)(unaff_retaddr + 0x16);
  uVar3 = in_stack_00000080 >> 0x10 & 0xff;
  do {
    uVar2 = *(uint *)(uVar3 + 0x10);
    FUN_40171218(uVar3 + 0x30);
    uVar3 = uVar2;
  } while (uVar2 != 0);
  (*(code *)&SUB_40094d80)(uVar1);
  return;
}

