// Function : FUN_4014c10c
// Address  : 0x4014c10c
// Size     : 52 bytes


undefined1 *
FUN_4014c10c(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  *param_1 = 0xdd;
  memw();
  param_1[1] = param_4;
  param_1[2] = 'o';
  param_1[3] = 's';
  param_1[4] = 't';
  param_1[5] = param_2;
  param_1[6] = param_3;
  memw();
  memw();
  return param_1 + 7;
}

