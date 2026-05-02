// Function : FUN_400f39b8
// Address  : 0x400f39b8
// Size     : 83 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f39b8(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","disable",0x9f,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    uVar2 = 0;
    FUN_400fddf8(_DAT_3ffbdc30,param_1,param_2);
  }
  return uVar2;
}

