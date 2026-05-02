// Function : FUN_401849d8
// Address  : 0x401849d8
// Size     : 29 bytes


undefined4 * FUN_401849d8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0xff;
  memw();
  return param_1 + 4;
}

