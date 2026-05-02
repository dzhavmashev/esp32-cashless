// Function : FUN_400f38d0
// Address  : 0x400f38d0
// Size     : 103 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f38d0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","_config",0xd5,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    iVar3 = *_DAT_3ffbdc30 + (param_1 + 0x20) * 4;
    memw();
    memw();
    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffb;
    uVar2 = 0;
    memw();
  }
  return uVar2;
}

