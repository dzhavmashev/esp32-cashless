// Function : FUN_4013eca8
// Address  : 0x4013eca8
// Size     : 58 bytes


undefined4 FUN_4013eca8(undefined4 *param_1)

{
  param_1[2] = 0x67452301;
  param_1[3] = 0xefcdab89;
  param_1[4] = 0x98badcfe;
  param_1[5] = 0x10325476;
  param_1[6] = 0xc3d2e1f0;
  *param_1 = 0;
  param_1[1] = 0;
  if (param_1[0x17] == 1) {
    memw();
    FUN_40143664();
  }
  param_1[0x17] = 0;
  memw();
  return 0;
}

