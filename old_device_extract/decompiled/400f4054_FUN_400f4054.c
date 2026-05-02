// Function : FUN_400f4054
// Address  : 0x400f4054
// Size     : 168 bytes


undefined4 FUN_400f4054(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","_enable",0x113,"d): %s\n");
  }
  else {
    uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,3,param_1);
    if (((uVar1 & 1) != 0) || ((param_2 & 2) == 0)) {
      if ((param_2 & 1) == 0) {
        FUN_400f3734(param_1);
      }
      else {
        FUN_400f3938();
      }
      if ((param_2 & 2) == 0) {
        FUN_400f379c(param_1);
      }
      else {
        FUN_400f3a0c();
      }
      if ((param_2 & 4) != 0) {
        FUN_400f3868();
        return 0;
      }
      FUN_400f38d0(param_1);
      return 0;
    }
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"encyMhz","e error",uVar2,"encyMhz",param_1);
  }
  return 0x102;
}

