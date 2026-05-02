// Function : FUN_400df508
// Address  : 0x400df508
// Size     : 51 bytes


void FUN_400df508(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x2c) != param_2) {
    memw();
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x2c);
    memw();
    *(int *)(param_1 + 0x84) = param_2;
    *(int *)(param_1 + 0x2c) = param_2;
    memw();
    *(undefined1 *)(param_1 + 0x7d) = 1;
    if (*(int *)(param_1 + 0x74) != 0) {
      func_0x40091e4c(*(int *)(param_1 + 0x74),0,0,2);
    }
  }
  return;
}

