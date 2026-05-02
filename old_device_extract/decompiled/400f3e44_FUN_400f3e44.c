// Function : FUN_400f3e44
// Address  : 0x400f3e44
// Size     : 83 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f3e44(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","t_level",0xb1,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    uVar2 = 0;
    FUN_400fde74(_DAT_3ffbdc30,param_1);
  }
  return uVar2;
}

