// Function : FUN_400e002c
// Address  : 0x400e002c
// Size     : 98 bytes


void FUN_400e002c(undefined4 *param_1)

{
  *param_1 = &DAT_3f406cb0;
  if ((*(char *)(param_1 + 0x27) != '\0') || (*(char *)((int)param_1 + 0x79) != '\0')) {
    FUN_400f0780(0x3ffc5490,"mpleted");
    if (*(char *)((int)param_1 + 0x79) != '\0') {
      FUN_400dffe8(param_1);
    }
    *(undefined1 *)(param_1 + 0x27) = 0;
    FUN_400f0780(0x3ffc5490,"troller");
  }
  if (param_1[0x26] != 0) {
    func_0x4009246c(param_1[0x26],5,0,0);
    param_1[0x26] = 0;
  }
  FUN_400f0a50(param_1 + 0x21);
  FUN_400dfd68(param_1);
  return;
}

