// Function : FUN_40131548
// Address  : 0x40131548
// Size     : 41 bytes


void FUN_40131548(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[2] != 0) {
      FUN_4013ae54(param_1[2],param_1[1] << 2);
      FUN_4013ae44(param_1[2]);
    }
    *param_1 = 1;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  memw();
  return;
}

