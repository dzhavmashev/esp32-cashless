// Function : FUN_400f4f6c
// Address  : 0x400f4f6c
// Size     : 166 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f4f6c(uint param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","r_pause",0x62,"en");
    uVar1 = 0x103;
  }
  else {
    if (param_1 < 8) {
      if (param_2 != (undefined2 *)0x0) {
        memw();
        memw();
        memw();
        *param_2 = (short)*(undefined4 *)(*_DAT_3ffc5554 + (param_1 + 0x18) * 4);
        memw();
        memw();
        return 0;
      }
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar3 = "o error";
      uVar2 = 100;
      memw();
    }
    else {
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar3 = "r error";
      uVar2 = 99;
    }
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","r_pause",uVar2,pcVar3);
    uVar1 = 0x102;
  }
  return uVar1;
}

