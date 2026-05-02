// Function : FUN_400f45e4
// Address  : 0x400f45e4
// Size     : 147 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f45e4(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","et_mode",0xff,"en");
    uVar1 = 0x103;
  }
  else if (param_1 < 8) {
    puVar2 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffbff | (param_2 & 1) << 10;
    uVar1 = 0;
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","et_mode",0x100,"r error");
    uVar1 = 0x102;
  }
  return uVar1;
}

