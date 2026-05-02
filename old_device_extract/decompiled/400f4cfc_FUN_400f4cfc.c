// Function : FUN_400f4cfc
// Address  : 0x400f4cfc
// Size     : 157 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f4cfc(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    if (_DAT_3ffc5554 == 0) {
      _DAT_3ffc5554 = (*(code *)&SUB_400841f0)(1,4,0x1000);
      if (_DAT_3ffc5554 == 0) {
        memw();
        uVar2 = (*(code *)&SUB_40094b80)();
        uVar1 = 0xffffffff;
        FUN_4012113c(1,"llup_en","initted",uVar2,"llup_en");
      }
      else {
        FUN_400fe628(_DAT_3ffc5554,0);
        uVar1 = 0;
      }
    }
    else {
      uVar1 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","_config",0x18c,"m error");
      uVar1 = 0x103;
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","_config",0x18b,"E ERROR");
    uVar1 = 0x102;
  }
  return uVar1;
}

