// Function : FUN_400f6de8
// Address  : 0x400f6de8
// Size     : 105 bytes


int FUN_400f6de8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 auStack_24 [9];
  
  if (param_1 < 3) {
    iVar2 = FUN_4011eb44((&DAT_3f41451c)[param_1 * 0x18],param_4,param_2,param_3,auStack_24);
    if (iVar2 == 0) {
      *(undefined4 *)(*(int *)(param_1 * 4 + 0x3ffc5588) + 8) = auStack_24[0];
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = auStack_24[0];
        memw();
      }
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"th","_select",uVar1,"th","set_pin",0x27a);
    iVar2 = -1;
  }
  return iVar2;
}

