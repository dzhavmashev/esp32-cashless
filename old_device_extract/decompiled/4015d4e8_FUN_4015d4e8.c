// Function : FUN_4015d4e8
// Address  : 0x4015d4e8
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015d4e8(int param_1,char param_2,int param_3)

{
  if (param_3 == 1) {
    param_2 = param_2 + *(char *)(param_1 + 0xa7);
  }
  else if (param_3 != 0) goto LAB_4015d500;
  *(char *)(param_1 + 0xa7) = param_2;
  memw();
LAB_4015d500:
  if (*(char *)(param_1 + 0xa7) < '\0') {
    *(undefined1 *)(param_1 + 0xa7) = 0;
    memw();
  }
  if ('\x0f' < *(char *)(param_1 + 0xa7)) {
    *(undefined1 *)(param_1 + 0xa7) = 0xf;
    memw();
  }
  if ((*(char *)(param_1 + 0xa7) == '\0') && (param_1 != _DAT_3ffca0b8)) {
    memw();
    FUN_4015cd08();
  }
  return;
}

