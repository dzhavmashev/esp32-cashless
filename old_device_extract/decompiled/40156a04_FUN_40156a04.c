// Function : FUN_40156a04
// Address  : 0x40156a04
// Size     : 63 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40156a04(uint param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  uVar1 = _DAT_3ffc799c;
  pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x58);
  *(uint *)(_DAT_3ffbfd50 + 0x114) = param_1 & 0xff;
  memw();
  (*pcVar2)(uVar1);
  FUN_40147fe4(1,8,5,0x3f435dd0,*(undefined4 *)(_DAT_3ffbfd50 + 0x114));
  return;
}

