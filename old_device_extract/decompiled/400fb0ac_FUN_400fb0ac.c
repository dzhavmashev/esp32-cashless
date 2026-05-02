// Function : FUN_400fb0ac
// Address  : 0x400fb0ac
// Size     : 52 bytes


void FUN_400fb0ac(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0xffffffff;
  *(undefined1 *)(param_1 + 5) = 0xfe;
  memw();
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0;
  memw();
  thunk_FUN_401849ab(param_1 + 0x11);
  param_1[0x14] = 0;
  memw();
  return;
}

