// Function : FUN_400f4310
// Address  : 0x400f4310
// Size     : 168 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f4310(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (_DAT_3ffbdc40 == 0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar1,"encyMhz","egister",0x1e2,"/gpio.c");
    uVar1 = 0x103;
  }
  else {
    uVar2 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
    if ((uVar2 & 1) == 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"encyMhz","hz",uVar1,"encyMhz","egister",0x1e3,"d): %s\n");
      uVar1 = 0x102;
    }
    else {
      (*(code *)&SUB_40092a98)(0x3ffbdc34,0xffffffff);
      FUN_400f3e44(param_1);
      if (_DAT_3ffbdc40 != 0) {
        puVar3 = (undefined4 *)(_DAT_3ffbdc40 + param_1 * 8);
        *puVar3 = 0;
        puVar3[1] = 0;
      }
      memw();
      (*(code *)&SUB_40092bec)(0x3ffbdc34);
      uVar1 = 0;
    }
  }
  return uVar1;
}

