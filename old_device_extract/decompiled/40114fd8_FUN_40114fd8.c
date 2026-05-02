// Function : FUN_40114fd8
// Address  : 0x40114fd8
// Size     : 46 bytes


void FUN_40114fd8(int param_1)

{
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("ONS_LEN",0x389,"efcount","!= NULL");
  }
  if (*(int *)(param_1 + 200) != 0) {
    FUN_4010afc4();
    *(undefined4 *)(param_1 + 200) = 0;
  }
  memw();
  return;
}

