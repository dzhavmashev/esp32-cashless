// Function : FUN_4013d7b8
// Address  : 0x4013d7b8
// Size     : 66 bytes


void FUN_4013d7b8(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(uint *)(param_1 + 4) < param_2) {
    (*(code *)&SUB_40094c54)("t/esp32/bignum.c",0x62,"ignum.c",&DAT_3f42258d);
  }
  (*(code *)&SUB_400845b8)(*(undefined4 *)(param_1 + 8),&DAT_3ff02200,param_2);
  while (param_2 < *(uint *)(param_1 + 4)) {
    iVar1 = param_2 * 4;
    param_2 = param_2 + 1;
    *(undefined4 *)(*(int *)(param_1 + 8) + iVar1) = 0;
    memw();
  }
  return;
}

