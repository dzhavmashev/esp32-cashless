// Function : FUN_400f50bc
// Address  : 0x400f50bc
// Size     : 163 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f50bc(uint param_1)

{
  undefined4 uVar1;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","r_clear",0x75,"en");
    uVar1 = 0x103;
  }
  else if (param_1 < 8) {
    (*(code *)&SUB_40092a98)(0x3ffbdc50,0xffffffff);
    memw();
    memw();
    *(uint *)(*_DAT_3ffc5554 + 0xb0) =
         (uint)(0xfffffffefffffffe >> 0x20 - (param_1 * 2 + 1 & 0x1f)) &
         *(uint *)(*_DAT_3ffc5554 + 0xb0);
    memw();
    (*(code *)&SUB_40092bec)(0x3ffbdc50);
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","r_clear",0x76,"r error");
    uVar1 = 0x102;
  }
  return uVar1;
}

