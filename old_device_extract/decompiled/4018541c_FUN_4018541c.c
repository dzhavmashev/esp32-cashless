// Function : FUN_4018541c
// Address  : 0x4018541c
// Size     : 29 bytes


void FUN_4018541c(int param_1,uint param_2)

{
  if (*(byte *)(param_1 + 5) != param_2) {
    *(char *)(param_1 + 5) = (char)param_2;
    *(undefined1 *)(param_1 + 6) = 0;
    *(undefined2 *)(param_1 + 10) = 0;
    memw();
  }
  memw();
  return;
}

