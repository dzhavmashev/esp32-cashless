// Function : FUN_400f3d28
// Address  : 0x400f3d28
// Size     : 160 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f3d28(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar5 = "d): %s\n";
    uVar3 = 0x94;
  }
  else {
    if (param_2 < 6) {
      (*(code *)&SUB_40092a98)(0x3ffbdc34,0xffffffff);
      iVar4 = *_DAT_3ffbdc30 + (param_1 + 0x20) * 4;
      memw();
      memw();
      *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xfffffc7f | (param_2 & 7) << 7;
      memw();
      (*(code *)&SUB_40092bec)(0x3ffbdc34);
      return 0;
    }
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar5 = "13FFC))";
    uVar3 = 0x95;
    memw();
  }
  memw();
  FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","_enable",uVar3,pcVar5);
  return 0x102;
}

