// Function : FUN_400dc63c
// Address  : 0x400dc63c
// Size     : 162 bytes


void FUN_400dc63c(undefined4 *param_1)

{
  *param_1 = &DAT_3f405ae8;
  if ((*(char *)(param_1 + 0x14) != '\0') || (*(char *)(param_1 + 0xc) != '\0')) {
    FUN_400f0780(0x3ffc5490,"D: %s)\n");
    if (*(char *)(param_1 + 0xc) != '\0') {
      FUN_400dc5a0(param_1);
    }
    *(undefined1 *)(param_1 + 0x14) = 0;
    FUN_400f0780(0x3ffc5490,"troller");
  }
  if (param_1[0x12] != 0) {
    func_0x4009246c(param_1[0x12],5,0,0);
    param_1[0x12] = 0;
  }
  if (param_1[0x13] != 0) {
    func_0x4009246c(param_1[0x13],5,0,0);
    param_1[0x13] = 0;
  }
  FUN_4016fa48(param_1[0x15]);
  param_1[0x15] = 0;
  FUN_400dc588(param_1[0xf],param_1[0x10]);
  if (param_1[0xf] != 0) {
    FUN_4016fa48();
  }
  *param_1 = &DAT_3f405abc;
  (*(code *)&LAB_40183a17_1)(param_1 + 5);
  (*(code *)&LAB_40183a17_1)(param_1 + 1);
  return;
}

