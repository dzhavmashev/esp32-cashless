// Function : FUN_40147168
// Address  : 0x40147168
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40147168(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_401460c8();
  uVar2 = 0x3001;
  if ((iVar1 != 0) && (uVar2 = 0x102, param_1 < 2)) {
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
    DAT_3ffc8a05 = (undefined1)param_1;
    memw();
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
    uVar2 = 0;
  }
  return uVar2;
}

