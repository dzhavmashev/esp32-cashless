// Function : FUN_400fb060
// Address  : 0x400fb060
// Size     : 74 bytes


void FUN_400fb060(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 int param_5,undefined1 param_6)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_6;
  memw();
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  if (param_5 == 0) {
    param_1[8] = 0;
    memw();
    memw();
  }
  else {
    memw();
    (*(code *)&SUB_4008c0f8)(param_1 + 8,param_5,0xf);
    param_1[0x17] = 0;
    memw();
  }
  memw();
  return;
}

