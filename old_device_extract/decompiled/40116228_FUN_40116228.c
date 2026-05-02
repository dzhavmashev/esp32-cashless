// Function : FUN_40116228
// Address  : 0x40116228
// Size     : 75 bytes


void FUN_40116228(int param_1,uint param_2)

{
  uint uVar1;
  
  if (2 < param_2) {
    uVar1 = (*(code *)&SUB_400842fc)();
    *(short *)(param_1 + 10) = (short)(uVar1 % param_2);
    memw();
    if (uVar1 % param_2 != 0) {
      memw();
      goto LAB_40116237;
    }
  }
  *(undefined2 *)(param_1 + 10) = 1;
  memw();
LAB_40116237:
  if (DAT_3ffc6478 == '\0') {
    memw();
    FUN_40113258(100,&DAT_401166b0);
    DAT_3ffc6478 = '\x01';
    memw();
  }
  memw();
  return;
}

