// Function : FUN_400f3a0c
// Address  : 0x400f3a0c
// Size     : 169 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f3a0c(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,3,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","disable",0xcd,"13FFC))");
    uVar2 = 0x102;
  }
  else {
    iVar3 = *_DAT_3ffbdc30;
    if ((int)param_1 < 0x20) {
      memw();
      *(int *)(iVar3 + 0x24) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    }
    else {
      memw();
      memw();
      memw();
      memw();
      memw();
      memw();
      *(uint *)(iVar3 + 0x30) =
           *(uint *)(iVar3 + 0x30) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_1 & 0x1f)) & 0xffU;
      memw();
    }
    memw();
    (*(code *)&SUB_40009f0c)(param_1,0x100,0);
    uVar2 = 0;
  }
  return uVar2;
}

