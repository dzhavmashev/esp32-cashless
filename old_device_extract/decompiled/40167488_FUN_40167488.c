// Function : FUN_40167488
// Address  : 0x40167488
// Size     : 78 bytes


undefined4 FUN_40167488(uint param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  memw();
  uVar2 = *(uint *)((param_1 & 0xff) * -0x3c + 0x3ff74270);
  uVar1 = (undefined1)(uVar2 >> 0x10);
  param_2[1] = (char)(uVar2 >> 8);
  *param_2 = (char)uVar2;
  param_2[2] = uVar1;
  param_2[3] = (char)(uVar2 >> 0x18);
  memw();
  if ((uVar2 & 0x1000000) == 0) {
    param_2[2] = 0x7f;
    memw();
  }
  else {
    param_2[2] = uVar1;
    memw();
    memw();
  }
  memw();
  return 0;
}

