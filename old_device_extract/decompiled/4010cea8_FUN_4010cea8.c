// Function : FUN_4010cea8
// Address  : 0x4010cea8
// Size     : 37 bytes


void FUN_4010cea8(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x3c) == 1) {
      (*(code *)&SUB_40094c54)(" LISTEN",0x83f,"cp_sent","lid seg");
    }
    *(undefined4 *)(param_1 + 0xb0) = param_2;
  }
  memw();
  return;
}

