// Function : FUN_400f521c
// Address  : 0x400f521c
// Size     : 177 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f521c(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint *puVar3;
  char *pcVar4;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","M ERROR",0xec,"en");
    uVar1 = 0x103;
  }
  else {
    if (param_1 < 8) {
      if ((param_2 & 0xffff) < 0x400) {
        puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
        memw();
        memw();
        *puVar3 = *puVar3 & 0xfffffc00 | param_2 & 0x3ff;
        memw();
        return 0;
      }
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar4 = "S ERROR";
      uVar2 = 0xee;
      memw();
    }
    else {
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar4 = "r error";
      uVar2 = 0xed;
    }
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","M ERROR",uVar2,pcVar4);
    uVar1 = 0x102;
  }
  return uVar1;
}

