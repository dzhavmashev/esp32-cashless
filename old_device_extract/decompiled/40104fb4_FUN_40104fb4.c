// Function : FUN_40104fb4
// Address  : 0x40104fb4
// Size     : 104 bytes


void FUN_40104fb4(undefined1 *param_1)

{
  undefined4 uVar1;
  int iStack_28;
  uint uStack_24;
  
  FUN_4010282c(&iStack_28);
  uVar1 = (*(code *)&SUB_40064ae0)(iStack_28 + -0x7c558180);
  *param_1 = (char)uVar1;
  param_1[2] = (char)((uint)uVar1 >> 0x10);
  param_1[3] = (char)((uint)uVar1 >> 0x18);
  param_1[1] = (char)((uint)uVar1 >> 8);
  memw();
  memw();
  uVar1 = (*(code *)&SUB_40064ae0)(uStack_24 * 0x10c7 - ((uStack_24 >> 5) + (uStack_24 >> 9)));
  param_1[4] = (char)uVar1;
  param_1[5] = (char)((uint)uVar1 >> 8);
  param_1[6] = (char)((uint)uVar1 >> 0x10);
  param_1[7] = (char)((uint)uVar1 >> 0x18);
  memw();
  memw();
  return;
}

