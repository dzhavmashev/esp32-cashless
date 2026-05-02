// Function : FUN_400f3e98
// Address  : 0x400f3e98
// Size     : 231 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f3e98(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,3,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","ll_mode",0xe3,"13FFC))");
    uVar2 = 0x102;
  }
  else {
    iVar3 = *_DAT_3ffbdc30;
    if (param_2 == 0) {
      if (0x1f < (int)param_1) {
        memw();
        memw();
        memw();
        memw();
        memw();
        memw();
        *(uint *)(iVar3 + 0x18) =
             *(uint *)(iVar3 + 0x18) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_1 & 0x1f)) & 0xffU;
        memw();
        return 0;
      }
      memw();
      *(int *)(iVar3 + 0xc) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
      memw();
    }
    else if ((int)param_1 < 0x20) {
      memw();
      *(int *)(iVar3 + 8) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    }
    else {
      memw();
      memw();
      memw();
      memw();
      memw();
      memw();
      *(uint *)(iVar3 + 0x14) =
           *(uint *)(iVar3 + 0x14) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_1 & 0x1f)) & 0xffU;
      memw();
    }
    uVar2 = 0;
    memw();
  }
  return uVar2;
}

