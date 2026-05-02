// Function : FUN_4010ced0
// Address  : 0x4010ced0
// Size     : 37 bytes


void FUN_4010ced0(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x3c) == 1) {
      (*(code *)&SUB_40094c54)(" LISTEN",0x853,"tcp_err","allback");
    }
    *(undefined4 *)(param_1 + 0xac) = param_2;
  }
  memw();
  return;
}

